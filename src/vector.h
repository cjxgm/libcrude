// vim: noet ts=4 sw=4 sts=0
// mathematical vector manipulation
#pragma once

#include <math.h>
#include "util.h"

////////////////////// NOTES ON CODING STYLE /////////////////////
//
// mathematical types DO NOT USE UPPER-CASE CHARACTERS
// no "Vec" but "vec". no "Mat" but "mat"
//
// for vectors , use "v" for prefix, not "v_", as in "vcross"
// for matrices, use "m" for prefix, not "m_", as in "mmul"
//
//////////////////////////////////////////////////////////////////

typedef float vec __attribute__((vector_size(sizeof(float)*4)));
#define v3($x, $y, $z)			((vec){($x), ($y), ($z)})
#define v4($x, $y, $z, $w)		((vec){($x), ($y), ($z), ($w)})
#define vspread($x)	({ \
	$_($x$, ($x)); \
	(vec){$x$, $x$, $x$, $x$}; \
})

float vdot(vec a, vec b);
#define vsqr($a) ({ \
	$_($a$, $a); \
	vdot($a$, $a$); \
})
#define vmod($a)				sqrtf(vsqr($a))
#define vnorm($a) ({ \
	$_($a$, $a); \
	$a$ / vmod($a$); \
})

vec vcross(vec a, vec b);

