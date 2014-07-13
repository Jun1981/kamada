#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"

#pragma warning(disable:4996)

void main ()
{
	int x[10], y[10];//的
	int x1=40;//自機
	int tama[20]={0};//弾の判定と座標


	int x2[20],y2[20];


	int atari[20] ={0};//当たり判定

	int muki[10];//

	unsigned int ten=0;

	int d[10], e[10];
	int s=0;//最初だけ
	char c;

	int kazu;//弾数

	int i,j;//ループ用

	int f=0;


	for(i=0;i<20;i++)
	{
		x2[i]=-100;
		y2[i]=-100;

	}


	srand((unsigned) time (NULL));

	for(i=0;i<10;i++)
	{
		x[i]=rand()%66+2;
		y[i]=rand()%18+2;
		muki[i]=rand()%4+1;
				switch(muki[i])
				{
				case 1:
					d[i]=1;
					e[i]=1;
					break;
				case 2:
					d[i]=1;
					e[i]=-1;
					break;
				case 3:
					d[i]=-1;
					e[i]=-1;
					break;
				case 4:
					d[i]=-1;
					e[i]=-1;
					break;
				}		
	}

	while(1)
	{
		locate(70,2);
		printf("%d",ten);

		setCursor(0);
		

		//弾の表示
		for(i=0;i<10;i++)
		{

			locate(x[i], y[i]);
			printf("●");
			
			Sleep(2);

			locate(x[i], y[i]);
			printf(" ");
			//Sleep(5);

			x[i]+=d[i];
			y[i]+=e[i];
			locate(x[i], y[i]);
			printf("●");
			
		}



		locate (x1,21);
		printf("▲");

		//弾の表示
		for(i=0;i<20;i++)
		{
			if(tama[i]==1 && atari[i]==0)
			{					
				if(y2[i]>0)
				{
					locate(x2[i], y2[i]);
					printf(" ");
					y2[i]--;
					locate(x2[i],y2[i]);
					printf("†");
				}else
				{
					locate(x2[i], y2[i]);
					printf(" ");
					kazu--;
					tama[i]=0;

				}
			}
		}

		//弾と的の座標が一致したら

		for(i=0;i<20;i++)
		{
			for(j=0;j<10;j++)
			{
				if(tama[i]==1 && x2[i]==x[j] && y2[i]==y[j] && atari[i]==0)
				{
					ten++;
					atari[i]=1;
					f=i;
					break;
				}
			}
		}



		if(atari[f]==1)
		{

			for(i=0;i<10;i++)
			{
				locate(x[i], y[i]);
				printf(" ");
			}
			for(i=0;i<20;i++)
			{
				tama[i]=0;
				atari[i]=0;
				locate(x2[i], y2[i]);
				printf(" ");
				x2[i]=-100;y2[i]=-100;

			}


			locate(35,10);
			printf("Hit!");
			Sleep(1000);
			locate(35,10);
			printf("    ");


			for(i=0;i<10;i++)
			{
				x[i]=rand()%65+2;
				y[i]=rand()%16+2;

				muki[i]=rand()%4+1;
				switch(muki[i])
				{
				case 1:
					d[i]=1;
					e[i]=1;
					break;
				case 2:
					d[i]=1;
					e[i]=-1;
					break;
				case 3:
					d[i]=-1;
					e[i]=-1;
					break;
				case 4:
					d[i]=-1;
					e[i]=-1;
					break;
				}		

			}



		}

		//キー受付
		if (_kbhit())
		{
			c = getch();

			if(c=='1' && x1>=1)
			{
				x1--;
			}else if(c=='3' && x1 <=67)
			{
				x1++;
			}else if(c=='x')
			{
				locate(40,10);
				printf("終了\n");
				break;
			}else if(c==' ')
			{
				for(i=0;i<20;i++)
				{
					if(tama[i]==0 && atari[i]==0 && kazu<20)
					{

						x2[i]=x1;
						y2[i]=21;
						tama[i]=1;
						kazu++;
						break;

					}
				}
			}
		}

		for(i=0;i<10;i++)
		{
		if(x[i]==0 && s==1)
		{
			d[i]=~d[i]+1;
		}else if(x[i]==68)
		{
			d[i]=~d[i]+1;
		}


		if(y[i]==0 && s==1)
		{
			e[i]=~e[i]+1;
		}else if(y[i]==20)
		{
			e[i]=~e[i]+1;
		}
		}

		if(s==0)
		{
			s=1;
		}
	}
}