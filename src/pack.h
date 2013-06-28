// vim: noet ts=4 sw=4 sts=0
// pack(anything-container) manipulation
#ifndef __CRUDE$PACK__
#define __CRUDE$PACK__

#include "list.h"
#include "util.h"


typedef List Pack;

typedef struct PackElement
{
	LISTABLE;
	void * data;
}
PackElement;


#define pack_walk_element($pack, $var, $block...) \
	list_walk((List *)($pack), PackElement, $var, $block)

#define pack_walk($pack, $type, $var, $block...) \
	pack_walk_element($pack, $pe$, { \
		$type * $var = ($type *)$pe$->data; \
		$block; \
	})


#define pack_new()					list_new()
#define pack_free($pack)			list_free((List *)($pack))
#define pack_init($pack)			list_init((List *)($pack))
#define pack_length($pack)			list_length((List *)($pack))
#define pack_remove($pack_element)	list_remove((List *)($pack_element))
#define pack_delete($pack_element)	list_delete((List *)($pack_element))
#define pack_delete_me()			({ \
	$pe$ = (PackElement *)list_prev((List *)$pe$); \
	list_delete(list_next((List *)$pe$)); \
})

#define pack_add_tail($pack, $data)	({ \
	create(PackElement, $pe$); \
	$pe$->data = ($data); \
	list_add_tail((List *)($pack), $pe$); \
})

#define pack_add_head($pack, $data)	({ \
	create(PackElement, $pe$); \
	$pe$->data = ($data); \
	list_add_head((List *)($pack), $pe$); \
})


#endif

