#include "sfwdraw.h"
#include "transform.h"
#include "Player.h"
#include "MyGuy.h"
#include "mat3.h"
#include "Rigidbody.h"

#include <cmath>
#include <string>
#include <cstring>
#include <cassert>


int main()
{
	sfw::initContext();

	Transform transform;
	Rigidbody rigidbody;

	transform.position = vec2{ 400, 300 };

	bool jumped = false;
	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();
		
		//rigidbody.force += { 0, -25 }; // gravity

		// moving jets
		if (sfw::getKey('W'))rigidbody.force +=
						transform.getGlobalTransform()[1].xy * 100;
		if (sfw::getKey('A'))rigidbody.torque +=  360;
		if (sfw::getKey('D'))rigidbody.torque += -360;

		if(sfw::getKey('Q')) rigidbody.impulse +=
			-transform.getGlobalTransform()[1].xy * 10;

		if (sfw::getKey(' ')) //breaking force
		{
			rigidbody.force += -rigidbody.velocity * 20;
			rigidbody.torque += -rigidbody.angularVelocity * 20;
		}

		rigidbody.integrate(transform, dt);
		DrawMatrix(transform.getGlobalTransform(), 48);
	}
	sfw::termContext();
}







