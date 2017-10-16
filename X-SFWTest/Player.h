#pragma once

#include "vec2.h"

class Player
{
public:
	vec2 pos;

	float speed;

	void update();
	void draw();
};