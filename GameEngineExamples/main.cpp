

#include "engine.h"
#include "GameObjects.h"
#include "LaserBeam.h"

void main()
{
	sfw::initContext();

	LaserBeam beam;
	Wall walls[8];

	for (int i = 0; i < 8; ++i)
	{
		walls[i].collider.box
			= { randRange({ 200,100 },{ 700, 500 }),
			    randRange({20,20},{120,120}) };
	}

	walls[0].collider.box = { {700,300-30}, {30, 300} };
	walls[1].collider.box = { { 400-30,500 },{ 400, 30 } };

	beam.origin = { {400,200}, fromAngle(33), 1000 };

	while (sfw::stepContext())
	{	
		beam.start();

		do
		{
			for (int i = 0; i < 2; ++i)
				beam.step(walls[i].transform, walls[i].collider);
		} while (beam.next() > 0);


		beam.draw(RED);

		for (int i = 0; i < 2; ++i)
			walls[i].collider.debugDraw(walls[i].transform, WHITE);
	}

	sfw::termContext();
}