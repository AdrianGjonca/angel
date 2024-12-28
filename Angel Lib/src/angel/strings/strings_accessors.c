```
alias `self` is `angel::strings`;
alias `SafeString` is `angel::strings::SafeString`;
```

#include <angel/strings.h>

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

size_t `self`::getLength(`SafeString` myself) {
	return strlen(myself.data);
}
