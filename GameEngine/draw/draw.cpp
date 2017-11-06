#include "DrawShape.h"
#include "sfwdraw.h"

void drawCircle(const circle &C)
{
	sfw::drawCircle(C.position.x, C.position.y, C.radius);
}


void DrawVecLine(const vec2 &a, const vec2 &b, int color)
{
	sfw::drawLine(a.x, a.y, b.x, b.y, color);
}

void drawAABB(const AABB & box, int color)
{
	vec2 TR = box.position + box.extents;
	vec2 BL = box.position - box.extents;
	vec2 TL = { box.position.x - box.extents.x, box.position.y + box.extents.y };
	vec2 BR = { TR.x, BL.y };

	DrawVecLine(TR, TL, color);
	DrawVecLine(TL, BL, color);
	DrawVecLine(BL, BR, color);
	DrawVecLine(BR, TR, color);


}
