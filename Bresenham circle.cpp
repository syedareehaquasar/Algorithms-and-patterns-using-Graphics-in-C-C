#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

void EightSymmetricPlot(int xc, int yc, int x, int y, int clr)
{
	putpixel(x + xc, y + yc, clr);
	putpixel(x + xc, -y + yc, clr);
	putpixel(-x + xc, -y + yc, clr);
	putpixel(-x + xc, y + yc, clr);
	putpixel(y + xc, x + yc, clr);
	putpixel(y + xc, -x + yc, clr);
	putpixel(-y + xc, -x + yc, clr);
	putpixel(-y + xc, x + yc, clr);
}

void BresenhamCircle(int xc, int yc, int r, int clr)
{
	int x = 0, y = r, d = 3 - ( 2 * r);
	EightSymmetricPlot(xc, yc, x, y, clr);
	
	while (x <= y)
	{
		if (d <= 0)
		{
			d = d + (4 * x) + 6;
		}
		else
		{
		d = d + (4 * x) - (4 * y) + 10;
		y = y - 1;
		}
		x = x + 1;
		EightSymmetricPlot(xc, yc, x, y, clr);
//		delay(100);
	}
}

int main(void)
{
	int xc, yc, r, c = 0, i, j, gdriver=DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
	
//	printf("\n Enter the values of xc and yc: \n");
//	scanf("%d %d", &xc, &yc);
//	printf("\n Enter the value of radius: \n");
//	scanf("%d", &r);
//	
//	BresenhamCircle(xc, yc, r, 4);
	for (i = 10; i < 100; i++)
	{
		BresenhamCircle(300, 300, i, 2);
	}
	BresenhamCircle(300, 300, 110, 2);
	for (i = 10; i < 50; i++)
	{
		BresenhamCircle(100, 100, i, 1);
	}
	BresenhamCircle(100, 100, 60, 1);
	for (i = 10; i < 70; i++)
	{
		BresenhamCircle(200, 200, i, 4);
	}
	BresenhamCircle(200, 200, 80, 4);
	for (i = 10; i < 60; i++)
	{
		BresenhamCircle(400, 400, i, 5);
	}
	BresenhamCircle(400, 400, 70, 5);
	
	BresenhamCircle(400, 100, 100, 6);
	
	//rangoli pattern circle
	int x, y, color, angle = 0;
    struct arccoordstype a, b;
	while (angle <= 360)
   {
      setcolor(BLACK);
      arc(400, 100, angle, angle + 2, 50);
      setcolor(RED);
      getarccoords(&a);
      BresenhamCircle(a.xstart, a.ystart, 25, 2);
      setcolor(BLACK);
      arc(400, 100, angle, angle + 2, 100);
      getarccoords(&a);
      setcolor(GREEN);
      BresenhamCircle(a.xstart, a.ystart, 25, 3);
      angle = angle+5;
      delay(50);
   }
	
	getch();
	closegraph();
	return 0;
	
	
}
