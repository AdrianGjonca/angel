```
alias `self` is `angel::strings`;
alias `SafeString` is `angel::strings::SafeString`;
```

#include <angel/strings.h>

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

`SafeString` `self`::new(
	size_t	maxSize,
	bool	onHeap,
	char * 	data
) {
	struct `SafeString` output = {
		maxSize,
		(strlen(data) >= maxSize),
		onHeap,
		data
	};
	
	return output;
}


