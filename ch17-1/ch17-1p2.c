// *******************
// 이중 포인터를 이용한 최댓값 찾기
// *******************

#include <stdio.h>
int get_max(int* ptrarr[], int len); // int** ptrarr
int main(void)
{
	int num1 = 50, num2 = 20, num3 = 30;
	int* ptrarr[3] = { &num1, &num2, &num3 }; // 변수의 주소를 3개 저장함
	int max;

	max = get_max(ptrarr, sizeof(ptrarr) / sizeof(ptrarr[0])); // 첫 번째 원소의 주소 int**
	printf("최댓값: %d\n", max);
	return 0;
}
int get_max(int* ptrarr[], int len)
{
	int tmp = *ptrarr[0]; // *ptrarr[0] == num1 == **ptrarr
	// 최댓값 비교해서 갱신
	for (int i = 1; i < len; i++)
		if (tmp < *(ptrarr[i])) // *&num2 *&num3 차례로 비교
			tmp = *(ptrarr[i]); // **(ptrarr + i)

	return tmp;
}
// int** ptrarr 함수에서 포인터 배열의 첫 번째 원소를 가리키는 매개변수
// **ptrarr == *ptrarr[0] 첫 번째 포인터가 가리키는 값 | ptrarr[0] == &num1
// **(ptrarr + i) == *ptrarr[i] i번째 포인터가 가리키는 값
