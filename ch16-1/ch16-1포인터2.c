// 2차원 배열을 1차원 배열로 만들어서 쓰는 방법
#include <stdio.h>

void addMatrix(int* m1, int* m2, int* msum);
void printMatrix(int* m); // int m[]

int main(void)
{
    // 2행 2열의 데이터를 일차원 배열에 순서대로 저장
    int m1[4] = { 2, 4, 5, -5 };
    int m2[4] = { -2, 3, 0, -5 };
    int msum[4] = { 0 };

    addMatrix(m1, m2, msum);
    printMatrix(msum);

    return 0;
}
void addMatrix(int* m1, int* m2, int* msum)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            msum[i * 2 + j] = m1[i * 2 + j] + m2[i * 2 + j];
            // *(msum + 2*i +j) = *(m1 + 2*i + j) + *(m2 + 2*i + j);
}

void printMatrix(int* m)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            printf("%d\t", m[i * 2 + j]);  // *(m + 2*i + j)

        putchar('\n');
    }
}
