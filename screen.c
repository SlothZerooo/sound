#include "screen.h"
#include <stdio.h>

/* function definition of clearScreen()
   This function uses VT100 escape sequence \ESC[2J to make the whole
   termial screen empty
   argument : no
   return : no
*/
void clearScreen(void){
	printf("%c[2J", ESC);
	fflush(stdout);
}

/* function definition of gotoxy()
   This function uses VT100 escape sequence \ESC[row;colH to set cursor
   to a specific localtion on the terminal screen
   argument :   row number, 1 is top row
   				col number, 1 is left column
   return : no
*/
void gotoxy(int row, int col){
	printf("%c[%d;%dH", ESC, row, col);
	fflush(stdout);
}

/* function definition of color()
   This function uses VT100 escape sequence \ESC[1;colorm to set color to
   chnage to different color on the terminal screen
   argument :	the highest voice is RED
   			 	the lowest voice is WHITE
   return : no
*/
void setColor(int color){
	if(color>=BLACK && color<=WHITE){
		printf("%c[1;%dm", ESC, color);
		fflush(stdout);
	}
}


//function defintion of dispBar()
// 30 to 90
void dispBar(int col, double dB){
	int i;
	for(i=0; i<dB/3; i++){
		gotoxy(30-i, col+1);
#ifndef UNICODE
		printf("%c", '*');
#else
		if(i<50/3) setColor(WHITE);
		else if(i<70/3) setColor(YELLOW);
		else(setColor(RED));
		printf("%s", BAR);
#endif
	}
}
