#define _CRT_SECURE_NO_WARNINGS	
#pragma warning(disable:6031)
#include <stdio.h>

enum Operation
{
	ADD = 1, SUB, MUL, DIV
};

// 함수 포인터 자료형에 이름 붙이기
typedef double (*OperationFunc)(int, int);

void input(int* p1, int* p2);
int select(void);
void print_result(int x, int y, OperationFunc operation);
// 반환형이 함수 포인터
OperationFunc get_operation(int opt);

double add(int a, int b);
double sub(int a, int b);
double mul(int a, int b);
double divide(int a, int b);

int main(void)
{
	int a, b;
	int sel = 0;
	OperationFunc operation = NULL;

	input(&a, &b);
	sel = select();
	// 선택한 사칙연산 함수의 '주소'를 저장
	operation = get_operation(sel);
	print_result(a, b, operation);

	return 0;
}
// 정수 2개 입력 받는 함수
void input(int* p1, int* p2)
{
	printf("정수 2개 입력: ");
	scanf("%d %d", p1, p2);
}
// 연산 선택 함수
int select(void)
{
	int opt;

	puts("연산을 선택하시오.");
	printf("%d:덧셈 %d:뺄셈 %d:곱셈 %d:나눗셈\n", ADD, SUB, MUL, DIV);
	printf("선택: ");
	scanf("%d", &opt);

	return opt;
}
// 선택한 번호에 해당하는 연산 함수의 '주소'를 반환하는 함수
OperationFunc get_operation(int opt)
{
	switch (opt)
	{
	case ADD:
		return add;
	case SUB:
		return sub;
	case MUL:
		return mul;
	case DIV:
		return divide;
	default :
		return NULL;
	}
}
// 선택한 연산의 결과를 출력하는 함수
void print_result(int x, int y, OperationFunc operation)
{
	if (operation == NULL)
	{
		puts("잘못된 선택입니다.");
		return;
	}

	if ((operation == divide) && (y == 0))
	{
		puts("0으로 나눌 수 없음.");
		return;
	}

	printf("결과: %.2f\n", operation(x, y));
}
// 사칙연산 함수
double add(int a, int b)
{
	return (double)a + b;
}
double sub(int a, int b)
{
	return (double)a - b;
}
double mul(int a, int b)
{
	return (double)a * b;
}
double divide(int a, int b)
{
	return (double)a / b;
}