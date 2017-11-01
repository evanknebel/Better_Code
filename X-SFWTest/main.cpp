

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

	Wall wall;
	wall.transform.position = { 400,300 };
	wall.transform.dimension = {240,240};
	wall.collider.box.extents = { .5,.5 };
	wall.sprite.handle = sfw::loadTextureMap("../resources/Giant_Tree.png");
	
	
	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();

		player.controller.poll(player.rigidbody, player.transform);

		player.rigidbody.integrate(player.transform, dt);
	
		player.sprite.draw(player.transform);
		wall.sprite.draw(wall.transform);

		doCollision(player, wall);


		drawAABB(player.collider.getGlobalBox(player.transform), MAGENTA);
		drawAABB(wall.collider.getGlobalBox(wall.transform), RED);



		//r = d-2(d.n)n
	}	
	sfw::termContext();
}







