#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>

typedef struct student {
	char name[11];
	int score;
} STD;

void inputScore(STD* lst, size_t n);
size_t getTopStd(const STD* lst, size_t n);

int main(void)
{
	STD stdList[3] = { { { '\0' }, 0 } };
	size_t n = sizeof(stdList) / sizeof(stdList[0]);
	size_t topIndex;

	inputScore(stdList, n);
	topIndex = getTopStd(stdList, n);

	printf("최우수 학생의 이름은 %s, 점수는 %d점\n", stdList[topIndex].name, stdList[topIndex].score); 
	// printf("%zu \n", strlen(stdList[topIndex].name));
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

size_t getTopStd(const STD* lst, size_t n)
{
	size_t top = 0;
	for (size_t i = 1; i < n; i++)
	{
		if (lst[i].score > lst[top].score)
			top = i;
	}
	return top;
}

// 배열 인덱스 lst[i].name 
// 구조체 포인터 (lst + i)->name
// (lst + i) i번째 구조체 주소 || (*(lst + i)) i번째 구조체 자체 == lst[i]
