// *************************
//  제목 : 교재 문제 풀이 - 주소 교환 p.264
//  날짜 : 2026년 9월 9일
//  작성 : 2600160 이현도
// *************************

#include <stdio.h>

int main(void)
{
	int num1 = 100, num2 = 200;
	int* ptr1 = &num1;
	int* ptr2 = &num2;
	int* tmp;

	*ptr1 += 150;
	*ptr2 -= 150;

	printf("가리키는 대상 교환 전\n");
	printf("ptr1이 가리키는 주소: %p | 들어있는 값: %d\n", (void*)ptr1, *ptr1);
	printf("ptr2이 가리키는 주소: %p | 들어있는 값: %d\n", (void*)ptr2, *ptr2);

	tmp = ptr1;
	ptr1 = ptr2;
	ptr2 = tmp;

	printf("가리키는 대상 교환 후\n");
	printf("ptr1이 가리키는 주소: %p | 들어있는 값: %d\n", (void*)ptr1, *ptr1);
	printf("ptr2이 가리키는 주소: %p | 들어있는 값: %d\n", (void*)ptr2, *ptr2);

	return 0;
}

