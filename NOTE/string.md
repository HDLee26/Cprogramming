# 문자형 배열의 선언

### 선언 및 초기화
```char str1[] = "Hello";```
- 문자열 리터럴을 이용한 일반적인 선언 방식. 컴파일러가 자동으로 맨 끝에 Null문자 삽입함.
```char str2[] = {'H', 'e', 'l', 'l', 'o', '\0'};```
- 메모리 구조는 str1과 100% 동일함. 실무에서 쓰지 않음.
```char str3[] = {'H', 'e', 'l', 'l', 'o'};```
- 단순한 문자들의 나열일 뿐, **문자열이 아니다.**

### 빈 문자열 선언
```char str[100] = "";```
- 첫 번째 원소 str[0]에 \0을 넣고, 나머지 공간은 배열 초기화 규칙에 따라 전부 \0으로 자동 초기화됨.
```char str[100] = { 0 };```
- 첫 번째 원소를 0 (ASCII 코드 0은 Null문자 \0이다)으로 채우고, 나머지 공간도 0으로 자동 초기화. 문자형 배열뿐만 아니라 다른 모든 자료형의 배열도 초기화할 때 이렇게 쓸 수 있음.

### 나중에 입력 받을 문자열의 길에 맞추어 배열의 크기를 바꾸려면?
```char str[] = "";```
- 이런 식으로 초기화하면 배열의 크기가 1 바이트밖에 안 돼서 문자열을 집어넣을 수 없음.
- 현재 배움의 정도에서는 ```char str[1000] = "";``` 처럼 배열의 크기를 크게 주고 시작해야 함.
- 이런 메모리 낭비를 막으려면 동적할당을 활용해야 함.
```c
#include <stdio.h>
#include <stdlib.h> // malloc, free를 사용하기 위함
#include <string.h> // strlen, strcpy를 사용하기 위함

int main() {
    char temp[1000]; // 1. 넉넉한 임시 보관소 (Stack 영역)
    char *str;       // 딱 맞는 크기를 가리킬 포인터 변수

    printf("단어를 입력하세요: ");
    scanf("%s", temp); // "apple" 입력했다고 가정

    // 2. 동적 할당: 5글자 + 널 문자(\0) 1칸 = 총 6바이트만큼의 공간 요청
    str = (char *)malloc(strlen(temp) + 1);

    // 3. 임시 보관소의 문자열을 맞춤형 공간으로 복사
    strcpy(str, temp);

    printf("딱 맞는 공간에 저장된 단어: %s\n", str);

    // 4. 다 쓴 맞춤형 메모리는 반드시 직접 반납해야 함
    free(str);

    return 0;
}
```
  
# 문자형 배열 선언 (심화) // 261007 배우고 업데이트할 것
### 동적 할당 calloc (Heap 메모리)
```char *str = (char*)calloc(100, sizeof(char));```
- 메모리에 할당함과 동시에 내부를 모두 0으로 초기화. 사용 후 ```free(str);```로 메모리를 해제해야 함.
### 메모리를 직접 제어 memset() 함수
```memset(str, 0, sizeof(str));```
- str 배열의 시작 위치부터 배열의 전체 크기만큼의 메모리 공간을 0으로 덮어씀.
### 전역 변수로 선언
```static char str[100];```
- C언어에서 초기화되지 않은 전역 변수나 정적(static) 변수는 메모리의 BSS(Block Started by Symbol) 영역이라는 특별한 곳에 저장됨. 운영체제가 프로그램을 메모리에 올릴 때 이 구역을 통째로 0으로 초기화함.

# 문자열의 길이를 구하자
### strlen() 함수
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "hello";

    char last = str[strlen(str) - 1]; // 마지막 문자의 인덱스 -> 길이 - 1
    printf("%c\n", last);  // o

    return 0;
}
```
### 포인터 이용
```c
char *p = str;

while (*p != '\0') 
    p++;
p--;  // 마지막 문자로 이동

printf("%c\n", *p);
```
### while문
```c
int len = 0;
while (word[len] != '\0')
    len++;
```

# 문자열을 입력 받자
### fgets() 함수
```c
fgets(str, sizeof(str), stdin);
```
- str에 저장, sizeof(str) - 1까지 읽으라, 표준입력(키보드)
- fgets()는 원래 파일 읽기 함수 나중에 배움. //26.10.07
```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[51];
    int idx = 0;

    printf("문자열 입력(50자 안): ");
    fgets(str, sizeof(str), stdin);

    // 개행문자 제거
    // str에서 \n이 처음 나오는 위치를 찾아 \0로 교체
    str[strcspn(str, "\n")] = '\0';

    printf("입력 받은 문자열: %s\n", str);

    printf("문자 단위로 출력: ");
    while (str[idx] != '\0')
    {
        printf("%c", str[idx]);
        idx++;
    }
    putchar('\n');

    return 0;
}
```
- gets는 버퍼 오버플로우 우려로 쓰면 안됨. gets_s는 MSVC에서만 지원.
