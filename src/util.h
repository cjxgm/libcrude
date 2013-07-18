// vim: noet ts=4 sw=4 sts=0
// un-categorized utility macros, functions, etc...
#ifndef __CRUDE$UTIL__
#define __CRUDE$UTIL__

#include <stdlib.h>


// anonymous/lambda function
#define $($ret_type, $definition...) \
	({ $ret_type $lambda_function$ $definition &$lambda_function$; })

// act like the "auto" keyword in c++11
#define $_($var, $what...) \
	typeof($what) $var = $what

// object function call
#define $$($object, $func, $args...) ({ \
	$_($object$, $object); \
	$_($func$, $func); \
	$object$->$func$($object$, $args); \
})

// simpler malloc
#define new($type, $expr...) \
	malloc(sizeof($type) $expr)

// simpler malloc
#define create($type, $var, $expr...) \
	$type * $var = malloc(sizeof($type) $expr)

// simpler valloc
#define vnew($type, $expr...) \
	malloc(sizeof($type) $expr)

// simpler valloc
#define vcreate($type, $var, $expr...) \
	$type * $var = malloc(sizeof($type) $expr)

// calculate fixed-sized array length
#define array_length($array) \
	(sizeof($array) / sizeof(*($array)))

// macro concatenate
#define mcat($x, $y) \
	$x ## $y

// macro implicit concatenate
#define micat($x, $y) \
	mcat($x, $y)

// declare a variable unused
#define UNUSED		__attribute__((__unused__))

// skip a parameter of a function in declaration
#define SKIP		void * micat(__unused, __COUNTER__) UNUSED

// cast to (void *)
#define ANY			(void *)


// boolean
typedef unsigned char bool;
#define true	1
#define false	0

#endif

