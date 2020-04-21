#include "Score.h"

void Score::DrawP1(Graphics& gfx )
{
    gfx.DrawRectDim(scoreP1BarBegin, scoreP1Bary, scoreP1BarEnd, scoreP1BarHeight, Colors::Blue);
    
}

void Score::DrawP2(Graphics& gfx)
{
    gfx.DrawRectDim(scoreP2BarBegin, scoreP2Bary, scoreP2BarEnd, scoreP2BarHeight, Colors::Green);
}
