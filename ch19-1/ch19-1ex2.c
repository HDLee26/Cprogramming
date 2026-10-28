// qsort 함수는 퀵 정렬 알고리즘으로 배열을 정렬하는 데에 쓰는 함수
// 정렬을 위해 사용할 비교 함수를 만들어서 인자로 넘겨야 함.
#include <stdio.h>
#include <stdlib.h>
int compare1(const int* a, const int* b);
int compare2(const int* a, const int* b);

int main(void) 
{
	int data[10] = { 21, 10, 41, 33, 25, 17, 68, 27, 14, 29 };

	qsort(data, 10, sizeof(int), compare1); // 오름차순
	for (int i = 0; i < 10; i++) 
		printf("%d ", data[i]);
	putchar('\n');

	qsort(data, 10, sizeof(int), compare2); // 내림차순
	for (int i = 0; i < 10; i++) 
		printf("%d ", data[i]);

	return 0;
}
int compare1(const int* a, const int* b)
{
	return(*a - *b); // 오름차순
}
int compare2(const int* a, const int* b)
{
	return(*b - *a); // 내림차순
}
//gsgdar
