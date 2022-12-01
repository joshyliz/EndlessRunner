#pragma once
#include "raylib.h"
#include "Level.h"

#define PLAYER_SPEED_CAP 5
#define PLAYER_MININUM_SPEED 2
#define PLAYER_JUMP_HEIGHT 500

typedef struct 
{
    Vector2 Position;
    Rectangle Bounds;
    Vector2 Velocity;
    float Friction;
    float Gravity;
    bool isGrounded;
} Player;

void PlayerUpdate(Player *player, Level *level);