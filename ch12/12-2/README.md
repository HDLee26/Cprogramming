# 실습과제1
- 아래의 변수들이 그림처럼 메모리에 할당될 때 표의 빈칸을 채우시오.
```c
char ch = 'A';
int in = 10;
double db = 3.4;
```
<img width="196" height="518" align="right" alt="image" src="https://github.com/user-attachments/assets/84361d0e-a8fa-4a5c-8c73-06c3dc7b5f02" />

|수식|결과값|결과값의 자료형|
|:----:|:---:|:-------:|
|&ch|100|char*|
|&in|101|int*|
|&db|105|double*|
|*&ch|A|char|
|*&in|10|int|
|*&db|3.4|double|
