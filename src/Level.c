#include "raylib.h"
#include "Global.h"
#include "Level.h"


void SetLevel(Level *level)
{
    for (int i = 0; i < 3; i++)
    {
        level->ground[i].height = 200;
        level->ground[i].width = 650;
        level->ground[i].x = 0;
        level->ground[i].y = GetScreenHeight() - level->ground[i].height;
    }
    
}
