#pragma once
#include "Graphics.h"
#include "Vec2.h"

class Ball
{
public:

    void Draw(Graphics& gfx);
    void ClampToScreen();
    bool CollisionDetect(int paddle_x, int paddle_y, int paddle_width, int paddle_height);


    Vec2 pos = { Graphics::ScreenWidth / 2, Graphics::ScreenHeight / 2 };
    const int height = 5;
    const int width = 5;
    int vx = 5;
    int vy = 5;
    
    int goalLineP1 = 5;
    int goalLineP2 = Graphics::ScreenWidth - 5;
    int sideLine1 = 5;
    int sideLine2 = Graphics::ScreenHeight - 5;
    int borderWidth = 3;
    
};