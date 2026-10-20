#include <stdio.h>

void add(int (*m1)[2], int (*m2)[2], int (*msum)[2], int rows);
void output(int (*arr)[2], int rows);

int main(void)
{
    int m1[2][2] = { {2, 4}, {5, -5} };
    int m2[2][2] = { {-2, 3}, {0, -5} };
    int msum[2][2] = { 0 };

    // 행의 개수 계산
    int rows = sizeof(m1) / sizeof(m1[0]);

    add(m1, m2, msum, rows);
    output(msum, rows);

    return 0;
}

// 행렬의 합을 구하는 함수
void add(int (*m1)[2], int (*m2)[2], int (*msum)[2], int rows)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < 2; j++)
            *(*(msum + i) + j) = *(*(m1 + i) + j) + *(*(m2 + i) + j);
}

// 결과를 출력하는 함수
void output(int (*arr)[2], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 2; j++)
            printf("%d\t", *(*(arr + i) + j));
        printf("\n");
    }
}
