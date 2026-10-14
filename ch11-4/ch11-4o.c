// string.h 없이 strlen, strcpy, strcat 구현
#include <stdio.h>

// 문자열 길이를 구하는 함수
size_t my_strlen(const char str[])
{
	size_t i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}
// 문자열을 복사하는 함수
void my_strcpy(char dest[], const char src[])
{
	size_t i;
	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	// 문자열 끝에 null문자 붙여줌
	dest[i] = '\0'; 
}
// dest의 문자열 끝에 src의 문자열을 덧붙이는 함수
void my_strcat(char dest[], const char src[])
{
	// dest의 null문자 위치 찾기
	size_t i = my_strlen(dest);  
	size_t j = 0;

	while (src[j] != '\0')
		dest[i++] = src[j++];

	// 이어붙이는 작업 끝낸 후 null문자 붙여줌
	dest[i] = '\0'; 
}
int main(void)
{
	char str[101] = "Computer Science";
	char copy[101] = "";
	char mystr[201] = "My major : ";

	printf("문자열의 길이: %zu\n", my_strlen(str));
	my_strcpy(copy, str);
	printf("복사한 문자열: %s\n", copy);
	my_strcat(mystr, str);
	printf("이어붙인 문자열: %s\n", mystr);

	return 0;
}
