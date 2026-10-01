#include <stdio.h>

int main(void)
{
	int m1[2][2] = { {2,4}, {5, -5} };
	int m2[2][2] = { {-2, 3}, {0, -5} };
	int msum[2][2] = { 0 };

	int* pm1 = &m1[0][0];
	int* pm2 = &m2[0][0];
	int* pmsum = &msum[0][0];

	// 행렬의 합
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2;j++)
			*(pmsum + j + 2 * i) = *(pm1 + j + 2 * i) + *(pm2 + j + 2 * i);

	// 결과 출력
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2;j++)
			printf("%d\t", *(pmsum + j + 2 * i));
		printf("\n");
	}

	return 0;
}
