# 연산
## 증감연산
```c
#include <stdio.h>

int main(void)
{
    int num1 = 12, num2 = 12;

    printf("num1: %d\n", num1); //12
    printf("num1++: %d\n", num1++); //12, 선 출력 후 1 더함 (후위 증가)
    printf("num1: %d\n\n", num1); //13

    printf("num2: %d\n", num2); //12
    printf("++num2: %d\n", ++num2); //13, 선 1 더하고 후 출력 (전위 증가)
    printf("num2: %d\n\n", num2); //13

    int num3 = 10;
    int num4 = (num3--) + 2; //num4 = 12 
    // 후위 연산은 나머지 식의 모든 연산이 끝난 후 실행
    // 즉 후위 연산은 괄호의 영향을 받지 않는다.
    int num5 = 10;
    int num6 = (--num5) + 2; //num 5 = 11

    printf("num3: %d\n", num3); //9
    printf("num4: %d\n", num4); //12
    printf("num5: %d\n", num5); //9
    printf("num6: %d\n", num6); //11

    return 0;
}
```
