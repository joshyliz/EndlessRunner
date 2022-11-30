#pragma once
#include "raylib.h"
#include "Level.h"

#define PLAYER_SPEED_CAP 100
#define PLAYER_JUMP_HEIGHT 200

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