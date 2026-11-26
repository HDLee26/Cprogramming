// strcat 함수 자작
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
#include <string.h>
char* my_strcat(char* dest, size_t size, const char* src)
{	
	size_t i = strlen(dest); // dest의 '\0' 위치
	size_t j = 0;
	// 두 문자열의 길이 합 + '\0' 하나 <= 도착 배열 크기
	if (strlen(src) + strlen(dest) < size)
	{
		while (src[j] != '\0')
			dest[i++] = src[j++];
	}
	dest[i] = '\0';

	return dest;
	// 성공시 dest의 주소 반환, 실패시 놀랍게도 반환값 없음. 정의되지 않은 동작.
}
int main(void)
{
	char str1[20] = "First~";
	char str2[20] = "Second";
	char* ptr = NULL;

	ptr = my_strcat(str1, sizeof(str1), str2);
	printf("문자열 %s 길이 %zu\n", str1, strlen(str1));
	printf("주소(str1) %p 주소(반환값) %p\n", str1, ptr);

	return 0;
}