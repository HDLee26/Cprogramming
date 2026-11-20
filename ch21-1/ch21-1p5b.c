// 입력 받은 문자열을 scanf("%c")만 이용해서 옮기기
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>

int main(void)
{
	char str[20] = { '\0' };
	
	size_t i;

	printf("문자열을 입력하세요: ");
	
	// str[19]는 '\0'으로 채워야 해서 -1 함.
	for (i = 0; i < sizeof(str) - 1; i++)
	{
		// 더 읽을 문자가 없거나, 입력 오류가 발생한 경우
		if (scanf("%c", &str[i]) != 1)
			break;
		
		if (str[i] == '\n')
			break;
	}

	// '\n'을 읽은 위치 혹은 마지막으로 저장한 문자 바로 뒤에 '\0' 붙임.
	str[i] = '\0';
	printf("문자열: %s\n", str);

	return 0;
}