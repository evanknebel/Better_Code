#include "draw.h"
#include "../sfwdraw.h"

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

void DrawMatrix(const mat3 & t, float drawing_scale)
{
	vec2 pos = t[2].xy;
	vec2 right_ep = pos + t[0].xy * drawing_scale;
	vec2 up_ep = pos + t[1].xy * drawing_scale;

	sfw::drawLine(pos.x, pos.y, right_ep.x, right_ep.y, RED);
	sfw::drawLine(pos.x, pos.y, up_ep.x, up_ep.y, GREEN);

	sfw::drawCircle(pos.x, pos.y, drawing_scale / 4);

}


void DrawTexture(unsigned sprite, const mat3 &t)
{
	sfw::drawTextureMatrix3(sprite, 0, WHITE, t.m);
}

void drawRay(const ray &r, int color)
{
 	DrawVecLine(r.position, r.position + r.direction*r.length, color);

}