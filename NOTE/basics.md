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
## 비교연산
```c
#include <stdio.h>

int main(void)
{
    int num1 = 10;
    int num2 = 12;
    int res1, res2, res3, res4;

    //조건이 참이면 1을, 거짓이면 0을 반환한다.
    //C언어는 0이 아닌 모든 값을 참으로 간주하지만, 1이 참을 의미하는 대표적인 값이다.
    res1 = (num1 == num2); // 0 (false)
    res2 = (num1 != num2); // 1 (true)
    res3 = (num1 <= num2); // 1 (true)
    res4 = (num1 > num2); // 0 (false)

    printf("result1: %d\n", res1);
    printf("result2: %d\n", res2);
    printf("result3: %d\n", res3);
    printf("result4: %d\n", res4);

    return 0;
}
```
