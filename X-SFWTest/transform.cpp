#include "transform.h"
#include "sfwdraw.h"

Transform::Transform(vec2 a_pos, vec2 a_dim, float a_ang)
{
	position = a_pos; //vec2{ 0,0 };
	dimension = a_dim;//  vec2{ 0,0 };
	angle = a_ang; // 0;
	e_parent = nullptr;
}

mat3 Transform::getLocalTransform() const
{

	return translate(position) * scale(dimension) * rotate(angle);
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

void DrawMatrix(const mat3 & t, float drawing_scale)
{
	vec2 pos = t[2].xy;
	vec2 right_ep = pos + t[0].xy * drawing_scale;
	vec2 up_ep = pos + t[1].xy * drawing_scale;

	sfw::drawLine(pos.x, pos.y, right_ep.x, right_ep.y, RED);
	sfw::drawLine(pos.x, pos.y, up_ep.x, up_ep.y, GREEN);

	sfw::drawCircle(pos.x, pos.y, drawing_scale / 4);

}


void DrawTexture(unsigned sprite, const mat3 &t)
{
	sfw::drawTextureMatrix3(sprite, 0, WHITE, t.m);
}