# 실습과제 1
```c
#include <stdio.h>
```
- stdio.h 헤더파일을 포함하라
```c
void addMatrix(int*, int*, int*); 
```
- 행렬의 합 구하는 함수 선언
```c
void printMatrix(int*);
```
- 구한 행렬을 출력하는 함수 선언
```c
int main(void)
```
- main 함수 시작
```c
	int m1[2][2] = { {2,4}, {5, -5} };
	int m2[2][2] = { {-2, 3}, {0, -5} };
```
- 연산할 행렬 선언 및 초기화
```c
	int msum[2][2] = { 0 };
```
- 계산한 값을 저장할 2x2 행렬
```c
	addMatrix(m1, m2, msum);
```
- addMatrix함수 호출
```c
	printMatrix(msum);
```
- printMatrix함수 호출
```c
	return 0;
```
- 0을 반환하고 main함수 정상 종료
```c
void addMatrix(int* m1, int* m2, int* msum)
```
- 두 행렬을 더하는 함수 정의 시작
```c
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			*(msum + j + 2 * i) = *(m1 + j + 2 * i) + *(m2 + j + 2 * i);
```
- 이중루프로 이차원 배열의 모든 요소에 접근하여 간접참조연산자로 값을 가져와 연산

```c
void printMatrix(int* m)
```
- 행렬을 출력하는 함수 정의 시작
```c
	for (int i = 0; i < 2; i++)
  {
		for (int j = 0; j < 2;j++)
			printf("%d\t", *(m + j + 2 * i));
		printf("\n");
  }
```
- 이중루프로 이차원 배열의 모든 요소에 접근하여 간접참조연산자로 값을 가져와 출력
### 실행결과
<img width="111" height="58" alt="image" src="https://github.com/user-attachments/assets/52b80929-03f1-437f-81fe-643f755e69c7" />

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
void inputScores(int scores[][3]);
```
- 이차원 배열에 세 학생의 성적을 입력하는 함수 선언
```c
double getAverage(int std_scores[], int cnt);
```
-각 학생의 세 과목의 평균을 구하는 함수 선언
```c
void getFirstStudent(int scores[][3], double avg[], int* topStudent, double* topAvg);
```
- 평균 최고 점수와 그 학생의 인덱스를 포인터를 통해 넘기는 함수 선언
```c
int main(void)
```
- main 함수 시작
```c
	int scores[3][3] = { 0 };
```
- 점수를 저장할 이차원 배열
```c
	double avg[3] = { 0 };
```
- 각 학생의 평균을 저장할 배열
```c
	int topStudent;
```
- 최고 평균 학생의 인덱스 저장할 변수
```c
	double topAvg;
```
- 최고 평균 점수를 저장할 변수
```c
	inputScores(scores);
```
- 점수 입력 받는 함수 호출
```c
	getFirstStudent(scores, avg, &topStudent, &topAvg);
```
- 평균 최고 점수와 그 학생의 인덱스를 구하는 함수 호출
```c
	printf("최우수 학생은 %d번째 학생이고 평균 점수는 %.2f점이다.\n", topStudent + 1, topAvg);
``` 
- 결과 출력
```c
	return 0;
```
- 0을 반환하고 main 함수 정상 종료
```c
void inputScores(int scores[][3])
```
- 이차원 배열에 세 학생의 성적을 입력하는 함수 정의 시작
```c
	for (int i = 0; i < 3; i++)
		printf("%d번째 학생의 국어, 영어, 수학 성적을 입력: ", i + 1);
		for (int j = 0 ; j < 3; j++)
			scanf("%d", &scores[i][j]);
```
- 이차원 배열에 점수를 입력 받는 이중루프 i-학생(행) j-과목(열)
```c
void getFirstStudent(int scores[][3], double avg[], int* topStudent, double* topAvg)
```
- 평균 최고 점수와 그 학생의 인덱스를 포인터를 통해 넘기는 함수 정의 시작
```c
	for (int i = 0; i < 3; i++)
		avg[i] = getAverage(scores[i], 3);
```
- i번째 학생의 점수가 든 행을 넘기고 반환된 평균 점수를 받아서 저장
```c
	*topStudent = 0;
	*topAvg = avg[0];
```
- 인덱스 0번째 학생의 평균으로 임시 초기화
```c
	for (int i = 1; i < 3; i++)
		if (avg[i] > *topAvg) {
			*topAvg = avg[i];
			*topStudent = i;
		}
```
- 최고 평균 점수와 그 학생의 인덱스를 구함
```c
double getAverage(int std_scores[], int cnt)
```
- 세 과목의 평균을 구하는 함수 정의 시작
```c
	int sum = 0;
	for (int i = 0; i < cnt; i++)
		sum += std_scores[i];
```
- 학생 한 명의 세 과목의 합을 구함
```c
	return (double)sum / cnt;
```
- 평균을 구해서 반환함


### 실행결과
<img width="445" height="123" alt="image" src="https://github.com/user-attachments/assets/01abf41f-f250-4880-bfc3-b909d58ef40c" />

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
#define ROW 3
#define COL 3
```
- 배열의 행과 열을 각각 3으로 정의
```c
void input(int matrix[][COL]);
```
- 배열에 값을 입력 받는 함수 선언
```c
void getMaxIndex(int matrix[][COL], int* max, int* row, int* col);
```
- 입력 받는 배열에서 최댓값과 그 위치(행과 열)를 포인터를 통해 넘기는 함수 선언
```c
int main(void)
```
- main 함수 시작
```c
	int m[ROW][COL] = { 0 };
	int max;
	int mrow, mcol;
```
- 입력 받은 값을 저장할 이차원 배열
- 최댓값을 저장할 변수
- 위치를 저장할 변수들
```c
	input(m);
```
- 배열에 값을 입력 받는 함수 호출
```c
	getMaxIndex(m, &max, &mrow, &mcol);
```
- 입력 받은 배열에서 최댓값과 그 위치를 찾는 함수 호출
```c
	printf("최댓값: %d\n", max);
	printf("위치: %d행 %d열\n", mrow, mcol);
```
- 결과 출력
```c
	return 0;
```
- 0을 반환하고 main 함수 정상 종료
```c
void input(int matrix[][COL])
```
- 한 행마다 COL개의 정수를 입력 받는 함수 정의
```c
	for (int i = 0; i < ROW; i++)
		printf("%d행 원소 %d개 입력: ", i + 1, COL);
```
- 한 행마다 안내문 출력하고
```c
		for (int j = 0; j < COL; j++)
			scanf("%d", &matrix[i][j]);
```
- 지정된 열 개수만큼 값 입력 받음
```c
void getMaxIndex(int matrix[][COL], int* max, int* row, int* col)
```
- 최댓값과 위치 찾는 함수 정의
```c
	*max = matrix[0][0];
	*row = 1;
	*col = 1;
```
- 최댓값을 첫번째 원소의 값으로 임시 저장
- 위치를 1행 1열로 임시 저장
```c
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			if (matrix[i][j] > *max) {
				*max = matrix[i][j];
				*row = i + 1;
				*col = j + 1;
			}
```
- 배열의 원소들 중에서 최댓값과 그 위치를 찾음


### 실행결과
<img width="255" height="161" alt="image" src="https://github.com/user-attachments/assets/b086e0e2-9dcb-4b84-9646-fc62de911d2a" />

---


