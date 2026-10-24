// 4개의 문자열을 입력 받고 각 문자열의 첫 글자만 비교해 사전식 순서를 구함
// 완전한 사전식 순서가 아님.
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>

void input(char arr[][11], int n);    // char (*arr)[11]
void get_dict(char arr[][11], int n); // char (*arr)[11]

int main(void)
{
	// 각 행은 문자 최대 10개와 종료 문자 '\0'을 저장
	char strs[4][11] = { '\0' };
	int rows = sizeof(strs) / sizeof(strs[0]);

	input(strs, rows);
	get_dict(strs, rows);

	return 0;
}
// 각 행에 문자열을 입력받는 함수
void input(char arr[][11], int n)
{
	// 각 행의 시작 위치만 알면 되므로 이중반복문 필요 없음. 
	for (int i = 0; i < n; i++)
	{
		printf("%d번째 문자열 입력: ", i + 1);
		// 이것들 입력하자 melon, blueberry, orange, apple
		scanf("%10s", &arr[i][0]);   // arr[i] 혹은 *(arr + i)
	}
}
// 사전식 순서를 비교하여 가장 뒤에 나오는 단어를 출력하는 함수
void get_dict(char arr[][11], int n)
{
	int tailNum = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i][0] > arr[tailNum][0])  // *(*(arr + i) + 0) > *(*(arr + tailNum) + 0)
			tailNum = i;                  // 혹은 **(arr + i) > **(arr + tailNum)
	}
	printf("사전상 가장 뒤에 나오는 단어: %s\n", arr[tailNum]); // *(arr + tailNum)
}

