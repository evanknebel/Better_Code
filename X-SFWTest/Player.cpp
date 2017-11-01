#include "Player.h"

bool doCollision(Player & player, const Wall & wall)
{

	auto hit = collides(player.transform, player.collider,
		wall.transform, wall.collider);

	if (hit.penetrationDepth > 0)
	{
		static_resolution(player.transform.position, player.rigidbody.velocity, hit);
		return true;
	}
	return false;
}



bool doCollision(Ball &ball, const Wall &wall)
{

	auto hit = collides(ball.transform, ball.collider,
		wall.transform, wall.collider);

	if (hit.penetrationDepth > 0)
	{
		static_resolution(ball.transform.position, ball.rigidbody.velocity, hit);
		return true;
	}
	return false;
}