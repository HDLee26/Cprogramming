# 배열과 포인터
```c
double *ptr = arr;

*(ptr+0), *(ptr+1), *(ptr+2) // 포인터 연산으로 각 원소의 값을 참조 (간접참조연산)
ptr[0], ptr[1], ptr[2]       // 포인터도 인덱스 연산으로 배열처럼 접근 가능
*(arr+0), *(arr+1), *(arr+2) // 배열명을 포인터처럼 사용해 각 원소에 접근
arr[0], arr[1], arr[2]       // 배열 인덱스로 접근
// arr[i] == *(arr + i)
```

# 자료형
```c
double arr[] = {1.0, 2.0, 3.0};
```
|표현	|의미	|타입	|가리키는 위치 |
|:---:|:---:|:---:|:----------|
|arr	|배열|	double[3] (배열 그자체)이지만 대부분의 식에서 double* (첫 번째 원소의 주소)로 변환	|arr[0] |
|&arr[0]	|첫 번째 원소의 주소	| double *	| arr[0] |
|arr + 1	| 다음 원소로 1칸 이동	| double *	| arr[1] |
|&arr |	배열 전체의 주소 |	double (*)[3] |	배열 전체 |
|&arr + 1 |	배열 전체 크기만큼 1칸 이동 |	double (*)[3]	|배열 바로 다음 위치|

### 직접 확인해보는 코드
```c
#include <stdio.h>

int main(void)
{
    double arr[] = {1.0, 2.0, 3.0};

    printf("arr      = %p\n", (void *)arr);
    printf("&arr[0]  = %p\n", (void *)&arr[0]);
    printf("arr + 1  = %p\n", (void *)(arr + 1));
    printf("&arr     = %p\n", (void *)&arr);       // 찍히는 주소는 첫 번째 원소의 주소지만
    printf("&arr + 1 = %p\n", (void *)(&arr + 1)); // 이걸 보면 배열 전체를 가리키고 있다는 걸 알 수 있다

    return 0;
}

```
### 실행결과
<img width="262" height="142" alt="image" src="https://github.com/user-attachments/assets/8c668448-e854-4947-9cc7-cee88d8a4d24" />

# 배열과 함수
- 함수의 매개변수로 쓰일 때만 ```int arr[] == int* arr```
- 표기를 배열처럼 할 수 있을 뿐 실제 작동방식은 전부 **포인터**이다. 따라서 넘어가는 값도 첫 번째 원소의 주소뿐이다.
```c
void func(int arr[]);
void func(int* arr);
```
### 왜 이렇게 만들었나
- 함수가 배열 전체를 값 복사로 받으면 배열의 원소를 전부 복사해야 하고, 시간이 오래 걸리고, 메모리도 많이 먹음. 하지만 시작 위치 즉 첫 번째 원소의 주소만 넘기면 효율적임.

### 몇 개 실습해보자
```c
#include <stdio.h>

void func(int arr[]) {
    printf("%zu\n", sizeof(arr));
}

int main() {
    int arr[5] = 0;
    printf("%zu\n", sizeof(arr));
    func(arr);
}
```
- int형 원소가 5개 (20 B), 그러나 나오는 값은 포인터의 크기 (8 B).
```c
void func(int arr[], int n)
```
- 첫 번째 원소의 주소만 받기 때문에 배열의 길이를 알 수 없음. 따라서 배열의 길이 정보를 항상 따로 넘겨줘야 함.
