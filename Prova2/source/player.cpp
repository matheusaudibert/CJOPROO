#include "player.hpp"

Player::Player() 
{
    position = { 400, 300 };
    speed = 3.0f;
    size = 40;
}

Player::Player(Texture2D texture) : texture(texture)
{
    position = { 400, 300 };
    speed = 3.0f;
    size = 40;
}

void Player::Update() 
{
    if (IsKeyDown(KEY_RIGHT) && position.x + size < 800) position.x += speed;
    if (IsKeyDown(KEY_LEFT) && position.x > 0) position.x -= speed;
    if (IsKeyDown(KEY_UP) && position.y > 0) position.y -= speed;
    if (IsKeyDown(KEY_DOWN) && position.y + size < 600) position.y += speed;
}

void Player::Draw() 
{
    DrawTexture(texture, position.x, position.y, WHITE);
}

Rectangle Player::GetRect() const 
{
    return { position.x, position.y, size, size };
}