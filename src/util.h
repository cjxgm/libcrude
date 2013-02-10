// vim: noet ts=4 sw=4 sts=0
// un-categorized utility macros, functions, etc...
#ifndef __CRUDE$UTIL__
#define __CRUDE$UTIL__

#include <stdlib.h>


// anonymous/lambda function
#define $($ret_type, $definition...) \
	({ $ret_type $lambda_function$ $definition &$lambda_function; })

// act like the "auto" keyword in c++11
#define $_($var, $what...) \
	typeof($what) $var = $what

// simpler malloc
#define new($type, $expr...) \
	malloc(sizeof($type) $expr)

// simpler malloc
#define create($type, $var, $expr...) \
	$type * $var = malloc(sizeof($type) $expr)


// boolean
typedef unsigned char bool;
#define true	1
#define false	0

#endif

