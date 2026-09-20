// *************************
//  제목 : 대문자를 소문자로, 소문자를 대문자로 바꾸는 프로그램
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

	printf("문자열 입력: ");
	scanf("%s", s);

	// 문자열 길이 구하기
	i = 0, cnt = 0;
	while (s[i] != '\0')
	{
		i++;
		cnt++;
	}

	// 대->소, 소->대
	for (int i = 0; i < cnt; i++)
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] += 32;
		else if (s[i] >= 97 && s[i] <= 122)
			s[i] -= 32;
	}

	// 바꾼 문자열 출력
	printf("%s", s);

	return 0;

}
