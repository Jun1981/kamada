#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include"console.h"

void main()
{
	int i=0,j=20;
	while(1)
	{
		if(i>=0&&i<=20)
		{
			clear();
			setCursor(0);
			color(7);
			locate(i,i);
			printf("*");
			Sleep(50);
			locate(i,i);
			printf(" ");
			Sleep(50);
			i+=1;
		}else if(j>=0)

		{
			clear();
			setCursor(0);
			color(7);
			locate(i,j);
			printf("*");
			Sleep(50);
			locate(i,j);
			printf(" ");
			Sleep(50);
			i++;
			j--;
		}else
		{
			break;
		}


	}

}