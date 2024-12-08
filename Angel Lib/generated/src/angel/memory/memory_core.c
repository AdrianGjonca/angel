#include <angel/memory.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct angel_0mem_0MemoryChunk {
	char tag[1024]; //Currently set at 1024, doubt it needs to be bigger. Likely ought to be smaller
	size_t size;
	void * data;
};

uint64_t _current_heapsize = 0; 

uint64_t angel_0mem_0getHeapSize(void) {
	return _current_heapsize;
}

angel_0mem_0MemoryChunk angel_0mem_0allocate(size_t size, char * tag) {
	void * data = calloc(1, size);
	
	angel_0mem_0MemoryChunk output;
	
	strcpy(output.tag, tag);
	output.size = size;
	output.data = data;
	
	return output;
}

void angel_0mem_0free( angel_0mem_0MemoryChunk chunk ) {
	if( angel_0mem_0isSuccess(chunk) ) {
		free(chunk.data);
	}
}

bool angel_0mem_0isSuccess( angel_0mem_0MemoryChunk chunk ) {
	return chunk.data == NULL;
}

