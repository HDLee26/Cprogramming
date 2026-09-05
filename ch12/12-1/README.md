# 4번 문제 소스코드 설명
```
#include<stdio.h>
```
- 헤더파일 stdio.h을 포함하라
```
int main(void)
```
- 메인함수 시작
```
char a = 'A';
```
- char형 변수 a를 선언하고 A로 초기화
```
int b = 36;
```
- int형 변수 b를 선언하고 36으로 초기화
```
int b = 36;
```
- double형 변수 c를 선언하고 3.141592로 초기화
```
printf("char형 변수 a의 주소 : %p \n", &a);
```
- a의 주소를 출력
```
printf("int형 변수 b의 주소 : %p \n", &b);
```
- b의 주소를 출력
```
printf("double형 변수 c의 주소 : %p \n", &c);
```
- c의 주소를 출력
- ChatGPT에게 물어보니 주소를 출력할 때는 서식자로 %p를 써야한다고 함.
- 출력 결과값은 16진수임.
```
return 0;
```
- 0을 반환하고 메인함수 정상 종료

# 실행결과

<img width="718" height="191" alt="image" src="https://github.com/HDLee26/Cprogramming/Images/image.png" />

