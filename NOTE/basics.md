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
## 논리연산
```c
#include <stdio.h>

int main(void)
{
    int num1 = 10, num2 = 12;
    int res1, res2, res3, res4;

    res1 = (num1 == 10 && num2 == 12); // 1 (true), 논리AND
    res2 = (num1 < 12 || num2 > 12); // 1 (true), 논리OR
    res3 = (!num1); // 0 (false), 논리NOT
    // 앞서 했듯이 C에서는 0을 제외한 모든 값을 참으로 간주하는데
    // !을 붙여 참이 아니다 했으므로 0을 반환함.
    res4 = (!res3); // 1 (true)

    printf("result1: %d\n", res1);
    printf("result2: %d\n", res2);
    printf("result3: %d\n", res3);
    printf("result4: %d\n", res4);

    return 0;
}
```
## 비트연산
```c
#include <stdio.h>
//비트 연산자는 bit 단위로 연산을 한다
//밑의 모든 출력은 서식문자가 %d이므로 모두 10진수 정수 형태 
int main(void)
{
    int n1 = 15; // 00000000 00000000 00000000 00001111
    int n2 = 20; // 00000000 00000000 00000000 00010100
    int res, shift1, shift2, shift3, shiftNeg;

    //and 연산
    res = n1 & n2;
    printf("and 연산의 결과: %d\n", res); // 생 략 00000100 = 4

    //or연산 
    res = n1 | n2;
    printf("or 연산의 결과: %d\n", res); // 생 략 00011111 = 31

    //xor 연산 
    res = n1 ^ n2;
    printf("xor 연산의 결과: %d\n", res); // 생 략00011011 = 27

    //not 연산 - 모든 비트 반전 
    res = ~n1;
    printf("not 연산의 결과: %d\n", res); // 11111111 11111111 11111111 11110000 = -16 
    // 2의 보수를 취해 음의 정수의 크기를 확인할 수 있음. 

    //<< 쉬프트 연산 - 모든 비트를 왼쪽으로 이동시킴 x2^n
    shift1 = n1 << 1; // 00000000 00000000 00000000 00011110 = 30
    shift2 = n1 << 2; // 00000000 00000000 00000000 00111100 = 60
    shift3 = n1 << 3; // 00000000 00000000 00000000 01111000 = 120
    printf("<< 연산의 결과: %d, %d, %d\n", shift1, shift2, shift3); 

    //>> 쉬프트 연산 - 모든 비트를 오른쪽으로 이동시킴 x2^(-n) 의 몫 (비트연산은 정수만 받음)
    shift1 = n2 >> 1; // 00000000 00000000 00000000 00001010 = 10
    shift2 = n2 >> 2; // 00000000 00000000 00000000 00000101 = 5
    shift3 = n2 >> 3; // 00000000 00000000 00000000 00000010 = 2 --넘어가는 비트는 잘림.
    printf(">> 연산의 결과: %d, %d, %d\n", shift1, shift2, shift3); 

    //>> 쉬프트 연산 -- 음의 정수를 옮기는 경우 
    shiftNeg = -16 >> 2; // shiftNeg = -4
    printf("%d\n", shiftNeg); // 11111111 11111111 11111111 11111100 = -4 --2의 보수를 취해 크기를 확인하자 
    
    /*
    음의 정수를 >> 연산하는 경우 컴퓨터 환경(CPU, 컴파일러 등)에 따라 
    빈자리를 0으로 채우거나 1로 채운다.
    VS에선 1로 채우고 그래야 사람이 생각하는 대로 연산이 됨.
    호환성이 필요한 경우 >>연산은 지양해야 함.
     */

    return 0;
}
```
## 연산 우선순위와 결합방향
<img width="572" height="616" alt="image" src="https://github.com/user-attachments/assets/0d23ffc0-40fa-43d5-ac61-3f69092774d7" />

---
