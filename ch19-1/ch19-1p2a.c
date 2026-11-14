#define _CRT_SECURE_NO_WARNINGS	
#pragma warning(disable:6031)
#include <stdio.h>

double add(int a, int b) {
    return a + b;
}

double sub(int a, int b) {
    return a - b;
}

double mul(int a, int b) {
    return a * b;
}

double div(int a, int b) {
    return (double)a / b;
}

void calculate(int x, int y, double (*operation)(int, int)) {
    printf("Result: %.2f\n", operation(x, y));
}

void input(int* num_ptr)
{
    printf("정수 입력: ");
    scanf("%d", num_ptr);
}

int main() {
    int a, b;

    input(&a);
    input(&b);

    puts("사칙연산 결과");
    calculate(a, b, add);       
    calculate(a, b, sub);  
    calculate(a, b, mul);
    if (b == 0)
        puts("0으로 나눌 수 없음.");
    else 
        calculate(a, b, div);

    return 0;
}