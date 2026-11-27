# 실습과제 1
- 구조체가 필요한 이유를 설명하라. 
  - 자료형이 서로 다르지만 관련이 있는 변수들을 묶어서 다루기 위함.
- 배열과 구조체의 공통점/차이점 
  - **공통점** 여러 데이터를 하나의 이름으로 묶어 다룰 수 있음. 
  -  **차이점** 배열은 자료형이 같은 변수를 모아야 하고, 구조체는 자료형이 다른 변수를 모을 수 있음.
- 기본 자료형과 구조체의 차이를 설명하라 
  - 기본 자료형은 미리 정의되어 있어 바로 변수를 선언할 수 있지만, 구조체는 사용자가 자료형을 정의한 후 구조체 변수를 선언하여 사용한다. 
  - 두 경우 모두 변수의 저장 공간은 변수를 선언할 때 확보된다. 
- 구조체 정의와 구조체 변수 선언의 의미를 각각 설명하라
  - 서로 관련된 여러 변수를 멤버로 묶어 새로운 사용자 정의 자료형을 만드는 것.
  - 정의한 구조체 자료형의 변수를 선언하여, 멤버들의 값을 저장할 메모리 공간을 확보하는 것.
 
---

# 실습과제 2
```c
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
```
- 문자열 관련 함수들의 보안 경고 무시용 & 리턴값 관련 경고 방지용
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
```
- stdio.h, string.h, stdlib.h 파일을 포함하라
```c
struct student {
	int id;
	char name[21];
	char address[31];
  }
```
- 학번, 이름, 주소 저정할 수 있는 구조체 정의 
```c
int main(void)
```
- main 함수 시작
```c
	struct student std;
```
- 구조체 변수 선언
```c
	char input[10];
```
- 학번을 문자열로 임시 저장할 배열
```c
	fputs("학번을 입력하시오: ", stdout);
	if (fgets(input, sizeof(input), stdin) != NULL)
		input[strcspn(input, "\n")] = '\0';
	std.id = strtol(input, NULL, 10);
```
- 학번을 문자열로 입력 받고 '\n' 지운 뒤 strtol 함수로 정수로 변환. (숫자만 올바르게 입력 받는다고 가정함.)
```c
	fputs("이름을 입력하시오: ", stdout);
	if (fgets(std.name, sizeof(std.name), stdin) != NULL)
		std.name[strcspn(std.name, "\n")] = '\0';
```
- 이름 입력 받아 멤버 변수에 저장
```c
	fputs("주소를 입력하시오: ", stdout);
	if (fgets(std.address, sizeof(std.address), stdin) != NULL)
		std.address[strcspn(std.address, "\n")] = '\0';
```
- 주소 입력 받아 멤버 변수에 저장
```c
	printf("학번: %d\n", std.id);
	printf("이름: %s\n", std.name);
	printf("주소: %s\n", std.address);
```
- 결과 출력
```c
	return 0;
```
- 0을 반환하고 main 함수 정상 종료

### 실행결과
<img width="301" height="157" alt="image" src="https://github.com/user-attachments/assets/932ca92b-e6f6-4f71-9044-df4f3677e356" />

# 실습과제 3
```c
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
```
- 문자열 관련 함수들의 보안 경고 무시용 & 리턴값 관련 경고 방지용
```c
#include <stdio.h>
#include <string.h>
```
- stdio.h, string.h 파일을 포함하라
```c
struct car {
	char model[11];
	char plate_number[21];
	int mileage;
	}
```
- 모델명, 번호판, 주행 거리 저장할 구조체 정의
```c
int main(void)
```
- main 함수 시작
```c
	struct car c1 = { '\0', '\0', 0 };
```
- 구조체 변수 선언
```c
	fputs("모델을 입력하시오: ", stdout);
	scanf(" %s", c1.model);
	fputs("번호판을 입력하시오: ", stdout);
	scanf(" %s", c1.plate_number);
	fputs("주행거리를 입력하시오: ", stdout);
	scanf("%d", &c1.mileage);
```
- 모델명, 차량 번호, 주행 거리 입력 받고 각각의 멤버 변수에 저장
```c
	printf("모델: %s\n", c1.model);
	printf("번호판: %s\n", c1.plate_number);
	printf("주행거리: %d km\n", c1.mileage);
```
- 결과 출력
```c
	return 0;
```
- 0을 반환하고 main 함수 정상 종료

### 실행결과 
<img width="268" height="140" alt="image" src="https://github.com/user-attachments/assets/a969810f-5440-431d-b812-2dc78f2b782b" />


