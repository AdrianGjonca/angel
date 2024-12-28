//PREFIX SECTION
//PREFIX SECTION
//PREFIX SECTION


#include <angel/strings.h>

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

size_t angel_0strings_0getLength(angel_0strings_0SafeString myself) {
	return strlen(myself.data);
}

