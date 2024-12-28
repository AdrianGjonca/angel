//PREFIX SECTION
//PREFIX SECTION
//PREFIX SECTION


#include <angel/strings.h>

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

size_t angel_0strings_0getLength(angel_0strings_0SafeString * myself) {
	return strlen(myself->data);
}

size_t angel_0strings_0getMaxLength(angel_0strings_0SafeString * myself) {
	return myself->maxSize;
}

bool angel_0strings_0isFailure(angel_0strings_0SafeString * myself) {
	return myself->failed;
}

bool angel_0strings_0isOnHeap(angel_0strings_0SafeString * myself) {
	return myself->onHeap;
}
//These two ought to be tested at some point with heap SafeStrings
bool angel_0strings_0isOnStack(angel_0strings_0SafeString * myself) {
	return !myself->onHeap;
}

char * angel_0strings_0data(angel_0strings_0SafeString * myself) {
	return myself->data;
}





