/**
 * @file memory.h
 * @brief Memory management in Angel Lib
 *
 * Provides a more complex form of memory management for C
 */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct angel::mem::MemoryChunk		angel::mem::MemoryChunk;

/**
 * @brief returns the heap size
 * Returns the number of bytes that have been allocated by Angel Lib's
 * memory management tool
 * 
 * @returns number of bytes allocated on heap by Angel Lib
 */
extern uint64_t angel::mem::getHeapSize(void);

/**
 * @brief allocates a region of memory with a certain tag
 * 
 * @param size the amount of bytes to allocate
 * @param tag the tag to associate with this chunk
 * @returns the angel::MemorySector of the allocated memory
 */
extern angel::mem::MemoryChunk angel::mem::allocate(size_t size, char * tag);

/**
 * @brief frees a region of memory with a certain tag
 * If the memory chunk was a failed allocation this does nothing 
 * @param chunk the memory chunk to free
 */
extern void angel::mem::free(angel::mem::MemoryChunk chunk);

/**
 * @breif checks if a memory chunk was a successfull alocation or not
 * @return TRUE if successful allocation, FALSE if not
 */
extern bool angel::mem::isSuccess(angel::mem::MemoryChunk chunk);
