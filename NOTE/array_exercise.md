## 배열 병합
- C에서는 새 배열을 만들고 복사하는 작업
### 복붙하기
```c
#include <stdio.h>
void merge(int*, int, int*, int, int*);
void printArray(int*, int);
int main() 
{
    int a[] = { 1, 2, 3 };
    int b[] = { 4, 5, 6 };
    int result[sizeof(a) / sizeof(a[0])
        + sizeof(b) / sizeof(b[0])];
    // sizeof() 연산은 컴파일 시 상수식이 됨

    int sizeA = sizeof(a) / sizeof(a[0]);
    int sizeB = sizeof(b) / sizeof(b[0]);
    int sizeResult = sizeA + sizeB;
    
    merge(a, sizeA, b, sizeB, result);
    printArray(result, sizeResult);

    return 0;
}
// 배열 합병
void merge(int a[], int sizeA, int b[], int sizeB, int result[]) 
{
    // a 복사
    for (int i = 0; i < sizeA; i++) 
        result[i] = a[i];
    
    // b 복사
    for (int i = 0; i < sizeB; i++) 
        result[sizeA + i] = b[i];
}
// 배열의 원소 출력
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

```
- C에서 const는 "값의 수정을 막는다"는 의미임. 컴파일 시 상수가 되는 것이 아님.
### 동적 할당 // 26.10.07 나중에 배우고 업데이트
