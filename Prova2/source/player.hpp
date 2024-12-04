#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <raylib.h>

class Player 
{
public:
    Player();
    Player(Texture2D texture);
    void Update();
    void Draw();
    Rectangle GetRect() const;

private:
    Vector2 position;
    float speed;
    int size;
    Texture2D texture;
};

#endif