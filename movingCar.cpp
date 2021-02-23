#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
 
int main() {
    int i, x, midy;
    initwindow(800, 800);

	// get coordinates of screen
    x = getmaxx();
    midy = getmaxy()/2;
 
    for (i=0; i < x-150; i=i+5) {
        cleardevice();// clearing screen
        setcolor(WHITE);
        line(0, midy + 37, x, midy + 37); // road
 		//carbody
 		setcolor(BLUE);
        line(i, midy + 23, i, midy);
        line(i, midy, 40 + i, midy - 20);
        line(40 + i, midy - 20, 80 + i, midy - 20);
        line(80 + i, midy - 20, 100 + i, midy);
        line(100 + i, midy, 120 + i, midy);
        line(120 + i, midy, 120 + i, midy + 23);
        line(0 + i, midy + 23, 18 + i, midy + 23);
        arc(30 + i, midy + 23, 0, 180, 12);
        line(42 + i, midy + 23, 78 + i, midy + 23);
        arc(90 + i, midy + 23, 0, 180, 12);
        line(102 + i, midy + 23, 120 + i, midy + 23);
        line(28 + i, midy, 43 + i, midy - 15);
        line(43 + i, midy - 15, 57 + i, midy - 15);
        line(57 + i, midy - 15, 57 + i, midy);
        line(57 + i, midy, 28 + i, midy);
        line(62 + i, midy - 15, 77 + i, midy - 15);
        line(77 + i, midy - 15, 92 + i, midy);
        line(92 + i, midy, 62 + i, midy);
        line(62 + i, midy, 62 + i, midy - 15);
		//wheels
		setcolor(RED);
        circle(30 + i, midy + 25, 9);
        circle(90 + i, midy + 25, 9);
        delay(100);
    }
 
    getch();
    closegraph();
    return 0;
}
