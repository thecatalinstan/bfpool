#include <stdio.h>
#include "bfpool.h"

static bfpool_t pool;

int main (int argc, const char * argv[]) {
	pool = bfpool_create(100);
	
	// test pop
	bfbuffer_t buf;
	do {
		buf = bfpool_buffer(pool);
		bfbuffer_desc(buf);		
	}
	while ( buf != NULL);
	
	
    return 0;
}
