

#include "engine.h"
#include "GameObjects.h"
#include "LaserBeam.h"
#include <cassert>
#include <iostream>

void main()
{
	sfw::initContext();

	LaserBeam beam;
	Wall walls[4];

	walls[0].collider.box = AABB::fromExtents({500,100}, {600,500});
	walls[1].collider.box = AABB::fromExtents({100,100 }, { 200,500 });
	walls[2].collider.box = AABB::fromExtents({200,100}, {400,200});

	beam.origin = { {400,300}, fromAngle(45), 1000 };

	int step = 0;

	while (sfw::stepContext())
	{	
		beam.origin.direction = fromAngle(step);
		step += 1;
		beam.start();
		do
		{
			for (int i = 0; i < 3; ++i)
			{
				beam.step(walls[i].transform, walls[i].collider);
			}
		} while (beam.next() > 0);


		beam.draw(RED);
	


		for (int i = 0; i < 3; ++i)
		{
			//auto d = intersect_ray_AABB(beam.origin, walls[i].collider.box);
			//std::cout << d.entry << " " << d.exit << " " << d.handedness << std::endl;
			//int col = d.entry < d.exit && d.entry > 0 ? BLUE : WHITE;
			walls[i].collider.debugDraw(walls[i].transform, WHITE);
		}
	}

	sfw::termContext();
}