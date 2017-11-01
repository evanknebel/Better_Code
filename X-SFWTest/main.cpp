

#include "sfwdraw.h"
#include "Player.h"
#include "DrawShape.h"


int main()
{
	sfw::initContext();


	Player player;

	player.sprite = sfw::loadTextureMap("../resources/classic_ship.png");
	player.transform.dimension = vec2{48, 48};
	player.transform.position = vec2{ 400,300 };
	player.collider.box.extents = {.5,.5};

	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();

		player.controller.poll(player.rigidbody, player.transform);

		player.rigidbody.integrate(player.transform, dt);
	
		player.sprite.draw(player.transform);


		drawAABB(player.collider.getGlobalBox(player.transform), MAGENTA);
	}

	sfw::termContext();
}







