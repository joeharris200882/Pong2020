#pragma once
#include "Graphics.h"

class Ball
{
public:

    void Draw(Graphics& gfx);

    int x = Graphics::ScreenWidth / 2;
    int y = Graphics::ScreenHeight / 2;
    const int height = 5;
    const int width = 5;
    int vx = 5;
    int vy = 5;
};