// ***************************
// 제목 : 두 행렬의 합
// 날짜 : 2026년 10월 1일
// 작성 : 2600160 이현도
// ***************************

#include <stdio.h>

int main(void)
{
	int m1[2][2] = { {2,4}, {5, -5} };
	int m2[2][2] = { {-2, 3}, {0, -5} };
	int msum[2][2] = { 0 };

	// 행렬의 합
	for (int i = 0; i<2; i++)
		for (int j = 0; j < 2;j++)
			msum[i][j] = m1[i][j] + m2[i][j];
		
	// 결과 출력
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2;j++)
			printf("%d\t", msum[i][j]);
		printf("\n");
	}
		
	return 0;
}
