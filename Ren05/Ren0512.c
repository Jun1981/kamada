#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"

#pragma warning(disable:4996)

void main ()
{
	int x = 0, y = 0;//�I
	int x1=40;//���@
	int tama=0,x2,y2;//�e�̔���ƍ��W

	int d=1, e=1;
	int s=0;//�ŏ�����
	char c;

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

		locate (x1,21);
		printf("��");

		if(tama==1)
		{					
			if(y2>0)
			{
				locate(x2, y2);
				printf(" ");
				y2--;
				locate(x2,y2);
				printf("|");
			}else
			{
				locate(x2, y2);
				printf(" ");
				tama=0;

			}
		}



		//�L�[��t
		if (_kbhit())
		{
			c = getch();

			if(c=='1' && x1>=1)
			{
				x1--;
			}
			else if(c=='3' && x1 <=77)
			{
				x1++;
			}		
			else if(c=='x')
			{
				locate(40,10);
				printf("�I��\n");
				break;
			}
			if(c==' ' && tama==0)
			{
				x2=x1;y2=21;
				tama=1;

			}
		}

		if(x==0 && s==1)
		{
			d=~d+1;
		}else if(x==79)
		{
			d=~d+1;
		}


		if(y==0 && s==1)
		{
			e=~e+1;
		}else if(y==20)
		{
			e=~e+1;
		}

		if(s==0)
		{
			s=1;
		}
	}
}