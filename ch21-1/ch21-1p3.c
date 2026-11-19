#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>

int main(void)
{
	char name[10] = { '\0' };
	char blood_type[5] = { '\0' };

	printf("이름을 입력하세요: ");
	scanf("%s", name);
	getchar();
	printf("혈액형을 입력하세요: ");
	scanf("%s", blood_type);

	printf("이름: %s\n", name);
	printf("혈액형: %s\n", blood_type);

	return 0;
}