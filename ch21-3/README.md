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

# 실습과제 3
```c
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
```
- 문자열 관련 함수들의 보안 경고 무시용 & 리턴값 관련 경고 방지용
```c
#include <stdio.h>
#include <string.h>
```
- stdio.h, string.h 파일을 포함하라
```c
char* my_strcpy(char* dest, size_t size, char* src)
```
- 문자열을 통째로 옮기는 함수 자작
```c
	size_t i = 0;
```
- 제어변수
```c
	if (strlen(src) <= size)
```
- 옮길 문자열의 길이가 저장할 배열 크기보다 작으면 실행
```c
		while(src[i] != '\0') {
			dest[i] = src[i];
			i++;
		}
```
- 옮길 문자열의 '\0'까지 문자를 하나씩 dest 배열에 옮김
```c
	dest[i] = '\0';
```
- 문자 다 옮긴 후 '\0' 붙여줌
```c
	return dest;
```
- dest의 주소 리턴
```c
int main(void)
```
- main 함수 시작
```c
	char str1[20] = "1234567890";
	char str2[20];
```
- 옮길 문자열 저장한 배열과 복사본 저장할 배열
```c
	char* ptr;
```
- 함수 반환값 저장할 포인터 변수
```c
	ptr = my_strcpy(str2, sizeof(str2), str1);
```
- my_strcpy 함수 호출
```c
	printf("문자열 %s 길이 %zu\n", str1, strlen(str1));
	printf("주소(str2) %p 주소(반환값) %p\n", str2, ptr);
```
- 결과 출력
```c
	return 0;
```
- 0을 반환하고 main 함수 정상 종료

### 실행결과
<img width="464" height="69" alt="image" src="https://github.com/user-attachments/assets/3fee7a38-d2fc-46b1-bbae-5df2ab5c67d2" />

# 실습과제 4
```c
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
```
- 문자열 관련 함수들의 보안 경고 무시용 & 리턴값 관련 경고 방지용
```c
#include <stdio.h>
#include <string.h>
```
- stdio.h, string.h 파일을 포함하라
```c
char* my_strcat(char* dest, size_t size, const char* src)
```
- 문자열 이어붙이는 함수 자작
```c
	size_t i = strlen(dest);
	size_t j = 0;
```
- i는 dest의 '\0' 위치를 저장. j는 src 첫 위치 저장.
```c
	if (strlen(src) + strlen(dest) < size)
```
- 두 문자열 길이의 합 + '\0' <= 도착지 배열 크기이어야 실행
```c
		while (src[j] != '\0') 
			dest[i++] = src[j++];
```
- src의 문자열의 끝까지 문자를 하나씩 이어붙임. 
```c
	dest[i] = '\0';
```
- dest 끝에 '\0' 붙여줌
```c
	return dest;
```
- dest의 주소 반환
```c
int main(void)
```
- main 함수 시작
```c
	char str1[20] = "First~";
	char str2[20] = "Second";
```
- str1 도착지 배열, str2 이어붙일 문자열
```c
	char* ptr = NULL;
```
- 반환된 주소 저장할 포인터 변수
```c
	ptr = my_strcat(str1, sizeof(str1), str2);
```
- 자작 my_strcat 함수 호출
```c
	printf("문자열 %s 길이 %zu\n", str1, strlen(str1));
	printf("주소(str1) %p 주소(반환값) %p\n", str1, ptr);
```
- 결과 출력
```c
	return 0;
```
- 0을 반환하고 main 함수 정상 종료

### 실행결과
<img width="472" height="76" alt="image" src="https://github.com/user-attachments/assets/013e5926-3b6b-42bc-b36d-4dade91c88af" />

# 실습과제 5

### 실행결과
<img width="271" height="181" alt="image" src="https://github.com/user-attachments/assets/20bcebc4-1b23-4e32-aa48-a92bc9dea93c" />







