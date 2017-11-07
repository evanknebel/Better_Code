#pragma once


#include "../collision/shapes.h"

void drawCircle(const circle &C);
void drawAABB(const AABB &box, int color);

void DrawVecLine(const vec2 &a, const vec2 &b, int color);

void DrawTexture(unsigned sprite, const mat3 &t);

void drawRay(const ray &a, int color);