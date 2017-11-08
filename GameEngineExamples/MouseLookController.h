#pragma once
#include <sfwdraw.h>
#include "engine.h"

class MouseLookController
{

public:
	float moveSpeed;

	MouseLookController(): moveSpeed(160) {}

	void poll(Transform &t, Rigidbody &rb)
	{
		vec2 mp{ sfw::getMouseX(),
				 sfw::getMouseY() };

		vec2 dir = norm(mp - t.getGlobalPosition());

		t.setGlobalAngle(toAngle(dir));


		vec2 move = 
			vec2{
			(float)sfw::getKey('D') - sfw::getKey('A'),
			(float)sfw::getKey('W') - sfw::getKey('S')
					  };

		if (mag(move) >= 0.001)
			move = norm(move);

		rb.force += move * moveSpeed;
	}

	void draw(Transform &t, const mat3 &cam = mat3::identity())
	{
		vec2 mp{ sfw::getMouseX(),
				 sfw::getMouseY() };
		drawCircle(circle { mp, 4 });
	}
};