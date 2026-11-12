// 멤버 변수 스왑
#include <stdio.h>

struct point
{
	int x;
	int y;
};

int main(void)
{
	struct point p1 = { 15, 15 }, p2 = { 30, 30 };
	int tmpx, tmpy;

	printf("교환전 p1의 좌표: (%d, %d)\n", p1.x, p1.y);
	printf("교환전 p2의 좌표: (%d, %d)\n", p2.x, p2.y);

	tmpx = p1.x;
	p1.x = p2.x;
	p2.x = tmpx;
	tmpy = p1.y;
	p1.y = p2.y;
	p2.y = tmpy;

	printf("교환후 p1의 좌표: (%d, %d)\n", p1.x, p1.y);
	printf("교환후 p2의 좌표: (%d, %d)\n", p2.x, p2.y);

	return 0;
}
