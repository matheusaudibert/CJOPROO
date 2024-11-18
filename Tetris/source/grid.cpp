#include "grid.h"
#include <iostream>
#include "cores.h"
using namespace std;

Grid::Grid()
{
    numLinhas = 20;
    numColunas = 10;
    tamCelula = 30;
    Initialize();
    cores = PegarCor();
}

void Grid::Initialize()
{
  for (int linha = 0; linha < numLinhas; linha++)
  {
    for (int coluna = 0; coluna < numColunas; coluna++)
    {
      grid[linha][coluna] = 0;
    }
  }
}

void Grid::Print()
{
  for (int linha = 0; linha < numLinhas; linha++)
  {
    for (int coluna = 0; coluna < numColunas; coluna++)
    {
      cout << grid[linha][coluna] << " ";
    }
    cout << endl;
  }
}

void::Grid::Draw()
{
  for (int linha = 0; linha < numLinhas; linha++)
  {
    for (int coluna = 0; coluna < numColunas; coluna++)
    {
      int valorCelula = grid[linha][coluna];
      DrawRectangle(coluna * tamCelula+11, linha * tamCelula+11, tamCelula-1, tamCelula-1, cores[valorCelula]);
    }
  }
}

bool Grid::celulaFora(int linha, int coluna)
{
  if (linha >=0 && linha < numLinhas && coluna >= 0 && coluna < numColunas)
  {
    return false;
  }
  return true;
}

bool Grid::celulaVazia(int linha, int coluna)
{
  if (grid[linha][coluna] == 0)
  {
    return true;
  }
  return false;
}

int Grid::LimparLinhaCompletamente()
{
  int linhaCompleta = 0;
  for (int linha = numLinhas - 1; linha >= 0; linha--)
  {
    if (LinhaCheia(linha))
    {
      LimparLinha(linha);
      linhaCompleta++;
    }
    else if(linhaCompleta > 0)
    {
      MoverLinha(linha, linhaCompleta);
    }
  }
  return linhaCompleta;
}

bool Grid::LinhaCheia(int linha)
{
  for (int coluna = 0; coluna < numColunas; coluna++)
  {
    if (grid[linha][coluna] == 0)
    {
      return false;
    }
  }
  return true;
}

void Grid::LimparLinha(int linha)
{
  for (int coluna = 0; coluna < numColunas; coluna++)
  {
    grid[linha][coluna] = 0;
  }
}

void Grid::MoverLinha(int linha, int numLinhas)
{
  for (int coluna = 0; coluna < numColunas; coluna++)
  {
    grid[linha + numLinhas][coluna] = grid[linha][coluna];
    grid[linha][coluna] = 0;
  }
}
