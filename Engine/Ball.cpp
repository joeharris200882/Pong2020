#include "Ball.h"

void Ball::Draw(Graphics& gfx)
{
	gfx.DrawRectDim(x, y, width, height, Colors::Red);
}

void Ball::ClampToScreen()
{
    const int ballright = x + width;
    if (x < goalLineP1+borderWidth)
    {
        x = goalLineP1+borderWidth;
        vx = -vx;
    }
    else if (ballright >= goalLineP2-borderWidth)
    {
        x = (goalLineP2-borderWidth) - width;
        vx = - vx;
    }

    const int ballbottom = y + height;
    if (y < sideLine1+borderWidth)
    {
        y = sideLine1+borderWidth;
        vy = -vy;
    }
    else if (ballbottom >= sideLine2-borderWidth)
    {
        y = (sideLine2-borderWidth) - height;
        vy = -vy;
    }
}

bool Ball::CollisionDetect(int obj_x, int obj_y, int obj_width, int obj_height)
{
     const int bottom = y + height;
     const int right = x + width;
     const int objRight = obj_x + obj_width;
     const int objBottom = obj_y + obj_height;
    


    return (x < objRight &&
        right > obj_x &&
        y < objBottom &&
        bottom > obj_y);

   
}

