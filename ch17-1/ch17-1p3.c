#include <stdio.h>
void prn_str(char** ptrarr, int cnt);
int main(void)
{
	char* ptrarr[] = { "eagle", "tiger", "lion", "squirrel" };
	int cnt;
	cnt = sizeof(ptrarr) / sizeof(ptrarr[0]); // 원소 개수 구함

	prn_str(ptrarr, cnt); // 첫 번째 원소의 주소-> 이중포인터

	return 0;
}
void prn_str(char** ptrarr, int cnt)
{
	int j;
	for (int i = 0; i < cnt; i++)
	{
		j = 0;
		// *ptrarr[i] -> 각 단어의 첫 글자
		// +j로 옆글자로 이동
		while (*(ptrarr[i]+j) != 0) // Null문자가 아닌 동안
		{
			printf("%c", *(ptrarr[i]+j));  // 한글자씩 출력
			j++;
		}
		printf("\n");    // 다음 단어로
	}
}
