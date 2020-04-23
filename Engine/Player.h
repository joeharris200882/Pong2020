#pragma once
#include "Graphics.h"

class Player
{
public:
    Player(int in_x, int in_y, Color in_c,
        int in_meterx, int in_metery,  Color in_meterc)
    {
        x = in_x, y = in_y, c = in_c,
        meterx = in_meterx, metery = in_metery, meterc = in_meterc;
    }
    //void InitPlayer(int in_x, int in_y, int in_width, int in_height,Color in_c);
    //void InitMeter(int in_meterx, int in_metery, int in_meterWidth, int in_meterHeight, Color in_c);
    
    void Draw(Graphics& gfx);
    void ClampScreenX();
    void DrawBar(Graphics& gfx);

    

    int x;
    int y;
    int width = 5;
    int height = 100;
    
    Color c;

    //FIGURE THIS OUT !!!
    int meterx;
    int metery;
    int meterWidth = 10;
    int meterHeight = metery + 15;
    Color meterc;
    const int scoreMax = 40;
    


};