#include "raylib.h"
#include <stdio.h>
#include <stdbool.h>

//My Headers
#include "Global.h"
#include "Player.h"
#include "Level.h"


int main(void)
{
    InitWindow(WINDOW_WIDTH, WINDOOW_HEIGHT, "Runner");
    SetTargetFPS(60);

    //Game
    Player player = {10, 10};
    player.Velocity.x = 0;
    player.Velocity.y = 0;
    player.Bounds.height = 50;
    player.Bounds.width = 50;
    player.Friction = 0.1f;
    player.Gravity = 10.0f;
    player.isGrounded = false;

    Level level; 
    SetLevel(&level);

    while (!WindowShouldClose())
    {
        //Update

        PlayerUpdate(&player, &level);

        //Draw        
        BeginDrawing();
        ClearBackground(WHITE);
        
        DrawRectangleRec(player.Bounds, GRAY);
        DrawRectangleRec(level.ground[0], BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}