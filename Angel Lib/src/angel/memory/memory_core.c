```
alias `self` is `angel::mem`;
alias `MemoryChunk` is `angel::mem::MemoryChunk`;
```

#include <angel/memory.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

extern void _show_chunk(angel::mem::MemoryChunk chunk);

////////////////

intmax_t _current_heapsize = 0; 
bool _verbose_mode = false;

////////////////

intmax_t `self`::getHeapSize(void) {
	return _current_heapsize;
}

`MemoryChunk` `self`::allocate(size_t size, char * tag) {
	void * data = calloc(1, size);
	
	`MemoryChunk` output;
	
	strcpy(output.tag, tag);
	output.size = size;
	output.data = data;
	
	//not using isSuccess just for a slight performance boost if any honestly...
	if(data) {
		_current_heapsize += size;
		if(_verbose_mode) {
			printf("Memory chunk allocation successful");
			output@_show_chunk();
		}
	}
	
	return output;
}

void `self`::free(`MemoryChunk` chunk) {
	if( `self`::isSuccess(chunk) ) {
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

bool `self`::isSuccess(`MemoryChunk` chunk) {
	return chunk.data != NULL;
}

void `self`::setVerbose(bool verbose) {
	_verbose_mode = verbose;
}

////////////////

void _show_chunk(`MemoryChunk` chunk) {
	printf("_HEAP_: %ju\n", _current_heapsize);
	printf("TAG:    %s\n"  , chunk.tag);
	printf("SIZE:   %zu\n" , chunk.size);
	printf("pDATA:  %p\n\n", chunk.data);
}





















