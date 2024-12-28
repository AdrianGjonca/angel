//PREFIX SECTION
//PREFIX SECTION
//PREFIX SECTION


#include <angel/strings.h>

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

angel_0strings_0SafeString angel_0strings_0new(
	size_t	maxSize,
	bool	onHeap,
	char * 	data
) {
	struct angel_0strings_0SafeString output = {
		maxSize,
		(strlen(data) >= maxSize),
		onHeap,
		data
	};
	
	return output;
}



