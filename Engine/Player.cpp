#include "Player.h"



void Player::Draw(Graphics& gfx)
{
	gfx.DrawRectDim(x, y, width, height, c);
}

void Player::DrawBar(Graphics& gfx)
{
    //check if the boundary grows when the scoremax is adjusted, otherwise you need to get rid of some magic numbers also width needs to grow
    gfx.DrawRectDim(meterx - meterOutlinePad, metery - meterOutlinePad, scoreMax + meterOutlinePad, meterOutlineThk, Colors::White);
    gfx.DrawRectDim(meterx - meterOutlinePad, metery -meterOutlinePad, meterOutlinePad, meterHeight+8, Colors::White);
    gfx.DrawRectDim(meterx -meterOutlinePad, (metery +meterHeight) +meterOutlinePad, scoreMax + meterOutlinePad, meterOutlineThk, Colors::White);
    gfx.DrawRectDim((meterx + scoreMax), metery -meterOutlinePad, meterOutlinePad, meterHeight+ 8, Colors::White);
   
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
