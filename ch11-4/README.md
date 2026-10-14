# 실습과제 1
- B, 'B', "B" 의 차이를 설명하라
  - B : 식별자. 변수명이나 상수명 등.
  - 'B' : 문자 상수. 단일 문자 하나. 보통 char형 변수에 저장하고 1바이트 차지. 서식지정자 %c.\
    다만 C의 문자 상수 타입은 int임. 문자를 저장할 때 정수로 바꾸어 저장하기 때문에.
  - "B" : 문자열 리터럴. 끝에 자동으로 '\0' 포함되어 2바이트 차지. 서식지정자 %s.

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
	char ch;
```
- 문자 저장할 변수 ch 선언
```c
	while (1)
```
- 무한루프 구성 시작
```c
		printf("문자 입력: ");
		scanf(" %c", &ch);
		printf("입력한 문자 : %c | 아스키코드 : %d\n", ch, ch);
```
- 입력 받은 문자와 그 아스키코드를 출력
- 입력 버퍼에 남은 공백 문자를 무시하기 위해 scanf에 " %c"로 작성

```c
		if ((ch == 'q') || (ch == 'Q'))
			printf("프로그램 종료\n");
			break;
```
- 무한루프 탈출 조건. 입력 받은 문자가 q 혹은 Q이면 탈출.
```c
	return 0;
```
- 0을 반환하고 main 함수 정상 종료

### 실행결과
<img width="307" height="297" alt="image" src="https://github.com/user-attachments/assets/92ba31be-a8ff-4d87-8b15-232e32e5cad6" />

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
#include <string.h>
```
- string.h 헤더파일을 포함하라
```c
int main(void)
```
- main 함수 시작
```c
	char str[101] ="";
```
- 입력할 문자열 저장할 char형 배열 선언
```c
	printf("소문자 문자열 입력(100글자): ");
	scanf("%100s", str);
```
- 100글자 입력 받아 저장 (띄어쓰기 없어야 함)
```c
	for (int i = 0; i < strlen(str); i++)
		str[i] -= 32;
```
- 소문자 -> 대문자 변환. 아스키코드상 소대문자가 32칸 차이 남을 이용.
```c
	printf("변환결과: %s\n", str);
```
- 결과 출력
```c
	return 0;
```
- 0을 반환하고 main 함수 정상 종료

### 실행결과
<img width="355" height="83" alt="image" src="https://github.com/user-attachments/assets/84276dc6-32d6-4075-8f3e-4aa361c689af" />

