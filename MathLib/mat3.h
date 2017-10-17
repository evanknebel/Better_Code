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
	float m[9];
	float mm[3][3]; // [col(y)][row(x)]
	vec3  c[3];

	vec3 &operator[](size_t idx); // column accessor
	const vec3 &operator[](size_t idx) const;
	
	static mat3 identity(); // creates and returns an identity matrix.
};

mat3 operator+(const mat3 &A, const mat3 &B); // not really used O__O
mat3 operator-(const mat3 &A, const mat3 &B); // not really used O__O

mat3 operator*(const mat3 &A, const mat3 &B); // combine transformations
vec3 operator*(const mat3 &A, const vec3 &V); // apply a transformation

mat3 transpose(const mat3 &A); // flip the rows and columns!

// Unknowns!
float determinant(const mat3 &A);
mat3 inverse(const mat3 &A);

/*
[1 0 x]
[0 1 y]
[0 0 1]



[(0,0) (0,1) (0,2)]
[(1,0) (1,1) (1,2)]
[(2,0) (2,1) (2,2)]

[c1 c2 c3]

*/