#include "Collider.h"
#include "../draw/draw.h"

Collision collides(const Transform & At, const Collider & Ac,
				   const Transform & Bt, const Collider & Bc)
{	
	return intersect_AABB(Ac.getGlobalBox(At), Bc.getGlobalBox(Bt));
}

void Collider::debugDraw(const Transform & At, int color, const mat3 & cam)
{
	drawAABB(cam * getGlobalBox(At), color);
}
