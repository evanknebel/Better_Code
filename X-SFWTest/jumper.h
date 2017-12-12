#pragma once

#include "transform.h"
#include "Rigidbody.h"
#include "Collider.h"
#include "Sprite.h"
#include "jumperController.h"
//#include "collectable.h"


class Collectable;

class Jumper
{
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	JumperController controller;
	Sprite sprite;
};

class Wall // static rigidbody
{
public:
	Transform transform;
	Collider collider;
	Sprite sprite;
};

bool doCollision(Jumper &jumper, const Wall & wall);

bool doCollision(Jumper &jumper,  Collectable & collectable);