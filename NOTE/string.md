## 문자열의 길이를 구하자
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

## 문자열을 입력 받자
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
