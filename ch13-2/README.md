# 실습과제 1
- C언어에서 문자를 메모리에 저장하는 방식에 대하여 설명하라\
  문자를 아스키코드를 통해 숫자로 바꾸어 저장함.
- NULL 문자의 용도를 설명하라\
  문자열의 끝을 표시하기 위함.
- 메모리에 저장된 문자열의 끝을 찾는 방법을 설명하라\
  NULL 문자의 위치를 찾는다.
- strlen()함수를 사용하지 않고 문자열의 길이를 구하는 알고리즘을 설명하라\
  문자열의 첫 번째 문자부터 \0까지 문자(char)의 개수를 구한다.

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
int i, cnt;
```
- 정수형 변수 i와 cnt 선언
```c
printf("문자열을 입력하시오: ");
```

```c
scanf("%s", s);
```
- 입력된 문자열을 배열 s에 저장. 배열명 s가 주소이므로 &연산은 불필요
```c
// 문자열 길이 구하기
```
```c
i = 0, cnt = 0;
```
```c
while (s[i] != '\0')
```
- 문자형 배열 s에 저장된 문자가 
```c
i++;
```
- NULL 문자가 아닌 동안
```c
cnt++;
```
- cnt를 증가시켜 문자열의 길이를 구함
```c
for (int i = 0; i < cnt; i++)
```
- 문자를 각각 출력하기 위한 반복문
```c
printf("%d번재 문자 %c\n", i+1, s[i]);
```
- 입력받은 문자열을 각 문자별로 출력
```c
return 0;
```
- 0을 반환하고 main함수 정상 종료

## 실행결과
<img width="263" height="183" alt="image" src="https://github.com/user-attachments/assets/11592ba6-aa99-437f-a6d2-8204fe0c38ad" />

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
int i, cnt;
```

```c
printf("문자열 입력: ");
```

```c
scanf("%s", s);
```
- 입력된 문자열을 배열 s에 저장. 배열명 s가 주소이므로 &연산은 불필요
```c
// 문자열 길이 구하기
```
```c
i = 0, cnt = 0;
```

```c
while (s[i] != '\0')
```
- 문자형 배열 s에 저장된 문자가 
```c
i++;
```
- NULL 문자가 아닌 동안
```c
cnt++;
```
- cnt를 증가시켜 문자열의 길이를 구함
```c
for (int i = 0; i < cnt; i++)
```
- 대문자를 소문자로, 소문자를 대문자로 바꾸기 위한 반복
```c
  if (s[i] >= 65 && s[i] <= 90)
```
- 대문자이면
```c
s[i] += 32;
```
- 소문자로 변환
```c
else if (s[i] >= 97 && s[i] <= 122)
```
- 소문자이면
```c
s[i] -= 32;
```
- 대문자로 변환
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
#include <string.h>
```
- string.h 헤더파일을 포함하라
```c
int main(void)
```
- main함수 시작
```c
char s1[51] = { 0 };
```

```c
char s2[51] = { 0 };
```
- 문자열을 저장할 문자형 배열 s1, 21 선언 및 NULL 문자로 초기화
```c
int i, len1 = 0, len2 = 0, len;
```
- 제언변수 i 선언, 문자열 길이를 저장할 변수 len1, len2, len 선언.
```c
printf("문자열 입력1: ");
```

```c
scanf("%50s", s1);
```

```c
printf("문자열 입력2: ");
```

```c
scanf("%50s", s2);
```
- 문자열 입력 받아 저장
```c
if (strcmp(s1, s2) == 0)
```
- 두 문자열이 동일한지 아닌지 비교
```c
printf("두 문자열은 같음\n");
```
- 같으면 안내문 출력 후
```c
return 0;
```
- 프로그램 종료
```c
for (int i = 0; s1[i] != 0; i++)
```

```c
len1++;
```

```c
for (int i = 0; s2[i] != 0; i++)
```

```c
len2++;
```
- 문자열의 길이를 구함
```c
if (len1 < len2)
```

```c
len = len1;
```

```c
else
```

```c
len = len2;
```
- 두 문자열 중 짧은 길이만큼만 비교하기 위한 처리
```c
for (int i = 0; i < len; i++)
```
- 앞 글자부터 차례로 사전식 순서를 비교하기 위한 반복문
```c
if (s1[i] < s2[i])
```

```c
printf("사전에서 앞에 나오는 단어: %s", s1);
```

```c
return 0;
```
- s1이 앞이면 안내문 출력 후 프로그램 종료
```c
else if (s1[i] > s2[i])
```

```c
printf("사전에서 앞에 나오는 단어: %s", s2);
```

```c
return 0;
```
- s2가 앞이면 안내문 출력 후 프로그램 종료
```c
if (len1 < len2)
```

```c
printf("사전에서 앞에 나오는 단어: %s\n", s1);
```

```c
else
```

```c
printf("사전에서 앞에 나오는 단어: %s\n", s2);
```
- len 개까지의 문자가 모두 같은 경우를 위한 처리
- 짧은 단어가 사전식 순서상 앞에 있음
```c
return 0;
```
- 0을 반환하고 프로그램 정상 종료

## 실행 결과
<img width="241" height="105" alt="image" src="https://github.com/user-attachments/assets/b5c2520c-a8ca-436a-90a4-54e5a899ba56" />
<img width="270" height="94" alt="image" src="https://github.com/user-attachments/assets/c7a71d80-44c9-41a9-9fe6-029f399a838a" />
<img width="283" height="100" alt="image" src="https://github.com/user-attachments/assets/3fe81752-9d03-4642-9fc9-056ab486d353" />


