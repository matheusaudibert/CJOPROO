#ifndef SCORE_HPP
#define SCORE_HPP

#include <raylib.h>

class Score 
{
public:
    Score();
    void Increase();
    void Draw() const;
    int GetScore() const; // Adicione um método para obter a pontuação atual

private:
    int score;
};

#endif