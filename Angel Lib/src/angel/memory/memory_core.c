#include <angel/memory.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

struct angel::mem::MemoryChunk {
	char * tag;
	size_t * size;
	void * data;
};

uint64_t _current_heapsize = 0; 

uint64_t angel::mem::getHeapSize(void) {
	return _current_heapsize;
}

angel::mem::MemoryChunk angel::mem::allocate(size_t size, char * tag) {
	void * data = calloc(1, size);
	
	angel::mem::MemoryChunk output;
	
	return output;
}

void angel::mem::free( angel::mem::MemoryChunk chunk ) {
	if( angel::mem::isSuccess(chunk) ) {
		free(chunk.data);
	}
}

bool angel::mem::isSuccess( angel::mem::MemoryChunk chunk ) {
	return chunk.data == NULL;
}
