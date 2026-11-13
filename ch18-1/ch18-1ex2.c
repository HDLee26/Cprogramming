// 이차원 배열과 함수
#include <stdio.h>

void fill(int (*ptr)[4],size_t row);   // int ptr[][4]
void print(int (*ptr)[4], size_t row); // int ptr[][4]

int main(void)
{
	int arr[3][4] = { 0 };
	size_t row = sizeof(arr) / sizeof(arr[0]);

	fill(arr, row);
	print(arr, row);

	return 0;
}

void fill(int (*ptr)[4], size_t row)
{
	int c = 1;
	for (size_t i = 0; i < row; i++)
		for (size_t j = 0; j < 4; j++)
			ptr[i][j] = c++;   // *(*(ptr + i) + j)

}

void print(int (*ptr)[4], size_t row)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < 4; j++)
			printf("%d\t", ptr[i][j]);
		putchar('\n');
	}
}

// 가리키는 대상의 자료형 / 포인터 변수명 / 한 행의 길이 = 열의 개수
/* 
	ptr + i : i번재 행 전체를 가리키는 포인터
	*(ptr + i) == ptr[i] : i번째 행 배열 자체인데
	*(ptr + i) == &ptr[i][0] : 대부분의 수식에서 그 행의 첫 원소를 가리키는 주소(int*)로 변환됨.
	*(*(ptr + i) + j) == ptr[i][j] : i번째 행 j번째 열의 원소
*/
