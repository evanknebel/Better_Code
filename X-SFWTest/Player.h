#pragma once

#include "transform.h"
#include "Rigidbody.h"
#include "Collider.h"
#include "Controller.h"
#include "Sprite.h"

class Player
{
public:
	Transform   transform;
	Rigidbody   rigidbody;
	Collider    collider;
	Controller  controller;
	Sprite		sprite;
};