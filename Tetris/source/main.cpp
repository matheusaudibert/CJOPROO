#include <raylib.h>
#include "game.h"
#include "cores.h"
#include <iostream>

double ultimoUptade = 0;

bool EventoDeAtualizacao(double intervalo)
{
    double tempoAtual = GetTime();
    if(tempoAtual - ultimoUptade >= intervalo)
    {
        ultimoUptade = tempoAtual;
        return true;
    }
    return false;
}

int main() 

{
    InitWindow(500, 620, "Raylib Tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("../Font/monogram.ttf", 64, 0, 0);            

    Game game = Game();

    while(WindowShouldClose() == false) 
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        if(EventoDeAtualizacao(0.2))
        {
            game.MoverBaixo();
        }
        BeginDrawing();
        ClearBackground(azulEscuro);
        DrawTextEx(font, "Pontos", {345, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Próximo", {340, 175}, 38, 2, WHITE);
        if(game.gameOver)
        {
            DrawTextEx(font, "Game Over", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, azulClaro);

        char textoDePontos[10];
        sprintf(textoDePontos, "%d", game.pontos);
        Vector2 tamanhoDoTexto = MeasureTextEx(font, textoDePontos, 38, 2);


        DrawTextEx(font, textoDePontos, {320 + (170 - tamanhoDoTexto.x)/2, 65}, 40, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, azulClaro);
        game.Draw();
        EndDrawing();

    }

    CloseWindow();
}