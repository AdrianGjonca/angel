/**
 * @file strings.h
 * @brief String manipulation in Angel Lib
 *
 * Provides some safe string functionality for C
 */

#ifndef ANGEL__STR_H
#define ANGEL__STR_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

typedef struct angel_0strings_0SafeString		angel_0strings_0SafeString;
struct angel_0strings_0SafeString {
	size_t maxSize;	// Maximum size of this string
	bool failed; 	// Is true if manipulations failed
	bool onHeap; 	// Is true if char-array declared on Heap (unrecomended)
	
	char * data;	// The string itself.
};

/**
 * @brief Creates a new SafeString with the given char* as the data
 * The data is not copied; the reference is! 
 * ^ This is to make it wholey stack based, if ofcourse the char*
 *   was even allocated in the stack as recomended.
 *
 * @param maxSize the size of the allocated char-array
 * @param onHeap set to true if on heap and false if not
 * @param data the char-array by pointer.
 *
 * @returns the angel_0strings_0SafeString constructed from these
 */
extern angel_0strings_0SafeString angel_0strings_0new(
	size_t	maxSize,
	bool	onHeap,
	char * 	data
);

/**
 * TODO write this
 */
#define angel_0strings_0INIT_SAFE_STRING(name, size, value) \
    char _______##name##_buffer[size]; \
    angel_0strings_0SafeString name = angel_0strings_0new(size, false, _______##name##_buffer); \
    strcpy(name.data, value)

/**
 * TODO write this
 * this is destructive!!
 */
extern angel_0strings_0SafeString angel_0strings_0repeat(
	angel_0strings_0SafeString to_manipulate,
	unsigned int n
);






/////////////////////////
// MUTATORS
/////////////////////////

/**
 * TODO write this
 * this is destructive!!
 */
extern angel_0strings_0SafeString angel_0strings_0repeat(
	angel_0strings_0SafeString to_manipulate,
	unsigned int n
);






/////////////////////////
// ACCESSORS
/////////////////////////

/**
 * TODO write this
 */
extern size_t angel_0strings_0getLength(angel_0strings_0SafeString myself);



















#endif

