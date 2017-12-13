#include "jumper.h"
#include "collectable.h"
#include <iostream>


bool doCollision(Jumper &jumper, const Wall & wall)
{
	Collision hit = collides(jumper.transform, jumper.collider, wall.transform, wall.collider);

	if (hit.penetrationDepth >= 0)
	{
		static_resolution(jumper.transform.position, jumper.rigidbody.velocity, hit, 0.01f);
		//jumper.controller.isGrounded = true;



		if (sfw::getKey(265) )
		{
			jumper.rigidbody.impulse += vec2{ 0, MAX_JUMP_SPEED };

			//jumper.controller.doAction = true;
			//jumper.isGrounded = false;
		}
		/*if (jumper.controller.doAction == true && !sfw::getKey(265))
		{
			jumper.controller.doAction = false;
		}*/
		else if (sfw::getKey(264))
		{
			jumper.rigidbody.impulse += vec2{ 0, SMALL_JUMP_SPEED };

			//jumper.controller.doAction = true;
			//jumper.isGrounded = false;
		}
		return true;
	}
	else 
	{
		
		//jumper.controller.isGrounded = false;
		//std::cout << "NotGrouned" << std::endl;
		return false;
	}

	
}

bool doCollision(Jumper &jumper, Collectable & collectable)
{
	Collision hit = collides(jumper.transform, jumper.collider, collectable.transform, collectable.collider);

	if (hit.penetrationDepth > 0)
	{
		
		collectable.isCollected = true;
		return true;
	}
	else
	{
		return false;
	}
}

