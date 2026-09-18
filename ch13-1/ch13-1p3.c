// ***************************
// 제목 : 배열명
// 날짜 : 2026. 09. 16
// 작성 : 2600160 이현도 
// ***************************

#include <stdio.h>

int main(void)
{
	int a[] = { 10, 20, 30 }, i, sum = 0;
	int* p = a;

	for (i = 0; i < 3; i++)
		sum += *p++;
	printf("sum : %d\n", sum);

	return 0;
}

/*
// 오류가 있는 코드
#include <stdio.h>

int main(void)
{
	int a[] = { 10, 20, 30 }, i, sum = 0;

	for (i = 0; i < 3; i++)
		sum += *a++;
	printf("sum : %d\n", sum);

	return 0;
}
*/
