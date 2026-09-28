// ************************
// 제목 : swap 함수를 만들어 세 정수 교환
// 날짜 : 2026년 9월 22일
// 작성 : 2600160 이현도
// ************************

#define _CRT_SECURE_NO_WARNINGS // 보안오류방지
#pragma warning(disable:6031)  // 리턴값관련 경고 방지

#include <stdio.h>

void swap(int*, int*, int*);

int main(void)
{
	int x, y, z;

	// 입력부
	printf("정수 x를 입력하시오: ");
	scanf("%d", &x);
	printf("정수 y를 입력하시오: ");
	scanf("%d", &y);
	printf("정수 z를 입력하시오: ");
	scanf("%d", &z);

	// swap 전후 비교
	printf("swap함수 호출 전 x = %d, y = %d, z = %d\n", x, y, z);
	swap(&x, &y, &z);
	printf("swap함수 호출 후 x = %d, y = %d, z = %d\n", x, y, z);

	return 0;
}

void swap(int* px, int* py, int* pz)
{
	int tmp;
	tmp = *px;
	*px = *py;
	*py = *pz;
	*pz = tmp;
}
