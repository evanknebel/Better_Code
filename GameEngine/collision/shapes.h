#pragma once

#include "../linmaths/mat3.h"

struct circle
{
	vec2 position;
	float radius;
};


// axis aligned bounding box
// is a rectangle w/out rotation
struct AABB
{
	vec2 position;
	vec2 extents;
	// position width and height
	// min max

	vec2 min() const { return position - extents; }
	vec2 max() const { return position + extents; }
};


struct ray
{
	vec2 position;
	vec2 direction;
	float length;
};

ray operator*(const mat3 &M, const ray &R);

circle operator*(const mat3 &M, const circle &C);

AABB operator*(const mat3 &M, const AABB &B);


