```
echo `You are compiling the version for testing angel-bd`;

alias `mem` is `angel::memory`;
alias `MemoryChunk` is `angel::memory::MemoryChunk`;

alias `SafeString` is `angel::strings::SafeString`;
alias `str` is `angel::strings`;
```

#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include<stddef.h>

#include<angel/memory.h>
#include<angel/strings.h>
#include<string.h>

#define KiB 1024L
#define TiB 1024L * 1024L * 1024L * 1024L

int main() {
	printf("HI\n");
	return 0;
}


