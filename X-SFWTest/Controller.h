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

		if (sfw::getKey(265))rb.force +=
			norm(t.getGlobalTransform()[1].xy) * speed;
		
		if (sfw::getKey(263))rb.torque += turningSpeed;
		if (sfw::getKey(262))rb.torque += -turningSpeed;

		if (sfw::getKey(264)) //breaking force
		{
			rb.force += -rb.velocity * brakePower;
			rb.torque += -rb.angularVelocity * brakePower;
		}
	}
};