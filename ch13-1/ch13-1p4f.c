
#define _CRT_SECURE_NO_WARNINGS // 보안오류방지
#pragma warning(disable:6031)  // 리턴값관련 경고 방지

#include <stdio.h>

// 입력
void input(double* ptr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d번째 값 입력: ", i + 1);
		scanf("%lf", ptr++);
	}
}
// 2.0 덧셈
void addTwo(double* ptr, int len)
{
	for (int i = 0; i < len; i++)
		*ptr++ += 2.0;
}
// 출력
void output(double* ptr, int len)
{
	for (int i = 0; i < len; i++)
		printf("arr[%d] = %f\n", i, *(ptr++));
}

int main(void)
{
	double arr[5] = { 0 };
	int len = sizeof(arr) / sizeof(arr[0]);

	input(arr, len);
	addTwo(arr, len);
	output(arr, len);

	return 0;
}
