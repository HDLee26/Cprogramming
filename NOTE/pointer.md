# 여러 개 동시 선언
```c
int *ptr1, *ptr2;
```
- 이렇게 하면 되는데
```c
int *ptr1;
int *ptr2;
```
- 그냥 하나씩 선언하는게 실수 방지에 좋음

# 포인터 연산
```c
/*  포인터변수: 주소값을 저장하기 위한 변수
	항상 시작 주소가 저장됨
	&연산자: 주소를 반환하는 연산자 ptr = &num;
	*연산자: 포인터가 가리키는 주소에 접근하는 연산자 (선언할 때는 아님) */

#include <stdio.h>

int main(void)
{
	int num1 = 100, num2 = 100;   
	int * ptr;    // int형 포인터변수 ptr 선언

	ptr = &num1; // 포인터 ptr이 변수 num1을 가리킴 -- num1의 주소를 저장
	*ptr += 30;  // ptr이 가리키는 곳(num1)에 30을 더해서 저장 -- num += 30

	ptr = &num2; // 포인터 ptr이 변수 num2를 가리킴 -- num2의 주소를 저장
	*ptr -= 30;  // ptr이 가리키는 곳(num2)에 30을 빼서 저장 -- num2 -= 30

	printf("num1: %d | num2: %d\n", num1, num2);

	// 포인터 변수의 크기  -- 64비트 시스템에선 주소값이 8바이트
	printf("ptr의 크기: %zu\n", sizeof(ptr));
	putchar('\n');

	// 포인터에 저장하는 건 시작 위치뿐이라 자료형과 포인터형을 맞춰줘야 값을 가져오는 연산에서 오류 안 생김.
	const double PI = 3.141592;
	int * ptr1 = &PI;     // ptr1에 저장된 주소를 시작으로 4바이트를 읽어들이고 이를 정수로 해석하라.
	double * ptr2 = &PI;  // ptr2에 저장된 주소를 시작으로 8바이트를 읽어들이고 이를 실수로 해석하라.

	printf("%d\n", *ptr1);    // 쓰레기값
	printf("%f\n", *ptr2);

	return 0;
}
```
