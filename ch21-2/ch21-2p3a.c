// 한글 문자열 입출력
// 한글은 cp949는 2바이트 utf-8은 3바이트 차지함.

#pragma warning(disable:6031)

#include <stdio.h>
#include <string.h>

typedef struct person {
	char name[20];
	char address[30];
	char car_number[20];
}Person;

void input(char* str, int size)
{
	if (fgets(str, size, stdin) != NULL)
		str[strcspn(str, "\n")] = '\0';
}

int main(void)
{
	Person std1 = { '\0' };

	fputs("이름: ", stdout);
	input(std1.name, sizeof(std1.name));

	fputs("주소: ", stdout);
	input(std1.address, sizeof(std1.address));

	fputs("자동차번호: ", stdout);
	input(std1.car_number, sizeof(std1.car_number));

	fputs("이름: ", stdout);
	puts(std1.name);
	fputs("주소: ", stdout);
	puts(std1.address);
	fputs("자동차번호: ", stdout);
	puts(std1.car_number);

	return 0;
}
