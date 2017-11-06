#include "mathutils.h"
#include <cmath>

int min(int a, int b)
{
	return a < b ? a : b;
}

float min(float a, float b)
{
	return a < b ? a : b;
}

float max(float a, float b)
{
	return a > b ? a : b;
}

float snap(float s, float v, float l)
{
	return abs(v - s) < abs(v - l) ? s : l;
}