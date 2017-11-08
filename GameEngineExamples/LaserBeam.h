#pragma once
#include "engine.h"

class LaserBeam
{
public:
	ray origin, m_current;
	float m_energy;
	float m_strength;
	Swept m_best;
	ray reflections[64];
	int nReflections;

	// Needs to be able to loop through all reflectable objects
		// Unfortunately, those might not all be in the same array or of different types


	// Begins a loop
	void start(const Transform &a_origin);

	// for the current beam,
	// consider the next obj
	// returns, if the obj is clsoer
	bool step(const Transform &At, const Collider &Bt);


	// apply the reflection and prepare
	// for the next beam's reflections
	float next(Rigidbody *rb = nullptr);

	void draw(int color = RED, const mat3 &cam = mat3::identity());
};



