// *************************
// 제목: 키보드로 입력 받은 값을 배열에 저장하는 함수를 이용한 프로그램
// 날짜: 2026. 9. 29.
// 작성: 2600160 이현도
// *************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
void get_data(int* param, int len);

int main(void)
{
	int data[5] = { 0 };
	int len = sizeof(data) / sizeof(data[0]);

	get_data(data, len); // &data[0]

	for (int i = 0; i < len; i++)
		printf("%d번째 data: %d\n", i + 1, data[i]);

	return 0;
}

void get_data(int* arr, int len)
{

	for (int i = 0; i < len; i++)
	{
		printf("%d번째 data를 입력하시오: ", i+1);
		scanf("%d", arr + i);  // i가 1씩 커질 때마다 다음 값을 저장할 주소로 넘어감
	}
}
