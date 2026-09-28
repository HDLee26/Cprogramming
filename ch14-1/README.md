# 실습과제 1
- 함수의 인자와 매개변수의 차이를 설명하라\
 함수의 인자는 함수를 호출할 때 괄호 안에 들어가고, 매개변수는 함수의 선언부의 괄호 안에 들어간다.
- 함수가 호출될 때 컴퓨터에 의해 자동으로 실행되는 2가지를 설명하라\
함수를 호출할 때 자동으로 매개변수가 메모리에 할당되고 매개변수를 인자값으로 초기화한다.
- 값에 의한 함수 호출방식의 문제점을 설명하라\
함수 안에서 변수의 값을 바꿔도 다른 함수에 선언된 변수의 값이 변하지 않는다.
- 주소에 의한 함수 호출방식이 필요한 경우를 설명하라\
다른 함수에 선언된 지역 변수의 값을 변경하고자 하는 경우에 주소에 의한 함수 호출 방식을 써야 한다.
---
# 실습과제 2
### 주어진 코드
```c
#include <stdio.h>
void add2(int value);

int main(void)
{
	int number;
	printf("정수를 입력하세요: ");
	scanf("%d", &number);
	add2(number);
	printf("2만큼 증가한 값: %d\n", number);
	return 0;
}
void add2(int value)
{
	value += 2;
}
```
- add2 함수는 매개변수의 값을 2만큼 증가시키는 함수이다. 주어진 코드가 의도대로 작동하지 않는 이유를 설명하라.\
인자값을 가진 변수 number와 매개변수로 쓰인 변수 value는 서로 다른 함수에 선언된 지역변수이다. 
넘긴 인자값은 매개변수에 복사되는 것과 유사하므로 add2 함수 안의 지역변수에 값을 어떻게 변경해도 number의 값에도 영향을 주지 않는다.

### 수정한 코드
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
void add2(int * ptr);
```
- add2 함수 선언
```c
int main(void)
```
- main함수 시작
```c
int number;
```
- int형 변수 number 선언
```c
printf("정수를 입력하세요: ");
```
- 안내문 출력
```c
scanf("%d", &number);
```
- 정수 하나를 입력 받아 number에 저장
```c
add2(&number);
```
- add2함수 호출하며 number의 주소를 인자로 넘김
```c
printf("2만큼 증가한 값: %d\n", number);
```
- number의 값 출력
```c
return 0;
```
- 0을 반환하고 main함수 정상 종료
```c
void add2(int * ptr)
```
- 정수형 주소를 매개변수로 하는 add2 함수 정의 부분
```c
*ptr += 2;
```
- 간접참조연산자로 ptr이 가리키는 변수(number)의 값을 2 증가시켜 저장

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
int add2(int value);
```
- add2 함수 선언
```c
int main(void)
```
- main함수 시작
```c
int number, added_number;
```
- 정수형 변수 number, added_number 선언
```c
printf("정수를 입력하세요: ");
```
- 안내문 출력
```c
scanf("%d", &number);
```
- 정수를 입력 받아 number에 저장
```c
added_number = add2(number);
```
- add2 함수의 반환값을 added_number에 저장
```c
printf("2만큼 증가한 값: %d\n", added_number);
```
- added_number의 값을 출력
```c
return 0;
```
- 0을 반환하고 main함수 정상 종료
```c
int add2(int value)
```
- add2 함수 정의부분. 반환형 int, 매개변수 value
```c
return value += 2;
```
- value에 2를 더하고 저장하고 그 값을 반환

---

# 실습과제 4
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
void swap(int*, int*, int*);
```
- swap 함수 선언
```c
int main(void)
```
- main함수 시작
```c
int x, y, z;
```
- 정수형 변수 x, y, z 선언
```c
printf("정수 x를 입력하시오: ");
scanf("%d", &x);
printf("정수 y를 입력하시오: ");
scanf("%d", &y);
printf("정수 z를 입력하시오: ");
scanf("%d", &z);
```
- 변수 x, y, z에 값을 저장
```c
printf("swap함수 호출 전 x = %d, y = %d, z = %d\n", x, y, z);
```
- swap전 원래 값 출력
```c
swap(&x, &y, &z);
```
- swap함수 호출
```c
printf("swap함수 호출 후 x = %d, y = %d, z = %d\n", x, y, z);
```
- swap후 값 출력
```c
return 0;
```
- 0을 반환하고 main 함수 정상 종료
```c
void swap(int* px, int* py, int* pz)
```
- swap 함수 정의부. 반환형 없음, 매개변수 int*형 px, py, pz
```c
int tmp;
```
- 임시로 값을 저장할 정수형 변수 tmp 선언
```c
tmp = *px;
*px = *py;
*py = *pz;
*pz = tmp;
```
- 간접참조연산으로 값 교환

---
# 실습과제 5
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
void SquareByValue(int);
```
- SquareByValue함수 선언
```c
void SquareByPointer(int*);
```
- SquareByPointer 함수 선언
```c
int main(void)
```
- main 함수 시작
```c
int num;
```
- int형 변수 num선언
```c
printf("정수를 입력하시오: ");
```
- 안내문 출력
```c
scanf("%d", &num);
```
- 정수를 입력 받아 num에 저장
```c
SquareByValue(num);
```
- SquareByValue함수 호출
```c
printf("값에 의한 호출로 바꾼 값: %d\n", num);
```
- 값 변화 확인 - 변하지 않음
```c
SquareByPointer(&num);
```
- SquareByPointer 함수 호출
```c
printf("주소에 의한 호출로 바꾼 값: %d\n", num);
```
- 값 변화 확인 - 변함
```c
return 0;
```
- 0을 반환하고 main 함수 정상 종료
```c
void SquareByValue(int value)
```
- SquareByValue 함수 정의부. 반환형 없음
```c
value += 100;
```
- value에 100을 더하고 저장
```c
void SquareByPointer(int* ptr)
```
- SquareByPointer 함수 정의부. 반환형 없음
```c
*ptr += 100;
```
- 간접참조연산자를 이용해 ptr가 가리키는 변수의 값에 100을 더하고 저장

