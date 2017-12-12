#pragma once

#include "transform.h"
#include "Rigidbody.h"
#include "sfwdraw.h"

const int LATERAL_SPEED = 800;
const int MAX_JUMP_SPEED = 850;

class JumperController
{
public:

	bool doAction = false;
	
	bool isGrounded = true;

	void poll(Transform &transform, Rigidbody &rigidbody)
	{
		if (sfw::getKey(265) && doAction == false && isGrounded == true)
		{
			rigidbody.impulse += vec2{ 0, MAX_JUMP_SPEED };
			
			doAction = true;
			isGrounded = false;
		}

		if (doAction == true && !sfw::getKey(265))
		{
			doAction = false;
		}

		if (sfw::getKey(262))
		{
			rigidbody.force += vec2{ LATERAL_SPEED, 0 };
		}
		if (sfw::getKey(263))
		{
			rigidbody.force += vec2{ -LATERAL_SPEED, 0 };
		}
	}
};