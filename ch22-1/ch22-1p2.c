// 구조체 연습1
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 구조체 정의
struct student 
{
	int id;
	char name[21];
	char address[31];
};

int main(void)
{
	// 구조체 변수 선언
	struct student std;
	char input[10]; 

	fputs("학번을 입력하시오: ", stdout);
	if (fgets(input, sizeof(input), stdin) != NULL)
		input[strcspn(input, "\n")] = '\0';
	std.id = strtol(input, NULL, 10);

	fputs("이름을 입력하시오: ", stdout);
	if (fgets(std.name, sizeof(std.name), stdin) != NULL)
		std.name[strcspn(std.name, "\n")] = '\0';

	fputs("주소를 입력하시오: ", stdout);
	if (fgets(std.address, sizeof(std.address), stdin) != NULL)
		std.address[strcspn(std.address, "\n")] = '\0';

	printf("학번: %d\n", std.id);
	printf("이름: %s\n", std.name);
	printf("주소: %s\n", std.address);

	return 0;
}
