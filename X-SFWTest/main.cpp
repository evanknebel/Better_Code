#include "sfwdraw.h"

#include "DrawShape.h"
#include "jumper.h"
#include "jumperController.h"
#include "collectable.h"

// scrollPos   += scrollDelta on update
// scrollDelta += scrollQueue on update
// scrollQueue    modified by callback
// getScrollPos
// getScrollDelta






const int WALL_AMOUNT = 7;
const int COLLECTABLE_AMOUNT = 3;
const int COLLECTABLE_SIZE = 20;

int main()
{
	sfw::initContext(1000,1000);

	sfw::drawCircle(500, 500, 30);


	Jumper jumper;
	jumper.sprite = sfw::loadTextureMap("../resources/classic_ship.png");
	jumper.transform.dimension = vec2{ 50, 50 };
	jumper.transform.position = vec2{ 700, 1000 };
	jumper.collider.box.extents = {.5,.5};

	Collectable collectables[COLLECTABLE_AMOUNT];
	//item 1
	collectables[0].transform.position = { 200,350 };
	collectables[0].transform.dimension = { COLLECTABLE_SIZE,COLLECTABLE_SIZE };
	collectables[0].collider.box.extents = { .5,.5 };

	//item 2
	collectables[1].transform.position = { 800,650 };
	collectables[1].transform.dimension = { COLLECTABLE_SIZE,COLLECTABLE_SIZE };
	collectables[1].collider.box.extents = { .5,.5 };

	//item 3
	collectables[2].transform.position = { 40,870 };
	collectables[2].transform.dimension = { COLLECTABLE_SIZE,COLLECTABLE_SIZE };
	collectables[2].collider.box.extents = { .5,.5 };

	Wall walls[WALL_AMOUNT];
	//platform 1
	walls[0].transform.position = { 220,300 };
	walls[0].transform.dimension = {400,10};
	walls[0].collider.box.extents = { .5,.5 };

	//platform 2
	walls[1].transform.position = { 750,600 };
	walls[1].transform.dimension = { 250,10 };
	walls[1].collider.box.extents = { .5,.5 };

	//platform 3
	walls[2].transform.position = { 40,850 };
	walls[2].transform.dimension = { 60,10 };
	walls[2].collider.box.extents = { .5,.5 };

	//wall left
	walls[3].transform.position = { 0,500 };
	walls[3].transform.dimension = { 10,1000 };
	walls[3].collider.box.extents = { .5,.5 };

	//wall right
	walls[4].transform.position = { 1000,500 };
	walls[4].transform.dimension = { 10,1000 };
	walls[4].collider.box.extents = { .5,.5 };

	//wall bottom
	walls[5].transform.position = { 500,0 };
	walls[5].transform.dimension = { 1000,10 };
	walls[5].collider.box.extents = { .5,.5 };

	//wall top
	walls[6].transform.position = { 500,1000 };
	walls[6].transform.dimension = { 1000,10 };
	walls[6].collider.box.extents = { .5,.5 };

	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();

		// update controllers
		jumper.controller.poll(jumper.transform, jumper.rigidbody);

		// update rigibodies
		// gravity
		jumper.rigidbody.force += vec2{ 0, -600.0f };
		jumper.rigidbody.integrate(jumper.transform, dt);

		// draw stuff


		jumper.sprite.draw(jumper.transform);

		for (int i = 0; i < WALL_AMOUNT; ++i)
			walls[i].sprite.draw(walls[i].transform);

		// Collision resolution
		for (int i = 0; i < WALL_AMOUNT; ++i)
		{
			doCollision(jumper, walls[i]);
		}



		// Debug boxes
		// for jumper
		drawAABB(jumper.collider.getGlobalBox(jumper.transform), MAGENTA);
		// for walls
		for (int i = 0; i < WALL_AMOUNT; ++i)
			drawAABB(walls[i].collider.getGlobalBox(walls[i].transform), RED);
		// for collectable
		for (int i = 0; i < COLLECTABLE_AMOUNT; ++i)
		{
			collectables[i].draw();
			doCollision(jumper, collectables[i]);
		}

	}	
	sfw::termContext();
}







