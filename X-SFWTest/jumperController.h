#pragma once

#include "transform.h"
#include "Rigidbody.h"
#include "sfwdraw.h"

const int LATERAL_SPEED = 800;
const int MAX_JUMP_SPEED = 620;
const int SMALL_JUMP_SPEED = 100;

class JumperController
{
public:

	bool doActionBig = false;
	bool doActionSmall = true;

	bool isGrounded = false;

	void poll(Transform &transform, Rigidbody &rigidbody)
	{
		//big jump
		if (sfw::getKey(265) && doActionBig == false && isGrounded == true)
		{
			rigidbody.impulse += vec2{ 0, MAX_JUMP_SPEED };
			
			doActionBig = true;
			isGrounded = false;
		}
		//small jump
		if (sfw::getKey(264) && doActionSmall == false && isGrounded == true)
		{
			rigidbody.impulse += vec2{ 0, SMALL_JUMP_SPEED };

			doActionSmall = true;
			isGrounded = false;
		}

		if (doActionBig == true && !sfw::getKey(265))
		{
			doActionBig = false;
		}
		if (doActionSmall == true && !sfw::getKey(264))
		{
			doActionSmall = false;
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