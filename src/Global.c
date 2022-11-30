#include "raylib.h"
#include "Global.h"
#include "Player.h"

Vector2 VectorZero()
{
    Vector2 a = {0, 0};

    return a; 
}    

/* Collsion Variables

    float Top1 = rec1.y;
    float Bottom1 = rec1.y + rec1.height; 
    float Left1 = rec1.x; 
    float Right1 = rec1.x + rec1.width;

    float Top2 = rec2.y;
    float Bottom2 = rec2.y + rec2.height; 
    float Left2 = rec2.x; 
    float Right2 = rec2.x + rec2.width;

*/



//Side Collsion Checks

bool TopCollision(Rectangle rec1, Vector2 velocity1, Rectangle rec2)
{
    float Top1 = rec1.y;
    float Bottom1 = rec1.y + rec1.height;
    float Left1 = rec1.x;
    float Right1 = rec1.x + rec1.width;

    float Top2 = rec2.y;
    float Left2 = rec2.x;
    float Right2 = rec2.x + rec2.width;


    if (Bottom1 + velocity1.y > Top2 && Right1 > Left2 && Left1 < Right2
        && Top1 <= Top2)
        return true;
    else return false;
}

bool BottomCollision(Rectangle rec1, Vector2 velocity1, Rectangle rec2)
{
    float Top1 = rec1.y;
    float Bottom1 = rec1.y + rec1.height;
    float Left1 = rec1.x;
    float Right1 = rec1.x + rec1.width; 

    float Bottom2 = rec2.y + rec2.height;
    float Left2 = rec2.x;
    float Right2 = rec2.x + rec2.width; 
       
    if (Top1 + velocity1.y < Bottom2 && Bottom1 > Bottom2
        && Right1 > Left2 && Left1 < Right2)
        return true;
    else return false;
}

bool LeftCollision(Rectangle rec1, Vector2 velocity1, Rectangle rec2)
{
    float Top1 = rec1.y;
    float Bottom1 = rec1.y + rec1.height;
    float Left1 = rec1.x;
    float Right1 = rec1.x + rec1.width;

    float Top2 = rec2.y;
    float Bottom2 = rec2.y + rec2.height;
    float Left2 = rec2.x;


    if (Right1 + velocity1.x > Left2 && Left1 < Left2
        && Bottom1 > Top2 && Top1 < Bottom2)
        return true;
    else return false;
}

bool RightCollsion(Rectangle rec1, Vector2 velocity1, Rectangle rec2)
{
    float Top1 = rec1.y;
    float Bottom1 = rec1.y + rec1.height; 
    float Left1 = rec1.x; 
    float Right1 = rec1.x + rec1.width;

    float Top2 = rec2.y;
    float Bottom2 = rec2.y + rec2.height; 
    float Right2 = rec2.x + rec2.width;

    if (Left1 + velocity1.x < Right2 && Right1 > Right2
        && Bottom1 > Top2 && Top1 < Bottom2)
        return true;
    else return false;
}

