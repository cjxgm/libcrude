
#include <stdio.h>
#include "pack.h"

int main()
{
	Pack * p = pack_new();
	while (1) {
		create(int, n);
		scanf("%d", n);
		if (*n == 0) break;
		pack_add_tail(p, n);
	}
	pack_walk(p, int, n, {
		printf("%d\n", *n);
	});
	return 0;
}

