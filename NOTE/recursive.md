### 피보나치 수열
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int Fibonacci(int n);

int main(void)
{
    int input;

    printf("피보나치 수열을 출력함.\n");
    printf("몇 번째 항까지 계산?(양의 정수 입력): ");
    scanf("%d", &input);

    for (int i = 1; i <= input; i++)
        printf("%d ", Fibonacci(i));

    return 0;
}

int Fibonacci(int n)
{
    // 1번째 항은 0
    if (n == 1)
        return 0;

    // 2번째 항은 1
    if (n == 2)
        return 1;

    // n번째 항 = (n-1)번째 항 + (n-2)번째 항
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
```
- 다음 정의를 그대로 옮긴 것이다
$F(1) = 0$\
$F(2) = 1$\
$F(n) = F(n-1) + F(n-2)$\
