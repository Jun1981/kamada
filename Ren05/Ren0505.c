#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include"console.h"

void main()
{
	int i;
	for(i=0;i<21;i++)
	{
		clear();
		setCursor(0);
		color(FOREGROUND_GREEN | FOREGROUND_BLUE);
		locate(i,i);
		printf("*");
		setCursor(1);
		Sleep(500);
		//getch();
		color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);



	}

}