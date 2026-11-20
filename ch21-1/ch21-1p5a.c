// 입력 받은 문자열을 scanf("%c")만 이용해서 옮기기
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>

int main(void)
{
	char str[20] = { '\0' };
	char tmp;

	printf("문자열을 입력하세요: ");
	
	for (size_t i = 0; i < sizeof(str) - 1; i++)
	{
		scanf("%c", &tmp);
		
		if (tmp == '\n')
		{
			str[i] = '\0';
			break;
		}
		
		str[i] = tmp;
	}

	printf("문자열: %s\n", str);
	return 0;
}
