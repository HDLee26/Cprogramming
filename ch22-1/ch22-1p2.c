// 구조체 연습1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

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

	printf("학번을 입력하시오: ");
	scanf("%d", &std.id);

	printf("이름을 입력하시오: ");
	scanf(" %s", std.name);

	printf("주소를 입력하시오: ");
	scanf(" %[^\n]s", std.address);

	printf("학번: %d\n", std.id);
	printf("이름: %s\n", std.name);
	printf("주소: %s\n", std.address);

	return 0;
}
