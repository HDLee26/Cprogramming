#include <stdio.h>
int get_max(int** , int );
int main(void)
{
	int num1 = 50, num2 = 20, num3 = 30;
	int* ptrarr[3] = { &num1, &num2, &num3 }; // 주소가 3개
	int max;

	max = get_max(ptrarr, 3); // 첫 번째 원소의 주소, int**
	printf("최댓값: %d\n", max);

	return 0;
}
int get_max(int** arr, int len)
{
	int tmp = *arr[0]; // -> *&num1
	for (int i = 1; i < len; i++)
		if (tmp < *(arr[i])) // -> *&num2 *&num3
			tmp = *(arr[i]);

	return tmp;
}
