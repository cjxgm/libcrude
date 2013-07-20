// vim: noet ts=4 sw=4 sts=0
// memory pool
#pragma once

#include <stddef.h>
#include "util.h"


typedef struct Pool
{
	size_t size;
	size_t used;
	void ** datas;
}
Pool;


Pool * pool_new(size_t size);
void pool_free(Pool * pool, void free_cb(void * ptr));
void * pool_get(Pool * pool);
bool pool_put(Pool * pool, void * data);

