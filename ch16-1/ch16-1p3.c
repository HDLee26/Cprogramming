// ***************************
// 제목 : 3x3 행렬에서 최댓값과 그 위치를 찾는 프로그램
// 날짜 : 2026년 10월 1일
// 작성 : 2600160 이현도
// ***************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>

#define ROW 3
#define COL 3

void input(int matrix[][COL]);  // int (*matrix)[COL]
void getMaxIndex(int matrix[][COL], int* max, int* row, int* col); 

int main(void)
{
	int m[ROW][COL] = { 0 };
	int max;
	int mrow, mcol;
	
	input(m);
	getMaxIndex(m, &max, &mrow, &mcol);

	// 출력
	printf("최댓값: %d\n", max);
	printf("위치: %d행 %d열\n", mrow, mcol);

	return 0;
}
// 한 행마다 COL개의 정수를 입력 받는 함수
void input(int matrix[][COL]) // int (*matrix)[COL]
{
	for (int i = 0; i < ROW; i++)
	{
		printf("%d행 원소 %d개 입력: ", i + 1, COL);
		for (int j = 0; j < COL; j++)
			scanf("%d", &matrix[i][j]); // *(matrix + i) + j
	}
} 
// 최댓값과 위치 찾는 함수
void getMaxIndex(int matrix[][COL], int* max, int* row, int* col) // int (*matrix)[COL]
{
	// 최댓값을 첫번째 값으로 임시 저장
	*max = matrix[0][0];  // *(*(matrix + 0) + 0)
	// 위치를 1행 1열로 임시 저장
	*row = 1;
	*col = 1; 

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (matrix[i][j] > *max)  // *(*(matrix + i) + j) > *max
			{
				*max = matrix[i][j]; // *(*(matrix + i) + j)
				*row = i + 1;
				*col = j + 1;
			}
		}
	}

}
