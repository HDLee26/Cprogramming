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

# 실습과제 2
```c
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
```
- 문자열 관련 함수들의 보안 경고 무시용 & 리턴값 관련 경고 방지용
```c
#include <stdio.h>
```
- stdio.h 파일을 포함하라
```c
size_t my_strlen(char* str);
```
- string.h 없이 문자열 길이 구하는 함수
```c
void removeBSN(char* str);
```
- 입력 받은 문자열의 '\n' 제거하는 함수
```c
int main(void)
```
- main 함수 시작
```c
	char str[100];
```
- 입력 받은 문자열 저장할 배열
```c
	fputs("문자열 입력: ", stdout);
	fgets(str, sizeof(str), stdin);
	printf("길이: %zu | 내용: %s\n", my_strlen(str), str);
```
- 문자열 입력 받고 출력. fgets는 문자열 그대로 받아 뒤에 '\0' 추가하므로 그 직전에 '\n' 저장되어있음.
```c
	removeBSN(str);
```
- 문자열의 '\n' 제거
```c
	printf("길이: %zu | 내용: %s\n", my_strlen(str), str);
```
- 제거 후 문자열 출력
```c
	return 0;
```
- 0을 반환하고 main 함수 정상 종료
```c
size_t my_strlen(char* str) {
	size_t i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}
```
- 문자열 길이를 구하는 자작 함수.'\0' 전까지의 문자 개수를 셈.
```c
void removeBSN(char* str) {
	size_t len = my_strlen(str);
	str[len - 1] = '\0';
}
```
- 문자열의 '\n' 제거하는 함수. 문자열의 끝부분이 '\n', '\0'로 저장되어 있을 것으로 가정함.

### 실행결과 
<img width="284" height="96" alt="image" src="https://github.com/user-attachments/assets/d7075df1-2a3a-443c-a722-f00797315d53" />



