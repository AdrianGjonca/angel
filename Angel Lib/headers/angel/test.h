```
alias `Ki` is ` * 1024`;
alias `Mi` is ` * 1024 * 1024`;
alias `Gi` is ` * 1024 * 1024 * 1024`;
```

/**
 * @file message.h
 * @brief 'Message' system for Angel Lib
 *
 * Provides a variable length manner to store strings in C on the stack
 */

#ifndef ANGEL__MESSAGE_H
#define ANGEL__MESSAGE_H

typedef struct angel::msg::Message		angel::msg::Message;
struct angel::msg::Message {
	size_t size;
	char text[128]; //Default is 128B
};

typedef struct angel::msg::Message__128B		angel::msg::Message__128B;
struct angel::msg::Message__128B {
	size_t size;
	char text[128];
};

typedef struct angel::msg::Message__256B		angel::msg::Message__256B;
struct angel::msg::Message__256B {
	size_t size;
	char text[256];
};

typedef struct angel::msg::Message__512B		angel::msg::Message__512B;
struct angel::msg::Message__512B {
	size_t size;
	char text[512];
};

typedef struct angel::msg::Message__1KiB		angel::msg::Message__1KiB;
struct angel::msg::Message__1KiB {
	size_t size;
	char text[1`Ki`];
};

typedef struct angel::msg::Message__2KiB		angel::msg::Message__2KiB;
struct angel::msg::Message__2KiB {
	size_t size;
	char text[2`Ki`];
};

typedef struct angel::msg::Message__4KiB		angel::msg::Message__4KiB;
struct angel::msg::Message__4KiB {
	size_t size;
	char text[4`Ki`];
};

typedef struct angel::msg::Message__8KiB		angel::msg::Message__8KiB;
struct angel::msg::Message__8KiB {
	size_t size;
	char text[8`Ki`];
};

typedef struct angel::msg::Message__16KiB		angel::msg::Message__16KiB;
struct angel::msg::Message__16KiB {
	size_t size;
	char text[16`Ki`];
};

typedef struct angel::msg::Message__32KiB		angel::msg::Message__32KiB;
struct angel::msg::Message__32KiB {
	size_t size;
	char text[32`Ki`];
};

typedef struct angel::msg::Message__64KiB		angel::msg::Message__64KiB;
struct angel::msg::Message__64KiB {
	size_t size;
	char text[64`Ki`];
};

typedef struct angel::msg::Message__128KiB		angel::msg::Message__128KiB;
struct angel::msg::Message__128KiB {
	size_t size;
	char text[128`Ki`];
};

typedef struct angel::msg::Message__256KiB		angel::msg::Message__256KiB;
struct angel::msg::Message__256KiB {
	size_t size;
	char text[256`Ki`];
};

typedef struct angel::msg::Message__512KiB		angel::msg::Message__512KiB;
struct angel::msg::Message__512KiB {
	size_t size;
	char text[512`Ki`];
};

typedef struct angel::msg::Message__1MiB		angel::msg::Message__1MiB;
struct angel::msg::Message__1MiB {
	size_t size;
	char text[1`Mi`];
};

typedef struct angel::msg::Message__2MiB		angel::msg::Message__2MiB;
struct angel::msg::Message__2MiB {
	size_t size;
	char text[2`Mi`];
};

typedef struct angel::msg::Message__4MiB		angel::msg::Message__4MiB;
struct angel::msg::Message__4MiB {
	size_t size;
	char text[4`Mi`];
};

typedef struct angel::msg::Message__8MiB		angel::msg::Message__8MiB;
struct angel::msg::Message__8MiB {
	size_t size;
	char text[8`Mi`];
};

typedef struct angel::msg::Message__16MiB		angel::msg::Message__16MiB;
struct angel::msg::Message__16MiB {
	size_t size;
	char text[16`Mi`];
};

typedef struct angel::msg::Message__32MiB		angel::msg::Message__32MiB;
struct angel::msg::Message__32MiB {
	size_t size;
	char text[32`Mi`];
};

typedef struct angel::msg::Message__64MiB		angel::msg::Message__64MiB;
struct angel::msg::Message__64MiB {
	size_t size;
	char text[64`Mi`];
};

typedef struct angel::msg::Message__128MiB		angel::msg::Message__128MiB;
struct angel::msg::Message__128MiB {
	size_t size;
	char text[128`Mi`];
};

typedef struct angel::msg::Message__258MiB		angel::msg::Message__258MiB;
struct angel::msg::Message__258MiB {
	size_t size;
	char text[258`Mi`];
};

typedef struct angel::msg::Message__512MiB		angel::msg::Message__512MiB;
struct angel::msg::Message__512MiB {
	size_t size;
	char text[512`Mi`];
};

typedef struct angel::msg::Message__1GiB		angel::msg::Message__1GiB;
struct angel::msg::Message__1GiB {
	size_t size;
	char text[1`Gi`];
};

typedef struct angel::msg::Message__2GiB		angel::msg::Message__2GiB;
struct angel::msg::Message__2GiB {
	size_t size;
	char text[2`Gi`];
};

typedef struct angel::msg::Message__3GiB		angel::msg::Message__3GiB;
struct angel::msg::Message__3GiB {
	size_t size;
	char text[3`Gi`];
};

typedef struct angel::msg::Message__4GiB		angel::msg::Message__4GiB;
struct angel::msg::Message__4GiB {
	size_t size;
	char text[4`Gi`];
};

typedef struct angel::msg::Message__5GiB		angel::msg::Message__5GiB;
struct angel::msg::Message__5GiB {
	size_t size;
	char text[5`Gi`];
};

typedef struct angel::msg::Message__6GiB		angel::msg::Message__6GiB;
struct angel::msg::Message__6GiB {
	size_t size;
	char text[6`Gi`];
};

typedef struct angel::msg::Message__7GiB		angel::msg::Message__7GiB;
struct angel::msg::Message__7GiB {
	size_t size;
	char text[7`Gi`];
};

typedef struct angel::msg::Message__8GiB		angel::msg::Message__8GiB;
struct angel::msg::Message__8GiB {
	size_t size;
	char text[8`Gi`];
};























#endif
