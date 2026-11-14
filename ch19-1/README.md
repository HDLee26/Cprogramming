# 실습과제 1
- 함수 선언, 호출, 정의를 각각 설명하라
  - 선언: 컴파일러의 문법 체크를 위해 함수를 호출하기 전에 함수명, 반환형, 매개변수 자료형을 써두는 것
  - 호출: 함수에 필요한 인자들을 전달하고, 정의된 코드를 실행하는 것
  - 정의: 함수가 실제로 실행할 동작을 코드로 작성한 것
- 함수의 자료형은?
  - 반환형과 매개변수들의 자료형으로 정의 -> 반환형(param자료형 ...)
- 함수명의 자료형은?
  - 함수명은 주소. (함수 자료형)* -> 반환형 (*변수명)(param자료형 ...)
- void 포인터의 용도는?
  - 포인터가 가리키는 변수들은 자료형이 모두 정해져 있어 그에 맞는 포인터 변수를 써야하는데, 주소만 가지고 노는 경우에는 그런 거 따질 필요없으니까 void 포인터 쓰면 됨.
- void 포인터에 간접참조 연산을 적용할 때 주의점은?
  - void 포인터는 가리키는 자료형이 정해져 있지 않으므로 변수에 들어있는 값에 접근하려면 시작 주소로부터 몇 바이트 읽어야 하는지 지정해줘야 함. -> 캐스팅 연산자.
- 강제 형변환과 자동 형변환을 설명하시오.
  - 형변환은 값의 자료형을 다른 자료형으로 바꾸는 것.
  - 자동 형변환은 별도로 지정하지 않아도 대입이나 연산 과정에서 자료형이 자동으로 변환되는 것. 특히 피연산자의 자료형이 일치하지 않는 경우 데이터의 손실을 최소화는 하는 방향으로 자동으로 진행됨.
  - 강제 형변환은 캐스팅 연산자를 이용해서 원하는 자료형으로 명시적으로 변환하는 것.
<img width="546" height="99" alt="image" src="https://github.com/user-attachments/assets/d7305399-d850-49f3-bf8a-d33a18927fa5" />
 
# 실습과제 2-1
- 함수의 매개변수에 함수 포인터를 사용하는 예제를 찾아보고 코드를 설명하시오.
```c
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
```
- VS scanf 함수 보안 경보 방지용 & 리턴값 관련 경고 방지용
```c
#include <stdio.h>
```
- stdio.h 헤더파일을 포함하라
```c
double add(int a, int b) {
    return a + b;
}
```
- 덧셈 함수
```c
double sub(int a, int b) {
    return a - b;
}
```
- 뺄셈 함수
```c
double mul(int a, int b) {
    return a * b;
}
```
- 곱셈 함수
```c
double div(int a, int b) {
    return (double)a / b;
}
```
- 나눗셈 함수
```c
void calculate(int x, int y, double (*operation)(int, int)) {
    printf("Result: %.2f\n", operation(x, y));
}
```
- 만들어놓은 사칙연산 함수들 중 원하는 함수를 선택하여 연산 결과를 출력하는 함수
```c
void input(int* num_ptr) {
    printf("정수 입력: ");
    scanf("%d", num_ptr);
}
```
- 정수 입력 받는 함수
```c
int main()
```
- main 함수 시작
```c
    int a, b;
    input(&a);
    input(&b);
```
- 정수 2개 a, b 입력 받음
```c
    puts("사칙연산 결과");
    calculate(a, b, add);
    calculate(a, b, sub);
    calculate(a, b, mul);
    if (b == 0)
        puts("0으로 나눌 수 없음.");
    else
        calculate(a, b, div);
```
- 사칙연산 결과 출력
```c
    return 0;
```
- 0을 반환하고 main 함수 정상 종료

### 실행결과
<img width="279" height="186" alt="image" src="https://github.com/user-attachments/assets/34a6edf4-2560-47f2-a4a7-cff43f3f2380" />



 
