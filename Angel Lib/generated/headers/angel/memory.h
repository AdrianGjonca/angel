/**
 * @file memory.h
 * @brief Memory management in Angel Lib
 *
 * Provides a more complex form of memory management for C
 */

#ifndef ANGEL__MEMORY_H
#define ANGEL__MEMORY_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct angel_0mem_0MemoryChunk		angel_0mem_0MemoryChunk;

struct angel_0mem_0MemoryChunk {
	char tag[1024]; //Currently set at 1024, doubt it needs to be bigger. Likely ought to be smaller
	size_t size;
	void * data;
};

/**
 * @brief returns the heap size
 * Returns the number of bytes that have been allocated by Angel Lib's
 * memory management tool
 * 
 * @returns number of bytes allocated on heap by Angel Lib
 */
extern intmax_t angel_0mem_0getHeapSize(void);

/**
 * @brief allocates a region of memory with a certain tag
 * 
 * @param size the amount of bytes to allocate
 * @param tag the tag to associate with this chunk
 * @returns the angel_0MemorySector of the allocated memory
 */
extern angel_0mem_0MemoryChunk angel_0mem_0allocate(size_t size, char * tag);

/**
 * @brief frees a region of memory with a certain tag
 * If the memory chunk was a failed allocation this does nothing 
 * @param chunk the memory chunk to free
 */
extern void angel_0mem_0free(angel_0mem_0MemoryChunk chunk);

/**
 * @breif checks if a memory chunk was a successfull alocation or not
 * @return TRUE if successful allocation, FALSE if not
 */
extern bool angel_0mem_0isSuccess(angel_0mem_0MemoryChunk chunk);

/**
 * @breif Configures if the memory-manager should be verbose or not
 * Verbose means that it prints terminal output for various memory functionality
 * Non-verbose means there is no terminal output by the memory management system
 * @param verbose TRUE for verbose, FALSE for non-verbose
 */
extern void angel_0mem_0setVerbose(bool verbose);

#endif








