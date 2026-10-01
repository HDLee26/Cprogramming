#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>

int main(void)
{
	int m[3][3] = { 0 };
	//int m[3][3] = { {-5, 2, 35}, {-20, 5, 100}, {-75, 5, -25} };
	int max;
	int row, col;

	// 3x3 행렬에 입력
	for (int i = 0; i < 3; i++)               
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d행 %d열 원소 입력: ", i+1, j+1);
			scanf("%d", &m[i][j]);
		}
	}

	// 최댓값과 위치 찾기
	max = m[0][0]; // 최댓값을 첫번째 값으로 임시 저장
	row = 1, col = 1; // 위치를 1행 1열로 임시 저장
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (m[i][j] > max)
			{
				max = m[i][j];
				row = i+1;
				col = j+1;
			}
		}
	}

	// 출력
	printf("최댓값: %d\n", max);
	printf("위치: %d행 %d열\n", row, col);

	return 0;
}
