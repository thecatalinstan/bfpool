/*
 *  bfpool.c
 *  bfpool
 *
 *  Created by Cătălin Stan on 1/24/19.
 *  Copyright 2019 __MyCompanyName__. All rights reserved.
 *
 */

#include "bfpool.h"

#import <stdio.h>
#import <stdlib.h>

typedef struct _bfbuffer {
	int idx;
	volatile bfbuffer_t next;
} _bfbuffer;

void bfbuffer_desc(bfbuffer_t buf) {
	if ( buf == NULL ) {
		printf(":NULL:");
		return;
	}
	printf("%d: %p =>  %d: %p\n", buf->idx, buf, buf->next != NULL ? buf->next->idx : -1, buf->next );	
}


static inline bfbuffer_t bfbuffer_create( int idx, bfbuffer_t next ) {
	bfbuffer_t buf = (bfbuffer_t)malloc( sizeof(struct _bfbuffer) );
	if ( buf ==NULL ) {
		return NULL;
	}
	
	buf->idx = idx;
	buf->next = next;

	return buf;
}

typedef struct _bfpool {
	volatile bfbuffer_t top;
} _bfpool;


static inline void _bfpool_push( bfpool_t pool, bfbuffer_t buf) {
	buf->next = pool->top;
	pool->top = buf;	
}

static inline bfbuffer_t _bfpool_pop( bfpool_t pool ) {
	if ( pool->top == NULL ) {
		return NULL;
	}
	bfbuffer_t buf = pool->top;
	pool->top = pool->top->next;
	return buf;
}


bfpool_t bfpool_create( int count ) {
	bfpool_t pool = malloc( sizeof(struct _bfpool) );	
	for ( int i = 0; i < count; i++ ) {
		_bfpool_push( pool, bfbuffer_create(i, NULL) );
	}
	return pool;
}

void bfpool_destroy( bfpool_t pool ) {
	
}

bfbuffer_t bfpool_buffer( bfpool_t pool ) {
	return _bfpool_pop(pool);
}

void bfpool_buffer_free( bfpool_t pool, bfbuffer_t buf) {
	return _bfpool_push(pool, buf);
}

