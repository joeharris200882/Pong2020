#pragma once
#include "Graphics.h"

class Score
{
public:

    void DrawP1(Graphics& gfx);
    void DrawP2(Graphics& gfx);


    int scoreP1BarBegin = 10;
    int scoreP1Bary = 10;
    int scoreP1BarEnd = 5;
    int scoreP1BarHeight = scoreP1Bary+10;
    int scoreP1Max = 50;
    int scoreP1Track = 1;
    

    int scoreP2BarBegin = 550;
    int scoreP2Bary = 10;
    int scoreP2BarEnd = 5;
    int scoreP2BarHeight = scoreP2Bary + 10;
    int scoreP2Max = 50;
    int scoreP2Track = 1;
};
