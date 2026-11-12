// 구조체 연습2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct car
{
	char model[11];
	char number[21];
	int km;
};

int main(void)
{
	struct car c1;
	printf("모델을 입력하시오: ");
	scanf(" %s", c1.model);
	printf("번호판을 입력하시오: ");
	scanf(" %s", c1.number);
	printf("주행거리를 입력하시오: ");
	scanf(" %d", &c1.km);

	printf("1. 모델: %s\n", c1.model);
	printf("2. 번호판: %s\n", c1.number);
	printf("3. 주행거리: %d km\n", c1.km);

	return 0;
}
