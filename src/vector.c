// vim: noet ts=4 sw=4 sts=0
#include "vector.h"

float vdot(vec a, vec b)
{
	vec c = a * b;
	// this method is faster than "c[0] + c[1] + c[2]"
	return (c + c[1] + c[2])[0];
}

vec vcross(vec a, vec b)
{
	return v3(
		a[1]*b[2] - b[1]*a[2],
		a[2]*b[0] - b[2]*a[0],
		a[0]*b[1] - b[0]*a[1]
	);
}

