// 4개의 문자열을 입력 받고 strlen없이 각 문자열 길이 구하기
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
void input(char arr[][11], int n);
void get_strlen(char arr[][11], int n);
int main(void)
{
	// 각 행에 10글자까지만 들어감.
	char strs[4][11] = { '\0' };
	int rows = sizeof(strs) / sizeof(strs[0]);

	input(strs, rows);
	get_strlen(strs, rows);

	return 0;

}
void input(char arr[][11], int n)
{
	// 각 행의 시작 위치만 알면 되므로 이중반복문 필요 없음. 
	for (int i = 0; i < n; i++)
	{
		printf("%d번째 문자열 입력: ", i + 1);
		scanf("%10s", &arr[i][0]);
	}
}
void get_strlen(char arr[][11], int n)
{

	for (int i = 0; i < n; i++)
	{
		int len = 0;
		for (int j = 0; arr[i][j] != '\0'; j++)
			len++;
		printf("%d번 문자열의 길이: %d\n", i + 1, len);
	}
		
}


