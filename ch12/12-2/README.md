# 실습과제1
- 아래의 변수들이 그림처럼 메모리에 할당될 때 표의 빈칸을 채우시오.
  
```c
char ch = 'A';
int in = 10;
double db = 3.4;
```
<table style="border-collapse: collapse; text-align: center;">
  <tr>
    <th style="border: 1px solid black; padding: 8px;">주소</th>
    <th style="border: 1px solid black; padding: 8px;">100</th>
    <th style="border: 1px solid black; padding: 8px;">101</th>
    <th style="border: 1px solid black; padding: 8px;">102</th>
    <th style="border: 1px solid black; padding: 8px;">103</th>
    <th style="border: 1px solid black; padding: 8px;">104</th>
    <th style="border: 1px solid black; padding: 8px;">105</th>
    <th style="border: 1px solid black; padding: 8px;">106</th>
    <th style="border: 1px solid black; padding: 8px;">107</th>
    <th style="border: 1px solid black; padding: 8px;">108</th>
    <th style="border: 1px solid black; padding: 8px;">109</th>
    <th style="border: 1px solid black; padding: 8px;">110</th>
    <th style="border: 1px solid black; padding: 8px;">111</th>
    <th style="border: 1px solid black; padding: 8px;">112</th>
  </tr>

  <tr>
    <th style="border: 1px solid black; padding: 8px;">메모리</th>
    <td style="border: 1px solid black; padding: 8px;">ch</td>
    <td colspan="4" style="border: 1px solid black; padding: 8px;">in</td>
    <td colspan="8" style="border: 1px solid black; padding: 8px;">db</td>
  </tr>
</table>



|수식|결과값|결과값의 자료형|
|:----:|:---:|:-------:|
|&ch|100|char*|
|&in|101|int*|
|&db|105|double*|
|*&ch|A|char|
|*&in|10|int|
|*&db|3.4|double|
