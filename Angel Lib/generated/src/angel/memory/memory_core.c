//PREFIX SECTION
//PREFIX SECTION
//PREFIX SECTION


#include <angel/memory.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

extern void _show_chunk(angel_0memory_0MemoryChunk chunk);

////////////////

intmax_t _current_heapsize = 0; 
bool _verbose_mode = false;

////////////////

intmax_t angel_0memory_0getHeapSize(void) {
	return _current_heapsize;
}

angel_0memory_0MemoryChunk angel_0memory_0allocate(size_t size, char * tag) {
	void * data = calloc(1, size);
	
	angel_0memory_0MemoryChunk output;
	
	strcpy(output.tag, tag);
	output.size = size;
	output.data = data;
	
	//not using isSuccess just for a slight performance boost if any honestly...
	if(data) {
		_current_heapsize += size;
		if(_verbose_mode) {
			printf("Memory chunk allocation successful");
			_show_chunk(output);
		}
	}
	
	return output;
}

void angel_0memory_0free(angel_0memory_0MemoryChunk chunk) {
	if( angel_0memory_0isSuccess(chunk) ) {
		free(chunk.data);
		_current_heapsize -= chunk.size;
		if(_verbose_mode) {
			printf("Successfully freed memory chunk\n");
			_show_chunk(chunk);
		}
	}else {
		if(_verbose_mode) {
			printf("Failed attempt to free memory chunk\n");
			printf("Chunk appears to have been a failed allocation\n");
			_show_chunk(chunk);
		}
	}
}

bool angel_0memory_0isSuccess(angel_0memory_0MemoryChunk chunk) {
	return chunk.data != NULL;
}

void angel_0memory_0setVerbose(bool verbose) {
	_verbose_mode = verbose;
}

////////////////

void _show_chunk(angel_0memory_0MemoryChunk chunk) {
	printf("_HEAP_: %ju\n", _current_heapsize);
	printf("TAG:    %s\n"  , chunk.tag);
	printf("SIZE:   %zu\n" , chunk.size);
	printf("pDATA:  %p\n\n", chunk.data);
}






















