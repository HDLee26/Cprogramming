// string.h 없이 각 문자열의 첫 글자들 중에서 최소값을 찾는 프로그램 (함수)
// 완전한 사전식 순서가 아님
#include <stdio.h>

char* get_first(const char* str[],  size_t len)
{
	const char* tmp = str[0];
	for (size_t i = 1; i < len; i++)
	{
		if (str[i][0] < tmp[0])
			tmp = str[i];
	}
	return tmp;
}

int main(void)
{
	// 문자열 배열 (포인터 배열)
	char* fruits[] = { "banana", "apple", "orange", "melon" };
	size_t len = sizeof(fruits) / sizeof(fruits[0]); // 32 ÷ 8
	const char* first;

	first = get_first(fruits, len);
	printf("사전에서 가장 앞에 나오는 단어: %s\n", first);

	return 0;
}
// const char* 가리키는 문자열의 내용을 수정하지 않겠다는 의미
// *(fruits[i] + 0) == fruits[i][0] <- *(p + 0) == p[0]
