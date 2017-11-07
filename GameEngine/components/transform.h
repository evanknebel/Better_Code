#pragma once

#include "../linmaths/mat3.h"

class Transform
{
public:
	vec2       position;
	vec2       dimension;
	float      angle;
	Transform *e_parent;
	Transform *children[8];
	int nChildren;

	Transform(vec2 a_pos = {0,0}, vec2 a_dim = { 1,1 }, float a_ang = 0);


	mat3 getLocalTransform() const;
	mat3 getGlobalTransform() const;

	float getGlobalAngle()   const;
	vec2 getGlobalUp()		 const;
	vec2 getGlobalRight()	 const;
	vec2 getGlobalPosition() const;

	void setGlobalPosition(const vec2 &v);
	void setGlobalAngle(float v);
};