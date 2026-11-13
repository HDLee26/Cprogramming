# 문제 1
```c
#include <stdio.h>
```
- stdio.h 헤더파일을 포함하라
```c
void prn_str(const char** ptr, size_t len);
void prn_menu(const char* (*ptr)[3], size_t row);
```
- 1차원 포인터 배열의 문자열 출력하는 함수 선언
- 2차원 포인터 배열의 문자열 출력하는 함수 선언
```c
int main(void)
```
- main 함수 시작
```c
	const char* vegetable[4] = {
		"Onion", "Potato", "Pumpkin", "Lettuce" };
```
- 1차원 문자열 배열 (포인터 배열)
```c
	const char* menu[][3] = {
		{ "김밥", "라면", "떡볶이" },
		{ "커피", "주스", "녹차" } }
```
- 2차원 문자열 배열 (포인터 배열)
```c
	size_t len = sizeof(vegetable) / sizeof(vegetable[0]);
	size_t row = sizeof(menu) / sizeof(menu[0]);
```
- 배열의 원소 개수, 행의 개수 구함
```c
	prn_str(vegetable, len);
	prn_menu(menu, row);
```
- 함수 호출
```c
	return 0;
```
- 0을 반환하고 main 함수 정상 종료
```c
void prn_str(const char** ptr, size_t len)
```
- 1차원 포인터 배열의 문자열 출력하는 함수 정의
```c
	puts("채소 출력");
```
- 안내문 출력
```c
	for (size_t i = 0; i < len; i++)
		printf("%s\t", ptr[i]);
```
- 배열의 원소인 문자열 순서대로 출력
```c
	putchar('\n');
```
- 서식 꾸미기
```c
void prn_menu(const char* (*ptr)[3], size_t row)
```
- 2차원 포인터 배열의 문자열 출력하는 함수
```c
	puts("메뉴 출력");
```
- 안내문 출력
```c
	for (size_t i = 0; i < row; i++)
  {
		for (size_t j = 0; j < 3; j++)
			printf("%s\t", ptr[i][j]);
		putchar('\n');
  }
```
-  배열의 원소인 문자열 순서대로 출력

### 실행결과
<img width="289" height="134" alt="image" src="https://github.com/user-attachments/assets/2223110a-5434-4943-ae96-83bfa68b0e99" />

---



