```
alias `self` is `angel::strings`;
alias `SafeString` is `angel::strings::SafeString`;
```

#include <angel/strings.h>

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

size_t `self`::getLength(`SafeString` * myself) {
	return strlen(myself->data);
}

size_t `self`::getMaxLength(`SafeString` * myself) {
	return myself->maxSize;
}

bool `self`::isFailure(`SafeString` * myself) {
	return myself->failed;
}

bool `self`::isOnHeap(`SafeString` * myself) {
	return myself->onHeap;
}
//These two ought to be tested at some point with heap SafeStrings
bool `self`::isOnStack(`SafeString` * myself) {
	return !myself->onHeap;
}

char * `self`::data(`SafeString` * myself) {
	return myself->data;
}




