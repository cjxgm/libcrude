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
#define CREATE($type, $var, $expr...) \
	$type * $var = malloc(sizeof($type) $expr)


#endif

