#pragma once

#include "transform.h"
#include "Rigidbody.h"
#include "Collider.h"

#include "Sprite.h"

class Jumper
{
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;

	Sprite sprite;
};