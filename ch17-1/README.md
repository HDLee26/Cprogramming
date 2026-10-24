# 실습과제 1
- 아래의 변수가 그림처럼 메모리에 할당될 때 표의 빈칸을 채우시오.
```c
double num = 6.28;
double* ptr = &num;
double** dptr = &ptr;
```

| 주소 | 100 | 300 | 500 |
|---|---|---|---|
| 변수 | num | ptr | dptr |

| 수식 | 결과값 | 결과값의 자료형 |
|---|---|---|
| `ptr` | 100 | `double*` |
| `dptr` | 300 | `double**` |
| `&ptr` | 300 | `double**` |
| `&dptr` | 500 | `double***` |
| `*ptr` | 6.28 | `double` |
| `*dptr` | 100 | `double*` |
| `**dptr` | 6.28 | `double` |

---
