/*
 *  bfpool.h
 *  bfpool
 *
 *  Created by Cătălin Stan on 1/24/19.
 *  Copyright 2019 __MyCompanyName__. All rights reserved.
 *
 */

typedef struct _bfbuffer	*bfbuffer_t;
typedef struct _bfpool		*bfpool_t;

void bfbuffer_desc(bfbuffer_t buf);

bfpool_t bfpool_create( int count );
void bfpool_destroy( bfpool_t pool );

bfbuffer_t bfpool_buffer( bfpool_t pool );
void bfpool_buffer_free( bfpool_t pool, bfbuffer_t buf);
