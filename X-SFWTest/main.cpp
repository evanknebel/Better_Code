

#include "sfwdraw.h"
#include "Player.h"
#include "DrawShape.h"


// scrollPos   += scrollDelta on update
// scrollDelta += scrollQueue on update
// scrollQueue    modified by callback
// getScrollPos
// getScrollDelta


int main()
{
	sfw::initContext();

	Player player;

	player.sprite = sfw::loadTextureMap("../resources/classic_ship.png");
	player.transform.dimension = vec2{64, 64};
	player.transform.position = vec2{ 400,300 };
	player.collider.box.extents = {.5,.5};

	Wall walls[2];
	walls[0].transform.position = { 600,300 };
	walls[0].transform.dimension = {80,240};
	walls[0].collider.box.extents = { .5,.5 };
	walls[0].sprite.handle = sfw::loadTextureMap("../resources/Giant_Tree.png");

	walls[1].transform.position = { 200,300 };
	walls[1].transform.dimension = { 80,240 };
	walls[1].collider.box.extents = { .5,.5 };
	walls[1].sprite.handle = sfw::loadTextureMap("../resources/Giant_Tree.png");

	
	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();

		// update controllers
		player.controller.poll(player.rigidbody, player.transform);

		// update rigibodies
		player.rigidbody.integrate(player.transform, dt);
	
		// draw stuff
		player.sprite.draw(player.transform);		
		for (int i = 0; i < 2; ++i)
			walls[i].sprite.draw(walls[i].transform);

		// Collision resolution
		for (int i = 0; i < 2; ++i)
			doCollision(player, walls[i]);


		// Debug boxes
		drawAABB(player.collider.getGlobalBox(player.transform), MAGENTA);
		for (int i = 0; i < 2; ++i)
			drawAABB(walls[i].collider.getGlobalBox(walls[i].transform), RED);
	}	
	sfw::termContext();
}







