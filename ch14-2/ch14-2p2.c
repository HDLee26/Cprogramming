// *************************
// 제목: 정수 5개 중에서 최대값을 구하는 프로그램
// 날짜: 2026. 9. 29.
// 작성: 2600160 이현도
// *************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
void get_data(int* arr, int n);
int get_max(int* arr, int n);

int main(void)
{
	int grade[5];
	int max;
	int len = sizeof(grade) / sizeof(grade[0]);

	get_data(grade, len);
	max = get_max(grade, len);
	printf("최댓값 : %d\n", max);

	return 0;
}
void get_data(int* arr, int n) // int arr[], int n
{
	for (int i = 0; i < 5; i++)
	{
		printf("성적(%d)을 입력하시오: ", i+1);
		scanf("%d", arr + i); // &arr[i]
		//i가 1씩 커질 때마다 다음 값을 저장할 주소로 넘어감
	}
}
int get_max(int* arr, int n) // int arr[], int n
{
	int max;
	max = *arr; // arr[0]
	for (int i = 1; i < n; i++)
		if (*(arr + i) > max) // arr[i]
			max = *(arr + i);

	return max;
}

