// 이중포인터로 포인터 배열의 문자열을 출력하는 프로그램
#include <stdio.h>
void prn_str(char** ptrarr, int len);
int main(void)
{
	char* ptrarr[] = { "eagle", "tiger", "lion", "squirrel" }; // 각 원소의 첫 글자의 주소를 저장함
	size_t len = sizeof(ptrarr) / sizeof(ptrarr[0]); // 문자열의 개수 구함 32÷8

	prn_str(ptrarr, len); // 첫 번째 원소의 주소 -> 주소의 주소 -> 이중포인터

	return 0;
}

void prn_str(char** ptrarr, int len) // char* ptrarr[]
{
	for (size_t i = 0; i < len; i++)
		printf("%s\n", *(ptrarr + i)); // ptrarr[i]
	// %s 문자열의 시작 위치가 필요함. **(ptrarr + i) 하면 첫 글자 하나 나옴.
}
