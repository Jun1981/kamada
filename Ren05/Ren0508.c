#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include"console.h"

void main()
{
	int i=0,j=20;
	while(1)
	{
		if(i<=20)
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
		}else if(i<=40)

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
		}else if(i>=41 &&i<=79)
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
			j++;
			
		}else
		{
			break;
		}
		

	}

}