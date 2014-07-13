#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"

#pragma warning(disable:4996)

void main ()
{
	int x = 0, y = 0;//的
	int x1=40;//自機
	int tama=0,x2=-100,y2=-100;//弾の判定と座標

	int atari =0;//当たり判定

	int muki;//

	unsigned int ten=0;

	int d=1, e=1;
	int s=0;//最初だけ
	char c;


	srand((unsigned) time (NULL));

	while(1)
	{
		locate(70,2);
		printf("%d",ten);

		if(atari==0)
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
		}

		locate (x1,21);
		printf("▲");

		if(tama==1 && atari==0)
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

		//弾と的の座標が一致したら
		if(x2>=x-2 && x2 <= x+2 && y2>=y && y2<=y+1 && atari==0)
		{
			ten++;
			atari=1;
		}


		if(atari==1)
		{
			locate(x, y);
			printf(" ");
			locate(x2, y2);
			printf(" ");

			locate(35,10);
			printf("Hit!");
			Sleep(1000);
			locate(35,10);
			printf("    ");



			x=rand()%65+2;
			y=rand()%16+2;

			muki=rand()%4+1;
			switch(muki)
			{
			case 1:
				d=1;
				e=1;
				break;
			case 2:
				d=1;
				e=-1;
				break;
			case 3:
				d=-1;
				e=-1;
				break;
			case 4:
				d=-1;
				e=-1;
				break;
			}		

			x2=-100;y2=-100;//とりあえず弾座標にマイナスの数値
			tama=0;
			atari=0;
		}

		//キー受付
		if (_kbhit())
		{
			c = getch();

			if(c=='1' && x1>=1)
			{
				x1--;
			}
			else if(c=='3' && x1 <=67)
			{
				x1++;
			}		
			else if(c=='x')
			{
				locate(40,10);
				printf("終了\n");
				break;
			}else
				if(c==' ' && tama==0 && atari==0)
				{

					x2=x1;
					y2=21;
					tama=1;

				}
		}


		if(x==0 && s==1)
		{
			d=~d+1;
		}else if(x==69)
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