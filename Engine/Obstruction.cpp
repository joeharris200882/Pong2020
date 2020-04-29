#include "Obstruction.h"

Obstruction::Obstruction(Vec2 in_pos, int in_dim, Color in_c)
{
	in_pos = pos;
	in_dim = dim;
	in_c = c;

}

void Obstruction::Draw(Graphics& gfx)
{
	gfx.DrawRectDim(pos.x, pos.y, dim, dim, c);
}
