## 배열과 포인터
```c
double *ptr = arr;

*(ptr+0), *(ptr+1), *(ptr+2) // 포인터 연산으로 각 원소의 값을 참조 (간접참조연산)
ptr[0], ptr[1], ptr[2]       // 포인터도 인덱스 연산으로 배열처럼 접근 가능
*(arr+0), *(arr+1), *(arr+2) // 배열명을 포인터처럼 사용해 각 원소에 접근
arr[0], arr[1], arr[2]       // 배열 인덱스로 접근
```

## 자료형
```c
double arr[] = {1.0, 2.0, 3.0};
```
|표현	|의미	|타입	|가리키는 위치 |
|:---:|:---:|:---:|:----------|
|arr	|배열|	double[3]이지만 대부분의 식에서 double *로 변환	|arr[0] |
|&arr[0]	|첫 번째 원소의 주소	| double *	| arr[0] |
|arr + 1	| 다음 원소로 1칸 이동	| double *	| arr[1] |
|&arr |	배열 전체의 주소 |	double (*)[3] |	배열 전체 |
|&arr + 1 |	배열 전체 크기만큼 1칸 이동 |	double (*)[3]	|배열 바로 다음 위치|

- 직접 확인해보는 코드
```c
#include <stdio.h>

int main(void)
{
    double arr[] = {1.0, 2.0, 3.0};

    printf("arr      = %p\n", (void *)arr);
    printf("&arr[0]  = %p\n", (void *)&arr[0]);
    printf("arr + 1  = %p\n", (void *)(arr + 1));
    printf("&arr     = %p\n", (void *)&arr);
    printf("&arr + 1 = %p\n", (void *)(&arr + 1));

    return 0;
}

```
- 실행결과
<img width="262" height="142" alt="image" src="https://github.com/user-attachments/assets/8c668448-e854-4947-9cc7-cee88d8a4d24" />

