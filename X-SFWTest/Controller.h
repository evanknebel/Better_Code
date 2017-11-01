#pragma once

// controller -> rigidbody -> transform
#include "transform.h"
#include "Rigidbody.h"
#include "sfwdraw.h"

// Poll for input and apply changes to the rigidbody
class Controller
{

public:
	float turningSpeed;
	float speed;
	float brakePower;

	Controller() : turningSpeed(240), speed(120), brakePower(8)
	{

	}

	void poll(Rigidbody &rb, const Transform &t)
	{

		if (sfw::getKey('W'))rb.force +=
			norm(t.getGlobalTransform()[1].xy) * speed;
		
		if (sfw::getKey('A'))rb.torque += turningSpeed;
		if (sfw::getKey('D'))rb.torque += -turningSpeed;

		if (sfw::getKey(' ')) //breaking force
		{
			rb.force += -rb.velocity * brakePower;
			rb.torque += -rb.angularVelocity * brakePower;
		}
	}
};