#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>

typedef struct student {
	char name[11];
	int score;
} STD;

void inputScore(STD* lst, size_t n);
size_t getFirstStd(STD* lst, size_t n);

int main(void)
{
	STD stdList[3] = { { { '\0' }, 0 } };
	size_t n = sizeof(stdList) / sizeof(stdList[0]);
	size_t first;

	inputScore(stdList, n);
	first = getFirstStd(stdList, n);
	printf("출석부에서 가장 먼저 나오는 학생: %s의 성적: %d \n",
		stdList[first].name, stdList[first].score);
	return 0;

}

void inputScore(STD* lst, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		fputs("이름을 입력하시오: ", stdout);

		if (fgets(lst[i].name, sizeof(lst[i].name), stdin) != NULL)   //  (*(lst + i)).name  (lst + i)->name  
			lst[i].name[strcspn(lst[i].name, "\n")] = '\0';           //  name 자체도 배열이라 & 필요없음.
		printf("성적을 입력하시오: ");
		scanf("%d", &lst[i].score);                                   //  score는 변수라서 & 필요함.
		getchar();
	}
}

size_t getFirstStd(STD* lst, size_t n)
{
	size_t firstStdIndex = 0;
	for (size_t i = 1; i < n; i++)
	{
		if (strcmp(lst[i].name, lst[firstStdIndex].name) < 0)
			firstStdIndex = i;
	}
	return firstStdIndex;
}

// strcmp는 두 문자열을 1바이트씩 비교하는데 한글은 utf-8 기준 한 글자당 3바이트씩 해석하니까 문제가 있을 수도?