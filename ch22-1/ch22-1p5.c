#include <stdio.h>

typedef struct 
{
	int x;
	int y;
}Point2D;

void swap(Point2D* ptr1, Point2D* ptr2)
{
	int tmpx = 0, tmpy = 0;

	tmpx = ptr1->x;      // tmpx = (*ptr1).x;
	ptr1->x = ptr2->x;   // (*ptr1).x = (*ptr2).x;
	ptr2->x = tmpx;      // (*ptr2).x = tmpx;
	// ptr이 가리키는 구조체를 먼저 찾고, 그 구조체의 멤버 변수에 접근함.
	tmpy = ptr1->y;
	ptr1->y = ptr2->y;
	ptr2->y = tmpy;
}
int main(void)
{
	Point2D p1 = { 15, 15 }, p2 = { 30, 30 };

	printf("교환전 p1의 좌표: (%d, %d)\n", p1.x, p1.y);
	printf("교환전 p2의 좌표: (%d, %d)\n", p2.x, p2.y);
	swap(&p1, &p2);
	printf("교환후 p1의 좌표: (%d, %d)\n", p1.x, p1.y);
	printf("교환후 p2의 좌표: (%d, %d)\n", p2.x, p2.y);

	return 0;
}