#include <stdio.h>
void prn_str(char** ptrarr, int cnt);
int main(void)
{
	char* ptrarr[] = { "eagle", "tiger", "lion", "squirrel" }; // 각 원소의 첫 글자의 주소를 저장함
	int cnt;
	cnt = sizeof(ptrarr) / sizeof(ptrarr[0]); // 문자열의 개수 구함 32÷8

	prn_str(ptrarr, cnt); // 첫 번째 원소의 주소 -> 이중포인터

	return 0;
}

void prn_str(char** ptrarr, int cnt) // char* ptrarr[]
{
	for (int i = 0; i < cnt; i++)
		printf("%s\n", *(ptrarr + i)); // ptrarr[i]
}
