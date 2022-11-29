#pragma once

typedef struct 
{
    Vector2 Position;
    Rectangle Bounds;
    Vector2 Velocity;
    float Friction;

} Player;

void PlayerUpdate(Player *player);