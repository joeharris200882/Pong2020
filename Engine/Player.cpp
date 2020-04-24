#include "Player.h"



void Player::Draw(Graphics& gfx)
{
	gfx.DrawRectDim(x, y, width, height, c);
}

void Player::DrawBar(Graphics& gfx)
{
    
    gfx.DrawRectDim(meterx - meterPad, metery - meterPad, scoreMax + meterPad, meterBorderWidth, Colors::White);
    gfx.DrawRectDim(meterx - meterPad, metery - meterPad, meterPad, meterHeight + 8, Colors::White);
    gfx.DrawRectDim(meterx - meterPad, (metery + meterHeight) + meterPad, scoreMax + meterPad, meterBorderWidth, Colors::White);
    gfx.DrawRectDim((meterx + scoreMax), metery - meterPad, meterPad, meterHeight + 8, Colors::White);

    gfx.DrawRectDim(meterx, metery, meterWidth, meterHeight, c);
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
