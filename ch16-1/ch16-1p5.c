// 4개의 문자열을 입력 받고 각 문자열의 첫 글자만 비교해 사전식 순서를 구함
// 완전한 사전식 순서가 아님.
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
void input(char arr[][11], int n);
void get_dict(char arr[][11], int n);
int main(void)
{
	// 각 행에 10글자까지만 들어감.
	char strs[4][11] = { '\0' };
	int rows = sizeof(strs) / sizeof(strs[0]);

	input(strs, rows);
	get_dict(strs, rows);

	return 0;

}
void input(char arr[][11], int n)
{
	// 각 행의 시작 위치만 알면 되므로 이중반복문 필요 없음. 
	for (int i = 0; i < n; i++)
	{
		printf("%d번째 문자열 입력: ", i + 1);
		// melon, blueberry, orange, apple
		scanf("%10s", &arr[i][0]);
	}
}
void get_dict(char arr[][11], int n)
{
	int tailNum = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i][0] > arr[tailNum][0])
			tailNum = i;
	}
	printf("사전상 가장 뒤에 나오는 단어: %s\n", arr[tailNum]);
}

