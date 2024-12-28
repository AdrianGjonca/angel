```
alias `self` is `angel::strings`;
alias `SafeString` is `angel::strings::SafeString`;
```

#include <angel/strings.h>

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

`SafeString` * `self`::repeat(
	`SafeString` * to_manipulate,
	unsigned int n
) {
	if(to_manipulate->failed) {
		return to_manipulate;
	}
	///
	int og_len = strlen(to_manipulate->data);
	if(og_len * n + 1 > to_manipulate->maxSize){
		to_manipulate->failed = true;
		return to_manipulate;
	}
	///
	
	for(int i = og_len; i < og_len * n; i++) {
		to_manipulate->data[i] = to_manipulate->data[i % og_len];
	}
	to_manipulate->data[og_len * n] = '\0';
	
	return to_manipulate;
}
