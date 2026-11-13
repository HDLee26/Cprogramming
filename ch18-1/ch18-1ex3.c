// 이차원 배열을 인자로 넘길 때 열의 개수를 고정하고 싶지 않다면 현재 배움 상태로는 3가지 방법이 있음.
// 1. 1차원 배열로 일단 저장하고 논리적으로는 2차원 배열로 생각하기 -> ch16장으로
// 2. 일단 열의 개수를 적당히 크게 주고 그 안에서 노는 방법. 메모리 낭비가 있음.
// 3. 가변 길이 배열(VLA) 이용. MSVC는 미지원.
// 따라서 여기선 2번 방법을 설명.

#define MAX_COL 10

#include <stdio.h>

void fill(int (*ptr)[MAX_COL], size_t row, size_t col);
void print(int (*ptr)[MAX_COL], size_t row, size_t col);

int main(void)
{
	int arr[3][MAX_COL] = { 0 };
	size_t row = sizeof(arr) / sizeof(arr[0]);
	size_t use_col = 4;

	fill(arr, row, use_col);
	print(arr, row, use_col);

	return 0;
}

void fill(int (*ptr)[MAX_COL], size_t row, size_t col)
{
	int c = 1;
	for (size_t i = 0; i < row; i++)
		for (size_t j = 0; j < col; j++)
			ptr[i][j] = c++;   // *(*(ptr + i) + j)

}

void print(int (*ptr)[MAX_COL], size_t row, size_t col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
			printf("%d\t", ptr[i][j]);
		putchar('\n');
	}
}
// 한 행에 10칸을 배정하지만 실제로 쓰는 건 use_col로 넘긴 개수만큼만 사용함.
// 나머지 6칸은 낭비되는 공간이 됨.
// 이 방식은 최대 크기를 지정할 근거가 있을 때 쓰고 
// 좀더 자유로운 방식은 동적할당을 배워야 함.

