

#include "sfwdraw.h"
#include "Player.h"
#include "DrawShape.h"
#include <Windows.h>


// scrollPos   += scrollDelta on update
// scrollDelta += scrollQueue on update
// scrollQueue    modified by callback
// getScrollPos
// getScrollDelta

const int WALL_AMOUNT = 7;

int main()
{
	sfw::initContext(1000,1000);

	Player player;

	player.sprite = sfw::loadTextureMap("../resources/classic_ship.png");
	player.transform.dimension = vec2{64, 64};
	player.transform.position = vec2{ 400,300 };
	player.collider.box.extents = {.5,.5};

	Wall walls[WALL_AMOUNT];
	//platform 1
	walls[0].transform.position = { 220,300 };
	walls[0].transform.dimension = {400,10};
	walls[0].collider.box.extents = { .5,.5 };
	//walls[0].sprite.handle = sfw::loadTextureMap("../resources/Giant_Tree.png");

	//platform 2
	walls[1].transform.position = { 750,600 };
	walls[1].transform.dimension = { 250,10 };
	walls[1].collider.box.extents = { .5,.5 };
	//walls[1].sprite.handle = walls[0].sprite.handle;

	//platform 3
	walls[2].transform.position = { 40,850 };
	walls[2].transform.dimension = { 60,10 };
	walls[2].collider.box.extents = { .5,.5 };
	//walls[2].sprite.handle = walls[0].sprite.handle;

	//wall left
	walls[3].transform.position = { 0,500 };
	walls[3].transform.dimension = { 10,1000 };
	walls[3].collider.box.extents = { .5,.5 };
	//walls[3].sprite.handle = walls[0].sprite.handle;

	//wall right
	walls[4].transform.position = { 1000,500 };
	walls[4].transform.dimension = { 10,1000 };
	walls[4].collider.box.extents = { .5,.5 };
	//walls[4].sprite.handle = walls[0].sprite.handle;

	//wall bottom
	walls[5].transform.position = { 500,0 };
	walls[5].transform.dimension = { 1000,10 };
	walls[5].collider.box.extents = { .5,.5 };
	//walls[5].sprite.handle = walls[0].sprite.handle;

	//wall top
	walls[6].transform.position = { 500,1000 };
	walls[6].transform.dimension = { 1000,10 };
	walls[6].collider.box.extents = { .5,.5 };
	//walls[6].sprite.handle = walls[0].sprite.handle;

	//Ball ball;
	//ball.transform.position = { 400,300 };
	//ball.sprite.handle = sfw::loadTextureMap("../resources/Gungeon.jpg");
	//ball.transform.dimension = {32,32};
	//ball.collider.box.extents = { .5,.5 };
	//ball.rigidbody.velocity = { 200,0 };
	//ball.rigidbody.drag = 0;
	
	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();

		// update controllers0
		player.controller.poll(player.rigidbody, player.transform);

		// update rigibodies
		player.rigidbody.integrate(player.transform, dt);
		//ball.rigidbody.integrate(ball.transform, dt);

		// draw stuff
		player.sprite.draw(player.transform);		
		//ball.sprite.draw(ball.transform);
		for (int i = 0; i < WALL_AMOUNT; ++i)
			walls[i].sprite.draw(walls[i].transform);

		// Collision resolution
		for (int i = 0; i < WALL_AMOUNT; ++i)
		{
			doCollision(player, walls[i]);
			//doCollision(ball, walls[i]);
		}

		//doCollision(player, ball);

		// Debug boxes
		drawAABB(player.collider.getGlobalBox(player.transform), MAGENTA);
		for (int i = 0; i < WALL_AMOUNT; ++i)
			drawAABB(walls[i].collider.getGlobalBox(walls[i].transform), RED);
	}	
	sfw::termContext();
}







