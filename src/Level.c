#include "raylib.h"
#include "Global.h"
#include "Level.h"
#include "Player.h"


void SetLevel(Level *level)
{
    for (int i = 0; i < SIZE_OF_GROUND; i++)
    {
        level->ground[i].height = 900;
        level->ground[i].width = 650;
        //level->ground[i].y = GetScreenHeight() - level->ground[i].height;
        level->ground[i].y = GetScreenHeight() / 2;
    }

    level->ground[0].x = 0;
    level->ground[1].x = -2000;
    level->ground[2].x = -1000;
}

void DrawLevel(Level *level)
{
    for (short i = 0; i < SIZE_OF_GROUND; i++)
    {
        DrawRectangleRec(level->ground[i], BLACK);
    }
    
}
