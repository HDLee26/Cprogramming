# 실습과제 1
- 스트림과 버퍼의 역할을 각각 설명하시오. 
  - 스트림: 프로그램과 입출력 장치 사이의 데이터의 이동을 위한 소프트웨어적 이동 경로. 단방향으로만 존재함.
  - 버퍼: 입출력 과정에서 데이터를 임시로 저장하는 메모리 공간. 스트림 내부에 있고 OS가 관리함.
- 버퍼를 사용하여 얻는 장점과 단점.
  - 장점: 데이터를 하나씩 보내는 것보다 효율적. 서로 속도가 다른 장치들 사이에서 데이터를 모아놓고 한번에 보내므로 데이터 손실을 방지.
  - 단점: 한번에 모아서 데이터를 보내므로 즉각적인 반응이 필요한 프로그램에서는 불리함.
- 입력 버퍼에 데이터가 이미 존재할 때 scanf함수를 호출하면 어떤 문제가 있는가? \
  버퍼에 남아있는 데이터를 읽어들이기 때문에 사용자로부터 추가로 데이터를 받을 수 없음.
- 운영체제가 어떤 경우에 출력 버퍼의 데이터를 모니터로 출력하는가? \
  버퍼가 가득 차거나, 데이터의 입력이 끝났을 때
- printf함수와 scanf함수 실행 시 함수와 운영체제의 역할분담에 대하여 설명하라.
  - 프로그램 -> printf -> 출력 버퍼 -> OS(D/D) -> 모니터
  - 키보드 -> OS(D/D) -> 입력 버퍼 -> scanf -> 프로그램

  - printf \
  1 문자를 버퍼로 옮김. \
  2 운영체제의 함수가 특정조건을 만족하면 버퍼의 데이터를 모니터로 전송하고 버퍼에서 삭제.

  - scanf \
  1 scanf함수에서 *버퍼가 비어 있으면* OS의 함수를 호출하고 대기 \
  2 운영체제의 함수가 입력된 문자를 버퍼로 전송함. 엔터키를 입력하면 scanf()함수 호출. \
  3 scanf()함수가 서식 지정자에 따라 입력 받은 문자를 알맞게 변수에 저장하고 버퍼에서 삭제.  \
  4 그런데 '\n'은 버퍼에 남음.

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
		printf("문자입력: ");
		scanf(" %c", &ch);
		printf("입력 된 문자는 %c\n", ch);
```
- 버퍼에서 공백문자가 아닌 문자가 나올 때까지 공백문자를 읽어서 버림.
- 그러므로 'q'나 'Q'를 입력 받은 후에는 버퍼에 '\n'가 남음. 
```c
	return 0;
```
- 0을 반환하고 main 함수 정상 종료

### 실행결과
<img width="203" height="210" alt="image" src="https://github.com/user-attachments/assets/ae127841-846a-44b3-89ce-eef15499795a" />

# 실습과제 3
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
	char name[10] = { '\0' };
	char blood_type[5] = { '\0' };
```
- 이름과 혈액형 저장할 char형 배열
```c
	printf("이름을 입력하세요: ");
	scanf("%s", name);
```
- 이름 입력 받고
```c
	getchar();
```
- 버퍼에 남은 '\n'을 읽어서 버림
```c
	printf("혈액형을 입력하세요: ");
	scanf("%s", blood_type);
```
- 혈액형 입력 받음.
```c
	printf("이름: %s\n", name);
	printf("혈액형: %s\n", blood_type);
```
- 이름과 혈액형 출력
```c
	return 0;
```
- 0을 반환하고 main 함수 정상 종료

### 실행결과
<img width="278" height="119" alt="image" src="https://github.com/user-attachments/assets/ea45be47-152b-401d-8b5e-21e6cdfd5921" />


  
  
