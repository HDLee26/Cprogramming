## 배열 병합
- C에서는 새 배열을 만들고 복사하는 작업
### 복붙하기
```c
#include <stdio.h>
void merge(int*, int, int*, int, int*);
int main() 
{
    int a[] = { 1, 2, 3 };
    int b[] = { 4, 5, 6 };

    int sizeA = 3;
    int sizeB = 3;

    int result[6];

    merge(a, 3, b, 3, result);

    // 출력
    for (int i = 0; i < sizeA + sizeB; i++) 
        printf("%d ", result[i]);

    return 0;
}

void merge(int a[], int sizeA, int b[], int sizeB, int result[]) 
{
    // a 복사
    for (int i = 0; i < sizeA; i++) 
        result[i] = a[i];
    
    // b 복사
    for (int i = 0; i < sizeB; i++) 
        result[sizeA + i] = b[i];
}

```

### 동적 할당 // 26.10.07 나중에 배우고 업데이트
