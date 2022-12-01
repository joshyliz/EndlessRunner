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
    Camera2D camera;
    camera.offset.x = -190;
    camera.offset.y = 0;
    camera.target.y = -75;

    camera.zoom = 1;
    camera.rotation = 0;

    Player player = {10, 10};

    player.Velocity.y = 0;
    player.Bounds.height = 50;

    player.Bounds.width = 50;
    player.Friction = 0.1f;
    player.Gravity = 10.0f;
    player.isGrounded = false;

    
    Level level; 
    SetLevel(&level); 

    typedef enum {One, Two, Three, NOVALUE} CurrentGround;

    CurrentGround currentGround = NOVALUE;

    
    while (!WindowShouldClose())
    {
        //Update

        for (short i = 0; i < SIZE_OF_GROUND; i++)
        {
            if(TopCollision(player.Bounds, player.Velocity, level.ground[i]))
            {
                switch(i)
                {
                    case 0:
                    if(currentGround != One)
                        RepeatGround(level.ground[0], &level.ground[1]);
                    currentGround = One;
                    break;

                    case 1:
                    if(currentGround != Two)
                        RepeatGround(level.ground[1], &level.ground[2]);
                    currentGround = Two;
                    break;

                    case 2:
                    if(currentGround != Three)
                        RepeatGround(level.ground[2], &level.ground[0]);
                    currentGround = Three;
                    break;
                }

            }
        }
        

        PlayerUpdate(&player, &level);
        camera.target.x = player.Position.x - WINDOW_WIDTH / 2 
        + player.Bounds.width / 2;

        //Draw        
        BeginDrawing();
        ClearBackground(WHITE);


        BeginMode2D(camera);
        
        DrawRectangleRec(player.Bounds, GRAY);
        DrawLevel(&level);
        
        EndMode2D();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}