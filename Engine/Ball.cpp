#include "Ball.h"

void Ball::Draw(Graphics& gfx)
{
	gfx.DrawRectDim(pos.x, pos.y, width, height, Colors::Red);
}

void Ball::ClampToScreen()
{
    const int ballright = pos.x + width;
    if (pos.x < goalLineP1+borderWidth)
    {
        pos.x = goalLineP1+borderWidth;
        vx = -vx;
    }
    else if (ballright >= goalLineP2-borderWidth)
    {
        pos.x = (goalLineP2-borderWidth) - width;
        vx = - vx;
    }

    const int ballbottom = pos.y + height;
    if (pos.y < sideLine1+borderWidth)
    {
        pos.y = sideLine1+borderWidth;
        vy = -vy;
    }
    else if (ballbottom >= sideLine2-borderWidth)
    {
        pos.y = (sideLine2-borderWidth) - height;
        vy = -vy;
    }
}

bool Ball::CollisionDetect(int obj_x, int obj_y, int obj_width, int obj_height)
{
     const int bottom = pos.y + height;
     const int right = pos.x + width;
     const int objRight = obj_x + obj_width;
     const int objBottom = obj_y + obj_height;
    


    return (pos.x < objRight &&
        right > obj_x &&
        pos.y < objBottom &&
        bottom > obj_y);

   
}

