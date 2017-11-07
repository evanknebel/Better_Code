#include "LaserBeam.h"
#include "draw\draw.h"
#include "linmaths\vec2.h"

void LaserBeam::start()
{
	m_energy = origin.length;
	reflections[0] = origin;
	nReflections = 1;
	m_best.entry = 100000;
}

bool LaserBeam::step(const Transform & Bt, 
					 const Collider  & Bc)
{		
	Swept res = intersect_ray_AABB(reflections[nReflections-1], 
								   Bc.getGlobalBox(Bt));

	if (res.entry < m_best.entry && res.entry >= 0)
	{
		m_best = res;
		return true;
	}
	return false;
}



float LaserBeam::next(Rigidbody *rb)
{
	if (nReflections >= 64 || m_best.entry == 100000) return -1;
	ray ref;
	
	
	reflections[nReflections - 1].length = m_best.entry;

	ray c = reflections[nReflections - 1];

	ref.position = c.position + c.direction * m_best.entry;
	ref.direction = reflect(c.direction, m_best.handedness*m_best.axis);
	
	m_energy -= m_best.entry;

	reflections[nReflections++] = ref;		
	m_best.entry = 100000;

	
	return m_energy;
}


void LaserBeam::draw(int color, const mat3 &cam)
{
	for (int i = 0; i < nReflections; ++i)
	{
		drawRay(reflections[i], color);
	}
}