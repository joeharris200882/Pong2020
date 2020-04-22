#include "Player.h"

void Player::InitPlayer(int in_x, int in_y, int in_width, int in_height, Color in_c)
{  
   
  
        x = in_x;
        y = in_y;
        width = in_width;
        height = in_height;
        c = in_c;
        
    
}

void Player::InitMeter(int in_meterx, int in_metery, int in_meterWidth, int in_meterHeight, Color in_c)
{
    in_meterx = meterx;
    in_metery = metery;
    in_meterWidth = meterWidth;
    in_meterHeight = meterHeight;
    in_c = meterc;
}

void Player::Draw(Graphics& gfx)
{
	gfx.DrawRectDim(x, y, width, height, c);
}

void Player::DrawBar(Graphics& gfx)
{

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
