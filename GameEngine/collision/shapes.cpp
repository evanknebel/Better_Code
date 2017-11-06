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


// AABB Transformation
/*




	cmath
*/
AABB operator*(const mat3 &M, const AABB &B)
{
	// OOOOoooo, MYSTERY
	AABB retval;

	vec2 TR = B.position + B.extents;
	vec2 BL = B.position - B.extents;
	vec2 TL = { BL.x, TR.y };
	vec2 BR = { TR.x, BL.y };

	TR = (M * vec3{ TR.x, TR.y, 1 }).xy;
	BL = (M * vec3{ BL.x, BL.y, 1 }).xy;
	TL = (M * vec3{ TL.x, TL.y, 1 }).xy;
	BR = (M * vec3{ BR.x, BR.y,1 }).xy;

	

	vec2 MinCorner = min(TR, min(BL, min(TL, BR)));
	vec2 MaxCorner = max(TR, max(BL, max(TL, BR)));

	retval.position = (MaxCorner + MinCorner) / 2;
	retval.extents  = (MaxCorner - MinCorner) / 2;

	

	return retval;
	// try and independently research a solution
}


ray operator*(const mat3 &M, const ray &R)
{
	ray res;
	res.position = mulPos(M, R.position);
	res.direction = mulDir(M, R.direction);
	res.length = R.length; // TODO: transform the scale

	return res;
}