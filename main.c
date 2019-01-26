#include <stdio.h>
#include "bfpool.h"

static bfpool_t pool;

int main (int argc, const char * argv[]) {
	pool = bfpool_create(100);
	
	// test pop
	bfbuffer_t buf;
	int i = 0;
	do {
		buf = bfpool_buffer(pool);
		printf("%d - ", i);
		bfbuffer_desc(buf);
		i++;
		if ( i % 3 == 0 ) {
			bfpool_buffer_free(pool, buf);
		}
	}
	while ( buf != NULL);
	
	
    return 0;
}
