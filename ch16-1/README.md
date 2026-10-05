# 실습과제 1
```c
#include <stdio.h>
```
- stdio.h 헤더파일을 포함하라
```c
void addMatrix(int*, int*, int*); // int matrix[][2]
```
- 행렬의 합 구하는 함수 선언
- 매개변수로 int* matrix와 int matrix[][2]는 같은 동작을 함
- int matrix[][2]는 열이 2개인 이차원 배열을 받는 매개변수임
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
```
- 행렬1
```c
	int m2[2][2] = { {-2, 3}, {0, -5} };
```
- 행렬 2
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

			// *(*(msum + i) + j) = *(*(m1 + i) + j) + *(*(m2 + i) + j);

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
    {
			// *(*(matrix + i) + j)
			printf("%d\t", *(m + j + 2 * i));
    }
		printf("\n");
  |
```
- 이중루프로 이차원 배열의 모든 요소에 접근하여 간접참조연산자로 값을 가져와 출력
### 실행결과
<img width="111" height="58" alt="image" src="https://github.com/user-attachments/assets/52b80929-03f1-437f-81fe-643f755e69c7" />

