#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[50] = { '\0' };
	char cat[50];

	while (1)
	{
		fputs("문자열 입력: ", stdout);
		if (fgets(cat, sizeof cat, stdin) != NULL)
			cat[strcspn(cat, "\n")] = '\0';

		// 종료 조건
		if (strcmp(cat, "quit") == 0)
		{
			puts("종료");
			break;
		}
		// str에 빈 공간이 있으면 이어붙임. 공백 한칸 \0 한칸
		if (strlen(cat) + 2 <= sizeof(str) - strlen(str))
		{
			strcat(str, " ");
			strcat(str, cat);
		}
		else
		{
			puts("더이상 빈 공간이 없습니다.");
			break;
		}
			
		printf("지금까지 입력된 문자열: %s\n", str);
	}

	return 0;
}