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
for (int i = 0; i < 5; i++){
  printf("성적을 입력하시오: ");
  scanf("%d", &grade[i]);
  }
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
### 실행결과
<img width="285" height="160" alt="image" src="https://github.com/user-attachments/assets/20dca238-f8ab-40d1-8389-f6ad5d1c9e4f" />

---

# 실습과제 3
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
void get_data(int* param, int len);
```
- 입력 받은 데이터를 배열에 저장하는 함수 get_data 선언
```c
int main(void)
```
- main함수 시작
```c
int data[5] = { 0 };
```
- 데이터 5개를 저장할 정수형 배열 data 선언
```c
int len = sizeof(data) / sizeof(data[0]);
```
- 배열의 요소의 개수를 구하여 변수 len에 저장
```c
get_data(data, len);
```
- get_data 함수 호출하고 배열명 data와 길이 len을 인자로 넘김
```c
for (int i = 0; i < len; i++)
  printf("%d번째 data: %d\n", i + 1, data[i]);
```
- 배열 data에 저장된 값을 차례대로 출력하는 루프
```c
return 0;
```
- 0을 반환하고 main함수 정상 종료
```c
void get_data(int* arr, int len)
```
- 함수 get_data 정의 시작
```c
for (int i = 0; i < len; i++){
  printf("%d번째 data를 입력하시오: ", i+1);
  scanf("%d", arr + i);
}
```
- 키보드로 입력한 값을 배열에 저장하기 위한 루프문\
배열 data에 저장하기 위해 배열명으로 주소를 가져오고 인덱스 번호를 하나씩 키워 차례대로 저장하고 있다

### 실행결과
<img width="251" height="221" alt="image" src="https://github.com/user-attachments/assets/bdba0afe-1270-421b-bb1b-0f2b0eacaa07" />

---

# 실습과제 4

### 실행결과
<img width="275" height="99" alt="image" src="https://github.com/user-attachments/assets/37072c75-f870-4d2f-91c4-f4b26d81badf" />



