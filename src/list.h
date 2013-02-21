// vim: noet ts=4 sw=4 sts=0
// double-ended in-structure list data structure manipulation
#ifndef __CRUDE$LIST__
#define __CRUDE$LIST__

#include <stddef.h>


#define LISTABLE \
	List * prev; \
	List * next


#define list_walk($list, $type, $var, $block...) ({ \
	for ($type * __$ = (void *)($list), * $var = (void *)__$->next; \
			$var != __$; $var = (void *)$var->next) \
		$block; \
})


#define list_next($list)				(((List *)($list))->next)
#define list_prev($list)				(((List *)($list))->prev)
#define list_head($list, $type)			(($type *)list_next($list))
#define list_tail($list, $type)			(($type *)list_prev($list))


typedef struct List List;	// so that LISTABLE can be used
struct List
{
	LISTABLE;
};


		List * list_new();
inline	void list_init(List * list);
		void list_add_tail(List * list, void * data);
inline	void list_add_head(List * list, void * data);
		size_t list_length(List * list);
inline	void list_remove(void * data);
		void list_delete(void * data);

#endif

