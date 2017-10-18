#include "vec3.h"

#include "mathutils.h"
#include <cmath>
#include <cfloat>

vec3 operator+(const vec3 &lhs, const vec3 &rhs)
{
	vec3 result;

	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;
	result.z = lhs.z + rhs.z;

	return result;

	// rewrite?
	for (int i = 0; i < 3; ++i)
	{
		result.v[i] = lhs.v[i] + rhs.v[i];
	}
}

vec3 operator-(const vec3 & lhs, const vec3 & rhs)
{
	vec3 result;
	for (int i = 0; i < 3; ++i)
	{
		result.v[i] = lhs.v[i] - rhs.v[i];
	}
	return result;
}

vec3 operator*(const vec3 & lhs, const float rhs)
{
	vec3 result; 
	for (int i = 0; i < 3; i++)
	{
		result.v[i] = lhs.v[i] * rhs;
	}
	return result;
}

vec3 operator*(const float lhs, const vec3 & rhs)
{
	vec3 result;
	for (int i = 0; i < 3; i++)
	{
		result.v[i] = rhs.v[i] * lhs;
	}
	return result;
}

vec3 operator/(const vec3 & lhs, const float rhs)
{
	vec3 result;
	for (int i = 0; i < 3; i++)
	{
		result.v[i] = lhs.v[0] / rhs;
	}
	return result;
}

vec3 operator+=(vec3 &lhs, const vec3 &rhs)
{
	lhs = lhs + rhs;

	return lhs;
}

vec3 operator-=(vec3 & lhs, const vec3 & rhs)
{
	lhs = lhs - rhs;

	return lhs;
}

vec3 operator*=(vec3 & lhs, const float rhs)
{
	lhs = lhs * rhs;
	return lhs;
}

vec3 operator/=(vec3 & lhs, const float rhs)
{
	lhs = lhs / rhs;
	return lhs;
}

bool operator==(const vec3 &lhs, const vec3 &rhs)
{
	if (abs(lhs.x - rhs.x) <= EPSILON &&
		abs(lhs.y - rhs.y) <= EPSILON &&
		abs(lhs.z - rhs.z) <= EPSILON)
	{
		return true;
	}

	return false;
}

bool operator!=(const vec3 & lhs, const vec3 & rhs)
{
	/*if (abs(lhs.x - rhs.x) < FLT_EPSILON &&
		abs(lhs.y - rhs.y) < FLT_EPSILON &&
		abs(lhs.z - rhs.z) < FLT_EPSILON)
	{
		return false;
	}

	return true;*/

	if (lhs == rhs)
	{
		return false;
	}
	else
	{
		return true;
	}

}

float mag(const vec3 & v)
{
	float aSqr = v.x * v.x;
	float bSqr = v.y * v.y;
	float cSqr = v.z * v.z;

	return sqrtf(aSqr + bSqr + cSqr);
}

vec3 norm(const vec3 & v)
{
	vec3 temp = v;
	float len = mag(v);

	temp /= len;
	return temp;
}

vec3 & normalize(vec3 & v)
{
	v = norm(v);
	return v;
}

float dot(const vec3 & a, const vec3 & b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

float dist(const vec3 & a, const vec3 & b)
{
	return mag(b - a);
}

vec3 min(const vec3 & a, const vec3 & b)
{
	vec3 temp;
	temp.x = fmin(a.x, b.x);
	temp.y = fmin(a.y, b.y);
	temp.z = fmin(a.z, b.z);
	return temp;
}

vec3 max(const vec3 & a, const vec3 & b)
{
	vec3 temp;
	temp.x = fmax(a.x, b.x);
	temp.y = fmax(a.y, b.y);
	temp.z = fmax(a.z, b.z);
	return temp;
}
vec3 clamp(const vec3 & a_min, const vec3 & v, const vec3 & a_max)
{
	vec3 dummy = v;
	//min {1,1,1};
	//value {0,6,3};
	//max {5,5,5};

	dummy = min(dummy, a_max);
	dummy = max(dummy, a_min);

	return dummy;
	
}
float & vec3::operator[](unsigned idx)
{
	return v[idx];
}

float vec3::operator[](unsigned idx) const
{
	return v[idx];
}


// Vector perpendicular to two other vectors	
// yz-zy, zx-xz, xy-yx
vec3 cross(const vec3 &a, const vec3 &b)
{
	return  vec3 { a.y*b.z - a.z*b.y,
				   a.z*b.x - a.x*b.z,
				   a.x*b.y - a.y*b.x };
} 