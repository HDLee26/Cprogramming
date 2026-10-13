// *************************
//  제목 : 교재 문제 풀이 p.264
//  날짜 : 2026년 9월 9일
//  작성 : 2600160 이현도
// *************************

#include <stdio.h>
void swap(int*, int*);
int main(void)
{
	int num1 = 100, num2 = 200;
	int* ptr1 = &num1;
	int* ptr2 = &num2;

	*ptr1 += 150;
	*ptr2 -= 150;

	swap(ptr1, ptr2);

	printf("ptr1이 가리키는 변수에 저장된 값: %d\n", *ptr1);
	printf("ptr2이 가리키는 변수에 저장된 값: %d\n", *ptr2);

	return 0;
}

void swap(int* ptr1, int* ptr2)
{
	int* tmp;
	tmp = ptr1;
	ptr1 = ptr2;
	ptr2 = tmp;
}
