// 4개의 문자열을 입력 받고 strlen없이 각 문자열 길이 구하기
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>

void input(char arr[][11], int n);   // char (*arr)[11]
int get_strlen(char str[]);          // char *str
void print_strlen(char arr[][11], int n); // char (*arr)[11]

int main(void)
{
	// 문자열 4개 저장: 각 행은 문자 10개와 종료 문자 '\0'을 저장
	char strs[4][11] = { '\0' };
	int rows = sizeof(strs) / sizeof(strs[0]);

	input(strs, rows);
	print_strlen(strs, rows);

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
		// i번째 행의 시작 주소에 최대 10개의 문자를 입력
		scanf("%10s", &arr[i][0]); // arr[i] 혹은 *(arr + i)
	}
}
// 문자열의 길이를 구하는 함수
int get_strlen(char str[])  
{
	int len = 0;

	for (int i = 0; str[i] != '\0'; i++)
		len++;

	return len;
}
// 각 문자열의 길이를 출력하는 함수
void print_strlen(char arr[][11], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d번 문자열의 길이: %d\n", i + 1, get_strlen(arr[i]));
}
/*
// sizeof(strs[0]) 첫 번째 행의 크기
// 문자열 입력에는 각 행의 첫 번째 문자의 주소를 전달함.
// arr[i]와 &arr[i][0]은 같은 주소를 나타냄.
// %s 출력은 전달된 주소부터 '\0' 직전까지의 문자를 출력함.
*/
