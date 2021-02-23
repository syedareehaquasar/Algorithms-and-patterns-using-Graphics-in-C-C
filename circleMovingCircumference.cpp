#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

void CircumRotation(int x, int y) {
	for (int angle = 0; angle < 360; angle++) {
		int nx = x + cos(angle/3.5)*100;
		int ny = y + sin(angle/3.5)*100;
		setcolor(WHITE);
		circle(nx, ny, 10);
		delay(500);
		setcolor(BLACK);
		circle(nx, ny, 10);
	}
}

void rotation(int x, int y, int radius) {
	int nx = x + 120;         
	int ny = y;
	for (int angle = 0; angle < 360; angle++) {
		setcolor(RED);
		int nx = x + cos(angle/3.5)*100;
		int ny = y + sin(angle/3.5)*100;
		circle(nx, ny, radius);
		delay(500);
		setcolor(BLACK);
		circle(nx, ny, radius);
		setcolor(YELLOW);
		nx = x + cos(angle/3.5)*120;
		ny = y + sin(angle/3.5)*120;
		circle(nx, ny, radius);
		delay(500);
		setcolor(BLACK);
		circle(nx, ny, radius);
		setcolor(BLUE);
		nx = x + cos(angle/3.5)*80;
		ny = y + sin(angle/3.5)*80;
		circle(nx, ny, radius);
		delay(500);
		setcolor(BLACK);
		circle(nx, ny, radius);
	}
}

int main() {
	initwindow (800, 800);
	circle (200, 200, 100);
//	rotation(200, 200, 10);
	CircumRotation(200, 200);
	getch();
	closegraph();
	return 0;
}
