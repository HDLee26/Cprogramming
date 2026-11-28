// C에서 OOP 흉내내기
#include <stdio.h>

// Define the Rectangle struct
typedef struct Rect
{
	double width, height;
	// 함수 포인터 변수를 멤버로 가짐 (C의 구조체엔 함수가 직접 못 들어가므로)
	void (*setter)(struct Rect*, double, double);
	double (*area)(struct Rect*);
	void (*show)(struct Rect*);
} Rect;

double area(Rect* rect);
void show(Rect* rect);
void setter(Rect* rect, double w, double h);
void constructRect(Rect* rect);
int inputRect(Rect* rect);

int main(void)
{
	// Create a Recatnagle object
	Rect rect = { 0, 0, NULL, NULL, NULL }; // 바로 밑에 생성자 있어서 필욘 없는데 그냥 변수 뭐 있는지 써놓고 싶었음.
	// 멤버 변수에 접근해야 하므로 main에서는 주소를 넘겨야 함
	// 생성자
	constructRect(&rect);

	if (!(inputRect(&rect)))
		return 1;

	rect.show(&rect);
	printf("Area: %.2f \n", rect.area(&rect));

	return 0;
}

// Function to find the area
double area(Rect* rect)
{
	return (rect->width) * (rect->height);
}

// Function to print the dimensions
void show(Rect* rect)
{
	printf("Width: %.2f, Height: %.2f \n", rect->width, rect->height);
}

// Function to set width and height
void setter(Rect* rect, double w, double h)
{
	rect->width = w;
	rect->height = h;
}

// Rect 객체에 대한 생성자
void constructRect(Rect* rect)
{
	rect->width = 0;
	rect->height = 0;
	// 각 함수의 주소를 멤버 변수에 저장함
	rect->setter = setter;
	rect->area = area;
	rect->show = show;
}

// 사용자로부터 폭과 넓이를 입력 받는 함수 (성공시 1, 실패시 0 반환)
int inputRect(Rect* rect)
{
	double width, height;
	fputs("폭과 넓이를 입력하세요: ", stdout);

	if (scanf_s("%lf %lf", &width, &height) != 2)
	{
		puts("잘못된 입력입니다");
		return 0;
	}

	rect->setter(rect, width, height);
	return 1;
}

