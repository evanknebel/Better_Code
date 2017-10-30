#include "DrawShape.h"
#include "sfwdraw.h"

void drawCircle(const circle &C)
{
	sfw::drawCircle(C.position.x, C.position.y, C.radius);
}
