#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

void shearx(int x,int x1,int x2,int y,int y1,int y2,int shearf){
	setcolor(RED);
	x=x+ y*shearf;
	x1=x1+ y1*shearf;
	x2=x2+ y2*shearf;
	line(x,y,x1,y1);
	line(x1,y1,x2,y2);
	line(x2,y2,x,y);
}

void sheary(int x,int x1,int x2,int y,int y1,int y2,int shearf){
	setcolor(GREEN);
	y=y+ x*shearf;
	y1=y1+ x1*shearf;
	y2=y2+ x2*shearf;
	line(x,y,x1,y1);
	line(x1,y1,x2,y2);
	line(x2,y2,x,y);
}

int main()
{
	int x,y,x1,y1,x2,y2,shearf;
	initwindow(800,800);
		
	x=100;y=200;
	x1=200;y1=100;
	x2=300;y2=200;
 	shearf=2;
 	setcolor(BLUE);
	line(x,y,x1,y1);
	line(x1,y1,x2,y2);
	line(x2,y2,x,y);
	
	shearx(x,x1,x2,y,y1,y2,shearf);
	sheary(x,x1,x2,y,y1,y2,shearf);
	getch();
	
	closegraph();
	return 0;
}
