// vim: noet ts=4 sw=4 sts=0
// very fast random number generator
#pragma once

extern int fast_seed;

// ranged [-1, 1]
#define fast_randf_at($x) ({ \
	int $x$ = ($x); \
	$x$ = ($x$<<13) ^ $x$; \
	(1.0 - ((($x$ * $x$ * 15731 + 789221) * $x$ + \
			1376312589) & 0x7fffffff) / 1073741824.0); \
})
#define fast_srand($seed)	fast_seed = ($seed)
#define fast_randf()		fast_randf_at(fast_seed++)
#define fast_rand()			((int)(((fast_randf()+1)/2) * 0x7FFFFFFF))

