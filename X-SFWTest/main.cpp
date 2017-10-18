#include "sfwdraw.h"
#include "transform.h"
#include "Player.h"

#include "mat3.h"

#include <cmath>

int main()
{
	sfw::initContext();

	Transform myTransform;
	myTransform.position = vec2{ 300,400 };
	myTransform.dimension = vec2{ 2,2 };
	myTransform.angle = 0;

	while (sfw::stepContext())
	{
	//Rotate your object around clockwise
		float t = sfw::getTime();

		myTransform.angle += sfw::getDeltaTime() * 90;
		myTransform.dimension = vec2{ sinf(t) + 2, sinf(t) + 2 };

		DrawMatrix(myTransform.getLocalTransform(), 40);
	}

	sfw::termContext();
}







