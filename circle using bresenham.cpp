#include<stdio.h>
#include<conio.h>
#include<graphics.h>
circle_func(int xc,int yc,int r, int clr )
{
	int i,y,x=0;
	float d;
	
	d=1.25-r;
	y=r;
	do{
		if(d<0.0){
			x=x+1;
			d=d+2*x+1;
		}
		else{
			x=x+1;
			y=y-1;
			d=d+2*x-2*y+1;
		}
	putpixel(xc+x,yc+y,clr);
	putpixel(xc-y,yc-x,clr);
	putpixel(xc+y,yc-x,clr);
	putpixel(xc-y,yc+x,clr);
	putpixel(xc+y,yc+x,clr);
	putpixel(xc-x,yc-y,clr);
	putpixel(xc+x,yc-y,clr);
	putpixel(xc-x,yc+y,clr);
	}
	while(x<y);
}

main()
{
	initwindow(800,800);
	int i = 100;
	while (i <= 700){
		circle_func(i,200,10, 1);
		circle_func(i,200,100, 7);
		circle_func(i,180,50, 2);
		circle_func(i,270,100, 3);
		i += 100;
		delay (100);
	}
	
	i = 200;
	while (i < 700){
		circle_func(i,400,10, 1);
		circle_func(i,400,100, 7);
		circle_func(i,380,50, 2);
		circle_func(i,370,100, 3);
		i += 100;
		delay (100);
	}
	
		for (i = 1; i <= 100; i++)
	{
		circle_func(400,500,i, 4);
	}
	delay (100);
	for (i = 1; i <= 50; i++)
	{
		circle_func(400,300,i, 1);
		circle_func(400,400,i, 1);
	}
	getch();
}
