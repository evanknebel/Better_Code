#pragma once

union vec2
{
	// access by array
	float v[2];

	// access by individual component
	struct { float x, y; };

	// access to vec2 by index
	float &operator[](unsigned idx);
	float operator[](unsigned idx) const;
};

vec2 operator+(const vec2 &lhs, const vec2 &rhs);
vec2 operator-(const vec2 &lhs, const vec2 &rhs);
vec2 operator*(const vec2 &lhs, float rhs);
vec2 operator*(float lhs, const vec2 &rhs);
vec2 operator/(const vec2 &lhs, float rhs);
vec2 operator-(const vec2 &lhs);

vec2 &operator+=(vec2 &lhs, const vec2 &rhs);
vec2 &operator-=(vec2 &lhs, const vec2 &rhs);
vec2 &operator*=(vec2 &lhs, float rhs);
vec2 &operator/=(vec2 &lhs, float rhs);

bool operator==(const vec2 &lhs, const vec2 &rhs);
bool operator!=(const vec2 &lhs, const vec2 &rhs);

float mag(const vec2 &v);
vec2 norm(const vec2 &v);
vec2 &normalize(vec2 &v);
float dot(const vec2 &a, const vec2 &b);
float dist(const vec2 &a, const vec2 &b);
vec2 perp(const vec2 &v);
vec2 lerp(const vec2 &s, const vec2 &e, float a);
vec2 min(const vec2 &a, const vec2 &b);
vec2 max(const vec2 &a, const vec2 &b);
vec2 clamp(const vec2 &a_min, const vec2 &a_val, const vec2 &a_max);

vec2 snap(const vec2 &a_min, const vec2 &a_val, const vec2 &a_max);


vec2 project(const vec2 &v, const vec2 &axis);
vec2 reflect(const vec2 &v, const vec2 &axis);

float toAngle(const vec2 &v);
vec2 fromAngle(float ang);