#include <stdio.h>

int main(void)
{
	int a = 100, b = 200;
	int sum;
	int* pa = &a;
	int* pb = &b;
	int* psum = &sum;

	*psum = *pa + *pb;
	printf("두 정수의 합: %d\n", *psum);

	return 0;
}