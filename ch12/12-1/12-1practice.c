// *************************
//  제목 : 주소연산자의 이용
//  날짜 : 2026년 9월 5일
//  작성 : 2600160 이현도
// *************************

#include <stdio.h>

int main(void)
{
	char a = 'A';
	int b = 36;
	double c = 3.141592;

	printf("char형 변수 a의 주소 : %p \n", &a);
	printf("int형 변수 b의 주소 : %p \n", &b);
	printf("double형 변수 c의 주소 : %p \n", &c);

	return 0;
}
