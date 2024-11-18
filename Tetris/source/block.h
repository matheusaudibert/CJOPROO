#pragma once
#include <vector>
#include <map>
#include "posicao.h"
#include "cores.h"
using namespace std;

class Block
{
  public:
    Block();
    void Draw(int offsetx, int offsety);
    void Move(int linha, int coluna);
    vector<Posicao> PegarPosicao();
    void Rotacionar();
    void DesfazerRotacao();
    int id;
    map<int, vector<Posicao>> celulas;
  private:
    int tamCelula;
    int estadoRotacao;
    vector<Color> cores;
    int linhaOffset;
    int colunaOffset;
};