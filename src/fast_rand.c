// vim: noet ts=4 sw=4 sts=0
#include "fast_rand.h"

int fast_seed;

float fast_randf_at(int x)
{
	x = (x<<13) ^ x;
	return (1.0 - (((x*x*15731 + 789221)*x +
					1376312589) & 0x7fffffff) / 1073741824.0); 
}

