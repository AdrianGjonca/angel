//PREFIX SECTION
//PREFIX SECTION
//PREFIX SECTION
//PREFIX SECTION
//PREFIX SECTION
//PREFIX SECTION
//PREFIX SECTION
//PREFIX SECTION


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
	intmax_t A = angel_0memory_0getHeapSize();
	return A == 0;
}

angel_0memory_0MemoryChunk _chunk001;
/*
 * Checks if the heap is incremented by 85 when we create memory chunk of 85
 */
bool unit_test002() {
	intmax_t A, B;
	
	A = angel_0memory_0getHeapSize();
	_chunk001 = angel_0memory_0allocate(85, "Placeholder Tag");
	B = angel_0memory_0getHeapSize();
	
	return (B-A) == 85;
}

/*
 * Checks (the obvious) that _chunk001 had been alocated successfully - which would have been the case if 001 succeeded.
 */
bool unit_test003() {
	return angel_0memory_0isSuccess(_chunk001);
}

/*
 * Attempts to allocate an insanely large chunk and 'hopefully' said allocation should fail
 */
bool unit_test004() {
	angel_0memory_0MemoryChunk a_chunk;
	
	a_chunk = angel_0memory_0allocate(
		/*
		 * Allocation of 1 TiB of memory should fail on most (reasonable) systems
		 */
		TiB, 
		"Placeholder Tag"
	);
	return !angel_0memory_0isSuccess(a_chunk);
}

/*
 * Tests 1000 heap allocations of a KiB and then 1000 deallocations of the prior chunks
 * Also checks that memory returns to normal after the deallocations
 */
bool unit_test005() {
	angel_0memory_0MemoryChunk chunks[1000];
	intmax_t A, B, C;
	uint16_t i;
	
	A = angel_0memory_0getHeapSize();
	
	for(i = 0; i<1000; i++) {
		chunks[i] = angel_0memory_0allocate(KiB, "Placeholder Tag");
		if(!angel_0memory_0isSuccess(chunks[i])){
			return false;
		}
	}
	
	B = angel_0memory_0getHeapSize();
	
	for(i = 0; i<1000; i++) {
		angel_0memory_0free(chunks[i]);
	}
	
	C = angel_0memory_0getHeapSize();
	
	return (A == C) && (B - A == 1000 * KiB);
	
}

/////////////////////////
/*
 * Takes "Hello" repeats 5* and sees if it became "HelloHelloHelloHelloHello"
 */
bool unit_test006() {
	char ____001[1024];
	angel_0strings_0SafeString a = angel_0strings_0new(
		1024,
		false,
		____001
	);
	strcpy(a.data, "Hello");
	
	angel_0strings_0repeat(&a,5);
	
	return strcmp("HelloHelloHelloHelloHello", a.data) == 0;
}

/*
 * Like 006 but uses the INIT_SAFE_STRING macro
 */
bool unit_test007() {
	
	angel_0strings_0INIT_SAFE_STRING(
		a,
		1024,
		"Hello"
	);
	
	angel_0strings_0repeat(&a,5);
	
	return strcmp("HelloHelloHelloHelloHello", a.data) == 0;
}

/*
 * Checks if getLength works
 */
bool unit_test008() {
	
	angel_0strings_0INIT_SAFE_STRING(
		a,
		1024,
		"Hello"
	);
	
	return angel_0strings_0getLength(&a) == 5;
}

/*
 * Checks if getMaxLength works
 */
bool unit_test009() {
	
	angel_0strings_0INIT_SAFE_STRING(
		a,
		1024,
		"Hello"
	);
	
	return angel_0strings_0getMaxLength(&a) == 1024;
}

/*
 * Checks if isFailure works on creation of SafeString
 */
bool unit_test010() {
	
	angel_0strings_0INIT_SAFE_STRING(
		a,
		1024,
		"Hello"
	);
	
	//Improper way
	angel_0strings_0SafeString b = angel_0strings_0new( 
		5,
		false, 
		"Hello"
	);
	
	//Proper way
	angel_0strings_0INIT_SAFE_STRING(
		c,
		5,
		"Hello"
	);
	
	printf("	test 010 : a (should be 0) => %d\n", angel_0strings_0isFailure(&a));
	printf("	test 010 : b (should be 1) => %d\n", angel_0strings_0isFailure(&b));
	printf("	test 010 : c (should be 1) => %d\n", angel_0strings_0isFailure(&c));
	
	return (! angel_0strings_0isFailure(&a)) && angel_0strings_0isFailure(&b) && angel_0strings_0isFailure(&c);
}

/*
 * Checks if isFailure works on buffer overflow from ...repeat(n)
 */
bool unit_test011() {
	angel_0strings_0INIT_SAFE_STRING(
		a,
		5,
		"a"
	);
	
	angel_0strings_0repeat(&a,66);
	
	//printf("%d\n", a.failed);
	//return a.failed;
	return angel_0strings_0isFailure(&a);
}

/*
 * Checks if isOnHeap returns false for stack SafeString
 */
bool unit_test012() {
	angel_0strings_0INIT_SAFE_STRING(
		a,
		5,
		"a"
	);
	
	return !( angel_0strings_0isOnHeap(&a) );
}

/*
 * Checks if isOnStack returns true for stack SafeString
 */
bool unit_test013() {
	angel_0strings_0INIT_SAFE_STRING(
		a,
		5,
		"a"
	);
	
	return angel_0strings_0isOnStack(&a);
}

/*
 * Checks if ...repeat(0) returns ""
 */
bool unit_test014() {
	
	angel_0strings_0INIT_SAFE_STRING(
		a,
		1024,
		"Hello"
	);
	
	angel_0strings_0repeat(&a,0);
	
	return strcmp("", angel_0strings_0data(&a)) == 0;
}

/*
 * Checks if ...repeat(1) returns "Hello" when given "Hello"
 */
bool unit_test015() {
	
	angel_0strings_0INIT_SAFE_STRING(
		a,
		1024,
		"Hello"
	);
	
	angel_0strings_0repeat(&a,1);
	
	return strcmp("Hello", angel_0strings_0data(&a) ) == 0;
}

/*
 * Checks if ...data() accesses like .data
 * "Hello" == "Hello"
 */ 
bool unit_test016() {
	angel_0strings_0INIT_SAFE_STRING(
		a,
		1024,
		"Hello"
	);
	
	return strcmp("Hello", angel_0strings_0data(&a) ) == 0;
}

/*
 * Checks if ...data() accesses like .data
 * "" == ""
 */ 
bool unit_test017() {
	angel_0strings_0INIT_SAFE_STRING(
		a,
		1024,
		""
	);
	
	return strcmp("", angel_0strings_0data(&a) ) == 0;
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



