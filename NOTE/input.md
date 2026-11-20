# 정수를 여러 개 입력 받자
### 1. fgets로 한 줄로 입력 받아 strtol로 분리하기
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char line[100];
    int a, b, c;
    char *p;

    printf("정수 3개 입력: ");
    fgets(line, sizeof(line), stdin);

    p = line;
    a = (int)strtol(p, &p, 10);
    b = (int)strtol(p, &p, 10);
    c = (int)strtol(p, &p, 10);

    printf("%d %d %d\n", a, b, c);
    return 0;
}
```
### 2. fgets로 한 줄로 입력 받아 sscanf로 해석하기
```c
#include <stdio.h>

int main() {
    char line[100];
    int a, b, c;

    printf("정수 3개 입력: ");
    fgets(line, sizeof(line), stdin);

    sscanf(line, "%d %d %d", &a, &b, &c);

    printf("%d %d %d\n", a, b, c);
    return 0;
}
```
### 3. getchar로 한 글자씩 읽은 뒤 숫자 재구성하기
```c
#include <stdio.h>

int readInt() {
    int num = 0;
    int ch;
    int sign = 1;

    ch = getchar();
    while (ch == ' ' || ch == '\n' || ch == '\t') {
        ch = getchar();
    }

    if (ch == '-') {
        sign = -1;
        ch = getchar();
    }

    while (ch >= '0' && ch <= '9') {
        num = num * 10 + (ch - '0');
        ch = getchar();
    }

    return num * sign;
}

int main() {
    int a, b, c;

    printf("정수 3개 입력: ");
    a = readInt();
    b = readInt();
    c = readInt();

    printf("%d %d %d\n", a, b, c);
    return 0;
}

```

# 문자열을 입력 받자
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[51];
	int idx = 0;

	// fgets함수
	printf("문자열 입력(50자 제한): ");
	fgets(str, sizeof(str), stdin);  // 배열 str에 sizeof(str)-1까지 읽어서 저장. 공백, 탭, 개행까지 모두 저장됨.
	str[strcspn(str, "\n")] = '\0';  // 문자열에서 \n이 처음 나오는 위치를 찾아서 그자리를 \0로 바꿈
	printf("입력 받은 문자열: %s\n", str);

	// 개행 문자 \n 있는 곳에서 끊기
	printf("문자열 입력(50자 제한): ");
	scanf("%[^\n]s", str);
	printf("입력 받은 문자열: %s\n", str);

	return 0;
}
```
# 버퍼를 비우자
```c
// '\n' 읽고 반환하는데 저장 안하니까 버려짐.
scanf("%d", &x);
getchar();   

// whitespace가 아닌 문자가 나올 때까지 whitespace는 읽어서 버림
scanf(" %s", str);

// 버퍼를 깔끔히 비우려면 함수로 만들어서 무한 반복시키자
void ClearReadBuffer(void)
{
    int ch;  // 문자 값과 EOF를 구별하기 위해 int 사용

    while ((ch = getchar()) != '\n' && ch != EOF) {
		 // getchar로 읽은 문자를 ch에 저장하므 '\n'를 읽고 나서야 종료됨
		 // 두 번째 조건은 문자열에 '\n'이 없는 경우를 위해 필요.
		 // 파일 끝에 도달하면 getchar()는 EOF를 반환하기 때문.
	}	
}

```
