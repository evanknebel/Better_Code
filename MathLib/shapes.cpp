#include "shapes.h"
#include <cmath>

// transform:
//	position, rotation, scale

/*
[sx   0   0]
[0   sy   0]
[0    0   1]
*/
circle operator*(const mat3 & M, const circle & C)
{
	circle ret = C;

	ret.position = (M * vec3{ C.position.x, C.position.y, 1.f }).xy;

	vec2 scale;
	scale.x = mag(M[0].xy);
	scale.y = mag(M[1].xy);
	// Average? 

	 ret.radius *= fmaxf(scale.x, scale.y);

	 return ret;
}


AABB operator*(const mat3 &M, const AABB &B)
{
	// OOOOoooo, MYSTERY
	return AABB();
	// try and independently research a solution
}