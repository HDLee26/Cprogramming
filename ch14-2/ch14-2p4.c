// *************************
// 제목: 실수를 입력 받아 정수부와 소수부로 나누어 출력하는 프로그램
// 날짜: 2026. 9. 29.
// 작성: 2600160 이현도
// *************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
void get_wnpdec(double, int*, double*);

int main(void)
{
	double input;
	int wnp;
	double dec;

	printf("실수를 입력하시오: ");
	scanf("%lf", &input);

	get_wnpdec(input, &wnp, &dec);

	printf("정수부: %d\n", wnp);
	printf("소수부: %lf\n", dec);

	return 0;
}

void get_wnpdec(double num, int* wnp, double* dec)
{
	*wnp = (int)num;
	*dec = num - (int)num;
}
