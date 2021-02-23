#include <graphics.h>
#include <iostream>
#include <math.h>
#include <sstream>

using namespace std;
 
void printTree(int x, int y, int* array, int index, int total_elements){
 	// Base Case
    if (index >= total_elements)
        return;
 
    // Convert int value into string
    ostringstream str1;
    str1 << array[index];
 
    string str2 = str1.str();
    char* str = &str2[0u];
 
    setcolor(GREEN);
 
    // Draw the circle of radius 15 that represent node of Tree
    circle(x, y, 15);
 
    // Print the values of the node in the circle
    outtextxy(x - 2, y - 3, str);
 
    // Set the color of the line from parent to child as green
    setcolor(GREEN);
 
    // Evaluating left and right child
    int left = 2 * index + 1;
    int right = 2 * index + 2;
 
    // Recursively draw the left subtree and the right subtree
    printTree(x - y / (index + 1), y + 50, array, left, total_elements);
 
    printTree(x + y / (index + 1), y + 50, array, right, total_elements);
 
    // Draw the line (or link) when the node is not the leaf node
    if (left < total_elements) {
        line(x, y, x - y / (index + 1), y + 50);
    }
 
    if (right < total_elements) {
        line(x, y, x + y / (index + 1), y + 50);
    }
 
    return;
}

int main()
{
    initwindow(900, 900);
 
    // Given array arr[]
    int array[] = {1, 2, 4, 5, 3};
 
    printTree(300, 100, array, 0, 5); //printing the tree
    
	getch();
    closegraph();
    return 0;
}
