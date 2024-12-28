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

typedef struct angel::strings::SafeString		angel::strings::SafeString;
struct angel::strings::SafeString {
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
 * @returns the angel::strings::SafeString constructed from these
 */
extern angel::strings::SafeString angel::strings::new(
	size_t	maxSize,
	bool	onHeap,
	char * 	data
);

/**
 * \fn void angel::strings::INIT_SAFE_STRING(lvalue name, size_t size, char * value)
 * \brief SHORTHAND: Creates a SafeString AND a char[size] stack-buffer to hold its data.
 * This Macro creates a buffer; calls angel::strings::new with the buffer as data.
 * And then strcpy in the value given into the buffer.
 * This is a shorthand to make creating SAFE_STRING with initial values easier.
 * 
 * \param name The name of the SafeString we will create (lvalue).
 * \param size The size of the buffer and therfore SafeString maxSize.
 * \param value The string to be copied into the buffer of the SafeString
 */
#define angel::strings::INIT_SAFE_STRING(name, size, value) \
    char _______##name##_buffer[size]; \
    angel::strings::SafeString name = angel::strings::new(\
    	size, \
    	false, \
    	_______##name##_buffer\
    ); \
    if(strlen(value) >= size) name.failed = true;\
    else strcpy(name.data, value)









/////////////////////////
// MUTATORS
/////////////////////////

/**
 * @brief repeats a string n times
 * this is destructive!!
 * @param myself The original string (as pntr)
 * @param the number of times to repeat
 * @return 'myself' but now freshly modified
 */
extern angel::strings::SafeString * angel::strings::repeat(
	angel::strings::SafeString * myself,
	unsigned int n
);










/////////////////////////
// ACCESSORS
/////////////////////////

/**
 * @brief gets the length of the SafeString
 * @param myself The input SafeString (as pntr)
 * @return the length
 */
extern size_t angel::strings::getLength(
	angel::strings::SafeString * myself
);

/**
 * @brief gets the MaximumLength of the SafeString
 * Same as SAFESTRING.maxSize but looks more OOP-esque.
 * @param myself The input SafeString (as pntr)
 * @return the maximum possible size of the SafeString
 */
extern size_t angel::strings::getMaxLength(
	angel::strings::SafeString * myself
);

/**
 * @brief returns True if SafeString is a failure
 * Same as SAFESTRING.failed
 * @param myself The input SafeString (as pntr)
 * @return true if failure, false if not
 */
extern bool angel::strings::isFailure(
	angel::strings::SafeString * myself
);

/**
 * @brief returns True if SafeString data is marked as on Heap
 * Same as SAFESTRING.onHeap
 * @param myself The input SafeString (as pntr)
 * @return true if marked as on the Heap, false if not
 */
extern bool angel::strings::isOnHeap(
	angel::strings::SafeString * myself
);

/**
 * @brief returns True if SafeString data is marked as on Stack
 * Same as !SAFESTRING.onHeap
 * @param myself The input SafeString (as pntr)
 * @return true if marked as on the Stack, false if not
 */
extern bool angel::strings::isOnStack(
	angel::strings::SafeString * myself
);

/**
 * @brief returns the data/char* of the SafeString
 * @param myself The input SafeString (as pntr)
 * @return the char* data
 */
extern char * angel::strings::data(
	angel::strings::SafeString * myself
);















#endif
