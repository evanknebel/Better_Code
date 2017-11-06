#pragma once


#include "shapes.h"

void drawCircle(const circle &C);
void drawAABB(const AABB &box, int color);

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