#include <stdio.h>
#include "raylib.h"

//My Headers
#include "Global.h"
#include "Player.h"
#include "Level.h"

int main(void)
{
    InitWindow(WINDOW_WIDTH, WINDOOW_HEIGHT, "Runner");

    //Game
    Player player = {10, 10};
    player.Bounds.height = 50;
    player.Bounds.width = 50;
    player.Friction = 15.0f;

    Level level; 
    SetLevel(&level);


    while (!WindowShouldClose())
    {
        //Update



        PlayerUpdate(&player);

        //Draw        
        BeginDrawing();
        ClearBackground(WHITE);
        
        DrawRectangleRec(player.Bounds, BLACK);
        DrawRectangleRec(level.ground[0], BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}