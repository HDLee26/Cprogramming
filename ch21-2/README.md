# 실습과제 1
- 표준 스트림에 접근하는 방법을 설명하라.
  - 스트림도 일종의 변수인데 변수명은 알 수 없으므로 포인터로 접근해야 함. 스트림의 자료형이 FILE이라서 포인터의 자료형은 FILE* 이다. 또한 표준스트림의 주소는 stdin, stdout, stderr로 간편히 접근할 수 있음.
- 공백을 포함한 문자열을 입력받을 때 사용가능한 함수는?
  - gets, fgets
- gets 함수 사용시 가장 큰 문제점은 무엇인가?
  - 입력할 문자열의 길이가 저장 받을 char형 배열의 크기보다 크면 런타임 오류가 발생함. 버퍼의 크기가 할당된 공간을 초과하는지 체크하지 않기 때문임.
- fgets 함수 사용시 문제점은 무엇인가?
  1) 종료 조건 중에 문자열의 '\n'까지 읽고 '\0'을 이어붙여 저장하는 경우가 있음. 문자열을 어떻게 사용할 것인지에 따라서는 '\n'을 지워줘야 할 수 있음.
  2) n-1개까지 버퍼에서 문자를 읽고 '\0'를 이어붙여 저장하는데 n번째 문자가 '\n'이면 버퍼에 그대로 남아있으므로 다음 fgets 호출 시 '\n'을 읽어들임.
- NULL문자와 NULL포인터의 용도를 설명하시오.
  - NULL 문자는 문자열의 끝을 표시해주는 용도, NULL포인터는 아무것도 가리키지 않겠다는 용도로 씀.
  - NULL포인터는 0번지를 가리키는데 실제로 접근 가능한 것은 아니므로 유효한 대상을 가리키지 않음.
 
# 실습과제 2
```c
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
```
- VS scanf 함수 보안 경보 방지용 & 리턴값 관련 경고 방지용
```c
#include <stdio.h>
```
- stdio.h 파일을 포함하라
```c
int main(void)
```
- main 함수 시작
```c
	char ch = '\0';
```
- 문자 저장할 변수 선언
```c
	while (1)
```
- 무한 루프 시작
```c
		if ((ch == 'q') || (ch == 'Q')) {
			puts("프로그램 종료");
			break;
}
```
- 탈출 조건 설정: 'q'나 'Q' 입력 받으면 루프 종료
```c
		fputs("문자입력: ", stdout);
```
- 안내문, 자동개행을 피하기 위해 fputs 사용
```c
		ch = getchar();
```
- 버퍼에서 문자 하나 읽어서 ch에 저장
```c
		getchar();
```
- 버퍼에 남은 '\n'읽어서 버림
```c
		fputs("입력 된 문자는 ", stdout);
```
- 안내문, 자동개행을 피하기 위해 fputs 사용
```c
		putchar(ch);
```
- ch에 저장된 문자 출력
```c
		putchar('\n');
```
- 개행
```c
	return 0;
```
- 0을 반환하고 main 함수 정상 종료

### 실행결과
<img width="221" height="200" alt="image" src="https://github.com/user-attachments/assets/4378d24f-034b-4c07-a9c4-39ad482d6909" />

# 실습과제 3
```c
#pragma warning(disable:6031)
```
- 리턴값 관련 경고 방지용
```c
#include <stdio.h>
```
- stdio.h 파일을 포함하라
```c
#include <string.h>
```
- string.h 파일을 포함하라
```c
typedef struct person {
	char name[20];
	char address[30];
	char car_number[20];
} Person;
```
- 이름, 주소, 자동차번호 저장할 수 있는 구조체 정의하고 typedef로 Person으로 자료형 재정의
```c
void input(char* str, int size)
```
-  문자열 입력 받는 함수
```c
	if (fgets(str, size, stdin) != NULL)
		str[strcspn(str, "\n")] = '\0';
```
- 문자열 입력 받고 문자열 중에 '\n'은 '\0'으로 바꿔 저장
```c
int main(void)
```
- main 함수 시작
```c
	Person std1 = { '\0' };
```
- 구조체 변수 std1 선언
```c
	fputs("이름: ", stdout);
	input(std1.name, sizeof(std1.name));
	fputs("주소: ", stdout);
	input(std1.address, sizeof(std1.address));
	fputs("자동차번호: ", stdout);
	input(std1.car_number, sizeof(std1.car_number));
```
- 이름 주소 자동차번호 차례로 입력 받고 각 멤버변수에 저장
```c
	fputs("이름: ", stdout);
	puts(std1.name);
	fputs("주소: ", stdout);
	puts(std1.address);
	fputs("자동차번호: ", stdout);
	puts(std1.car_number);
```
- 입력 받은 문자열 출력
```c
	return 0;
```
-  0을 반환하고 main 함수 정상 종료

### 실행결과
<img width="228" height="159" alt="image" src="https://github.com/user-attachments/assets/5ac9b540-f844-4330-a26d-d202357833bc" />


