#include "mathutils.h"
#include "vec2.h"
#include "vec3.h"
#include <iostream>
#include <cassert>
#include "mat3.h"

int main()
{
	// equality and inequality
	/*{
		vec2 a = { 5,3 };
		vec2 b = { 4,2 };
		vec2 c = { 0,1 };
		vec2 d = { 0,1 };

		assert((a + b) == (vec2{ 9, 5 }));
		assert(c == d);
		assert(a != c);
	}


	vec2 test;
	test.x = 5;
	test.y = 20;

	vec2 testB;
	testB.x = 13;
	testB.y = 4;

	vec2 result = test + testB;

	vec2 num;
	num.x = 0;
	num.y = 0;

	num += test;

	bool eq = num == test;
	bool ieq = num == testB;

	std::cout << "ALL TESTS OK" << std::endl;*/


	mat3 I = mat3::identity();
	mat3 Z = mat3::zero();
	mat3 A = { 1,2,3,4,5,6,7,8,9 };
	vec3 v = { 1,2,3 };

	assert(I + Z == I);
	assert(Z + I == I);
	assert(I - Z == I);
	assert(!(Z - I == I));
	assert(transpose(I) == I);
	assert(A*I == A);
	assert(I*A == A);

	assert(I*v == v);

	assert(inverse(I) == I);

	// -6.39757843e-07 == the equivalent of 0.
	// -0.0000006 : close to zero!

	mat3 T =         scale(vec2{ 1, 2 }) * 
					 rotate(90) *
					 translate(vec2{ 3, 0 });
	
	T = scale(vec2{ 1,2 });
	T = T * rotate(90);
	T = T * translate(vec2{ 3,0 });

	assert((T[2].xy == vec2{ 0,6 }));

	while (true) {}
}
