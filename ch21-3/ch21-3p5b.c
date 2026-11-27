
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
#include <string.h>

void input(char (*strs)[50], size_t len);
int is_before(int cmp);
int is_after(int cmp);
size_t find_index(char (*strs)[50], size_t rows, int (*update_index)(int));

int main(void)
{
	char strs[5][50] = { '\0' };
	size_t rows = sizeof(strs) / sizeof(strs[0]);
	size_t first, end;

	input(strs, rows);
	first = find_index(strs, rows, is_before);
	end = find_index(strs, rows, is_after);
	printf("사전 제일 앞: %s \n", strs[first]);
	printf("사전 제일 뒤: %s \n", strs[end]);

	return 0;
}

void input(char (*strs)[50], size_t rows)
{
	size_t i;
	for (i = 0; i < rows; i++)
	{
		printf("문자열 입력(%zu): ", i + 1);
		if (fgets(strs[i], 50, stdin) != NULL)
			strs[i][strcspn(strs[i], "\n")] = '\0';
	}
}

size_t find_index(char (*strs)[50], size_t rows, int (*update_index)(int))
{
	size_t index = 0;
	for (size_t i = 1; i < rows; i++)
	{
		// 반환값은 양수 0 음수 중 하나
		int cmp = strcmp(strs[i], strs[index]);

		if (update_index(cmp))
			index = i;
	}
	return index;
}

// 반환값이 음수이면 참, strs[i]가 사전상 앞, index 갱신
int is_before(int cmp)
{
	return cmp < 0;
}
// 반환값이 양수이면 참, strs[i]가 사전상 뒤, index 갱신
int is_after(int cmp)
{
	return cmp > 0;
}

