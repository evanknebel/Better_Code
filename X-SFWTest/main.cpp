#include "sfwdraw.h"
#include "transform.h"
#include "Player.h"
#include "MyGuy.h"
#include "mat3.h"

#include <cmath>

int main()
{
	sfw::initContext();



	myGuy me(3, 1, vec2{ 300, 400 }, vec2{ 1,1 }, 0);
	
	/*Transform myTransform;
	myTransform.position = vec2{ 400,300 };
	myTransform.dimension = vec2{ 2,2 };
	myTransform.angle = 0;
	
	
	Transform myBaby;
	myBaby.position = vec2{ 100,0 };
	myBaby.dimension = vec2{ 1,1 };
	myBaby.angle = 0;
	myBaby.e_parent = &myTransform;*/
	
	while (sfw::stepContext())
	{
	//Rotate your object around clockwise
		float t = sfw::getTime();


		me.update(me.myTrans.getGlobalTransform());
		me.draw(me.myTrans.getGlobalTransform());
		//myTransform.angle += sfw::getDeltaTime() * 90;
		//myTransform.dimension = vec2{ sinf(t) + 2, sinf(t) + 2 };

		DrawMatrix(me.myTrans.getGlobalTransform(), 40);
		//DrawMatrix(myBaby.getGlobalTransform(), 30);
	}

	sfw::termContext();
}







