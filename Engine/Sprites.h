#pragma once
#include "Graphics.h"


class Sprites
{
public:


	void GameOver(Graphics& gfx);
	
	int x = Graphics::ScreenWidth /3;
	int y = Graphics::ScreenHeight /2;
	int vx = 2;
	int vy = 2;
};