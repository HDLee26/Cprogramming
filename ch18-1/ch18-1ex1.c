// 이차원 배열의 배열명
#include <stdio.h>

int main(void)
{
	int arr[3][3] = { 0 };

	puts("주소 | 크기");
	printf("arr       : %p\t %zu\n", arr, sizeof(arr));                // 36, 배열 전체
	printf("arr[0]    : %p\t %zu\n", arr[0], sizeof(arr[0]));          // 12, 한 행
	printf("arr[0][0] : %p\t %zu\n", &arr[0][0], sizeof(arr[0][0]));   // 4, 원소 하나

	puts("주소");
	printf("arr       : %p\n", arr);               
	printf("arr + 1   : %p\n", arr + 1);  // 12칸 차이 == 한 행 크기
	printf("&arr + 1  : %p\n", &arr + 1); // 36칸 차이 == 배열 전체 크기
	
	return 0; 
}
// 배열명은 사용법이 두 개이다. 첫 번째 원소를 가리킬 수도 있고, 배열 전체를 의미할 수도 있고.
// 첫 번째 원소를 가리키는 경우에, 이차원 배열의 각 원소는 **1차원 배열**이므로 이를 가지고 연산을 하면 **한 행씩** 움직인다.
