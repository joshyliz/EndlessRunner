#include "raylib.h"
#include "Player.h"
#include <stdio.h>

void PlayerUpdate(Player *player)
{
    float delta = GetFrameTime();

    if(IsKeyDown(KEY_A))
        player->Velocity.x = -20;
    else if(IsKeyDown(KEY_D))
        player->Velocity.x = 20;   
    else if(player->Velocity.x < 0)
    {
        player->Velocity.x += player->Friction * delta;
    }
    else if(player->Velocity.x > 0)
    {
        player->Velocity.x -= player->Friction * delta;
    }


    player->Position.x += player->Velocity.x * delta;
    player->Position.y += player->Velocity.y * delta;

    player->Bounds.x = player->Position.x;
    player->Bounds.y = player->Position.y;
}