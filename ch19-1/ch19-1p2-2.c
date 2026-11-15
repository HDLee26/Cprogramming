// 여러 자료형의 데이터를 하나의 함수로 처리하는 예제
#include <stdio.h>

// 자료형을 구분하기 위한 번호
enum DataType
{
    TYPE_INT,
    TYPE_DOUBLE,
    TYPE_CHAR
};

// ptr: 출력할 데이터의 주소
// type: 해당 데이터의 실제 자료형
void printValue(const void* ptr, enum DataType type)
{
    switch (type)
    {
    case TYPE_INT:
        printf("int 값: %d\n", *(const int*)ptr);
        break;

    case TYPE_DOUBLE:
        printf("double 값: %.2f\n", *(const double*)ptr);
        break;

    case TYPE_CHAR:
        printf("char 값: %c\n", *(const char*)ptr);
        break;

    default:
        printf("알 수 없는 자료형입니다.\n");
        break;
    }
}

int main(void)
{
    int age = 20;
    double height = 175.5;
    char grade = 'A';

    printValue(&age, TYPE_INT);
    printValue(&height, TYPE_DOUBLE);
    printValue(&grade, TYPE_CHAR);

    return 0;
}
