#pragma once

#include "transform.h"
#include "Rigidbody.h"
#include "Collider.h"
#include "Sprite.h"
//#include "jumperController.h"



class Collectable
{
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;

	bool isCollected = false;
	void draw();

};
