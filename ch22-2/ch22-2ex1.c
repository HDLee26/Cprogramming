// 구조체 포인터 연습
// 모든 입력은 정상적이라고 가정
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

typedef struct point2D
{
	double x, y;
} Point2D;

typedef struct rect
{
	Point2D LeftUp;
	Point2D RightBottom;
	double width, height, area, peri;
} Rect;

void inputRect(Rect* rect);
void getRect(Rect* rect);
void showRect(Rect* rect);

int main(void)
{
	Rect r1;
	inputRect(&r1);
	getRect(&r1);
	showRect(&r1);

	return 0;
}

void inputRect(Rect* rect)
{
	fputs("좌상단 좌표를 입력하세요: ", stdout);
	scanf("%lf %lf", &(*rect).LeftUp.x, &(*rect).LeftUp.y);
	fputs("우하단 좌표를 입력하세요: ", stdout);
	scanf("%lf %lf", &rect->RightBottom.x, &rect->RightBottom.y);
}

void getRect(Rect* rect)
{
	(*rect).width = (*rect).RightBottom.x - (*rect).LeftUp.x;
	rect->height = rect->LeftUp.y - rect->RightBottom.y;
	rect->area = rect->width * rect->height;
	rect->peri = 2 * (rect->width + rect->height);
}

void showRect(Rect* rect)
{
	printf("폭: %.2f, 넓이: %.2f \n", rect->width, rect->height);
	printf("넓이: %.2f, 둘레: %.2f \n", rect->area, rect->peri);
}
