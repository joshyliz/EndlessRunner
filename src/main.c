#include <stdio.h>
#include "raylib.h"

//My Headers
#include "Global.h"
#include "Player.h"

int main(void)
{
    InitWindow(WINDOW_WIDTH, WINDOOW_HEIGHT, "Runner");

    //Game
    Player player = {10, 10};
    player.Bounds.height = 50;
    player.Bounds.width = 50;

    while (!WindowShouldClose())
    {
        //Update
        PlayerUpdate(&player);

        //Draw        
        BeginDrawing();
        ClearBackground(WHITE);
        
        DrawRectangleRec(player.Bounds, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}