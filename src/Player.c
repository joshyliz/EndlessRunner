#include "raylib.h"
#include "Global.h"
#include "Player.h"
#include "Level.h"
#include <stdio.h>
#include <stdbool.h>

void PlayerUpdate(Player *player, Level *level)
{
    float delta = GetFrameTime();

    player->Position.x += player->Velocity.x;
    player->Position.y += player->Velocity.y;

    player->Bounds.x = player->Position.x;
    player->Bounds.y = player->Position.y;
     
    player->Velocity.x += 5 * delta;

    if(IsKeyDown(KEY_A))
        player->Velocity.x -= 7.5f * delta;

    if(player->Velocity.x < (float)PLAYER_MININUM_SPEED)
        player->Velocity.x = (float)PLAYER_MININUM_SPEED;

    /* Not needed friction code 
    else if(player->Velocity.x != 0)
        player->Velocity.x -= (player->Velocity.x -= player->Friction
        * player->Velocity.x) * delta;
    */

    if(player->Velocity.x > (float)PLAYER_SPEED_CAP)
        player->Velocity.x = (float)PLAYER_SPEED_CAP; 
    else if(player->Velocity.x < -(float)PLAYER_SPEED_CAP)
        player->Velocity.x = -(float)PLAYER_SPEED_CAP;

    for (size_t i = 0; i < SIZE_OF_GROUND; i++)
    { 
        if(TopCollision(player->Bounds, player->Velocity, level->ground[i]))
        {
            player->isGrounded = true;
            player->Velocity.y = 0;
        }    
    }    

    if(player->isGrounded == true && IsKeyDown(KEY_SPACE))
    {
        player->Velocity.y -= (float)(PLAYER_JUMP_HEIGHT) * delta;
        player->isGrounded = false;
    }    

    if(player->isGrounded == false)
        player->Velocity.y += (player->Gravity) * delta;
    
    player->isGrounded = false;
}
