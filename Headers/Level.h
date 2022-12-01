#pragma once
#include "raylib.h"

#define SIZE_OF_GROUND 3

typedef struct 
{
    Rectangle ground[3];

} Level;

void SetLevel(Level *level);

void DrawLevel(Level *level);