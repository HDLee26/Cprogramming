// 구조체 연습3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct dot2D
{
	double x;
	double y;
};

int main(void)
{
	struct dot2D UpLeft;
	struct dot2D BottomRight;
	double width, height;

	printf("좌측상단의 좌표 입력: ");
	scanf("%lf %lf", &UpLeft.x, &UpLeft.y);
	printf("우측하단의 좌표 입력: ");
	scanf("%lf %lf", &BottomRight.x, &BottomRight.y);

	width = BottomRight.x - UpLeft.x;
	height = UpLeft.y - BottomRight.y;
	printf("사각형의 폭: %f\n", width);
	printf("사각형의 높이: %f\n", height);

	return 0;
}
