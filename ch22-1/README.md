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

# 실습과제 4
```c
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
```
- 문자열 관련 함수들의 보안 경고 무시용 & 리턴값 관련 경고 방지용
```c
#include <stdio.h>
#include <stdlib.h>
```
- stdio.h, stdlib.h 파일을 포함하라
```c
typedef struct {
	double x;
	double y;
}dot2D;
```
- 구조체로 좌표 저장할 수 있는 사용자 자료형 정의
```c
void inputPoint2D(dot2D* inputDot);
void getRectangleInfo(dot2D ULDot, dot2D BRDot, double* w, double* h, double* area);
void printRectangleInfo(double w, double h, double area);
```
- 좌표 입력 받는 함수
- 두 좌표에서 사각형의 폭, 높이, 넓이 구하는 함수
- 결과 출력 함수
```c
int main(void)
```
- main 함수 시작
```c
	dot2D UpLeft;
	dot2D BottomRight;
	double width, height, area;
```
- 좌상단 좌표, 우하단 좌표, 폭, 높이, 넓이 저장할 변수들
```c
	fputs("좌측상단의 좌표 입력: ", stdout);
	inputPoint2D(&UpLeft);
	fputs("우측하단의 좌표 입력: ", stdout);
	inputPoint2D(&BottomRight);
```
- 좌표 입력 받아 실수로 바꿔 저장
- 멤버 변수에 접근해야 하므로 주소를 인자로 넘김
```c
	if ((UpLeft.x >= BottomRight.x) || (UpLeft.y <= BottomRight.y)) {
		puts("점의 위치가 잘못되었습니다.");
		return 0;
	}
```
- 좌표 위치가 올바른지 확인
```c
	else
		getRectangleInfo(UpLeft, BottomRight, &width, &height, &area);
```
- 폭, 높이, 넓이 구함.
- 멤버변수의 값만 필요하니까 그냥 변수로 넘김
```c
	printRectangleInfo(width, height, area);
```
- 결과 출력하는 함수 호출
```c
	return 0;
```
- 0을 반환하고 main 함수 정상 종료
```c
void inputPoint2D(dot2D *inputDot)
	char tmp[10] = { '\0' };
	char* end = NULL;
```
- 입력 받은 숫자를 임시 저장할 배열
- 숫자 변환이 끝난 위치를 기록할 포인터 변수
```c
	if (fgets(tmp, sizeof(tmp), stdin) != NULL) {
		inputDot->x = strtod(tmp, &end);   // (*inputDot).x
		inputDot->y = strtod(end, NULL);   // (*inputDot).y
	}
```
- fgets로 숫자 입력 받고 strtod로 실수로 변환
- ㄱ end는 변환이 끝난 위치(char*)를 가리켜야 하므로 인자로 넘겨야 하는 건 그 위치의 주소임(char**)
- ㄴ end 위치부터 읽기 시작하는데 공백 문자는 무시해줌
```c
void getRectangleInfo(dot2D ULDot, dot2D BRDot, double* w, double* h, double* area) {
	*w = BRDot.x - ULDot.x;
	*h = ULDot.y - BRDot.y;
	*area = (*w) * (*h);
}
```
- 두 좌표를 통해 사각형 폭, 높이, 넓이 구하는 함수
```c
void printRectangleInfo(double w, double h, double area) {
	printf("사각형의 폭: %f\n", w);
	printf("사각형의 높이: %f\n", h);
	printf("사각형의 넓이: %f\n", area);
}
```
- 결과 출력 함수  

### 실행결과
<img width="292" height="142" alt="image" src="https://github.com/user-attachments/assets/5f21720a-e63c-4871-acce-d49579c17daa" />
<img width="273" height="112" alt="image" src="https://github.com/user-attachments/assets/4a0fe876-6096-4f02-9f4c-282580b89a7d" />

# 실습과제 5
```c
#include <stdio.h>
```
- stdio.h 파일을 포함하라
```c
typedef struct {
	int x;
	int y;
}Point2D;
```
- 좌표 저장할 구조체에 이름 붙여줌
```c
void swap(Point2D* ptr1, Point2D* ptr2)
```
- 좌표의 멤버 변수끼리 값을 스왑하는 함수
```c
	int tmpx = 0, tmpy = 0;
```
- 좌표값 임시 저장할 변수
```c
	tmpx = ptr1->x;
	ptr1->x = ptr2->x;
	ptr2->x = tmpx;
```
- x좌표끼리 교환
```c
	tmpy = ptr1->y;
	ptr1->y = ptr2->y;
	ptr2->y = tmpy;
```
- y좌표끼리 교환
```c
int main(void)
```
- main 함수 시작
```c
	Point2D p1 = { 15, 15 }, p2 = { 30, 30 };
```
- 좌표 설정
```c
	printf("교환전 p1의 좌표: (%d, %d)\n", p1.x, p1.y);
	printf("교환전 p2의 좌표: (%d, %d)\n", p2.x, p2.y);
```
- 교환전 좌표 출력
```c
	swap(&p1, &p2);
```
- 스왑함수 호출하며 점의 주소를 넘김 (멤버 변수에 접근해야 하므로)
```c
	printf("교환후 p1의 좌표: (%d, %d)\n", p1.x, p1.y);
	printf("교환후 p2의 좌표: (%d, %d)\n", p2.x, p2.y);
```
- 교환후 좌표 출력
```c
	return 0;
```
- 0을 반환하고 main 함수 정상 종료




