#pragma once

#include "vec3.h"


/*
[0 3 6]
[1 4 7] - Column-Major (as opposed to Row-Major)
[2 5 8]
vp = A * B * C * D * v // col major
vp = v * D * C * B * A // row major
*/


union mat3
{
	vec3  c[3];
	float m[9];
	float mm[3][3]; // [col(y)][row(x)]
	

	      vec3 &operator[](size_t idx)		 { return c[idx]; }
	const vec3 &operator[](size_t idx) const { return c[idx]; }
	
	static mat3 identity()
	{
		return mat3{1,0,0,
				    0,1,0,
					0,0,1};
	}

	static mat3 zero()
	{
		return mat3{ 0,0,0,
					 0,0,0,
					 0,0,0 };
	}
};

// A[2][1]

bool operator==(const mat3 &A, const mat3 &B);


mat3 operator+(const mat3 &A, const mat3 &B); // not really used O__O
mat3 operator-(const mat3 &A, const mat3 &B); // not really used O__O

											  // I(T) == I
mat3 transpose(const mat3 &A); // flip the rows and columns!

// A*I == A
mat3 operator*(const mat3 &A, const mat3 &B); // combine transformations
vec3 operator*(const mat3 &A, const vec3 &V); // apply a transformation


// Unknowns!
float determinant(const mat3 &A);
mat3 inverse(const mat3 &A);


/* Translation:
[1 0 X]
[0 1 Y]
[0 0 1] */
mat3 translate(const vec2 &t);

/* Scale:
[X 0 0]
[0 Y 0]
[0 0 1] */
mat3 scale(const vec2 &s);

/* Rotation:
A[0].xy is the x-axis
A[1].xy is the y-axis

[cos(a) -sin(a)  0]
[sin(a)  cos(a)  0]
[     0       0  1] */
mat3 rotate(float deg);