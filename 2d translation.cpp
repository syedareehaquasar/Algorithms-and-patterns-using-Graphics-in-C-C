#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

void smiley(int x, int y, int r)
{
	setcolor(YELLOW); 
  
    // creating circle and fill it with 
    // yellow color using floodfill. 
    circle(x, y, r); 
    setfillstyle(SOLID_FILL, YELLOW); 
    floodfill(x, y, YELLOW); 
  
    // Set color of background to black 
    setcolor(BLACK); 
    setfillstyle(SOLID_FILL, BLACK); 
  
    // Use fill ellipse for creating eyes 
    fillellipse(x + 10, y - 15, 2, 6); 
    fillellipse(x - 10, y - 15, 2, 6); 
  
    // Use ellipse for creating mouth 
    ellipse(x, y, y + 105, x + 35, r - 20, r - 31); 
    ellipse(x, y, y + 105, x + 35, r - 20, r - 30); 
    ellipse(x, y, y + 105, x + 35, r - 20, r - 29); 
}

int rotation(int x, int y, int r, int flag)
{
	int p, q;
	p = abs(x * cos(r) - y * sin(r));
	q = abs(y * cos(r) + x * sin(r));
	if (flag == 1)
		return p;
		
	return q;
}

void rotate(float angle)
{
 int x1,x2,x3,x4;
 int y1,y2,y3,y4;
 int refx,refy;
 int ax1,ax2,ax3,ax4,ay1,ay2,ay3,ay4;
 
 angle=angle*(3.14/180);
 refx=100;
 refy=100;
 x1=100;
 y1=100;
 x2=150;
 y2=100;
 x3=150;
 y3=150;
 x4=100;
 y4=150;

 ax1=refy+(x1-refx)*cos(angle)-(y1-refy)*sin(angle);
 ay1=refy+(x1-refx)*sin(angle)+(y1-refy)*cos(angle);
 ax2=refy+(x2-refx)*cos(angle)-(y2-refy)*sin(angle);
 ay2=refy+(x2-refx)*sin(angle)+(y2-refy)*cos(angle);
 ax3=refy+(x3-refx)*cos(angle)-(y3-refy)*sin(angle);
 ay3=refy+(x3-refx)*sin(angle)+(y3-refy)*cos(angle);
 ax4=refy+(x4-refx)*cos(angle)-(y4-refy)*sin(angle);
 ay4=refy+(x4-refx)*sin(angle)+(y4-refy)*cos(angle);

 setcolor(4);
 rectangle(100,150,150,100);
 line(ax1,ay1,ax2,ay2);
 line(ax2,ay2,ax3,ay3);
 line(ax3,ay3,ax4,ay4);
 line(ax4,ay4,ax1,ay1);

}

main()
{
	initwindow(800, 800);
	rectangle(150, 200, 300, 400);
	circle(200, 200, 100);
	smiley(300, 100, 100);
	
	// translation
	printf("\n TRANSLATION \n\n");
	printf("Enter the value you want the x-coordinate to: \n");
	int x, y;
	scanf("%d", &x);
	printf("Enter the value you want the y-coordinate to: \n");
	scanf("%d", &y);
	rectangle(150 + x, 200 + y, 300 + x, 400 + y);
	circle(200 + x, 200 + y, 100);
	smiley(300 + x, 100 + y, 100);
	
	// scaling
	printf("\n\n scaling \n\n");
	printf("Enter the scaling factor\n");
	int d;
	scanf("%d", &d);
	rectangle(150 * d , 200 * d, 300 * d, 400 * d);
	circle(200, 200 , 100 * d);
	
	// rotation
	printf("\n\n ROTATION \n\n");
	printf("Enter the angle\n");
	int r;
	scanf("%d", &r);
	// 2 ways to print:
//	rectangle(rotation(15, 20, r, 1), rotation(15, 20, r, 0), rotation(30, 40, r, 1), rotation(30, 40, r, 0));
	rotate(r);
	
	getch();
	closegraph();
} 
