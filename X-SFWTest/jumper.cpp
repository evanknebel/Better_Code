#include "jumper.h"
#include "collectable.h"
bool doCollision(Jumper &jumper, const Wall & wall)
{
	Collision hit = collides(jumper.transform, jumper.collider, wall.transform, wall.collider);

	if (hit.penetrationDepth > 0)
	{
		static_resolution(jumper.transform.position, jumper.rigidbody.velocity, hit, 0.75f);
		jumper.controller.isGrounded = true;
		return true;
	}
	else
	{
		//jumper.controller.isGrounded = false;
		return false;
	}
}

bool doCollision(Jumper &jumper, Collectable & collectable)
{
	Collision hit = collides(jumper.transform, jumper.collider, collectable.transform, collectable.collider);

	if (hit.penetrationDepth > 0)
	{
	//	static_resolution(jumper.transform.position, jumper.rigidbody.velocity, hit, 0.75f);
		//score++
		collectable.isCollected = true;
		return true;
	}
	else
	{
		return false;
	}
}