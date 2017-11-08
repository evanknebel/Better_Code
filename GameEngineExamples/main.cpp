

#include "engine.h"
#include "GameObjects.h"
#include "LaserBeam.h"
#include <cassert>
#include <iostream>

void main()
{
	sfw::initContext();

	Player player;
	player.transform.position = vec2{ 400,300 };
	player.transform.dimension = vec2{80,80};

	Wall walls[4];

	walls[0].collider.box = AABB::fromExtents({500,100}, {600,500});
	walls[1].collider.box = AABB::fromExtents({100,100 }, { 200,500 });
	walls[2].collider.box = AABB::fromExtents({200,100}, {400,200});

	while (sfw::stepContext())
	{	
		float dt = sfw::getDeltaTime();

		
		player.controller.poll(player.transform, player.rigidbody);

		player.rigidbody.integrate(player.transform, dt);
		

		player.beam.start(player.transform);
		
		do for (int i = 0; i < 3; ++i)
			player.beam.step(walls[i].transform, walls[i].collider);
		while (player.beam.next() > 0);

		for (int i = 0; i < 3; ++i)
		{
			auto hit = collides(player.transform, player.collider,
								walls[i].transform, walls[i].collider);
			
			if(hit.penetrationDepth > 0)
			{
			vec2 pos = player.transform.getGlobalPosition();
			
			vec2 vel = player.rigidbody.velocity;
			static_resolution(pos, vel, hit);
			player.transform.position = pos;
			player.rigidbody.velocity = vel;
			}
		}

		player.beam.draw(RED);	
		player.controller.draw(player.transform);
		player.collider.debugDraw(player.transform,WHITE);

		for (int i = 0; i < 3; ++i)		
			walls[i].collider.debugDraw(walls[i].transform, WHITE);
	}

	sfw::termContext();
}