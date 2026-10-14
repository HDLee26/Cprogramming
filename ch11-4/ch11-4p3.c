// 키보드로부터 입력 받은 문자를 출력하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

int main(void)
{
	char ch;

	while (1)
	{
		printf("문자 입력: ");
		scanf(" %c", &ch);
		printf("입력한 문자 : %c | 아스키코드 : %d\n", ch, ch);

		// 탈출 조건
		if ((ch == 'q') || (ch == 'Q'))
		{
			printf("프로그램 종료\n");
			break;
		}
	}
	return 0;
}
