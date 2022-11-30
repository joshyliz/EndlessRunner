#pragma once
#include "raylib.h"

typedef struct 
{
    Rectangle ground[3];

} Level;

void SetLevel(Level *level);
