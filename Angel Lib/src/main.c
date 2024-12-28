```
echo `You are compiling the version for Unit testing`;

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
#include <string.h>

#define KiB 1024L
#define TiB 1024L * 1024L * 1024L * 1024L

/*
 * Checks if the heap is empty at the beginning of the program
 */
bool unit_test001() {
	intmax_t A = `mem`::getHeapSize();
	return A == 0;
}

`MemoryChunk` _chunk001;
/*
 * Checks if the heap is incremented by 85 when we create memory chunk of 85
 */
bool unit_test002() {
	intmax_t A, B;
	
	A = `mem`::getHeapSize();
	_chunk001 = `mem`::allocate(85, "Placeholder Tag");
	B = `mem`::getHeapSize();
	
	return (B-A) == 85;
}

/*
 * Checks (the obvious) that _chunk001 had been alocated successfully - which would have been the case if 001 succeeded.
 */
bool unit_test003() {
	return `mem`::isSuccess(_chunk001);
}

/*
 * Attempts to allocate an insanely large chunk and 'hopefully' said allocation should fail
 */
bool unit_test004() {
	`MemoryChunk` a_chunk;
	
	a_chunk = `mem`::allocate(
		/*
		 * Allocation of 1 TiB of memory should fail on most (reasonable) systems
		 */
		TiB, 
		"Placeholder Tag"
	);
	return !`mem`::isSuccess(a_chunk);
}

/*
 * Tests 1000 heap allocations of a KiB and then 1000 deallocations of the prior chunks
 * Also checks that memory returns to normal after the deallocations
 */
bool unit_test005() {
	`MemoryChunk` chunks[1000];
	intmax_t A, B, C;
	uint16_t i;
	
	A = `mem`::getHeapSize();
	
	for(i = 0; i<1000; i++) {
		chunks[i] = `mem`::allocate(KiB, "Placeholder Tag");
		if(!`mem`::isSuccess(chunks[i])){
			return false;
		}
	}
	
	B = `mem`::getHeapSize();
	
	for(i = 0; i<1000; i++) {
		chunks[i]@`mem`::free();
	}
	
	C = `mem`::getHeapSize();
	
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
	
	&a@`str`::repeat(5);
	
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
	
	&a@`str`::repeat(5);
	
	return strcmp("HelloHelloHelloHelloHello", a.data) == 0;
}

/*
 * Checks if getLength works
 */
bool unit_test008() {
	
	`str`::INIT_SAFE_STRING(
		a,
		1024,
		"Hello"
	);
	
	return &a@`str`::getLength() == 5;
}

/*
 * Checks if getMaxLength works
 */
bool unit_test009() {
	
	`str`::INIT_SAFE_STRING(
		a,
		1024,
		"Hello"
	);
	
	return &a@`str`::getMaxLength() == 1024;
}

/*
 * Checks if isFailure works on creation of SafeString
 */
bool unit_test010() {
	
	`str`::INIT_SAFE_STRING(
		a,
		1024,
		"Hello"
	);
	
	//Improper way
	`SafeString` b = `str`::new( 
		5,
		false, 
		"Hello"
	);
	
	//Proper way
	`str`::INIT_SAFE_STRING(
		c,
		5,
		"Hello"
	);
	
	printf("	test 010 : a (should be 0) => %d\n", &a@`str`::isFailure());
	printf("	test 010 : b (should be 1) => %d\n", &b@`str`::isFailure());
	printf("	test 010 : c (should be 1) => %d\n", &c@`str`::isFailure());
	
	return (! &a@`str`::isFailure()) && &b@`str`::isFailure() && &c@`str`::isFailure();
}

/*
 * Checks if isFailure works on buffer overflow from ...repeat(n)
 */
bool unit_test011() {
	`str`::INIT_SAFE_STRING(
		a,
		5,
		"a"
	);
	
	&a@`str`::repeat(66);
	
	//printf("%d\n", a.failed);
	//return a.failed;
	return &a@`str`::isFailure();
}

/*
 * Checks if isOnHeap returns false for stack SafeString
 */
bool unit_test012() {
	`str`::INIT_SAFE_STRING(
		a,
		5,
		"a"
	);
	
	return !( &a@`str`::isOnHeap() );
}

/*
 * Checks if isOnStack returns true for stack SafeString
 */
bool unit_test013() {
	`str`::INIT_SAFE_STRING(
		a,
		5,
		"a"
	);
	
	return &a@`str`::isOnStack();
}

/*
 * Checks if ...repeat(0) returns ""
 */
bool unit_test014() {
	
	`str`::INIT_SAFE_STRING(
		a,
		1024,
		"Hello"
	);
	
	&a@`str`::repeat(0);
	
	return strcmp("", &a@`str`::data()) == 0;
}

/*
 * Checks if ...repeat(1) returns "Hello" when given "Hello"
 */
bool unit_test015() {
	
	`str`::INIT_SAFE_STRING(
		a,
		1024,
		"Hello"
	);
	
	&a@`str`::repeat(1);
	
	return strcmp("Hello", &a@`str`::data() ) == 0;
}

/*
 * Checks if ...data() accesses like .data
 * "Hello" == "Hello"
 */ 
bool unit_test016() {
	`str`::INIT_SAFE_STRING(
		a,
		1024,
		"Hello"
	);
	
	return strcmp("Hello", &a@`str`::data() ) == 0;
}

/*
 * Checks if ...data() accesses like .data
 * "" == ""
 */ 
bool unit_test017() {
	`str`::INIT_SAFE_STRING(
		a,
		1024,
		""
	);
	
	return strcmp("", &a@`str`::data() ) == 0;
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
	printf("TEST 008 : %s\n", unit_test008() ? "SUCCESS" : "FAILURE");
	printf("TEST 009 : %s\n", unit_test009() ? "SUCCESS" : "FAILURE");
	printf("TEST 010 : %s\n", unit_test010() ? "SUCCESS" : "FAILURE");
	printf("TEST 011 : %s\n", unit_test011() ? "SUCCESS" : "FAILURE");
	printf("TEST 012 : %s\n", unit_test012() ? "SUCCESS" : "FAILURE");
	printf("TEST 013 : %s\n", unit_test013() ? "SUCCESS" : "FAILURE");
	printf("TEST 014 : %s\n", unit_test014() ? "SUCCESS" : "FAILURE");
	printf("TEST 015 : %s\n", unit_test015() ? "SUCCESS" : "FAILURE");
	printf("TEST 016 : %s\n", unit_test016() ? "SUCCESS" : "FAILURE");
	printf("TEST 017 : %s\n", unit_test017() ? "SUCCESS" : "FAILURE");
}

void __test() {
	
}

int main() {
	runUnitTests();
	//__test();
	return 0;
}


