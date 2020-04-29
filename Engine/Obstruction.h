#pragma once
#include "Vec2.h"
#include "Graphics.h"


class Obstruction
{
public:

	Obstruction(Vec2 in_pos, int in_dim, Color in_c);
	void Draw(Graphics& gfx);

	Vec2 pos;
	int dim;
	Color c;

};