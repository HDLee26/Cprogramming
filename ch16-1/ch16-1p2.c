#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
void inputScores(int scores[][3]);
double getAverage(int scores[][3], int cnt);
void getFirstStudent(int scores[][3], double avg[], int* topStudent, double* topScore);

int main(void)
{
	int scores[3][3] = { 0 };
	double avg[3] = { 0 };
	int topStudent;
	double topScore;

	inputScores(scores);
	getFirstStudent(scores, avg, &topStudent, &topScore);
	printf("최우수 학생은 %d번째 학생이고 평균 점수는 %lf점이다.\n", topStudent + 1, topScore);

	return 0;
}
// 이차원 배열에 세 학생의 성적을 입력하는 함수
void inputScores(int scores[][3])
{
	for (int i = 0; i < 3; i++)
	{
		printf("%d번째 학생의 국어, 영어, 수학 성적을 입력: ", i + 1);
		scanf("%d %d %d", &scores[i][0], &scores[i][1], &scores[i][2]);
	}
}
void getFirstStudent(int scores[][3], double avg[], int* topStudent, double* topScore)
{
	for (int i = 0; i < 3; i++)
		avg[i] = getAverage(scores[i], 3);

	*topStudent = 0;
	*topScore = avg[0];
	for (int i = 1; i < 3; i++)
		if (avg[i] > *topScore)
		{ 
			*topScore = avg[i];
			*topStudent = i;
		}
}

// 세 과목의 평균을 구하는 함수
double getAverage(int scores[], int cnt)
{
	int sum = 0;
	
	for (int i = 0; i < cnt; i++)
		sum += scores[i];

	return (double)sum / cnt;
}
