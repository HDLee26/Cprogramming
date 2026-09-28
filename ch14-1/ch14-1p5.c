// ***************************
// 제목 : 값을 이용한 호출과 포인터를 이용한 호출 비교
// 날짜 : 2026년 9월 22일
// 작성 : 2600160 이현도
// ***************************

#define _CRT_SECURE_NO_WARNINGS // 보안오류방지
#pragma warning(disable:6031)  // 리턴값관련 경고 방지

#include <stdio.h>

void SquareByValue(int);
void SquareByPointer(int*);

int main(void)
{
	int num;
	printf("정수를 입력하시오: ");
	scanf("%d", &num);

	SquareByValue(num);
	printf("값에 의한 호출로 바꾼 값: %d\n", num);
	SquareByPointer(&num);
	printf("주소에 의한 호출로 바꾼 값: %d\n", num);

	return 0;
}

void SquareByValue(int value)
{
	value += 100;
}
void SquareByPointer(int* ptr)
{
	*ptr += 100;
}
