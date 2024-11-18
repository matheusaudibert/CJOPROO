#include "cores.h"
using namespace std;

extern const Color verdeEscuro = {26,31, 40, 255};
extern const Color verde = {47, 230, 23, 255};
extern const Color vermelho = {232, 18, 18, 255};
extern const Color laranja = {226, 116, 17, 255};
extern const Color amarelo = {237, 234, 4, 255};
extern const Color roxo = {166, 0, 247, 255};
extern const Color ciano = {21, 204, 209, 255};
extern const Color azul = {13, 64, 216, 255};
extern const Color azulClaro = {59, 85, 165, 255};
extern const Color azulEscuro = {44, 44, 127, 255};

vector<Color> PegarCor(){
  return {verdeEscuro, verde, vermelho, laranja, amarelo, roxo, ciano, azul};
}

