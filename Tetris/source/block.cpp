#include "block.h"
using namespace std;

Block::Block()
{
  tamCelula = 30;
  estadoRotacao = 0;
  cores = PegarCor();
  linhaOffset = 0;
  colunaOffset = 0;
}

void Block::Draw(int offsetx, int offsety)
{
  vector<Posicao> quadrados = PegarPosicao();
  for (Posicao item : quadrados)
  {
    DrawRectangle(item.coluna * tamCelula + offsetx, item.linha * tamCelula + offsety, tamCelula - 1, tamCelula - 1, cores[id]);
  }
}

void Block::Move(int linha, int coluna)
{
  linhaOffset += linha;
  colunaOffset += coluna;
}

vector<Posicao> Block :: PegarPosicao()
{
  vector<Posicao> quadrados = celulas[estadoRotacao];
  vector<Posicao> quadradosMovidos;
  for (Posicao item : quadrados)
  {
    Posicao novaPosicao = Posicao(item.linha + linhaOffset, item.coluna + colunaOffset);
    quadradosMovidos.push_back(novaPosicao);
  }
  return quadradosMovidos;
}

void Block::Rotacionar()
{
  estadoRotacao++;
  if (estadoRotacao == celulas.size())
  {
    estadoRotacao = 0;
  }
}

void Block::DesfazerRotacao()
{
  estadoRotacao--;
  if (estadoRotacao == -1)
  {
    estadoRotacao = celulas.size() - 1;
  }
}