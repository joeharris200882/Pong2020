#pragma once
#include "Vec2.h"
#include "Graphics.h"


class Obstacles
{
public:

	Obstacles( Vec2 in_pos, int in_dim, Color in_c );
	void Draw(Graphics& gfx);
	void ClampScreenX();
	void ClampScreenY();

	Vec2 pos;
	Color c;
	int dim;
	Vec2 vel;
};