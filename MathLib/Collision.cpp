#include "Collision.h"

Collision intersect_1D(float Amin, float Amax, float Bmin, float Bmax)
{
	Collision ret;

	float lPD = Bmax - Amin;
	float rPD = Amax - Bmin;
	
	ret.penetrationDepth = min(lPD, rPD);
	ret.handedness = copysign(1, rPD - lPD);

	return ret;
}

Collision intersect_AABB(const AABB & A, const AABB & B)
{
	Collision xres = intersect_1D(A.min().x, A.max().x, B.min().x, B.max().x);
	Collision yres = intersect_1D(A.min().y, A.max().y, B.min().y, B.max().y);

	xres.axis = vec2{ 1,0 };
	yres.axis = vec2{ 0,1 };

	return xres.penetrationDepth < yres.penetrationDepth ? xres : yres;
}


Collision intersect_circle(const circle & A, const circle & B)
{
	Collision ret;
	ret.axis       = norm(B.position - A.position);
	ret.handedness = -1;

	float Ap = dot(ret.axis, A.position);
	float Bp = dot(ret.axis, B.position);

	float Amin = Ap - A.radius;
	float Amax = Ap + A.radius;

	float Bmin = Bp - B.radius;
	float Bmax = Bp + B.radius;

	// how do we calculate penetration depth?
	ret.penetrationDepth = intersect_1D(Amin, Amax, Bmin, Bmax).penetrationDepth;

	return ret;
}

Collision intersect_AABB_circle(const AABB &A, const circle &B)
{
	// HINT:
		// First find the axis (closest point on AABB to circle)
		// then project the points of each onto the axis.
		// Find min and max of those points for each.
		// perform 1D intersection.

	return Collision();
}



void static_resolution(vec2 & pos, vec2 & vel, const Collision & hit, float elasticity)
{
	// for position, we need to correct:
	pos += hit.axis * hit.handedness * hit.penetrationDepth;

	// for velocity, we need to reflect:
	vel = -reflect(vel, hit.axis*hit.handedness) * elasticity;
}