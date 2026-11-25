# 실습과제 1
```c
#define _CRT_SECURE_NO_WARNINGS
```
- 문자열 관련 함수들의 보안 경고 무시용
```c
#include <stdio.h>
#include <string.h>
```
- stdio.h와 string.h을 포함하라
```c
int main(void)
```
- main 함수 시작
```c
	char str[50] = { '\0' };
	char cat[50];
```
- 이어붙인 문자열을 저장할 배열과 입력한 문자열을 저장할 배열
```c
	while (1)
```
- 무한 루프 시작
```c
		fputs("문자열 입력: ", stdout);
```
- 안내문
```c
		if (fgets(cat, sizeof cat, stdin) != NULL)
			cat[strcspn(cat, "\n")] = '\0';
```
- 문자열 입력 받아 cat에 저장하고 '\n' 지움
```c
		if (strcmp(cat, "quit") == 0) {
			puts("종료");
			break;
		}
```
- 입력한 문자열이 quit이면 무한루프 탈출
```c
		if (strlen(cat) + 2 <= sizeof(str) - strlen(str)) {
			strcat(str, " ");
			strcat(str, cat);
		}
```
- str에 빈 공간이 남아있는지 체크하고 cat의 내용을 이어붙임
- 공백 문자, '\0' 문자 2칸이 더 필요함.
```c
		else {
			puts("더이상 빈 공간이 없습니다.");
			break;
    	}
```
- 빈 공간이 없으면 안내문 출력하고 루프 종료
```c
		printf("지금까지 입력된 문자열: %s\n", str);
```
- 안내문
```c
	return 0;
```
- 0을 반환하고 main 함수 종료

### 실행결과
<img width="396" height="254" alt="image" src="https://github.com/user-attachments/assets/3521b745-2ff5-4820-8e82-e43728c5a3a2" />
<img width="491" height="155" alt="image" src="https://github.com/user-attachments/assets/d0c5ab8e-7bce-4b7d-95ee-735bf274c102" />

