// 공백을 이용하여 단어의 개수 세기
#include <stdio.h>

int count_char(const char* str, char target)
{
	int cnt = 0;
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == target)
			cnt++;
	}

	return cnt;
}
int main(void)
{
	char str[50] = { '\0' };
	int cnt = 0;

	fputs("문자열 입력: ", stdout);
	fgets(str, sizeof(str), stdin);

	printf("단어 수: %d\n", count_char(str, ' ') + 1);
	return 0;
}