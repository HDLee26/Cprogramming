// 한글 문자열 입출력
// 한글은 cp949는 2바이트 utf-8은 3바이트 차지함.
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
#include <string.h>

typedef struct person {
	char name[10];
	char address[30];
	char car_number[10];
}Person;

int ClearLineFromReadBuffer(void)
{
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF) 
	{ }

	if (ch == EOF && ferror(stdin))
		return -1; // 오류

	return 1; // 정상
}

int input(char* str, int size)
{
	if (fgets(str, size, stdin) == NULL)
	{
		// 입력 오류
		if (ferror(stdin))
			return -1;
		// EOF
		if (feof(stdin))
			return 0;
	} 

	size_t pos = strcspn(str, "\n");
	// fgets를 통해 읽은 문자열에 '\n' 있으면 제거
	if (str[pos] == '\n')
		str[pos] = '\0';
	// 읽은 문자열에 '\n' 없으면 버퍼를 비움
	else if (ClearLineFromReadBuffer() == -1)
		return -1; // 버퍼 비우기 오류
	// 정상
	return 1;
}

int main(void)
{
	Person std1 = { '\0' };
	int check;

	fputs("이름: ", stdout);
	check = input(std1.name, sizeof(std1.name));

	if (check == 1)
	{
		fputs("주소: ", stdout);
		input(std1.address, sizeof(std1.address));
	}

	if (check == 1)
	{
		fputs("자동차번호: ", stdout);
		input(std1.car_number, sizeof(std1.car_number));
	}

	// EOF 또는 오류 처리
	if (check == -1)
	{
		fputs("입력 오류\n", stderr);
		return 1;
	}
	if (check == 0)
	{
		puts("EOF");
		return 0;
	}

	fputs("이름: ", stdout);
	puts(std1.name);
	fputs("주소: ", stdout);
	puts(std1.address);
	fputs("자동차번호: ", stdout);
	puts(std1.car_number);

	return 0;
}
