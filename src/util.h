// vim: noet ts=4 sw=4 sts=0
// un-categorized utility macros, functions, etc...
#pragma once

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

// simpler calloc
#define new0($type, $expr...) \
	calloc(sizeof($type) $expr, 1)

// simpler calloc
#define create0($type, $var, $expr...) \
	$type * $var = calloc(sizeof($type) $expr, 1)

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

// cause the function to be called before main()
#define CONSTRUCTOR	__attribute__((constructor))

// cause the function to be called after main() or exit()
#define DESRTUCTOR	__attribute__((destructor))

// mark as desprecated
#define DESPRECATED	__attribute__((desprecated))

// mark the function that it will never return
#define NO_RETURN	__attribute__((noreturn))

// mark a function to be optimized for speed, regardless of the size
#define HOT			__attribute__((hot))

// mark a function to be optimized for size, regardless of the speed
#define COLD		__attribute__((cold))

// var do not align to 4-byte size
#define PACKED		__attribute__((packed))

// generate compile-time warning
#define COMPILER_WARNING($msg)	__attribute__((warning($msg)))

// generate compile-time error
#define COMPILER_ERROR($msg)	__attribute__((error($msg)))

// call the function when a var goes out of scope.
#define CLEANUP($func)			__attribute__((cleanup($func)))


// boolean
typedef unsigned char bool;
#define true	1
#define false	0

