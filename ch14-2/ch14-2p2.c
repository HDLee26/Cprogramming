// *************************
// 제목: 정수 5개 중에서 최대값을 구하는 프로그램
// 날짜: 2026. 9. 29.
// 작성: 2600160 이현도
// *************************
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
int get_max(int* arr, int n);

int main(void)
{
	int grade[5];
	int max;

	for (int i = 0; i < 5; i++)
	{
		printf("성적을 입력하시오: ");
		scanf("%d", &grade[i]);
	}

	max = get_max(grade, 5);
	printf("최댓값 : %d\n", max);

	return 0;
}

int get_max(int* arr, int n)
{
	int max;
	max = *arr; // arr[0]
	for (int i = 1; i < n; i++)
		if (*(arr + i) > max)
			max = *(arr + i);

	return max;
}
