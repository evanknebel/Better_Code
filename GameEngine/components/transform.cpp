#include "transform.h"
#include "../sfwdraw.h"

Transform::Transform(vec2 a_pos, vec2 a_dim, float a_ang)
{
	position = a_pos; //vec2{ 0,0 };
	dimension = a_dim;//  vec2{ 0,0 };
	angle = a_ang; // 0;
	e_parent = nullptr;
}

mat3 Transform::getLocalTransform() const
{
	return translate(position)  * rotate(angle) * scale(dimension);
}

mat3 Transform::getGlobalTransform() const
{
	if (e_parent != nullptr)
	{
		return e_parent->getGlobalTransform() * getLocalTransform();
	}
	else
	{
		return getLocalTransform();
	}
}

float Transform::getGlobalAngle() const		{ return toAngle(getGlobalRight()); }

vec2 Transform::getGlobalUp() const			{ return norm(getGlobalTransform()[1].xy); }

vec2 Transform::getGlobalRight() const		{ return norm(getGlobalTransform()[0].xy); }

vec2 Transform::getGlobalPosition() const	{ return getGlobalTransform()[2].xy; }

void Transform::setGlobalPosition(const vec2 & v)
{
	if (e_parent)
		position = mulPos(inverse(e_parent->getGlobalTransform()), v);
	
	else position = v;
}

void Transform::setGlobalAngle(float v)
{
	mat3 par = e_parent ? e_parent->getGlobalTransform() : mat3::identity();

	angle = toAngle(mulDir(inverse(par), fromAngle(v)));
}

