// strcpy 함수 자작
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
#include <string.h>

char* my_strcpy(char* dest, size_t size, char* src)
{
	size_t i = 0;
	if (strlen(src) <= size)
	{
		while(src[i] != '\0')
		{ 
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return dest;
	// 성공시 반환값은 dest의 주소. 실패시 놀랍게도 반환값이 없음.
}
int main(void)
{
	char str1[20] = "1234567890";
	char str2[20];
	char* ptr;
	ptr = my_strcpy(str2, sizeof(str2), str1);
	printf("문자열 %s 길이 %zu\n", str1, strlen(str1));
	printf("주소(str2) %p 주소(반환값) %p\n", str2, ptr);
	return 0;
}

