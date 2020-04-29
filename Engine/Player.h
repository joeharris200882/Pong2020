#pragma once
#include "Graphics.h"
#include "Vec2.h"

class Player
{
public:

  
    Player(int in_x, int in_y, Color in_c,
        int in_meterx, int in_metery, Color in_meterc)
    {
        pos.x = in_x, pos.y = in_y, c = in_c,
            meterx = in_meterx, metery = in_metery, meterc = in_meterc;
    }

    
    
    void Draw(Graphics& gfx);
    void ClampScreenX();
    void DrawBar(Graphics& gfx);

    
    Vec2 pos;
    //int x;
    //int y;
    int width = 5;
    int height = 100;

    
    Color c;

    
    int meterx;
    int metery;
    int meterWidth = 10;
    int meterHeight = 15;
    Color meterc;
    const int scoreMax = 100;
    int meterBorderWidth = 2;
    int meterPad = 3;
    


};