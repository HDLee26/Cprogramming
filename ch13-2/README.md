# 실습과제 1
- C언어에서 문자를 메모리에 저장하는 방식에 대하여 설명하라\
  문자를 아스키코드를 통해 숫자로 바꾸어 저장함.
- NULL 문자의 용도를 설명하라\
  문자열의 끝을 알려주기 위함.
- 메모리에 저장된 문자열의 끝을 찾는 방법을 설명하라\
  NULL 문자를 찾는다.
- strlen()함수를 사용하지 않고 문자열의 길이를 구하는 알고리즘을 설명하라\
  문자열의 첫 번째 문자부터 \0까지 문자(char)의 개수를 구한다.

---

# 실습과제 2
```c
#define _CRT_SECURE_NO_WARNINGS
```
- VS scanf 함수 보안 경보 방지용
```c
#pragma warning(disable:6031)
```
- 리턴값 관련 경고 방지용
```c
#include <stdio.h>
```
- stdio.h 헤더파일을 포함하라
```c
int main(void)
```
- main함수 시작
```c
char s[50] = { 0 };
```
- 문자열을 저장하기 위한 문자형 배열 선언 및 NULL 문자로 초기화
```c
int i, cnt;
```
- 정수형 변수 i와 cnt 선언
```c
printf("문자열을 입력하시오: ");
```

```c
scanf("%s", s);
```
- 입력된 문자열을 배열 s에 저장. 배열명 s가 주소이므로 &연산은 불필요
```c
// 문자열 길이 구하기
```
```c
i = 0, cnt = 0;
```
```c
while (s[i] != '\0')
```
- 문자형 배열 s에 저장된 문자가 
```c
i++;
```
- NULL 문자가 아닌 동안
```c
cnt++;
```
- cnt를 증가시켜 문자열의 길이를 구함
```c
for (int i = 0; i < cnt; i++)
```
- 문자를 각각 출력하기 위한 반복문
```c
printf("%d번재 문자 %c\n", i+1, s[i]);
```
- 입력받은 문자열을 각 문자별로 출력
```c
return 0;
```
- 0을 반환하고 main함수 정상 종료

## 실행결과
<img width="263" height="183" alt="image" src="https://github.com/user-attachments/assets/11592ba6-aa99-437f-a6d2-8204fe0c38ad" />

---

