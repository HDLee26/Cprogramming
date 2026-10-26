// string.h 없이 각 문자열의 첫 글자들 중에서 최소값을 찾는 프로그램
// 완전한 사전식 순서가 아님
#include <stdio.h>

int main(void)
{
	// 문자열 배열 (포인터 배열)
	char* fruits[] = { "banana", "apple", "orange", "melon" };
	size_t len = sizeof(fruits) / sizeof(fruits[0]); // 32 ÷ 8
	const char* first; // 문자열 하나를 가리킬 char* 포인터 변수

	first = fruits[0];
	for (size_t i = 1; i < len; i++)
	{
		// 비교할 때는 문자열의 첫 글자를 꺼내서, 결과 저장은 첫 글자의 주소로.
		if (*fruits[i] < *first) // fruits[i][0] < first[0]
			first = fruits[i];
	}

	printf("사전에서 가장 앞에 나오는 단어: %s\n", first);

	return 0;
}
// const char* 가리키는 문자열의 내용을 수정하지 않겠다는 의미
// *(fruits[i] + 0) == fruits[i][0] <- *(p + 0) == p[0]
