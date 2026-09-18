# 실습과제 1
- 16 MB 메모리의 주소의 범위를 구하시오.\
0 ~ 16,777,215 (0 ~ 16 × $2^{20}$ - 1)
- 변수의 주소를 설명하시오.\
프로그램에서 선언한 모든 변수는 메모리에 저장됨. 변수의 자료형에 따라 차지하는 메모리 공간의 크기가 다르지만 변수의 주소는 변수가 차지하는 공간의 가장 첫 번째 주소를 읽어서 씀.
- 변수의 주소의 자료형은 무엇인가?\
  char*, int*, double*
- 포인터란 무엇인가?\
  주소를 저장하기 위한 변수.
- 포인터의 자료형은 무엇인가?\
  char*, int*, double*
- 변수의 주소를 int형 변수에 저장하면 어떻게 되는가?\
  정수형 변수의 자료형 int와 정수형 변수의 주소의 자료형 int*은 다른 것으로 에러가 남.

---

# 실습과제 2
~~~c
double * pt;
~~~
- 위의 pt가 가리키는 데이터의 자료형은?\
  double
- 위의 pt에 저장될 주소의 자료형은?\
  double*
- 위의 pt의 자료형은?\
  double*
- 위처럼 포인터를 선언할 때 double의 의미를 설명하라.\
  pt가 가리키는 데이터의 자료형이 double임
- 위의 포인터 변수 pt가 메모리에 할당될 때 메모리의 크기는?\
  64비트 시스템에서는 8 바이트.

---

# 실습과제 3
- 아래의 변수들이 그림처럼 메모리에 할당될 때 표의 빈칸을 채우시오.

```c
char ch = 'A';
int in = 10;
double db = 3.4;
```

<table style="border-collapse: collapse; text-align: center;">
  <tr>
    <th style="border: 1px solid black;">주소</th>
    <th style="border: 1px solid black;">100</th>
    <th style="border: 1px solid black;">101</th>
    <th style="border: 1px solid black;">102</th>
    <th style="border: 1px solid black;">103</th>
    <th style="border: 1px solid black;">104</th>
    <th style="border: 1px solid black;">105</th>
    <th style="border: 1px solid black;">106</th>
    <th style="border: 1px solid black;">107</th>
    <th style="border: 1px solid black;">108</th>
    <th style="border: 1px solid black;">109</th>
    <th style="border: 1px solid black;">110</th>
    <th style="border: 1px solid black;">111</th>
    <th style="border: 1px solid black;">112</th>
  </tr>

  <tr>
    <th style="border: 1px solid black;">메모리</th>
    <td style="border: 1px solid black;">ch</td>
    <td colspan="4" style="border: 1px solid black; vertical-align: middle;">in</td>
    <td colspan="8" style="border: 1px solid black; vertical-align: middle;">db</td>
  </tr>
</table>

|수식|결과값|결과값의 자료형|
|:----:|:---:|:-------:|
|&ch|100|char*|
|&in|101|int*|
|&db|105|double*|
