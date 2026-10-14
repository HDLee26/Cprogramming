// 모든 소문자를 대문자로 변환하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[101] ="";

	printf("소문자 문자열 입력(100글자): ");
	scanf("%100s", str);

	for (int i = 0; i < strlen(str); i++)
		str[i] -= 32;

	printf("변환결과: %s\n", str);
	
	return 0;
}
