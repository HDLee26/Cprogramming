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
