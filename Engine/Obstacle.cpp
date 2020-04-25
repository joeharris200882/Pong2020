#include "Obstacle.h"

Obstacles::Obstacles(Vec2 in_pos, int in_dim, Color in_c)
{
	pos = in_pos;
	dim = in_dim;
	c = in_c;
}

void Obstacles::Draw(Graphics& gfx)
{
	gfx.DrawRectDim(pos.x, pos.y, dim, dim, c);
}

void Obstacles::ClampScreenX()
{
  
        if (pos.x < 0)
        {
            pos.x = 1;
        }

        if (pos.x + dim > Graphics::ScreenWidth)
        {
            pos.x = (Graphics::ScreenWidth - dim) - 1;
        }
}

void Obstacles::ClampScreenY()
{
    if (pos.y < 0)
    {
        pos.y = 1;
    }

    if (pos.y + dim > Graphics::ScreenHeight)
    {
        pos.y = (Graphics::ScreenHeight - dim) - 1;
    }
}
