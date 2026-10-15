// ***********************************
//  제목 : 두 소문자 단어를 입력 받아 사전식 순서를 비교하는 프로그램
//  날짜 : 2026년 9월 18일
//  작성 : 2600160 이현도
// ***********************************
#define _CRT_SECURE_NO_WARNINGS // VS scanf함수 보안 경고 방지용
#pragma warning(disable:6031)  // 리턴값관련 경고 방지용

#include <stdio.h>

int main(void)
{
	char s1[51] = { 0 };
	char s2[51] = { 0 };
	size_t i;

	// 입력
	printf("소문자 단어 입력1: ");
	scanf("%50s", s1);
	printf("소문자 단어 입력2: ");
	scanf("%50s", s2);

	// 두 문자열 중 짧은 쪽의 길이를 찾음
	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0'))
		i++;

	// 찾은 길이로 마지막 글자끼리 아스키코드값 비교
	if (s1[i] == s2[i])
		printf("두 문자열은 동일함.");
	else if (s1[i] < s2[i])
		printf("사전에서 앞에 나오는 단어: %s\n", s1);
	else
		printf("사전에서 앞에 나오는 단어: %s\n", s2);

	return 0;
}
