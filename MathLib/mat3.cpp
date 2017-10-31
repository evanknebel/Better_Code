#include "mat3.h"
#include <cmath>

mat3 operator+(const mat3 &A, const mat3 &B)
{
	return mat3{ A[0] + B[0],
			     A[1] + B[1],
				 A[2] + B[2] };
}


mat3 operator-(const mat3 &A, const mat3 &B)
{
	return mat3{ A[0] - B[0],
				 A[1] - B[1],
				 A[2] - B[2] };
}


bool operator==(const mat3 & A, const mat3 & B)
{
	return A[0] == B[0] &&
		   A[1] == B[1] &&
		   A[2] == B[2];
}

mat3 transpose(const mat3 &A)
{
	//mat3 retval;

	//for (int x = 0; x < 3; ++x)
	//	for (int y = 0; y < 3; ++y)
	//		retval[x][y] = A[y][x];

	//return retval;

	return mat3{A[0][0], A[1][0], A[2][0],
				A[0][1], A[1][1], A[2][1],
				A[0][2], A[1][2], A[2][2]};
}


mat3 operator*(const mat3 &A, const mat3 &B)
{
	mat3 retval;
	// we can flip the rows and cols so that the rows
	// of A (rhs) are accessible as vectors. This makes
	// finding the dot products of A's rows and B's cols
	// more convenient.
	mat3 At = transpose(A); 

	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 3; ++x)
			retval[y][x] = dot(At[x], B[y]);

	return retval;
}

vec3 operator*(const mat3 &A, const vec3 &B)
{
	mat3 At = transpose(A);
	float x = dot(At[0], B);
	float y = dot(At[1], B);
	float z = dot(At[2], B);
	return vec3 { dot(At[0], B),
				  dot(At[1], B),
				  dot(At[2], B) };
}


// Determinant is the "triple product"
float determinant(const mat3 &A)
{
	return dot(A[0], cross(A[1], A[2]));
}

// triple cross product
// A * inverse(A) == I
mat3 inverse(const mat3 &A)
{
	float di = 1 / determinant(A);
	
	return transpose( mat3 {
			cross(A[1], A[2]) * di,
			cross(A[2], A[0]) * di,
			cross(A[0], A[1]) * di } );
}

/*
0 - X-Axis, Right Direction
1 - Y-Axis, Up direction
2 - Translation, Position
*/

mat3 translate(const vec2 &t)
{
	//mat3 retval = mat3::identity();
	//retval[2].xy = t;
	//return retval;

	return mat3{     1,   0, 0,
				     0,   1, 0,
		           t.x, t.y, 1 };
}

mat3 scale(const vec2 &s)
{
	return mat3{s.x,   0, 0,
	              0, s.y, 0,
				  0,   0, 1};
}

// #include <cmath>

mat3 rotate(float deg)
{
	// rad = deg * pi/180
	// deg = rad * 180/pi

	float rad = deg * 0.0174533;
		

	return mat3{  cos(rad), sin(rad), 0, // x-axis
				 -sin(rad), cos(rad), 0, // y-axis
						 0,        0, 1 };
}