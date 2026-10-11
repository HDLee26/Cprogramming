# 배열의 크기와 길이
```c
#include <stdio.h>

int main(void)
{
	// 1차원 배열 선언 및 초기화
	int arr1[4] = { 1, 2, 3, 4 };
	int arr2[] = { 1, 2, 3, 4, 5, 6, 7 };  // 길이를 알아서 맞춰줌.
	int arr3[5] = { 1, 2 };             // 빈칸은 0으로 채움.
	int arr1Len, arr2Len, arr3Len, i;

	// 배열의 크기 -- int형으로 선언되었으므로 값 하나당 4바이트. 크기 = 길이 * 4
	printf("배열 arr1의 크기: %zu\n", sizeof(arr1));
	printf("배열 arr2의 크기: %zu\n", sizeof(arr2));
	printf("배열 arr3의 크기: %zu\n", sizeof(arr3));
	putchar('\n');

	// 배열의 길이 -- int형으로 선언했으므로 4로 나눠야 길이만 나옴.
	arr1Len = sizeof(arr1) / sizeof(int);
	arr2Len = sizeof(arr2) / sizeof(int);
	arr3Len = sizeof(arr3) / sizeof(int);
	printf("배열 arr1의 길이: %d\n", arr1Len);
	printf("배열 arr2의 길이: %d\n", arr2Len);
	printf("배열 arr3의 길이: %d\n", arr3Len);
	putchar('\n');

	// 배열에 저장된 값 출력  
	for (i = 0; i < arr1Len; i++)
		printf("%d ", arr1[i]);
	putchar('\n');

	for (i = 0; i < arr2Len; i++)
		printf("%d ", arr2[i]);
	putchar('\n');

	for (i = 0; i < arr3Len; i++)
		printf("%d ", arr3[i]);
	putchar('\n');

	return 0;
}
```
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
## 매개변수
```c
int arr[] = {1, 2, 3, 4, 5};
void func(int* param);
void func(int param[]);
```
- 배열명은 (대부분의 경우에) 첫번째 원소의 주소. 함수 호출 시 인자로 쓰면 주소값이 넘어감.
  따라서 함수의 매개변수는 포인터 변수인게 원칙.
- 그러나 함수의 매개변수로 쓰일 때만은 ```int param[]``` 이라는 배열 표현도 허용함.
- 표기를 배열처럼 할 수 있을 뿐 실제 작동방식은 전부 **포인터**이다.
  함수 내부의 param[i]도 *(param + i)로 컴파일러가 자동으로 바꿔 해석함.
## 배열의 크기 혹은 길이 정보
```c
void func(int param[], int len);
```
- 상술했듯이 함수에 인자로 넘어가는 것은 주소이기 때문에 함수 안에서는 배열의 크기를 구할 수 없다.
- 만약 함수 안에서 sizeof(arr) 연산을 한다해도 나오는 것은 포인터상수 arr의 크기 즉 8 B이다.
- 그래서 ```func(int param[], int len)``` 처럼 밖에서 배열의 길이를 구해서 같이 넘겨줘야 함.

### 왜 이렇게 만들었나
- 함수가 배열 전체를 값 복사로 받으면 배열의 원소를 전부 복사해야 하고, 시간이 오래 걸리고, 메모리도 많이 먹음. 하지만 시작 위치 즉 첫 번째 원소의 주소만 넘기면 효율적임.

### 몇 개 실습해보자
```c
#include <stdio.h>

void func(int arr[]) {
    printf("%zu\n", sizeof(arr));
}

int main() {
    int arr[5] = { 0 };
    printf("%zu\n", sizeof(arr)); // 20, 실제 배열의 크기
    func(arr);                    // 8, 포인터의 크기(주소값 8 B)
    return 0;
}
```
- int형 원소가 5개 (20 B), 그러나 나오는 값은 포인터의 크기 (8 B).
```c
void func(int arr[], int n)
```
- 첫 번째 원소의 주소만 받기 때문에 배열의 길이를 알 수 없음. 따라서 배열의 길이 정보를 항상 따로 넘겨줘야 함.

# 포인터배열
- 포인터 변수도 변수이므로 배열로 만들 수 있다.
포인터 변수로 이루어진, 그래서 주소값의 저장이 가능한 배열을 포인터 배열이라고 한다.
```c
#include <stdio.h>

int main(void)
{
    int num1 = 10, num2 = 20, num3 = 30, num4 = 40;
    double num5 = 1.1, num6 = 2.2, num7 = 3.3, num8 = 4.4;
    int* arr1[4] = { &num1, &num2, &num3, &num4 }; // 주소를 저장
    double* arr2[4] = { &num5, &num6, &num7, &num8 };
    int len = sizeof(arr1) / sizeof(arr1[0]);

    printf("주소 | 값\n");
    for (int i = 0; i < len; i++)
        printf("%p | %d \n", arr1[i], *arr1[i]);
    putchar('\n');

    printf("주소 | 값\n");
    for (int i = 0; i < len; i++)
        printf("%p | %f \n", arr2[i], *arr2[i]);
    putchar('\n');

    return 0;
}

```

# 문자열 배열
- 정확히 말하자면 문자열을 저장하는 포인터 배열이다. char형 배열에 문자열 리터럴들을 저장한 것인데 각 문자열의 맨 앞글자의 주소를 저장하기 때문이다.
```c
#include <stdio.h>

int main(void)
{
    // 각 문자열의 첫글자의 주소가 포인터 배열에 저장됨
    char * strArr[] = {"Simple", "String", "Array"};
    int len = sizeof(strArr) / sizeof(strArr[0]);

    printf("주소 | 값 \n");
    for (int i = 0; i < len; i++)
        printf("%p | %s \n", strArr[i], strArr[i]);
    
    return 0;
}
```
