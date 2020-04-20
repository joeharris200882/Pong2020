#pragma once
#include "Graphics.h"

class Score
{
public:

    void Draw(Graphics& gfx);

    int scorex = 10;
    int scorey = 10;
    int scoreWidth = 20;
    int scoreHeight = 15;
    int scoreTrack = 1;
    int scoreMax = 50;
};
