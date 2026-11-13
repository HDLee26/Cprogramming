// qsort 함수는 퀵 정렬 알고리즘으로 배열을 정렬하는 데에 쓰는 함수
// 정렬을 위해 사용할 비교 함수를 만들어서 인자로 넘겨야 함.
// 함수포인터를 이용해 인자로 넘기는 것이지 실행하는 게 아니므로 () 붙이지 않음.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillRandInt(int* arr, size_t len);
void print(int* arr, size_t len);
int ascending(const void* a, const void* b);
int descending(const void* a, const void* b);

int main(void) 
{
	int data[10] = { 0 };
	size_t len = sizeof(data) / sizeof(data[0]);
	size_t i;

	// 현재 시간으로 난수 시드 설정 
	srand((unsigned int)time(NULL));
	// 0이상 99이하의 정수 난수 저장
	fillRandInt(data, len);

	puts("정렬 전");
	print(data, len);
	putchar('\n');

	puts("오름차순 정렬");
	qsort(data, len, sizeof(data[0]), ascending);
	print(data, len);
	putchar('\n');

	puts("내림차순 정렬");
	qsort(data, len, sizeof(data[0]), descending);
	print(data, len);
	putchar('\n');

	return 0;
}
// 작은 값이 앞에 오도록 비교
int ascending(const void* a, const void* b)
{
	int x = *(const int*)a;
	int y = *(const int*)b;

	return x - y;  // (x > y) - (x < y)
}
// 큰 값이 앞에 오도록 비교
int descending(const void* a, const void* b)
{
	int x = *(const int*)a;
	int y = *(const int*)b;

	return y - x;  // (x < y) - (x > y)
}
void print(int* arr, size_t len)
{
	size_t i;
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
}
void fillRandInt(int* arr, size_t len)
{
	size_t i; 
	for (i = 0; i < len; i++)
		arr[i] = rand() % 100; // 0이상 99이하 정수 난수
}

/*
void qsort(
	void* base,     // 정렬할 배열의 시작 주소
	size_t count,   // 정렬할 원소의 개수
	size_t size,    // 원소 하나의 크기
	int (*compare)(const void*, const void*) // 비교 함수
);
// 정렬한 결과는 base에 직접 저장함.
// 비교함수의 반환값은 {
	음수 : 첫번째 원소가 앞에 와야 함
	0   : 두 원소의 정렬 순위가 같음
	양수 : 첫 번째 원소가 뒤에 와야 함
	} 을 의미함.
// 직접 정수끼리 뺄셈하는 것은 int의 범위를 넘을 수 있어서 지양해야 함.
*/
