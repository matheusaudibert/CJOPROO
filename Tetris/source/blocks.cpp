#include "block.h"
#include "posicao.h"
using namespace std;

class LBlock :public Block
{
  public:
    LBlock(){
      id = 1;
      celulas[0] = {Posicao(0, 2), Posicao(1, 0), Posicao(1, 1), Posicao(1, 2)};
      celulas[1] = {Posicao(0, 1), Posicao(1, 1), Posicao(2, 1), Posicao(2, 2)};
      celulas[2] = {Posicao(1, 0), Posicao(1, 1), Posicao(1, 2), Posicao(2, 0)};
      celulas[3] = {Posicao(0, 0), Posicao(0, 1), Posicao(1, 1), Posicao(2, 1)};
      Move(0, 3);
      }
};

class JBlock :public Block
{
  public:
    JBlock(){
      id = 2;
      celulas[0] = {Posicao(0, 0), Posicao(1, 0), Posicao(1, 1), Posicao(1, 2)};
      celulas[1] = {Posicao(0, 1), Posicao(0, 2), Posicao(1, 1), Posicao(2, 1)};
      celulas[2] = {Posicao(1, 0), Posicao(1, 1), Posicao(1, 2), Posicao(2, 2)};
      celulas[3] = {Posicao(0, 1), Posicao(1, 1), Posicao(2, 0), Posicao(2, 1)};
      Move(0, 3);
      }
};

class IBlock :public Block
{
  public:
    IBlock(){
      id = 3;
      celulas[0] = {Posicao(1, 0), Posicao(1, 1), Posicao(1, 2), Posicao(1, 3)};
      celulas[1] = {Posicao(0, 2), Posicao(1, 2), Posicao(2, 2), Posicao(3, 2)};
      celulas[2] = {Posicao(2, 0), Posicao(2, 1), Posicao(2, 2), Posicao(2, 3)};
      celulas[3] = {Posicao(0, 1), Posicao(1, 1), Posicao(2, 1), Posicao(3, 1)};
      Move(-1, 3);
      }
};

class OBlock :public Block
{
  public:
    OBlock(){
      id = 4;
      celulas[0] = {Posicao(0, 0), Posicao(0, 1), Posicao(1, 0), Posicao(1, 1)};
      celulas[1] = {Posicao(0, 0), Posicao(0, 1), Posicao(1, 0), Posicao(1, 1)};
      celulas[2] = {Posicao(0, 0), Posicao(0, 1), Posicao(1, 0), Posicao(1, 1)};
      celulas[3] = {Posicao(0, 0), Posicao(0, 1), Posicao(1, 0), Posicao(1, 1)};
      Move(0, 4);
      }
};

class SBlock :public Block
{
  public:
    SBlock(){
      id = 5;
      celulas[0] = {Posicao(0, 1), Posicao(0, 2), Posicao(1, 0), Posicao(1, 1)};
      celulas[1] = {Posicao(0, 0), Posicao(1, 0), Posicao(1, 1), Posicao(2, 1)};
      celulas[2] = {Posicao(0, 1), Posicao(0, 2), Posicao(1, 0), Posicao(1, 1)};
      celulas[3] = {Posicao(0, 0), Posicao(1, 0), Posicao(1, 1), Posicao(2, 1)};
      Move(0, 3);
      }
};

class TBlock :public Block
{
  public:
    TBlock(){
      id = 6;
      celulas[0] = {Posicao(0, 1), Posicao(1, 0), Posicao(1, 1), Posicao(1, 2)};
      celulas[1] = {Posicao(0, 1), Posicao(1, 1), Posicao(1, 2), Posicao(2, 1)};
      celulas[2] = {Posicao(1, 0), Posicao(1, 1), Posicao(1, 2), Posicao(2, 1)};
      celulas[3] = {Posicao(0, 1), Posicao(1, 0), Posicao(1, 1), Posicao(2, 1)};
      Move(0, 3);
      }
};

class ZBlock :public Block
{
  public:
    ZBlock(){
      id = 7;
      celulas[0] = {Posicao(0, 0), Posicao(0, 1), Posicao(1, 1), Posicao(1, 2)};
      celulas[1] = {Posicao(0, 1), Posicao(1, 0), Posicao(1, 1), Posicao(2, 0)};
      celulas[2] = {Posicao(0, 0), Posicao(0, 1), Posicao(1, 1), Posicao(1, 2)};
      celulas[3] = {Posicao(0, 1), Posicao(1, 0), Posicao(1, 1), Posicao(2, 0)};
      Move(0, 3);
      }
};
