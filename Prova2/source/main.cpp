#include <raylib.h>
#include <iostream>
#include <vector>
#include "player.hpp"
#include "enemy.hpp"
#include "score.hpp"

bool GameLoop(Texture2D playerTexture, Texture2D enemyTexture, Texture2D pointTexture);
bool EndMenu();

int main() 
{
    // Inicializa a janela
    InitWindow(800, 600, "Prova P2");
    SetTargetFPS(60);

    // Carrega texturas
    Texture2D playerTexture = LoadTexture("../assets/player.png");
    Texture2D enemyTexture = LoadTexture("../assets/enemy.png");
    Texture2D pointTexture = LoadTexture("../assets/score.png");

    while (!WindowShouldClose()) 
    {
        if (!GameLoop(playerTexture, enemyTexture, pointTexture)) 
        {
            if (!EndMenu()) 
            {
                break;
            }
        }
    }

    // Descarrega texturas
    UnloadTexture(playerTexture);
    UnloadTexture(enemyTexture);
    UnloadTexture(pointTexture);

    CloseWindow();
    return 0;
}

bool GameLoop(Texture2D playerTexture, Texture2D enemyTexture, Texture2D pointTexture) 
{
    Player player(playerTexture);
    std::vector<Enemy> enemies;
    std::vector<Enemy> points;
    Score score;
    int life = 100; // Vida inicial do jogador

    int enemySpawnTimer = 0;

    while (!WindowShouldClose()) 
    {
        // Atualiza o jogador e os inimigos
        player.Update();
        for (auto& enemy : enemies) 
        {
            enemy.Update();
        }

        // Atualiza os pontos verdes
        for (auto& point : points) 
        {
            point.Update();
        }

        // Adiciona novos inimigos de forma contínua e aleatória
        if (enemySpawnTimer <= 0 && enemies.size() < 7) // Aumente o limite de inimigos para 7
        {
            enemies.push_back(Enemy(enemyTexture));
            enemySpawnTimer = GetRandomValue(60, 180); // Tempo aleatório entre 1 e 3 segundos
        } 
        else 
        {
            enemySpawnTimer--;
        }

        // Adiciona novos pontos verdes se houver menos de 3 na tela
        if (points.size() < 3 && GetRandomValue(0, 100) < 2) 
        {
            points.push_back(Enemy(pointTexture, true));
        }

        // Verifica colisão com os inimigos
        for (auto it = enemies.begin(); it != enemies.end();) 
        {
            if (CheckCollisionRecs(player.GetRect(), it->GetRect())) 
            {
                life -= 10; // Reduz a vida em 10%
                it = enemies.erase(it); // Remove o inimigo
                if (life <= 0) 
                {
                    std::cout << "Você perdeu!" << std::endl;
                    return false;
                }
            } 
            else 
            {
                ++it;
            }
        }

        // Verifica colisão com os pontos verdes
        for (auto it = points.begin(); it != points.end();) 
        {
            if (CheckCollisionRecs(player.GetRect(), it->GetRect())) 
            {
                score.Increase();
                it = points.erase(it);
            } 
            else 
            {
                ++it;
            }
        }

        // Desenha na tela
        BeginDrawing();
        ClearBackground(BLACK); // Altere a cor de fundo para preto

        player.Draw();
        for (const auto& enemy : enemies) 
        {
            enemy.Draw();
        }
        for (const auto& point : points) 
        {
            point.Draw();
        }
        score.Draw();

        // Desenha as informações do jogador
        DrawText(TextFormat("Enemys: %i", life / 10), 600, 30, 30, WHITE); // Número de inimigos baseado na vida
        DrawText(TextFormat("Grovy: %i%%", life), 600, 70, 30, WHITE); // Vida do jogador
        DrawText(TextFormat("Score: %i", score.GetScore()), 600, 110, 30, WHITE); // Pontuação do jogador

        EndDrawing();
    }

    return false; // Retorna false se a janela for fechada
}

bool EndMenu() 
{
    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("Você perdeu!", 350, 200, 20, RED);
        DrawText("Pressione ENTER para jogar novamente", 250, 250, 20, WHITE);
        DrawText("Pressione ESC para sair", 300, 300, 20, WHITE);

        EndDrawing();

        if (IsKeyPressed(KEY_ENTER)) 
        {
            return true;
        }
        if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose()) 
        {
            return false;
        }
    }

    return false;
}