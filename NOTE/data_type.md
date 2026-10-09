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
- 서식 문자에 관해서 scanf는 입력받은 값을 실제 변수 메모리 주소에 넣어야 하므로 정확한 자료형을 알아야 함.
따라서 서식문자가 float는 %f double은 %lf로 따로 존재함.
하지만 printf는 디폴트로 %f가 double임. 실수 리터럴이 double이듯이.
따라서 float가 전달되면 자동으로 double로 승격해서 출력하고, 이를 '기본 인자 승격'이라고 함.

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
- 리터럴 상수란 변경이 불가능한 데이터. 이름이 없는 상수이다. ```int add = 30 + 40;```에서 30과 40이 리터럴이다. 30과 40도 메모리 공간 어딘가에 저장되어있음. (연산 결과인 70은 add란 변수에 저장되어있다.)
```c
#include <stdio.h>

int main(void)
{
    //리터럴 상수의 디폴트 자료형 확인
    printf("literal int size: %zd\n", sizeof(7));        // 4 정수는 기본적으로 int
    printf("literal double size: %zd\n", sizeof(3.141)); // 8 실수는 기본적으로 double
    printf("literal char size: %zd\n", sizeof('A'));     // 4 문자도 기본적으로 int형임에 주의. 

    // 만약 리터럴도 자료형을 지정해주고 싶으면 접미사를 붙인다
    unsigned int num1 = 12004U;
    long long num2 = 9203382LL;
    float num3 = 3.134F;

    return 0;
}
```
- 8행 문자도 기본적으로 int형으로 저장된다. 왜냐하면 'A'의 아스키코드값이 65로 정수이고, 컴퓨터는 그 정수 아스키코드값을 저장하기 때문이다.

## 자동 형 변환에 따른 데이터 손실
```c
int inum = 3.141592; // 3 소수점 이하 손실
char ch = 129; // -127 상위 바이트의 손실
```
- 129 = 00000000 00000000 00000000 10000001 (4 B) 인데
char형으로 저장하면 상위 3 바이트가 잘리고 10000001로만 저장됨. 
unsinged char형이면 0 ~ 255까지 표현 가능하니까 129로 잘 저장되는데 
char형이면 가장 첫 비트(MSB)가 1이니까 음수로 저장됨. 
2의 보수를 취해 크기를 구해보면 -127임을 알 수 있음.

## 자동 형 변환
- int보다 작은 크기의 정수형 데이터는 int로 형 변환 돼 연산이 진행됨을 이미 안다. (정수의 승격)
- 그외에도 피연산자의 자료형이 일치하지 않으면 다음의 방향으로 자동 형 변환이 일어난다. 
모두 데이터의 손실을 최소화하는 방향으로 일어남.
```
int -> long -> long long -> float -> double -> long double
```

## 강제 형 변환
```c
int num1 = 3, num2 = 4;
double res1, res2;
res1 = num1 / num2;         // 0.0 정수의 나눗셈이라 몫만 저장됨. 
res2 = (double)num1 / num2; // 0.75 강제 형변환으로 실수의 나눗셈으로 바꿔줌.
```
-  연산 시의 자동 형 변환 덕분에 
```double num2 = num1 / 3.0;``` 이런 식으로 해도 알아서 잘 되지만
```double num2 = (double)num1 / 3.0;``` 의식적으로 casting연산자를 이용해 명시적으로 보여주는 것이 좋다.
