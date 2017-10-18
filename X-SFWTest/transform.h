#pragma once
#include "vec2.h"
#include "mat3.h"
class Transform
{
public:
	vec2 position;
	vec2 dimension;
	float angle;
	Transform *e_parent;


	Transform();

	mat3 getLocalTransform() const;
	mat3 getGlobalTransform() const;
};

void DrawMatrix(const mat3 &t, float drawing_scale);