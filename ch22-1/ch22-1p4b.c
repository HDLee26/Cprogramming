#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	double x;
	double y;
}dot2D;

void inputPoint2D(dot2D* inputDot);
void getRectangleInfo(dot2D ULDot, dot2D BRDot, double* w, double* h, double* area);
void printRectangleInfo(double w, double h, double area);

int main(void)
{
	dot2D UpLeft;
	dot2D BottomRight;
	double width, height, area;
	
	// 좌표 입력 받아 실수로 바꿔 저장
	fputs("좌측상단의 좌표 입력: ", stdout);
	inputPoint2D(&UpLeft);
	fputs("우측하단의 좌표 입력: ", stdout);
	inputPoint2D(&BottomRight);

	// 좌표 위치가 올바른지 확인하고
	if ((UpLeft.x >= BottomRight.x) || (UpLeft.y <= BottomRight.y))
	{
		puts("점의 위치가 잘못되었습니다.");
		return 0;
	}
	// 폭, 높이, 넓이 구함
	else
		getRectangleInfo(UpLeft, BottomRight, &width, &height, &area);

	// 결과 출력
	printRectangleInfo(width, height, area);

	return 0;
}

void inputPoint2D(dot2D *inputDot)
{
	char tmp[10] = { '\0' };  // 입력 받은 숫자를 임시 저장할 배열
	char* end = NULL;         // 숫자 변환이 끝난 위치를 기록할 포인터 변수

	if (fgets(tmp, sizeof(tmp), stdin) != NULL)
	{
		inputDot->x = strtod(tmp, &end);   // (*inputDot).x
		inputDot->y = strtod(end, NULL);   // (*inputDot).y
	}
}

void getRectangleInfo(dot2D ULDot, dot2D BRDot, double* w, double* h, double* area)
{
	*w = BRDot.x - ULDot.x;
	*h = ULDot.y - BRDot.y;
	*area = (*w) * (*h);
}

void printRectangleInfo(double w, double h, double area)
{
	printf("사각형의 폭: %f\n", w);
	printf("사각형의 높이: %f\n", h);
	printf("사각형의 넓이: %f\n", area);
}