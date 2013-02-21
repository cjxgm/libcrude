// vim: noet ts=4 sw=4 sts=0
#include "list.h"
#include "util.h"

List * list_new()
{
	create(List, list);
	list_init(list);
	return list;
}

inline void list_init(List * list)
{
	list->prev = list->next = list;
}

void list_add_tail(List * list, void * data)
{
	list_add_head(list->prev, data);
}

inline void list_add_head(List * list, void * data)
{
	List * t = data;
	t->prev = list;
	t->next = list->next;
	list->next->prev = t;
	list->next = t;
}

size_t list_length(List * list)
{
	size_t len = 0;
	list_walk(list, List, p, len++);
	return len;
}

inline void list_remove(void * data)
{
	List * t = data;
	t->prev->next = t->next;
	t->next->prev = t->prev;
}

void list_delete(void * data)
{
	list_remove(data);
	free(data);
}

