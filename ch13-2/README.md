# 실습과제 1
- C언어에서 문자를 메모리에 저장하는 방식에 대하여 설명하라\
  문자를 아스키코드를 통해 정수로 바꾸어 저장함.
- NULL 문자의 용도를 설명하라\
  문자열의 끝을 표시하기 위함.
- 메모리에 저장된 문자열의 끝을 찾는 방법을 설명하라\
  NULL 문자의 위치를 찾는다.
- strlen()함수를 사용하지 않고 문자열의 길이를 구하는 알고리즘을 설명하라\
  반복문을 이용하여 문자열의 첫 번째 문자부터 \0까지의 문자의 개수를 구한다.

---

# 실습과제 2
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
int main(void)
```
- main함수 시작
```c
char s[50] = { 0 };
```
- 문자열을 저장하기 위한 문자형 배열 s 선언 및 NULL 문자로 초기화
```c
int cnt;
```
- 문자열의 길이를 저장할 변수 cnt 선언
```c
printf("문자열을 입력하시오: ");
scanf("%[^\n]s", s);
```
- 입력된 문자열을 배열 s에 저장. 배열명 s가 주소이므로 &연산은 불필요

```c
cnt = 0;
while (s[i] != '\0')
  cnt++;
```
- char형 배열 s에 저장된 문자가 NULL 문자가 아닌 동안 cnt를 증가시켜 문자열의 길이를 구함
```c
for (int i = 0; i < cnt; i++)
  printf("%d번재 문자 %c\n", i+1, s[i]);
```
- 저장된 문자열을 문자별로 각각 출력
```c
return 0;
```
- 0을 반환하고 main함수 정상 종료

### 실행결과
<img width="305" height="277" alt="image" src="https://github.com/user-attachments/assets/d5de9b0b-a33f-4ba9-b24b-6985bd0c73d8" />


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
int main(void)
```
- main함수 시작
```c
char s[50] = { 0 };
```
- 문자열을 저장하기 위한 문자형 배열 s 선언 및 NULL 문자로 초기화
```c
int len;
```
- 문자열의 길이를 저장할 변수 len 선언
```c
printf("문자열 입력(대소문자만 이용): ");
scanf("%s", s);
```
- 입력된 문자열을 배열 s에 저장. 배열명 s가 주소이므로 &연산은 불필요

```c
len = 0;
while (s[i] != '\0')
  len++;
```
- 문자형 배열 s에 저장된 문자가 NULL 문자가 아닌 동안 len을 증가시켜 문자열의 길이를 구함
```c
for (int i = 0; i < len; i++)
```
- 대문자를 소문자로, 소문자를 대문자로 바꾸기 위한 반복문
```c
  if (s[i] >= 65 && s[i] <= 90)
    s[i] += 32;
```
- 대문자는 소문자로 변환
```c
  else if (s[i] >= 97 && s[i] <= 122)
    s[i] -= 32;
```
- 소문자는 대문자로 변환
```c
printf("%s", s);
```
- 바꾼 문자열을 출력
```c
return 0;
```
- 0을 반환하고 main함수 정상 종료

## 실행결과
<img width="250" height="85" alt="image" src="https://github.com/user-attachments/assets/ccc17469-06d9-4f03-8a0f-1425e1bca419" />

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
int main(void)
```
- main함수 시작
```c
	char s1[51] = { 0 };
	char s2[51] = { 0 };
```
- 소문자 단어 저장할 char형 배열 2개 선언
```c
	size_t i;
```
- 문자열의 길이를 저장할 변수 선언
```c
	printf("소문자 단어 입력1: ");
	scanf("%50s", s1);
	printf("소문자 단어 입력2: ");
	scanf("%50s", s2);
```
- 50글자까지만 입력 받아서 각각 저장
```c
	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0'))
		i++;
```
- strlen 없이 문자열의 길이를 구함
- 두 문자열 중 짧은 쪽의 길이를 저장함
```c
	if (s1[i] == s2[i])
		printf("두 문자열은 동일함.");
```
- 찾은 길이로 마지막 글자끼리 아스키코드값 비교
- 두 글자가 동일하면 s1[i] == s2[i] == '\0'
```c
	else if (s1[i] < s2[i])
		printf("사전에서 앞에 나오는 단어: %s\n", s1);
	else
		printf("사전에서 앞에 나오는 단어: %s\n", s2);
```
- 동일하지 않으면 찾은 길이에서 마지막 문자끼리 서로 비교함
- 두 문자열의 길이가 서로 달라도 \0의 아스키코드가 0이니까 길이가 더 짧은 단어가 출력됨.
```c
	return 0;
```
- 0을 반환하고 main 함수 종료

### 실행 결과
<img width="290" height="103" alt="image" src="https://github.com/user-attachments/assets/3a082f47-9142-4de1-b58b-bb81ffffaa72" />
<img width="312" height="107" alt="image" src="https://github.com/user-attachments/assets/83e14e22-4203-4dd0-91ac-1ca7772d59ed" />
<img width="301" height="103" alt="image" src="https://github.com/user-attachments/assets/6f77c6ed-04ef-4294-a076-49440b99d11e" />

---

# 실습과제 5
```c
#include <stdio.h>
```
- stdio.h 헤더파일을 포함하라
```c
int main(void)
```
- main함수 시작
```c
	char* fruits[] = { "banana", "apple", "orange", "melon" };
```
- 과일 이름 4개가 든 문자열 배열 선언
```c
	size_t len = sizeof(fruits) / sizeof(fruits[0]); // 32 ÷ 8
```
- 배열의 길이를 저장할 변수 선언
```c
	const char* first; 
```
- 문자열의 첫글자의 주소를 저장할 char* 포인터. const char*은 가리키는 문자열의 내용을 수정하지 않겠다는 의미.
```c
	first = fruits[0];
```
- first가 첫 번째 문자열을 가리키게 함
```c
	for (size_t i = 1; i < len; i++)
		if (*fruits[i] < *first)
			first = fruits[i];
```
- 비교할 때는 문자열의 첫 글자를 꺼내서, 결과 저장은 첫 글자의 주소로.
```c
	printf("사전에서 가장 앞에 나오는 단어: %s\n", first);
```
- 결과 출력
```c
	return 0;
```
- 0을 반환하고 main함수 정상 종료

### 실행결과
<img width="320" height="66" alt="image" src="https://github.com/user-attachments/assets/7f055282-da68-4a29-b575-0e837834bc0b" />



