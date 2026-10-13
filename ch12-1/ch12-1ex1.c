// 포인터 변수의 크기

#include <stdio.h>

int main(void)
{
	int i = 10;
	char c = 128;
	double d = 3.14;
	char* pc = &c;

	printf("i의 크기: %zu\n", sizeof(i));
	printf("c의 크기: %zu\n", sizeof(c));
	printf("d의 크기: %zu\n", sizeof(d));
	printf("pc의 크기: %zu\n", sizeof(pc));
	
	return 0;
}
// 64비트 CPU에서 포인터 변수의 크기는 8 바이트
// 주소값 하나당 8바이트로 저장하기 때문임.
