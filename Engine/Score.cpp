#include "Score.h"

void Score::Draw(Graphics& gfx )
{
    gfx.DrawRectDim(scorex, scorey, scoreWidth, scoreHeight, Colors::Blue);
    
}
