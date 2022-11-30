#pragma once
#include "raylib.h"

#define WINDOW_WIDTH 800
#define WINDOOW_HEIGHT 450

Vector2 VectorZero();

bool TopCollision(Rectangle rec1, Vector2 velocity1, Rectangle rec2);
bool BottomCollision(Rectangle rec1, Vector2 velocity1, Rectangle rec2);
bool LeftCollision(Rectangle rec1, Vector2 velocity1, Rectangle rec2);
bool RightCollsion(Rectangle rec1, Vector2 velocity1, Rectangle rec2);