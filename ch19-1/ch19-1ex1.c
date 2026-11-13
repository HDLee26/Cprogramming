// 함수의 일부기능을 외부의 함수들 중에서 선택하여 구현
#define _CRT_SECURE_NO_WARNINGS	
#pragma warning(disable:6031)
#include <stdio.h>

void input_data(int* arr, size_t len);  // int arr[]
int big(int a, int b);
int small(int a, int b);
int get_value(int* arr, size_t len, int (*fp)(int, int));

int main(void)
{
	int arr[5] = { 0 };
	int max, min;
	size_t len = sizeof(arr) / sizeof(arr[0]);

	input_data(arr, len);
	max = get_value(arr, len, big);   
	min = get_value(arr, len, small); 
	printf("최대값: %d, 최소값: %d\n", max, min);

	return 0;
}
void input_data(int* arr, size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		printf("정수 입력(%d번째): ", i + 1);
		scanf("%d", &arr[i]);     // arr + i
	}
}
int get_value(int* arr, size_t len, int (*fp)(int, int))
{
	int tmp = arr[0];   // *arr 

	for (int i = 1; i < len; i++)
		if (fp(tmp, arr[i]))  // 함수포인터로 함수 호출
			tmp = arr[i];     // *(arr + i)

	return tmp;
}
// get_value에서 함수 호출하는 문장이 if문 안에 있으니 논리값 반환해야함.
// b가 더 작으면 참, b로 tmp 갱신
int small(int a, int b)
{
	return a > b;
}
// b가 더 크면 참, b로 tmp 갱신
int big(int a, int b)
{
	return a < b;
}
