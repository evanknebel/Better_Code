#include "jumper.h"

bool doCollision(Jumper &jumper, const Wall & wall)
{
	Collision hit = collides(jumper.transform, jumper.collider, wall.transform, wall.collider);

	if (hit.penetrationDepth > 0)
	{
		static_resolution(jumper.transform.position, jumper.rigidbody.velocity, hit);
		return true;
	}
	else
	{
		return false;
	}
}