#pragma once
#include <vector>
#include <raylib.h>
using namespace std;

class Grid
{
  public:
    Grid();
    void Initialize();
    void Print();
    void Draw();
    bool celulaFora(int linha, int coluna);
    bool celulaVazia(int linha, int coluna);
    int LimparLinhaCompletamente();
    int grid[20][10]; 

  private:
    bool LinhaCheia(int linha);
    void LimparLinha(int linha);
    void MoverLinha(int linha, int numLinhas);
    int numLinhas;
    int numColunas;
    int tamCelula;
    vector<Color> cores;

};