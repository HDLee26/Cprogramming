// *************************
//  제목 : 간접참조연산자의 이용2
//  날짜 : 2026년 9월 9일
//  작성 : 2600160 이현도
// *************************

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
