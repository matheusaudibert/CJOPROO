#pragma once
#include "grid.h"
#include "blocks.cpp"
using namespace std;

class Game
{
  public:
    Game();
    ~Game();
    void Draw();
    void HandleInput();
    void MoverBaixo();
    bool gameOver;
    int pontos;
    Music music;

  private:
    Grid grid;
    void MoverEsquerda();
    void MoverDireita();
    Block BlockAleatorio();
    vector<Block> PegarTodosBlocks();
    bool blockFora();
    void RotacionarBlock();
    void TravarBlock();
    bool BlockEncaixa();
    void Reiniciar();
    void AtualizaPontos(int linhaLimpas, int MoverPontos);
    vector<Block> blocks;
    Block blockAtual;
    Block proximoBlock;
    Sound rotateSound;
    Sound clearSound;
};