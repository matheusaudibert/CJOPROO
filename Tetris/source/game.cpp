#include "game.h"
#include <random>
using namespace std;

Game::Game()
{
  grid = Grid();
  blocks = PegarTodosBlocks();
  blockAtual = BlockAleatorio();
  proximoBlock = BlockAleatorio();
  gameOver = false;
  pontos = 0;
  InitAudioDevice();
  music = LoadMusicStream("../Sounds/music.mp3");
  PlayMusicStream(music);
  rotateSound = LoadSound("../Sounds/rotate.mp3");
  clearSound = LoadSound("../Sounds/clear.mp3");
}

Game::~Game()
{
  UnloadSound(rotateSound); 
  UnloadSound(clearSound); 
  UnloadMusicStream(music);
  CloseAudioDevice();
}

Block Game::BlockAleatorio()
{
  if(blocks.empty())
  {
    blocks = PegarTodosBlocks();
  }

  int IndexAleatorio = rand() % blocks.size();
  Block block = blocks[IndexAleatorio];
  blocks.erase(blocks.begin() + IndexAleatorio);
  return block;
}

vector<Block> Game::PegarTodosBlocks()
{
  return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw()
{
  grid.Draw();
  blockAtual.Draw(11, 11);
  switch(proximoBlock.id){
    case 3:
      proximoBlock.Draw(255, 290);
    break;
    case 4:
      proximoBlock.Draw(255, 280);
    break;
    default:
      proximoBlock.Draw(270, 270);
    break;
  }
}

void Game::HandleInput()
{
  int teclaPressionada = GetKeyPressed();
  if(gameOver && teclaPressionada != 0)
  {
    gameOver = false;
    Reiniciar();
  }
  switch(teclaPressionada)
  {
    case KEY_LEFT:
      MoverEsquerda();
      break;
    case KEY_RIGHT:
      MoverDireita();
      break;
    case KEY_DOWN:
      MoverBaixo();
      AtualizaPontos(0,1);
      break;  
    case KEY_UP:
      RotacionarBlock();
      break;
  }
}

void Game::MoverEsquerda()
{
  if(!gameOver){
    blockAtual.Move(0, -1);
    if(blockFora() || BlockEncaixa() == false)
    {
      blockAtual.Move(0, 1);
    }
  }
}

void Game::MoverDireita()
{
  if(!gameOver){
    blockAtual.Move(0, 1);
    if(blockFora() || BlockEncaixa() == false)
    {
      blockAtual.Move(0, -1);
    }
  }
}

void Game::MoverBaixo()
{
  if(!gameOver){
    blockAtual.Move(1, 0);
    if(blockFora() || BlockEncaixa() == false)
    {
      blockAtual.Move(-1, 0);
      TravarBlock();
    }
  }
}

bool Game::blockFora()
{
  vector<Posicao> quadrados = blockAtual.PegarPosicao();
  for (Posicao item : quadrados)
  {
    if(grid.celulaFora(item.linha, item.coluna))
    {
      return true;
    }
  }
  return false;
}

void Game::RotacionarBlock()
{
  if(!gameOver){
    blockAtual.Rotacionar();
    if(blockFora() || BlockEncaixa() == false)
    {
      blockAtual.DesfazerRotacao();
    }
    else
    {
      PlaySound(rotateSound);
    }
  }
}

void Game::TravarBlock()
{
  vector<Posicao> quadrados = blockAtual.PegarPosicao();
  for (Posicao item : quadrados)
  {
    grid.grid[item.linha][item.coluna]= blockAtual.id;
  }
  blockAtual = proximoBlock;
  if(BlockEncaixa() == false)
  {
    gameOver = true;
  }
  proximoBlock = BlockAleatorio();
  int linhasCompletas = grid.LimparLinhaCompletamente();
  if(linhasCompletas > 0)
  {
    PlaySound(clearSound);
    AtualizaPontos(linhasCompletas, 0);
  }
}

bool Game::BlockEncaixa()
{
  vector<Posicao> quadrados = blockAtual.PegarPosicao();
  for (Posicao item : quadrados)
  {
    if(grid.celulaVazia(item.linha, item.coluna) == false)
    { 
      return false;
    }
  }
  return true;
}

void Game::Reiniciar()
{
  
  grid.Initialize();
  blocks = PegarTodosBlocks();
  blockAtual = BlockAleatorio();
  proximoBlock = BlockAleatorio();
  pontos = 0;
}

void Game::AtualizaPontos(int linhaLimpas, int blocosPraBaixo)
{
  switch(linhaLimpas){
    case 1:
      pontos += 100;
      break;
    case 2:
      pontos += 300;
      break;
    case 3:
      pontos += 500;
      break;
  }

  pontos += blocosPraBaixo;
}