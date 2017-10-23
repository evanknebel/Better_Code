#include "MyGuy.h"
#include "sfwdraw.h"

myGuy::myGuy(float speed, float rotSpeed, vec2 pos, vec2 dim, float anglez)
{
	Speed = speed;
	turnSpeed = rotSpeed;
	myTrans.position = pos;
	myTrans.dimension = dim;
	myTrans.angle = anglez;
}

void myGuy::update(/*const mat3 & t*/)
{
	mat3 t = myTrans.getGlobalTransform();

	vec2 Dir = norm((t[1].xy)) * Speed;
	
	if (sfw::getKey('W'))
	{
		myTrans.position += Dir;
	}
	if (sfw::getKey('S'))
	{
		myTrans.position -= Dir;
	}
	if (sfw::getKey('A'))
	{
		myTrans.angle += turnSpeed;
	}
	if (sfw::getKey('D'))
	{
		myTrans.angle -= turnSpeed;
	}
}

void myGuy::draw(const mat3 & t)
{
	vec2 pos = t[2].xy;

	sfw::drawCircle(pos.x, pos.y, 20, 12, RED);
	DrawMatrix(myTrans.getGlobalTransform(), 1);
}
