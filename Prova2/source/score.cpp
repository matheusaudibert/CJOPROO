#include "score.hpp"

Score::Score() 
{
    score = 0;
}

void Score::Increase() 
{
    score++;
}

void Score::Draw() const 
{
    DrawText(TextFormat("Score: %i", score), 700, 10, 20, BLACK);
}

int Score::GetScore() const 
{
    return score;
}