#pragma once

// controller -> rigidbody -> transform
#include "transform.h"
#include "Rigidbody.h"
#include "sfwdraw.h"

// Poll for input and apply changes to the rigidbody
class Controller
{

public:
	void poll(Rigidbody &rb, const Transform &t)
	{

		if (sfw::getKey('W'))rb.force +=
			t.getGlobalTransform()[1].xy * 100;
		
		if (sfw::getKey('A'))rb.torque += 360;
		if (sfw::getKey('D'))rb.torque += -360;

		if (sfw::getKey('Q')) rb.impulse +=
			-t.getGlobalTransform()[1].xy * 10;

		if (sfw::getKey(' ')) //breaking force
		{
			rb.force += -rb.velocity * 20;
			rb.torque += -rb.angularVelocity * 20;
		}
	}
};