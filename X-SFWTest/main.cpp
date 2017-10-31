#include "sfwdraw.h"
#include "transform.h"
#include "Player.h"
#include "MyGuy.h"
#include "mat3.h"
#include "Rigidbody.h"
#include "shapes.h"
#include "DrawShape.h"
#include "Collision.h"

#include <cmath>
#include <string>
#include <cstring>
#include <cassert>
#include "Collider.h"


int main()
{
	sfw::initContext();

	Transform transform;
	Rigidbody rigidbody;

	circle circ = { {0,0}, 1 };
	AABB box = { {0,0}, {1,1} };
	transform.position = vec2{ 600, 300 };
	transform.dimension = vec2{ 30,30 };

	AABB box2 = { {400, 300}, {160,160} }; // new box!
	circle circ2 = {{ 400,300 }, 50};

	bool jumped = false;
	while (sfw::stepContext())
	{
		// Check collision with our box
		Collision result = intersect_circle(
		transform.getGlobalTransform() * circ, circ2);

		// change color based on penetration
		unsigned color = result.penetrationDepth < 0 ? WHITE : RED;
		// if we overlap, then apply the "minimum translation vector" to the transform
		if(result.penetrationDepth >= 0)
		{
			// prevents overlap
		transform.position += result.axis * result.handedness * result.penetrationDepth;
		
		}

		drawCircle(circ2);
		//drawAABB(box2,color);
		//drawAABB(transform.getGlobalTransform() * box, MAGENTA);

		drawCircle(transform.getGlobalTransform() * circ);
		DrawMatrix(transform.getGlobalTransform(), 1);

		float dt = sfw::getDeltaTime();
		
		//rigidbody.force += { 0, -25 }; // gravity

		// moving jets

		rigidbody.integrate(transform, dt);

	}
	sfw::termContext();
}







