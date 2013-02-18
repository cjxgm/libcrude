// vim: noet ts=4 sw=4 sts=0
// very fast random number generator
#ifndef __CRUDE$FAST_RAND__
#define __CRUDE$FAST_RAND__

extern int fast_seed;
float fast_randf_at(int x);		// ranged [-1, 1]
#define fast_srand($seed)	fast_seed = ($seed)
#define fast_randf()		fast_randf_at(fast_seed++)
#define fast_rand()			((int)(((fast_randf()+1)/2) * 0x7FFFFFFF))

#endif

