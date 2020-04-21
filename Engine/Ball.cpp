#include "Ball.h"

void Ball::Draw(Graphics& gfx)
{
	gfx.DrawRectDim(x, y, width, height, Colors::Red);
}
