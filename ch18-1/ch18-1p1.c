#include <stdio.h>

void prn_str(const char** ptr, size_t len);       // char* ptr[]
void prn_menu(const char* (*ptr)[3], size_t row); // char* ptr[][3]

int main(void)
{
	// 1차원 포인터 배열
	const char* vegetable[4] = {
		"Onion", "Potato", "Pumpkin", "Lettuce" };
	// 2차원 포인터 배열
	const char* menu[][3] = {
		{ "김밥", "라면", "떡볶이" },
		{ "커피", "주스", "녹차" }
	};
	size_t len = sizeof(vegetable) / sizeof(vegetable[0]); // 32 ÷ 8
	size_t row = sizeof(menu) / sizeof(menu[0]);           // 48 ÷ 24

	prn_str(vegetable, len);
	prn_menu(menu, row);

	return 0;
}

void prn_str(const char** ptr, size_t len)
{
	puts("채소 출력");
	for (size_t i = 0; i < len; i++)
		printf("%s\t", ptr[i]);  // *(ptr + i)
	putchar('\n');
}

void prn_menu(const char* (*ptr)[3], size_t row)
{
	puts("메뉴 출력");
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < 3; j++)
			printf("%s\t", ptr[i][j]); // *(*(ptr + i) + j)
		
		putchar('\n');
	}
}
