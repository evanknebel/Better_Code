#include "collectable.h"
#include "DrawShape.h"
void Collectable::draw()
{
	if(isCollected == false)
		drawAABB(collider.getGlobalBox(transform), RED);
}
