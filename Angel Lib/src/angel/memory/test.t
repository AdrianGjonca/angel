#include <angel/memory.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

extern void _show_chunk(angel_0mem_0MemoryChunk chunk);

////////////////

struct angel_0mem_0MemoryChunk {
	char tag[1024]; //Currently set at 1024, doubt it needs to be bigger. Likely ought to be smaller
	size_t size;
	void * data;
};

////////////////

intmax_t _current_heapsize = 0; 
bool _verbose_mode = 0; //We cant use 'FALSE' outside of functions for some reason

////////////////

intmax_t angel_0mem_0getHeapSize(void) {
	return _current_heapsize;
}

angel_0mem_0MemoryChunk angel_0mem_0allocate(size_t size, char * tag) {
	void * data = calloc(1, size);
	
	angel_0mem_0MemoryChunk output;
	
	strcpy(output.tag, tag);
	output.size = size;
	output.data = data;
	
	//not using isSuccess just for a slight performance boost if any honestly...
	if(data) {
		_current_heapsize += size;
		if(_verbose_mode) {
			printf("Memory chunk allocation successful");
			chunk@_show_chunk();
		}
	}
	
	return output;
}

void angel_0mem_0free( angel_0mem_0MemoryChunk chunk ) {
	if( angel_0mem_0isSuccess(chunk) ) {
		free(chunk.data);
		_current_heapsize -= chunk.size;
		if(_verbose_mode) {
			printf("Successfully freed memory chunk\n");
			chunk@_show_chunk();
		}
	}else {
		if(_verbose_mode) {
			printf("Failed attempt to free memory chunk\n");
			printf("Chunk appears to have been a failed allocation\n");
			chunk@_show_chunk();
		}
	}
}

bool angel_0mem_0isSuccess( angel_0mem_0MemoryChunk chunk ) {
	return chunk.data == NULL;
}

void angel_0mem_0setVerbose(bool verbose) {
	_verbose_mode = verbose;
}

////////////////

void _show_chunk(angel_0mem_0MemoryChunk chunk) {
	printf("_HEAP_: %ju\n", _current_heapsize);
	printf("TAG:   %s\n"  , chunk.tag);
	printf("SIZE:  %zu\n" , chunk.size);
	printf("pDATA: %p\n\n", () chunk.data);
}









