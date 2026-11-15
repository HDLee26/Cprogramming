#define _CRT_SECURE_NO_WARNINGS	
#pragma warning(disable:6031)
#include <stdio.h>

// 열거형으로 사용할 값만 모아두기
enum Operation
{
	ADD = 1, SUB, MUL, DIV
};

void input(int* p1, int* p2);
int select(void);
void calculate(int x, int y, int opt);

double add(int a, int b);
double sub(int a, int b);
double mul(int a, int b);
double divide(int a, int b);

int main(void)
{
	int a, b;
	int sel;

	input(&a, &b);
	sel = select();
	calculate(a, b, sel);

	return 0;
}
// 정수 2개 입력 받는 함수
void input(int* p1, int* p2)
{
	printf("정수 2개 입력: ");
	scanf("%d %d", p1, p2);
}
// 연산 선택하는 함수
int select(void)
{
	int opt;

	puts("연산을 선택하시오.");
	printf("%d:덧셈 %d:뺄셈 %d:곱셈 %d:나눗셈\n", ADD, SUB, MUL, DIV);
	printf("선택: ");
	scanf("%d", &opt);

	return opt;
}

// 선택한 연산을 실행하고 결과를 출력하는 함수
void calculate(int x, int y, int opt)
{
	double res;
	double (*operation)(int, int);

	switch (opt)
	{
	case ADD :
		operation = add;
		break;

	case SUB :
		operation = sub;
		break;

	case MUL : 
		operation = mul;
		break;

	case DIV:
		if (y == 0)
		{ 
			puts("0으로 나눌 수 없음.");
			return;
		}

		operation = divide;
		break;

	default : 
		puts("잘못된 입력입니다.");
		return;
	}

	res = operation(x, y);
	printf("결과: %.2f\n", res);
}
// 사칙연산 함수
double add(int a, int b)
{
	return a + b;
}
double sub(int a, int b)
{
	return a - b;
}
double mul(int a, int b)
{
	return a * b;
}
double divide(int a, int b)
{
	return (double)a / b;
}
