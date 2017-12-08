#pragma once

#include "transform.h"
#include "Rigidbody.h"
#include "sfwdraw.h"

class JumperController
{
public:
	void poll(Transform &transform, Rigidbody &rigidbody)
	{
		if (sfw::getKey(263))
		{
			rigidbody.force += vec2{ -4, 0 };
		}
	}


};