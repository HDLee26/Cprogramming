# 자료형
## 정수형 자료형의 크기
```c
#include <stdio.h>

int main(void)
{
    char num1 = 1, num2 = 2, res1 = 0; // 1 byte
    short num3 = 300, num4 = 400, res2 = 0; // 2 bytes
    long long num5 = 1000, num6 = 2000, res3 = 0;

    printf("size of num1 & num2: %zu, %zu\n", sizeof(num1), sizeof(num2));  // 1, 1
    printf("size of num3 & num4: %zu, %zu\n", sizeof(num3), sizeof(num4));  // 2, 2
    printf("size of num5 & num6: %zu, %zu\n", sizeof(num5), sizeof(num6));  // 8, 8
    printf("size of char add: %zu\n", sizeof(num1 + num2));    // 4
    printf("size of short add: %zu\n", sizeof(num3 + num4));   // 4
    printf("size of long long add: %zu\n", sizeof(num5 + num6)); // 8
    putchar('\n');

    res1 = num1 + num2;
    res2 = num3 + num4;
    res3 = num5 + num6;
    printf("size of res1 & res2 & res3: %zu, %zu, %zu\n", sizeof(res1), sizeof(res2), sizeof(res3));  //1, 2, 8
    //연산 결과를 저장하면 다시 1, 2 bytes로 돌아감. 애초에 res1, res2를 char, short로 선언했으니까.

    return 0;
}
```
- 15행 16행 CPU가 연산하기에 가장 적합한 데이터의 크기가 int형이기 때문에 int보다 작은 것들 연산시에는 자동으로 int형으로 바뀌며 이를 정수의 승격이라고 한다.
- 연산을 자주하는 경우에는 int형으로 선언하는 것이 좋고, 메모리 공간을 매우 아낄 때는 char형 short형 이용.

## 실수형 자료형의 크기
```c
#include <stdio.h>

int main(void)
{
    float fnum1 = 3.14, fnum2 = 6.28;
    double dnum1 = 1.4142, dnum2 = 2.8284;

    printf("size of float: %zu\n", sizeof(fnum1));     // 4
    printf("size of double: %zu\n", sizeof(dnum1));    // 8
    printf("size of float add: %zu\n", sizeof(fnum1 + fnum1));   // 4
    printf("size of double add: %zu\n", sizeof(dnum1 + dnum2));  // 8
    printf("size of float & double add: %zu\n", sizeof(fnum1 + dnum1));   // 8
    // float형 변수와 double형 변수를 연산하면 float형 변수는 double형으로 자동 형 변환된다. 
    
    return 0;
}
```
- 실수는 가장 중요한 요소가 '정밀도'임. 그래서 보편적으로 double을 씀.

## 문자를 위한 자료형
```c
#include <stdio.h>

int main(void)
{
    char ch1 = 'A', ch2 = 65; // 'A'의 아스키 코드 값이 65이다. 즉 ch1 == ch2
    int ch3 = 'Z', ch4 = 90; // 'Z'의 아스키 코드 값이 90이다. 즉 ch3 == ch4

    printf("%c\t %d\n", ch1, ch1);
    printf("%c\t %d\n", ch2, ch2);
    printf("%c\t %d\n", ch3, ch3);
    printf("%c\t %d\n", ch4, ch4);
    // %c로는 문자가, %d로는 아스키코드값이 출력됨.
    
    return 0;
}
```
- 결국 문자도 정수로 저장되므로 자료형은 char, int 둘 다 쓸 수 있지만 그냥 char형 씀. 어차피 모든 아스키코드가 1 byte로 충분히 표현 가능하기 때문이고 대부분의 경우에 문자를 가지고 연산할 일이 없다.
- char가 문자의 표현을 위한 자료형이기 때문에 '문자형'이라고도 한지만 엄밀히 '정수형'이다. 다시 말하지만 문자도 정수로 저장하기 때문이다.

## 리터럴 상수 (literal)
## 정수의 승격
## 강제 형 변환 (casting 연산)
