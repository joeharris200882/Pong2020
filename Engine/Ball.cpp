#include "Ball.h"

void Ball::Draw(Graphics& gfx)
{
	gfx.DrawRectDim(x, y, width, height, Colors::Red);
}

void Ball::ClampToScreen()
{
    const int ballright = x + width;
    if (x < 0)
    {
        x = 0;
        vx = -vx;
    }
    else if (ballright >= Graphics::ScreenWidth)
    {
        x = (Graphics::ScreenWidth - 1) - width;
        vx = - vx;
    }

    const int ballbottom = y + height;
    if (y < 0)
    {
        y = 0;
        vy = -vy;
    }
    else if (ballbottom >= Graphics::ScreenHeight)
    {
        y = (Graphics::ScreenHeight - 1) - height;
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

