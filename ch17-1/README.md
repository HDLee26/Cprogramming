# 실습과제 1
- 아래의 변수가 그림처럼 메모리에 할당될 때 표의 빈칸을 채우시오.
```c
double num = 6.28;
double* ptr = &num;
double** dptr = &ptr;
```

| 주소 | 100 | 300 | 500 |
|---|---|---|---|
| 변수 | num | ptr | dptr |

| 수식 | 결과값 | 결과값의 자료형 |
|---|---|---|
| `ptr` | 100 | `double*` |
| `dptr` | 300 | `double**` |
| `&ptr` | 300 | `double**` |
| `&dptr` | 500 | `double***` |
| `*ptr` | 6.28 | `double` |
| `*dptr` | 100 | `double*` |
| `**dptr` | 6.28 | `double` |

---

# 실습과제 2

```c
#include <stdio.h>
```
- stdio.h 파일을 포함하라
```c
int get_max(int* ptrarr[], int len);
```
- 이중포인터로 최댓값 찾는 함수 선언
```c
int main(void)
```
- main 함수 선언
```c
	int num1 = 50, num2 = 20, num3 = 30;
```
- 미리 준비한 정수들
```c
	int* ptrarr[3] = { &num1, &num2, &num3 };
```
- 포인터 배열에 변수들의 주소를 저장
```c
	int max;
```
- 최댓값 저장할 변수
```c
	max = get_max(ptrarr, sizeof(ptrarr) / sizeof(ptrarr[0]));
```
- 이중포인터로 최댓값 찾는 함수 호출하고 반환값 저장
```c
	printf("최댓값: %d\n", max);
```
- 결과 출력
```c
	return 0;
```
- 0을 반환하고 main 함수 정상 종료
```c
int get_max(int* ptrarr[], int len)
```
- 이중포인터로 최댓값 찾는 함수 정의
```c
	int tmp = *ptrarr[0];
```
- 첫 번째 변수의 값을 간접참조연산을 이용해 저장
```c
	for (int i = 1; i < len; i++)
		if (tmp < *(ptrarr[i]))
			tmp = *(ptrarr[i]);
```
- 나머지 변수의 값들과 비교하여 최댓값 갱신
```c
	return tmp;
```
-  최댓값 반환

### 실행결과
<img width="141" height="66" alt="image" src="https://github.com/user-attachments/assets/7a2c8103-ce64-4f99-8c65-5b244a989c44" />

---



