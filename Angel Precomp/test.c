#include <stdio.h>

int abc::_123 = 5;

void test::test() {
	printf("I replaced all test:: shenannigans\n");
}

int main() {
	test::test();
	abc::_123 += 134;
	return 0;
}
