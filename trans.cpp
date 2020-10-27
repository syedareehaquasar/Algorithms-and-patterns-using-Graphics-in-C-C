#include <stdio.h>
#include <graphics.h>
#include <conio.h>
 
int main()
{
	initwindow(800, 800);
	circle(200,200,100);
	rectangle (200,200,300,300);
	getch();
	closegraph();
    
	return 0;

} 
