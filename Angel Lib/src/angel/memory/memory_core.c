#include <angel/memory.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct angel::mem::MemoryChunk {
	char tag[1024]; //Currently set at 1024, doubt it needs to be bigger. Likely ought to be smaller
	size_t size;
	void * data;
};

uint64_t _current_heapsize = 0; 

uint64_t angel::mem::getHeapSize(void) {
	return _current_heapsize;
}

angel::mem::MemoryChunk angel::mem::allocate(size_t size, char * tag) {
	void * data = calloc(1, size);
	
	angel::mem::MemoryChunk output;
	
	strcpy(output.tag, tag);
	output.size = size;
	output.data = data;
	
	//not using isSuccess just for a slight performance boost if any honestly...
	if(data) {
		_current_heapsize += size;
	}
	
	return output;
}

void angel::mem::free( angel::mem::MemoryChunk chunk ) {
	if( angel::mem::isSuccess(chunk) ) {
		free(chunk.data);
		_current_heapsize -= size;
	}
}

bool angel::mem::isSuccess( angel::mem::MemoryChunk chunk ) {
	return chunk.data == NULL;
}
