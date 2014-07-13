#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include"console.h"
#include <stdlib.h>

void main()
{
	int i,j;
	srand((unsigned) time(NULL));
	while(1)
	{
		j=rand()%7+1;
		clear();
		setCursor(0);
		color(j);
		locate(10,10);
		printf("Hello!");
		setCursor(1);
		Sleep(500);
		//getch();
		color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		//printf("%d\n",FOREGROUND_GREEN | FOREGROUND_BLUE |FOREGROUND_RED);

	}
}