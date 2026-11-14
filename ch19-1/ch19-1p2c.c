// 자료형 해석 없이 메모리 자체만 (주소만) 다루는 예제
// copyMemory 함수는 데이터가 어떤 자료형인지 알 수 없음. 원본 데이터를 1바이트씩 그대로 옮기는 것임.
#include <stdio.h>
#include <stddef.h>

// 서로 겹치지 않는 메모리 영역을 count바이트만큼 복사
void copyMemory(void* dest, const void* src, size_t count)
{
    // 메모리를 1바이트씩 다루기 위해 변환
    unsigned char* d = (unsigned char*)dest;
    const unsigned char* s = (const unsigned char*)src;

    // src 데이터에서 1바이트씩 읽고 dest에 1바이트씩 씀
    for (size_t i = 0; i < count; i++)
        d[i] = s[i];
}

int main(void)
{
    // 원본 데이터와 복사본 저장할 변수 선언
    int originalNumber = 100;
    int copiedNumber = 0;

    double originalValue = 3.14;
    double copiedValue = 0.0;

    int originalArray[3] = { 10, 20, 30 };
    int copiedArray[3] = { 0 };

    // 정수 하나 복사 4 B
    copyMemory(&copiedNumber, &originalNumber, sizeof(originalNumber));

    // 실수 하나 복사 8 B
    copyMemory(&copiedValue, &originalValue, sizeof(originalValue));

    // 배열 전체 복사 12 B
    copyMemory(copiedArray, originalArray, sizeof(originalArray));

    printf("복사한 정수: %d\n", copiedNumber);
    printf("복사한 실수: %.2f\n", copiedValue);
    printf("복사한 배열: ");
    for (int i = 0; i < 3; i++)
        printf("%d ", copiedArray[i]);

    putchar('\n');

    return 0;
}
