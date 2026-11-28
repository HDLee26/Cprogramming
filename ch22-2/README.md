# 실습과제 1
```c
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
```
- 문자 문자열 관련 함수들 보안 경고 무시용 & 반환값 관련 경고 무시용
```c
#include <stdio.h>
#include <string.h>
```
- stdio.h, string.h 파일을 포함하라
```c
typedef struct student {
	char name[11];
	int score;
} STD;
```
- 학생 이름과 성적을 저장할 구조체 정의
- 참고로 utf-8 기준 한글 한 자당 3바이트 차지하므로 입력받을 때 세글자 + \n + \0 11바이트 다 참.
```c
void inputScore(STD* lst, size_t n);
size_t getTopStd(const STD* lst, size_t n);
```
- 성적 입력하는 함수, 최고점수 학생을 구하는 함수
```c
int main(void)
```
- main 함수 시작
```c
	STD stdList[3] = { { { '\0' }, 0 } };
```
- 각 배열의 멤버 변수들을 초기화 -> 구조체{ 배열{ name 배열{ }, score 변수} }
```c
	size_t n = sizeof(stdList) / sizeof(stdList[0]);
```
- 구조체 배열의 원소 개수
```c
	size_t topIndex;
```
- 최고점수 학생의 인덱스
```c
	inputScore(stdList, n);
	topIndex = getTopStd(stdList, n);
```
- 함수 호출
```c
	printf("최우수 학생의 이름은 %s, 점수는 %d점\n", stdList[topIndex].name, stdList[topIndex].score);
```
- 결과 출력
```c
	return 0;
```
- 0을 반환하고 main 함수 정상 종료
```c
void inputScore(STD* lst, size_t n)
	for (size_t i = 0; i < n; i++)
```
- 각 배열에 접근하면서
```c
		fputs("이름을 입력하시오: ", stdout);
		if (fgets(lst[i].name, sizeof(lst[i].name), stdin) != NULL)
			lst[i].name[strcspn(lst[i].name, "\n")] = '\0';
```
- 이름 입력 받고 (name이 배열이라 & 쓰지 않음)
```c
		printf("성적을 입력하시오: ");
		scanf("%d", &lst[i].score);
		getchar();
```
- 성적 입력 받음. (score는 변수이므로 & 필요함)
- getchar();는 버퍼에 남은 '\n' 지우는 용도
```c
size_t getTopStd(const STD* lst, size_t n)
	size_t top = 0;
```
- 0번 학생을 최고득점 학생으로 임시 저장
```c
	for (size_t i = 1; i < n; i++)
		if (lst[i].score > lst[top].score)
			top = i;
```
- 각 배열에 담긴 score에 접근하여 최고득점인 학생의 인덱스를 구해서
```c
	return top;
```
- 그 인덱스를 반환함.
- 구조체 (변수) 배열의 멤버에 접근할 때는 3가지 방법을 쓸 수 있음.
  - 인덱스 lst[i].name
  - 구조체 포인터 (lst + i)->name
  - 역참조 (*(lst + i)).name

### 실행결과
<img width="406" height="172" alt="image" src="https://github.com/user-attachments/assets/aceea9e3-8a99-42bb-9077-4e4eb9293649" />

# 실습과제 2, 3
```c
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
```
- 문자 문자열 관련 함수들 보안 경고 무시용 & 반환값 관련 경고 무시용
```c
#include <stdio.h>
#include <string.h>
```
- stdio.h, string.h 파일을 포함하라
```c
typedef struct student {
	char name[11];
	int score;
} STD;
```
- 학생 이름과 성적을 저장할 구조체 정의
```c
void inputScore(STD* lst, size_t n);
size_t getFirstStd(STD* lst, size_t n);
```
- 성적 입력하는 함수, 명부상 가장 앞에 나오는 학생의 인덱스 구하는 함수
```c
int main(void)
```
- main 함수 시작
```c
	STD stdList[3] = { { { '\0' }, 0 } };
	size_t n = sizeof(stdList) / sizeof(stdList[0]);
	size_t first;
```
- 구조체 배열, 배열의 원소의 개수, 명부상 가장 앞에 나오는 학생의 인덱스 
```c
	inputScore(stdList, n);
	first = getFirstStd(stdList, n);
```
- 함수 호출
```c
	printf("출석부에서 가장 먼저 나오는 학생: %s의 성적: %d \n", stdList[first].name, stdList[first].score);
```
- 결과 출력
```c
	return 0;
```
- 0을 반환하고 main 함수 정상 종료
```c
void inputScore(STD* lst, size_t n) {
	for (size_t i = 0; i < n; i++) {
		fputs("이름을 입력하시오: ", stdout);
		if (fgets((lst + i)->name, sizeof(lst[i].name), stdin) != NULL) 
			(*(lst + i)).name[strcspn(lst[i].name, "\n")] = '\0';
		printf("성적을 입력하시오: ");
		scanf("%d", &(lst + i)->score);      // &lst[i].score  &(*(lst + i)).score
		getchar();
	}
}
```
- 각 배열에 접근하면서 이름과 성적 입력 받음
```c
size_t getFirstStd(STD* lst, size_t n)
	size_t firstStdIndex = 0;
```
- 0번째 학생을 가장 앞에 나오는 학생으로 임시 설정
```c
	for (size_t i = 1; i < n; i++)
		(strcmp((lst + i)->name, lst[firstStdIndex].name) < 0)   
			firstStdIndex = i;
```
- 나머지 두 배열에 담긴 name에 접근하여 가장 앞에 나오는 학생의 인덱스를 찾고
```c
	return firstStdIndex;
```
- 그 인덱스를 반환함.

### 실행결과
<img width="439" height="174" alt="image" src="https://github.com/user-attachments/assets/77ccf513-5744-4364-bd9c-6636f3920b32" />



