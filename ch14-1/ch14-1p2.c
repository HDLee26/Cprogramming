// ************************
// 제목 : 포인터를 이용한 호출
// 날짜 : 2026년 9월 22일
// 작성 : 2600160 이현도
// ************************

#define _CRT_SECURE_NO_WARNINGS // 보안오류방지
#pragma warning(disable:6031)  // 리턴값관련 경고 방지

#include <stdio.h>
void add2(int * ptr);

int main(void)
{
	int number;
	printf("정수를 입력하세요: ");
	scanf("%d", &number);
	add2(&number);
	printf("2만큼 증가한 값: %d\n", number);
	return 0;
}
void add2(int * ptr)
{
	*ptr += 2;
}
