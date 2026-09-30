# 실습과제 1
- 주소에 의한 호출을 사용해야 하는 3가지 경우를 설명하라 
  - 다른 함수에 선언된 지역 변수의 값을 변경하고 싶을 경우
  - 함수 호출 시 인자로 배열을 넘기고 싶을 때
  - 함수의 반환값으로 2개 이상을 반환하고 싶을 때
- 최댓값을 구하는 알고리즘을 설명하라\
  값이 여러 개 있을 때 일단 최댓값 변수에 첫 번째 값 넣고 차례대로 다른 값들이랑 비교하면서 큰 값으로 바로 최댓값을 갱신하면 됨.
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
int get_max(int* arr, int n);
```
- 최댓값 구하는 함수 get_max 선언
```c
int main(void)
```
- main함수 시작
```c
int grade[5];
```
- 성적 5개를 저장할 정수형 배열 grade 선언 
```c
int max;
```
- 최댓값 저장할 변수 max 선언
```c
for (int i = 0; i < 5; i++)
  printf("성적을 입력하시오: ");
  scanf("%d", &grade[i]);
```
- 성적 5개 입력 받는 루프문
```c
max = get_max(grade, 5);
```
- get_max 함수 호출하고 리턴값을 max에 저장
```c
printf("최댓값 : %d\n", max);
```
- 최댓값 출력
```c
return 0;
```
- 0을 반환하고 main함수 정상 종료
```c
int get_max(int* arr, int n)
```
- get_max 함수 정의 시작
```c
int max;
```
- 최댓값을 저장할 변수 max 선언
```c
max = *arr;
```
- 우선 배열의 가장 첫번째 값을 최댓값으로 저장
```c
for (int i = 1; i < n; i++)
  if (*(arr + i) > max)
    max = *(arr + i);
```
- max에 저장된 값을 배열의 두 번째 요소의 값부터 차례대로 비교하며 큰 수를 max에 갱신해 저장
```c
return max;
```
- 구한 최댓값을 리턴

---

