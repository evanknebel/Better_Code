#pragma once

#include "vec2.h"

union vec3
{

	// access by array
	float v[3];
	
	// access by individual component
	struct { float x, y, z; };

	// access as vec2
	vec2 xy;

	// access to vec3 by index
	float &operator[](unsigned idx);
	float operator[](unsigned idx) const;
};

vec3 operator+(const vec3 &lhs, const vec3 &rhs);
vec3 operator-(const vec3 &lhs, const vec3 &rhs);
vec3 operator*(const vec3 &lhs, const float rhs);
vec3 operator*(const float lhs, const vec3 &rhs);
vec3 operator/(const vec3 &lhs, const float rhs);

vec3 operator+=(vec3 &lhs, const vec3 &rhs);
vec3 operator-=(vec3 &lhs, const vec3 &rhs);

vec3 operator*=(vec3 &lhs, const float rhs);
vec3 operator/=(vec3 &lhs, const float rhs);


bool operator==(const vec3 &lhs, const vec3 &rhs);
bool operator!=(const vec3 &lhs, const vec3 &rhs);

float mag(const vec3 &v);
vec3 norm(const vec3 &v);
vec3 &normalize(vec3 &v);

float dot(const vec3 &a, const vec3 &b);
float dist(const vec3 &a, const vec3 &b);

vec3 min(const vec3 &a, const vec3 &b);
vec3 max(const vec3 &a, const vec3 &b);
vec3 clamp(const vec3 &a_min, const vec3 &v, const vec3 & a_max);


vec3 cross(const vec3 &a, const vec3 &b);