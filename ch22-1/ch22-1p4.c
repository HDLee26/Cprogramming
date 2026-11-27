// 구조체 연습3a
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>

struct dot2D
{
	double x;
	double y;
};

int main(void)
{
	struct dot2D UpLeft;
	struct dot2D BottomRight;
	double width, height, area;
	char input[10];  // 입력 받은 숫자를 임시 저장할 배열
	char* end;       // 숫자 변환이 끝난 위치를 기록할 포인터 변수

	fputs("좌측상단의 좌표 입력: ", stdout);
	scanf("%lf %lf", &UpLeft.x, &UpLeft.y);
	getchar(); // 버퍼에 남은 '\n' 읽어서 지움

	fputs("우측하단의 좌표 입력: ", stdout);
	if (fgets(input, sizeof(input), stdin) != NULL)
	{
		BottomRight.x = strtod(input, &end); // ㄱ
		BottomRight.y = strtod(end, NULL);   // ㄴ
	}
	// ㄱ end는 변환이 끝난 위치(char*)를 가리켜야 하므로 인자로 넘겨야 하는 건 그 위치의 주소임(char**)
	// ㄴ end 위치부터 읽기 시작하는데 공백 문자는 무시해줌
	if ((UpLeft.x >= BottomRight.x) || (UpLeft.y <= BottomRight.y))
	{
		puts("점의 위치가 잘못되었습니다.");
		return 0;
	}

	width = BottomRight.x - UpLeft.x;
	height = UpLeft.y - BottomRight.y;
	area = width * height;
	
	printf("사각형의 폭: %f\n", width);
	printf("사각형의 높이: %f\n", height);
	printf("사각형의 넓이: %f\n", area);

	return 0;
}
