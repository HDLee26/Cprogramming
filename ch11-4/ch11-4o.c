// string.h 없이 strlen, strcpy, strcat 구현
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
// 문자열 길이를 구하는 함수
int strlen(char str[])
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}
// 문자열을 복사하는 함수
void strcpy(char dest[], const char src[])
{
	int src_len = strlen(src);
	for (int i = 0; i < src_len; i++)
		dest[i] = src[i];
	dest[src_len] = '\0'; // 문자열 끝에 null문자 붙여줌
}
// 문자열을 이어붙이는 함수 (src의 문자열을 dest로 이어붙임)
void strcat(char dest[], const char src[])
{
	int i = strlen(dest);
	int src_len = strlen(src);
	for (int j = 0; j < src_len; j++)
		dest[i++] = src[j];
	dest[i] = '\0';
}
int main(void)
{
	char str[101] = "Computer Science";
	char copy[101] = "";
	char mystr[201] = "My major : ";

	printf("문자열의 길이: %d\n", strlen(str));
	strcpy(copy, str);
	printf("복사한 문자열: %s\n", copy);
	strcat(mystr, str);
	printf("이어붙인 문자열: %s\n", mystr);

	return 0;
}
