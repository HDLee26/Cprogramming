// 함수의 일부기능을 외부의 함수들 중에서 선택하여 구현
#include <stdio.h>
int big(int a, int b);
int small(int a, int b);
int get_value(int* a, int (*fp)(int, int));
int main(void)
{
	int arr[5] = { -1, 2, 10, 5,7 };
	int res;

	res = get_value(arr, big);   // 함수명을 인자로 전달
	printf("결과값은: %d\n", res);
	res = get_value(arr, small); // 함수명을 인자로 전달
	printf("결과값은: %d\n", res);
	return 0;
}

int get_value(int* a, int (*fp)(int, int))
{
	int res = a[0];

	for (int i = 1; i < 5; i++)
		if (fp(res, a[i]))  // 함수포인터로 함수 호출
			res = a[i]; 
	return res;
}
int big(int a, int b)
{
	if (a > b) return 1;
	else return 0;
}
int small(int a, int b)
{
	if (a > b) return 0;
	else return 1;
}
