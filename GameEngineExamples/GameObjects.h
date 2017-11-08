#pragma once

#include "engine.h"
#include "MouseLookController.h"
#include "LaserBeam.h"

class Player
{
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	MouseLookController controller;
	LaserBeam beam;
};


class Wall
{
public:
	Transform transform;
	Collider collider;
};
