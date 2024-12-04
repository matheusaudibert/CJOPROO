#include "enemy.hpp"

Enemy::Enemy(bool isPoint) 
{
    this->isPoint = isPoint;
    position = { isPoint ? 0 : 800, static_cast<float>(GetRandomValue(0, 580)) };
    speed = isPoint ? 3.0f : 4.0f;
    size = isPoint ? 20 : 40;
}

Enemy::Enemy(Texture2D texture, bool isPoint) : texture(texture)
{
    this->isPoint = isPoint;
    position = { isPoint ? 0 : 800, static_cast<float>(GetRandomValue(0, 580)) };
    speed = isPoint ? 3.0f : 4.0f;
    size = isPoint ? 20 : 40;
}

void Enemy::Update() 
{
    position.x += speed;
    if (position.x > 800) 
    {
        position.x = 0;
        position.y = static_cast<float>(GetRandomValue(0, 580));
    }
}

void Enemy::Draw() const
{
    DrawTexture(texture, position.x, position.y, WHITE);
}

Rectangle Enemy::GetRect() const 
{
    return { position.x, position.y, size, size };
}