// ***************************
// 제목 : 배열명을 이용한 포인터 표현
// 날짜 : 2026. 09. 16
// 작성 : 2600160 이현도 
// ***************************

#define _CRT_SECURE_NO_WARNINGS // VS scanf 함수 보안 경고 방지용
#pragma warning(disable:6031)   // 리턴값 관련 경고 방지용
#include <stdio.h>

int main(void)
{
	int grade[5];
	int sum = 0, i;
	double average;

	for (i = 0; i < 5; i++)
	{
		printf("성적을 입력하시오: ");
		scanf("%d", (grade + i));
	}

	for (i = 0; i < 5; i++)
		sum += *(grade + i);

	average = sum / 5.0;
	printf("성적 평균 = %lf\n", average);

	return 0;
}
