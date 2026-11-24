// 공백을 이용하여 단어의 개수 세기
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[50] = { '\0' };
	int cnt = 0;

	fputs("문자열 입력: ", stdout);
	fgets(str, sizeof(str), stdin);

	for (size_t i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ')
			cnt++;
	}
	printf("단어 수: %d\n", cnt + 1);
	return 0;
}