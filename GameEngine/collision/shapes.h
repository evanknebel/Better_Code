#pragma once

#include "../linmaths/mat3.h"
#include <cmath>

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

	float min(const vec2 &axis) const
	{
		vec2 p[4] =  { min(),   max(),
					 { min().x, max().y },
					 { max().x, min().y } };
		float d[4];
		for (int i = 0; i < 4; ++i)
			d[i] = dot(p[i], axis);

		return fminf( fminf(d[0], d[2]), fminf(d[1], d[3]));
	}

	float max(const vec2 &axis) const
	{
		vec2 p[4] = { min(),max(),
					{ min().x,max().y },
					{ max().x,min().y } };
		float d[4];
		for (int i = 0; i < 4; ++i)
			d[i] = dot(p[i], axis);

		return fmaxf(fmaxf(d[0], d[2]), fmaxf(d[1], d[3]));
	}

	static AABB fromExtents(const vec2 &m, const vec2 &x)
	{
		return {(x+m)/2, (x-m)/2};
	}
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


