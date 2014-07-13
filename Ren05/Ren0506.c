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
		color(7);
		locate(i,i);
		printf("*");
		Sleep(500);
		locate(i,i);
		printf(" ");
		Sleep(500);
		


	}

}