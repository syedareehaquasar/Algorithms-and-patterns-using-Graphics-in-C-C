#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main(){
    initwindow(900, 900); // window size and initialization
    
    //screen coordinates
    int x = getmaxx()/2;
    int y = getmaxy()/2;
    
    setcolor(4); //red
    for (int i = 10; i < 40; i++) {
    	arc(x, y, 0, 180, i + 10);
	}
    delay(100);

    setcolor(6); //orange (brown)
    for (int i = 40; i < 80; i++) {
    	arc(x, y, 0, 180, i + 10);
	}
    delay(100);
	
    setcolor(14); //yellow
    for (int i = 80; i < 120; i++) {
    	arc(x, y, 0, 180, i + 10);
	}
    delay(100);
	
    setcolor(2); // green
    for (int i = 120; i < 160; i++) {
    	arc(x, y, 0, 180, i + 10);
	}
    delay(100);
	
    setcolor(3); // aqua
    for (int i = 160; i < 200; i++) {
    	arc(x, y, 0, 180, i + 10);
	}
    delay(100);
	
    setcolor(9); // navy blue (light blue)
    for (int i = 200; i < 240; i++) {
    	arc(x, y, 0, 180, i + 10);
	}
    delay(100);
	
    setcolor(1); // indigo (blue)
    for (int i = 240; i < 270; i++) {
    	arc(x, y, 0, 180, i + 10);
	}
    delay(100);
	
	getch();
	return 0;
}
