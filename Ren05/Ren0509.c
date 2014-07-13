#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"

#pragma warning(disable:4996)

void main ()
{
	int x = 0, y = 0;
	int d=1, e=1;
	int s=0;

	while(1)
	{
		setCursor(0);
		locate(x, y);
		printf("*");Sleep(20);
		locate(x, y);
		printf(" ");
		x+=d;
		y+=e;
		locate(x, y);
		printf("*");

		if(x==0 && y==0 && s==1)
		{
			d=~d+1;
			e=~e+1;
		}else
			if(x==79 && y==20)
			{
				d=~d+1;
				e=~e+1;
			}else
				if(x==0 && y==20)
				{
					d=~d+1;
					e=~e+1;
				}else
					if(x==79 && y==0)
					{
						d=~d+1;
						e=~e+1;
					}else
						if(x==0 && s==1)
						{
							d=~d+1;
						}else
							if(x==79)
							{
								d=~d+1;

							}else
								if(y==0 && s==1)
								{
									e=~e+1;
								}else
									if(y==20)
									{
										e=~e+1;
									}


									if(s==0)
									{
										s=1;
									}
	}
}