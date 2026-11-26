// 함수 포인터로 고칠 수 있을 듯한데.
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
#include <string.h>

void input(char (*strs)[50], size_t len);
size_t head(char (*strs)[50], size_t rows);
size_t tail(char (*strs)[50], size_t rows);

int main(void)
{
	char strs[5][50] = {'\0'};
	size_t rows = sizeof(strs) / sizeof(strs[0]);
	size_t first, end;

	input(strs, rows);
	first = head(strs, rows);
	end = tail(strs, rows);
	printf("사전 제일 앞: %s \n", strs[first]);
	printf("사전 제일 뒤: %s \n", strs[end]);

	return 0;
}

void input(char (*strs)[50], size_t rows)
{
	size_t i;
	for (i = 0; i < rows; i++)
	{
		printf("문자열 입력(%d): ", i + 1);
		if (fgets(strs[i], 50, stdin) != NULL)
			strs[i][strcspn(strs[i], "\n")] = '\0';
	}
}

size_t head(char (*strs)[50], size_t rows)
{
	size_t first = 0;
	for (size_t i = 1; i < rows; i++)
	{
		if (strcmp(strs[i], strs[first]) < 0)
			first = i;
	}
	return first;
}

size_t tail(char (*strs)[50], size_t rows)
{
	size_t end = 0;
	for (size_t i = 1; i < rows; i++)
	{
		if (strcmp(strs[i], strs[end]) > 0)
			end = i;
	}
	return end;
}
