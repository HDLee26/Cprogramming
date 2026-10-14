// ***************************
// 제목 : 배열 접근 방식 5개
// 날짜 : 2026. 09. 16
// 작성 : 2600160 이현도 
// ***************************

#define _CRT_SECURE_NO_WARNINGS // 보안오류방지
#pragma warning(disable:6031)  // 리턴값관련 경고 방지

#include <stdio.h>

int main(void)
{
	double arr[5] = { 0 };
	double* ptr = arr; // &arr[0]
	int len = sizeof(arr) / sizeof(arr[0]);
	int i;

	// 입력
	for (i = 0; i < len; i++)
	{
		printf("%d번째 값 입력: ", i + 1);
		scanf("%lf", ptr + i);
	}

	// 방식 5개
	for (i = 0; i < len; i++)
		arr[i] += 2.0;
	for (i = 0; i < len; i++)
		*(arr + i) += 2.0;
	for (i = 0; i < len; i++)
		*(ptr + i) += 2.0;
	for (i = 0; i < len; i++)
		ptr[i] += 2.0;
	for (i = 0; i < len; i++)
		*ptr++ += 2.0;

	// 출력
	for (i = 0; i < len; i++)
		printf("arr[%d] = %f\n", i, arr[i]);

	return 0;
}
