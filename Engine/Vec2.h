#pragma once

class Vec2
{
public:

	int x;
	int y;

	void Add(Vec2& val)
	{
		x += val.x;
		y += val.y;

	}

};