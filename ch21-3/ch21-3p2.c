#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>

size_t my_strlen(char* str);
void removeBSN(char* str);

int main(void)
{
	char str[100];

	fputs("문자열 입력: ", stdout);
	fgets(str, sizeof(str), stdin);

	printf("길이: %zu | 내용: %s\n", my_strlen(str), str);
	removeBSN(str);
	printf("길이: %zu | 내용: %s\n", my_strlen(str), str);

	return 0;
}
size_t my_strlen(char* str)
{
	size_t i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}
void removeBSN(char* str) 
{
	size_t len = my_strlen(str);
	str[len - 1] = '\0';
}