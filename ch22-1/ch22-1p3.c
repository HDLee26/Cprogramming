// 구조체 연습2
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>

struct car
{
	char model[11];
	char plate_number[21];
	int mileage;
};

int main(void)
{
	struct car c1 = { '\0', '\0', 0 };

	fputs("모델을 입력하시오: ", stdout);
	scanf(" %s", c1.model);
	fputs("번호판을 입력하시오: ", stdout);
	scanf(" %s", c1.plate_number);
	fputs("주행거리를 입력하시오: ", stdout);
	scanf("%d", &c1.mileage);

	printf("모델: %s\n", c1.model);
	printf("번호판: %s\n", c1.plate_number);
	printf("주행거리: %d km\n", c1.mileage);

	return 0;
}
