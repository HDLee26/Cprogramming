// ***********************************
//  제목 : 두 문자열을 입력 받아 사전식 순서를 비교하는 프로그램
//  날짜 : 2026년 9월 18일
//  작성 : 2600160 이현도
// ***********************************
#define _CRT_SECURE_NO_WARNINGS // VS scanf함수 보안 경고 방지용
#pragma warning(disable:6031)  // 리턴값관련 경고 방지용

#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[51] = { 0 };
	char s2[51] = { 0 };
	int i, len1 = 0, len2 = 0, len;

	printf("문자열 입력1: ");
	scanf("%50s", s1);
	printf("문자열 입력2: ");
	scanf("%50s", s2);

	// 두 문자열이 동일한지 아닌지 비교
	if (strcmp(s1, s2) == 0)
	{
		printf("두 문자열은 같음\n");
		return 0;
	}

	// 문자열 길이 구하기
	for (int i = 0; s1[i] != 0; i++)
		len1++;

	for (int i = 0; s2[i] != 0; i++)
		len2++;

	// 둘 중 짧은 길이만큼만 문자 비교
	if (len1 < len2)
		len = len1;
	else
		len = len2;

	// 앞 글자부터 사전식 순서 비교
	for (int i = 0; i < len; i++)
	{
		if (s1[i] < s2[i])
		{
			printf("사전에서 앞에 나오는 단어: %s", s1);
			return 0;
		}
		else if (s1[i] > s2[i])
		{
			printf("사전에서 앞에 나오는 단어: %s", s2);
			return 0;
		}
	}

	// len 개까지의 문자가 모두 같은 경우를 위한 처리
	if (len1 < len2)
		printf("사전에서 앞에 나오는 단어: %s\n", s1);
	else
		printf("사전에서 앞에 나오는 단어: %s\n", s2);

	return 0;

}
