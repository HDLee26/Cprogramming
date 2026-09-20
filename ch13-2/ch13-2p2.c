// *************************
//  제목 : 문자열의 문자들을 각각 출력하는 프로그램
//  날짜 : 2026년 9월 18일
//  작성 : 2600160 이현도
// *************************

#define _CRT_SECURE_NO_WARNINGS // 보안오류방지
#pragma warning(disable:6031)  // 리턴값관련 경고 방지

#include <stdio.h>

int main(void)
{
	char s[50] = { 0 };
	int i, cnt;

	printf("문자열을 입력하시오: ");
	scanf("%s", s);

	// 문자열 길이 구하기
	i = 0, cnt = 0;
	while (s[i] != '\0')
	{
		i++;
		cnt++;
	}
	
	// 문자 각각 출력
	for (int i = 0; i < cnt; i++)
	{
		printf("%d번재 문자 %c\n", i+1, s[i]);
	}

	return 0;

}
