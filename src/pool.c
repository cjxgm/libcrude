// vim: noet ts=4 sw=4 sts=0
#include <stdlib.h>
#include "pool.h"

Pool * pool_new(size_t size)
{
	create(Pool, pool);
	pool->size = size;
	pool->used = 0;
	pool->datas = new(void *, * size);
	return pool;
}

void pool_free(Pool * pool, void free_cb(void * ptr))
{
	void * data;
	while ((data = pool_get(pool)))
		free_cb(data);
	free(pool);
}

void * pool_get(Pool * pool)
{
	if (!pool->used) return NULL;
	return pool->datas[--pool->used];
}

bool pool_put(Pool * pool, void * data)
{
	if (pool->used == pool->size) return true;	// full
	pool->datas[pool->used++] = data;
	return false;
}

