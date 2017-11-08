#include "LaserBeam.h"
#include "draw\draw.h"
#include "linmaths\vec2.h"

void LaserBeam::start(const Transform &a_origin)
{
	origin.position = a_origin.getGlobalPosition();
	origin.direction = a_origin.getGlobalRight();

	m_current = origin;
	reflections[0] = origin;
	nReflections = 1;
	m_best.exit = -1;
	m_best.entry = 1000000;
	m_energy = 1000000; // total length of the beam
}

// search for the best entry time
bool LaserBeam::step(const Transform & Bt, 
					 const Collider  & Bc)
{		
	Swept res = intersect_ray_AABB(m_current, Bc.getGlobalBox(Bt));

	if (res.entry < res.exit && res.entry > 0 && res.entry < m_best.entry)
	{
		m_best = res;
		return true;
	}
	return false;
}



float LaserBeam::next(Rigidbody *rb)
{
	// cut the length off of the previous ray
	reflections[nReflections - 1].length = min(m_energy,m_best.entry);
	m_energy -= m_best.entry;

	if (m_energy <= 0 || nReflections == 64) return -1;

	ray ref;	
	ref.position  = m_current.position + m_current.direction * m_best.entry;
	ref.direction = reflect(m_current.direction, m_best.axis*m_best.handedness);
	m_current = reflections[nReflections] = ref;
	nReflections++;

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