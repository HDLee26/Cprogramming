#define _CRT_SECURE_NO_WARNINGS // 보안오류방지
#pragma warning(disable:6031)  // 리턴값관련 경고 방지

#include <stdio.h>

int main(void)
{
	double arr[5] = { 0 };
	double* ptr = NULL;
	int len = sizeof(arr) / sizeof(arr[0]);
	int i;

	// 입력
	ptr = arr;
	for (i = 0; i < len; i++)
	{
		printf("%d번째 값 입력: ", i+1);
		scanf("%lf", ptr++);
	}

	// 각 요소 2.0 증가
	ptr = arr;
	for (i = 0; i < len; i++)
	{
		*ptr += 2.0;
		ptr++;
	}

	// 출력
	ptr = arr;
	for (i = 0; i < len; i++)
		printf("arr[%d] = %f\n", i, arr[i]);

	return 0;
}