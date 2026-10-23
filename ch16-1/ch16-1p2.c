// *************************************
// 제목: 학생 3명의 3과목 점수를 입력 받아 각 학생의 평균을 구하고 
// 평균 최고 점수를 가진 학생을 구하는 프로그램
// *************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
void inputScores(int scores[][3]); // int(*scores)[3])
double getAverage(int std_scores[], int cnt); // int* std_scores
void getFirstStudent(int scores[][3], double avg[], int* topStudent, double* topAvg); // int (*scores)[3], double* avg

int main(void)
{
	int scores[3][3] = { 0 }; // 3명의 3과목 점수 저장
	double avg[3] = { 0 };    // 3명의 과목 평균 점수 저장
	int topStudent;
	double topAvg;

	inputScores(scores);
	getFirstStudent(scores, avg, &topStudent, &topAvg);
	printf("최우수 학생은 %d번째 학생이고 평균 점수는 %.2f점이다.\n", topStudent + 1, topAvg);

	return 0;
}
// 이차원 배열에 세 학생의 성적을 입력하는 함수
void inputScores(int scores[][3]) // int (*scores)[3]
{
	for (int i = 0; i < 3; i++)
	{
		printf("%d번째 학생의 국어, 영어, 수학 성적을 입력: ", i + 1);
		for (int j = 0 ; j < 3; j++)
			scanf("%d", &scores[i][j]); // *(scores + i) + j
	}
}
// 평균 최고 점수와 그 학생의 인덱스를 포인터를 통해 넘기는 함수
void getFirstStudent(int scores[][3], double avg[], int* topStudent, double* topAvg)
{
	// i번째 학생의 점수가 든 행을 넘김
	for (int i = 0; i < 3; i++)
		avg[i] = getAverage(scores[i], 3); // *(avg + i) , *(scores + i)

	*topStudent = 0;
	*topAvg = avg[0];
	for (int i = 1; i < 3; i++)
		// 평균이 동점인 경우를 고려하지 않음.
		if (avg[i] > *topAvg) // *(avg + i)
		{ 
			*topAvg = avg[i];
			*topStudent = i;
		}
}
// 세 과목의 평균을 구하는 함수
double getAverage(int std_scores[], int cnt) // int* std_scores
{
	int sum = 0;
	
	for (int i = 0; i < cnt; i++)
		sum += std_scores[i]; // *(std_scores + i)

	return (double)sum / cnt;
}
