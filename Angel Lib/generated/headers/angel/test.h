//PREFIX SECTION
//PREFIX SECTION
//PREFIX SECTION
//PREFIX SECTION


/**
 * @file message.h
 * @brief 'Message' system for Angel Lib
 *
 * Provides a variable length manner to store strings in C on the stack
 */

#ifndef ANGEL__MESSAGE_H
#define ANGEL__MESSAGE_H

typedef struct angel_0msg_0Message		angel_0msg_0Message;
struct angel_0msg_0Message {
	size_t size;
	char text[128]; //Default is 128B
};

typedef struct angel_0msg_0Message__128B		angel_0msg_0Message__128B;
struct angel_0msg_0Message__128B {
	size_t size;
	char text[128];
};

typedef struct angel_0msg_0Message__256B		angel_0msg_0Message__256B;
struct angel_0msg_0Message__256B {
	size_t size;
	char text[256];
};

typedef struct angel_0msg_0Message__512B		angel_0msg_0Message__512B;
struct angel_0msg_0Message__512B {
	size_t size;
	char text[512];
};

typedef struct angel_0msg_0Message__1KiB		angel_0msg_0Message__1KiB;
struct angel_0msg_0Message__1KiB {
	size_t size;
	char text[1 * 1024];
};

typedef struct angel_0msg_0Message__2KiB		angel_0msg_0Message__2KiB;
struct angel_0msg_0Message__2KiB {
	size_t size;
	char text[2 * 1024];
};

typedef struct angel_0msg_0Message__4KiB		angel_0msg_0Message__4KiB;
struct angel_0msg_0Message__4KiB {
	size_t size;
	char text[4 * 1024];
};

typedef struct angel_0msg_0Message__8KiB		angel_0msg_0Message__8KiB;
struct angel_0msg_0Message__8KiB {
	size_t size;
	char text[8 * 1024];
};

typedef struct angel_0msg_0Message__16KiB		angel_0msg_0Message__16KiB;
struct angel_0msg_0Message__16KiB {
	size_t size;
	char text[16 * 1024];
};

typedef struct angel_0msg_0Message__32KiB		angel_0msg_0Message__32KiB;
struct angel_0msg_0Message__32KiB {
	size_t size;
	char text[32 * 1024];
};

typedef struct angel_0msg_0Message__64KiB		angel_0msg_0Message__64KiB;
struct angel_0msg_0Message__64KiB {
	size_t size;
	char text[64 * 1024];
};

typedef struct angel_0msg_0Message__128KiB		angel_0msg_0Message__128KiB;
struct angel_0msg_0Message__128KiB {
	size_t size;
	char text[128 * 1024];
};

typedef struct angel_0msg_0Message__256KiB		angel_0msg_0Message__256KiB;
struct angel_0msg_0Message__256KiB {
	size_t size;
	char text[256 * 1024];
};

typedef struct angel_0msg_0Message__512KiB		angel_0msg_0Message__512KiB;
struct angel_0msg_0Message__512KiB {
	size_t size;
	char text[512 * 1024];
};

typedef struct angel_0msg_0Message__1MiB		angel_0msg_0Message__1MiB;
struct angel_0msg_0Message__1MiB {
	size_t size;
	char text[1 * 1024 * 1024];
};

typedef struct angel_0msg_0Message__2MiB		angel_0msg_0Message__2MiB;
struct angel_0msg_0Message__2MiB {
	size_t size;
	char text[2 * 1024 * 1024];
};

typedef struct angel_0msg_0Message__4MiB		angel_0msg_0Message__4MiB;
struct angel_0msg_0Message__4MiB {
	size_t size;
	char text[4 * 1024 * 1024];
};

typedef struct angel_0msg_0Message__8MiB		angel_0msg_0Message__8MiB;
struct angel_0msg_0Message__8MiB {
	size_t size;
	char text[8 * 1024 * 1024];
};

typedef struct angel_0msg_0Message__16MiB		angel_0msg_0Message__16MiB;
struct angel_0msg_0Message__16MiB {
	size_t size;
	char text[16 * 1024 * 1024];
};

typedef struct angel_0msg_0Message__32MiB		angel_0msg_0Message__32MiB;
struct angel_0msg_0Message__32MiB {
	size_t size;
	char text[32 * 1024 * 1024];
};

typedef struct angel_0msg_0Message__64MiB		angel_0msg_0Message__64MiB;
struct angel_0msg_0Message__64MiB {
	size_t size;
	char text[64 * 1024 * 1024];
};

typedef struct angel_0msg_0Message__128MiB		angel_0msg_0Message__128MiB;
struct angel_0msg_0Message__128MiB {
	size_t size;
	char text[128 * 1024 * 1024];
};

typedef struct angel_0msg_0Message__258MiB		angel_0msg_0Message__258MiB;
struct angel_0msg_0Message__258MiB {
	size_t size;
	char text[258 * 1024 * 1024];
};

typedef struct angel_0msg_0Message__512MiB		angel_0msg_0Message__512MiB;
struct angel_0msg_0Message__512MiB {
	size_t size;
	char text[512 * 1024 * 1024];
};

typedef struct angel_0msg_0Message__1GiB		angel_0msg_0Message__1GiB;
struct angel_0msg_0Message__1GiB {
	size_t size;
	char text[1 * 1024 * 1024 * 1024];
};

typedef struct angel_0msg_0Message__2GiB		angel_0msg_0Message__2GiB;
struct angel_0msg_0Message__2GiB {
	size_t size;
	char text[2 * 1024 * 1024 * 1024];
};

typedef struct angel_0msg_0Message__3GiB		angel_0msg_0Message__3GiB;
struct angel_0msg_0Message__3GiB {
	size_t size;
	char text[3 * 1024 * 1024 * 1024];
};

typedef struct angel_0msg_0Message__4GiB		angel_0msg_0Message__4GiB;
struct angel_0msg_0Message__4GiB {
	size_t size;
	char text[4 * 1024 * 1024 * 1024];
};

typedef struct angel_0msg_0Message__5GiB		angel_0msg_0Message__5GiB;
struct angel_0msg_0Message__5GiB {
	size_t size;
	char text[5 * 1024 * 1024 * 1024];
};

typedef struct angel_0msg_0Message__6GiB		angel_0msg_0Message__6GiB;
struct angel_0msg_0Message__6GiB {
	size_t size;
	char text[6 * 1024 * 1024 * 1024];
};

typedef struct angel_0msg_0Message__7GiB		angel_0msg_0Message__7GiB;
struct angel_0msg_0Message__7GiB {
	size_t size;
	char text[7 * 1024 * 1024 * 1024];
};

typedef struct angel_0msg_0Message__8GiB		angel_0msg_0Message__8GiB;
struct angel_0msg_0Message__8GiB {
	size_t size;
	char text[8 * 1024 * 1024 * 1024];
};























#endif

