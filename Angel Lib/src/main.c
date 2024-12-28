```
echo `You are compiling the version for Unit testing`;

alias `mem` is `angel::mem`;

alias `SafeString` is `angel::strings::SafeString`;
alias `str` is `angel::strings`;
```

#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include<stddef.h>

#include<angel/memory.h>
#include<angel/strings.h>
#include <string.h>

#define KiB 1024L
#define TiB 1024L * 1024L * 1024L * 1024L

/*
 * Checks if the heap is empty at the beginning of the program
 */
bool unit_test001() {
	intmax_t A = angel::mem::getHeapSize();
	return A == 0;
}

angel::mem::MemoryChunk _chunk001;
/*
 * Checks if the heap is incremented by 85 when we create memory chunk of 85
 */
bool unit_test002() {
	intmax_t A, B;
	
	A = angel::mem::getHeapSize();
	_chunk001 = angel::mem::allocate(85, "Placeholder Tag");
	B = angel::mem::getHeapSize();
	
	return (B-A) == 85;
}

/*
 * Checks (the obvious) that _chunk001 had been alocated successfully - which would have been the case if 001 succeeded.
 */
bool unit_test003() {
	return angel::mem::isSuccess(_chunk001);
}

/*
 * Attempts to allocate an insanely large chunk and 'hopefully' said allocation should fail
 */
bool unit_test004() {
	angel::mem::MemoryChunk a_chunk;
	
	a_chunk = angel::mem::allocate(
		/*
		 * Allocation of 1 TiB of memory should fail on most (reasonable) systems
		 */
		TiB, 
		"Placeholder Tag"
	);
	return !angel::mem::isSuccess(a_chunk);
}

/*
 * Tests 1000 heap allocations of a KiB and then 1000 deallocations of the prior chunks
 * Also checks that memory returns to normal after the deallocations
 */
bool unit_test005() {
	angel::mem::MemoryChunk chunks[1000];
	intmax_t A, B, C;
	uint16_t i;
	
	A = angel::mem::getHeapSize();
	
	for(i = 0; i<1000; i++) {
		chunks[i] = angel::mem::allocate(KiB, "Placeholder Tag");
		if(!angel::mem::isSuccess(chunks[i])){
			return false;
		}
	}
	
	B = angel::mem::getHeapSize();
	
	for(i = 0; i<1000; i++) {
		chunks[i]@angel::mem::free();
	}
	
	C = angel::mem::getHeapSize();
	
	return (A == C) && (B - A == 1000 * KiB);
	
}

/////////////////////////
/*
 * Takes "Hello" repeats 5* and sees if it became "HelloHelloHelloHelloHello"
 */
bool unit_test006() {
	char ____001[1024];
	`SafeString` a = `str`::new(
		1024,
		false,
		____001
	);
	strcpy(a.data, "Hello");
	
	a@`str`::repeat(5);
	
	return strcmp("HelloHelloHelloHelloHello", a.data) == 0;
}

/*
 * Like 006 but uses the INIT_SAFE_STRING macro
 */
bool unit_test007() {
	
	`str`::INIT_SAFE_STRING(
		a,
		1024,
		"Hello"
	);
	
	a@`str`::repeat(5);
	
	return strcmp("HelloHelloHelloHelloHello", a.data) == 0;
}

/////////////////////////

void runUnitTests() {
	printf("Check of SIZE_MAX required for TEST 004\n");
	printf("Required Size    %16lX\n", TiB);
	printf("Max Size         %16lX\n", SIZE_MAX);
	if(SIZE_MAX > TiB) {
		printf("Tests should run fine.\n");
	}else{
		printf("Houston we have a problem!\n");
	}
	
	printf("\n");
	printf("Unit Tests for Angel Lib\n");
	printf("#angel::mem#\n");
	printf("TEST 001 : %s\n", unit_test001() ? "SUCCESS" : "FAILURE");
	printf("TEST 002 : %s\n", unit_test002() ? "SUCCESS" : "FAILURE");
	printf("TEST 003 : %s\n", unit_test003() ? "SUCCESS" : "FAILURE");
	printf("TEST 004 : %s\n", unit_test004() ? "SUCCESS" : "FAILURE");
	printf("TEST 005 : %s\n", unit_test005() ? "SUCCESS" : "FAILURE");
	
	printf("\n");
	printf("#angel::strings#\n");
	printf("TEST 006 : %s\n", unit_test006() ? "SUCCESS" : "FAILURE");
	printf("TEST 007 : %s\n", unit_test007() ? "SUCCESS" : "FAILURE");
}

void __test() {
	
}

int main() {
	runUnitTests();
	//__test();
	return 0;
}


