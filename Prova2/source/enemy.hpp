#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <raylib.h>

class Enemy 
{
public:
    Enemy(bool isPoint = false);
    Enemy(Texture2D texture, bool isPoint = false);
    void Update();
    void Draw() const;
    Rectangle GetRect() const;

private:
    Vector2 position;
    float speed;
    int size;
    bool isPoint;
    Texture2D texture;
};

#endif