#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include"console.h"

void main()
{
	clear();
	setCursor(0);
	color(FOREGROUND_GREEN | FOREGROUND_BLUE);
	locate(10,10);
	printf("Hello!");
	setCursor(1);
	getch();
	color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	printf("%d\n",FOREGROUND_GREEN | FOREGROUND_BLUE |FOREGROUND_RED);




}