// ***************************
// 제목 : 두 행렬의 합 - 함수
// 날짜 : 2026년 10월 1일
// 작성 : 2600160 이현도
// ***************************

#include <stdio.h>

void addMatrix(int*, int*, int*); // int matrix[][2]
void printMatrix(int*);

int main(void)
{
	int m1[2][2] = { {2,4}, {5, -5} };
	int m2[2][2] = { {-2, 3}, {0, -5} };
	int msum[2][2] = { 0 };

	addMatrix(m1, m2, msum);
	printMatrix(msum);

	return 0;
}
// 두 행렬을 더하는 함수
void addMatrix(int* m1, int* m2, int* msum)
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			*(msum + j + 2 * i) = *(m1 + j + 2 * i) + *(m2 + j + 2 * i);
}

// 행렬을 출력하는 함수
void printMatrix(int* m)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2;j++)
			printf("%d\t", *(m + j + 2 * i));
		printf("\n");
	}
}
