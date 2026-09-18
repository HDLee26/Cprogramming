# 실습과제1
- 아래의 변수들이 그림처럼 메모리에 할당될 때 표의 빈칸을 채우시오.
  
```c
char ch = 'A';
int in = 10;
double db = 3.4;
```

<table style="border-collapse: collapse; text-align: center;">
  <tr>
    <th style="border: 1px solid black;">주소</th>
    <th style="border: 1px solid black;">100</th>
    <th style="border: 1px solid black;">101</th>
    <th style="border: 1px solid black;">102</th>
    <th style="border: 1px solid black;">103</th>
    <th style="border: 1px solid black;">104</th>
    <th style="border: 1px solid black;">105</th>
    <th style="border: 1px solid black;">106</th>
    <th style="border: 1px solid black;">107</th>
    <th style="border: 1px solid black;">108</th>
    <th style="border: 1px solid black;">109</th>
    <th style="border: 1px solid black;">110</th>
    <th style="border: 1px solid black;">111</th>
    <th style="border: 1px solid black;">112</th>
  </tr>

  <tr>
    <th style="border: 1px solid black;">메모리</th>
    <td style="border: 1px solid black;">ch</td>
    <td colspan="4" style="border: 1px solid black; vertical-align: middle;">in</td>
    <td colspan="8" style="border: 1px solid black; vertical-align: middle;">db</td>
  </tr>
</table>

|수식|결과값|결과값의 자료형|
|:----:|:---:|:-------:|
|&ch|100|char*|
|&in|101|int*|
|&db|105|double*|
|*&ch|A|char|
|*&in|10|int|
|*&db|3.4|double|

---

# 실습과제 2 코드 설명
- 변수 이름을 사용하지 않고 포인터를 이용하여 값을 출력하라

```c
#include <stdio.h>
```
- 헤더파일 stdio.h을 포함하라
```c
int main(void)
```
- 메인함수 시작
```c
int a = -100;
```
- int형 변수 a를 선언하고 -100으로 초기화
```c
char b = 'A';
```
- char형 변수 b를 선언하고 A로 초기화
```c
double c = 3.14;
```
- doublue형 변수 c를 선언하고 3.14로 초기화
```c
int* pa = &a;
```
- 변수 a를 가리키도록 int*형 포인터 pa 선언 및 초기화
```c
char* pb = &b;
```
- 변수 b를 가리키도록 char*형 포인터 pb 선언 및 초기화
```c
double* pc = &c;
```
- 변수 c를 가리키도록 double*형 포인터 pc 선언 및 초기화
```c
printf("int형 변수 a의 값은: %d\n", *pa);
```
- 변수 a의 값을 포인터와 간접참조 연산자를 통해 출력
```c
printf("char형 변수 b의 값은: %c\n", *pb);
```
- 변수 b의 값을 포인터와 간접참조 연산자를 통해 출력
```c
printf("double형 변수 c의 값은: %lf\n", *pc);
```
- 변수 c의 값을 포인터와 간접참조 연산자를 통해 출력
```c
return 0;
```
- 0을 반환하고 main함수 정상 종료

## 실행결과
<img width="318" height="102" alt="image" src="https://github.com/user-attachments/assets/0827d7ab-14af-4be5-bb9e-4b3678f6c6cc" />

---

# 실습과제 3
~~~c
#include <stdio.h>

int main(void)
{
  int* ptr = (int*)125; // 1번
  *ptr = 10;
  printf("%d\n", *ptr);
  return 0;
}
~~~
- 위 코드의 1번에서 강제 형변환을 사용한 이유를 설명하라.\
  그냥 정수 125의 자료형은 int이므로 포인터변수와 자료형을 맞춰주려면 int*로 형변환을 해줘야 함.
- 위 코드를 실행하면 에러가 발생하여 중단된다. 이유를 설명하라.\
  위 코드는 포인터변수 ptr을 선언하고 주소로 125번지를 가리키게한 후, 간접참조 연산자로 125번지에 10이라는 정수 값을 저장한 것이다. 그러나 애초에 메모리는 OS가 관리하는 것이고, 125번지에 어떤 데이터가 있는지 어떻게 사용하고 있는지 알 수 없는데 사용자가 임의로 값을 저장하는 것은 위험함.

---

# 실습과제 4 코드 설명

