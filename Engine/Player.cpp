#include "Player.h"



void Player::Draw(Graphics& gfx)
{
	gfx.DrawRectDim(x, y, width, height, c);
}

void Player::DrawBar(Graphics& gfx)
{

    gfx.DrawRectDim(meterx, metery, meterWidth, meterHeight, meterc);
}

void Player::ClampScreenX()
{
    if (y < 0)
    {
        y = 1;
    }

    if (y + height > Graphics::ScreenHeight)
    {
        y = (Graphics::ScreenHeight - height) - 1;
    }
}
