// 'q'나 'Q'를 입력할 때까지 계속 문자 입력 받기
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>

int main(void)
{
	char ch = '\0';

	while (1)
	{
		if ((ch == 'q') || (ch == 'Q'))
		{
			puts("프로그램 종료");
			break;
		}

		fputs("문자입력: ", stdout);
		ch = getchar();
		getchar();  // 버퍼에서 '\n' 버리기
		fputs("입력 된 문자는 ", stdout);
		putchar(ch);
		putchar('\n');
	}

	return 0;
}