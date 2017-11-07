#pragma once


#include "../collision/shapes.h"
#include "transform.h"
#include "../collision/collision.h"

class Collider
{
public:
	AABB box;

	AABB getGlobalBox(const Transform &t) const
	{
		return t.getGlobalTransform() * box;
	}

	Collider(const AABB &a_box = { {0,0},{.5,.5} }) : box(a_box)
	{

	}

	void Collider::debugDraw(const Transform & At, int color, const mat3 & cam = mat3::identity());
};


Collision collides(const Transform &At, const Collider &Ac,
				   const Transform &Bt, const Collider &Bc);


