#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"

#pragma warning(disable:4996)

void main()
{
	int x[10], y[10];//的の座標
	int x1 = 40;//自機のｘ座標
	int tama[20] = { 0 };//弾が出ているかどうかの判定
	int x2[20], y2[20];//弾の座標
	int atari[20] = { 0 };//当たり判定
	int muki[10];//弾の向き
	unsigned int ten = 0;//スコア
	int d[10], e[10];//ｘとｙ方向の進む値
	int s = 0;//最初の（０，０）座標を無視するためのスイッチ
	//char c;//キー受け取り用
	int kazu=0;//弾数
	int i, j;//ループ用
	int f = 0, g = 0;//ループが終わったときの回数を入れる変数
	int ty[10];//的のそれぞれの強さを入れる配列

	int speed_orig[10];//的のスピード調整オリジナル
	int speed[10];//的のスピード調整
	int count=0;//キーチェックの頻度調整

	int matocount[10]={0};
	//int r[10];



	
	for(i=0;i<10;i++)
	{
		ty[i] = rand() % 3 + 1;
		if(ty[i]==1)
		{
			speed_orig[i]=10;
		}else if(ty[i]==2)
		{
			speed_orig[i]=4;
		}else if(ty[i]==3)
		{
			speed_orig[i]=2;
		}
		speed[i]=speed_orig[i];
	}



	/*for(i=0;i<10;i++)
	{
		r[i]=rand()%2+1;

	}*/




	for (i = 0; i < 20; i++)
	{
		x2[i] = -100;
		y2[i] = -100;

	}

	srand((unsigned)time(NULL));

	for (i = 0; i < 10; i++)
	{
		x[i] = rand() % 66 + 2;
		y[i] = rand() % 18 + 2;
		muki[i] = rand() % 4 + 1;
		switch (muki[i])
		{
		case 1:
			d[i] = 1;
			e[i] = 1;
			break;
		case 2:
			d[i] = 1;
			e[i] = -1;
			break;
		case 3:
			d[i] = -1;
			e[i] = -1;
			break;
		case 4:
			d[i] = -1;
			e[i] = -1;
			break;
		}

		

	}

	while (1)
	{
		locate(70, 2);
		printf("%d", ten);

		setCursor(0);




		//的の表示

		for (i = 0; i < 10; i++)
		{
			locate(x[i], y[i]);
			if (ty[i] == 1)
			{
				printf("3");

			}else if(ty[i]==2)

			{
				printf("6");
			}else if(ty[i]==3 &&matocount[i]==0)
			{
				printf("�I");
			}else if(ty[i]==3 && matocount[i]==1)

			{
				printf("10");
			}

			locate(x[i], y[i]);
			printf("　");


			if(speed[i]==0)
			{
				x[i] += d[i];
				y[i] += e[i];
				speed[i]=speed_orig[i];
			}else
			{
				speed[i]--;
			}

			
		

			locate(x[i], y[i]);
			if (ty[i] == 1)
			{
				printf("3");

			}else if(ty[i]==2)

			{
				printf("6");
			}else if(ty[i]==3&&matocount[i]==0)
			{
				printf("�I");
			}else if(ty[i]==3 && matocount[i]==1)

			{
				printf("10");
			}
			
		}




		locate(x1, 21);
		printf("▲");

		//弾の表示
		for (i = 0; i<20; i++)
		{
			if (tama[i] == 1 && atari[i] == 0)
			{
				if (y2[i]>0)
				{
					locate(x2[i], y2[i]);
					printf(" ");
					y2[i]--;
					locate(x2[i], y2[i]);
					printf("†");
				}
				else
				{
					locate(x2[i], y2[i]);
					printf(" ");
					kazu--;
					tama[i] = 0;

				}
			}
		}

		//弾と的の座標が一致したら

		for (i = 0; i < 20; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (tama[i] == 1 &&  atari[i] == 0)
				{

					if (ty[j] == 1 && x2[i] == x[j] && y2[i] == y[j])
					{
						atari[i] = 1;
						ten += 3;
						f = i;
						g = j;
						break;
					}
					else if (ty[j] == 3 && x2[i] >= x[j]-1 &&  x2[i] <= x[j]+1 && y2[i] == y[j])
					{
						if(matocount[j]==1)
						{

							atari[i] = 1;
							ten += 10;
							f = i;
							g = j;
							matocount[j]=0;
							break;
						}
						else
						{
							tama[i]=0;
							matocount[j]++;
						}
					}else if(ty[j] == 2 && x2[i] == x[j] && y2[i] == y[j])
					{
						atari[i] = 1;
						ten += 6;
						f = i;
						g = j;
						break;


					}


				}
			}
		}


		if (atari[f] == 1)
		{
			kazu = 0;
			for (i = 0; i < 10; i++)
			{
				locate(x[i], y[i]);
				printf("　");
			}
			for (i = 0; i < 20; i++)
			{
				tama[i] = 0;
				atari[i] = 0;
				locate(x2[i], y2[i]);
				printf("　");
				x2[i] = -100; y2[i] = -100;

			}

			if (ty[g] == 1)
			{
				locate(35, 10);
				printf("Hit! +3");
				Sleep(1000);
				locate(35, 10);
				printf("       ");
			}
			else if(ty[g]==3)
			{
				locate(35, 10);
				printf("Hit! +10");
				Sleep(1000);
				locate(35, 10);
				printf("        ");
			}else if(ty[g]==2)
			{
				locate(35, 10);
				printf("Hit! +6");
				Sleep(1000);
				locate(35, 10);
				printf("       ");
			}


			for (i = 0; i < 10; i++)
			{
				x[i] = rand() % 65 + 2;
				y[i] = rand() % 16 + 2;

				muki[i] = rand() % 4 + 1;
				switch (muki[i])
				{
				case 1:
					d[i] = 1;
					e[i] = 1;
					break;
				case 2:
					d[i] = 1;
					e[i] = -1;
					break;
				case 3:
					d[i] = -1;
					e[i] = -1;
					break;
				case 4:
					d[i] = -1;
					e[i] = -1;
					break;
				}

			}

		}



		//if(count==0)
		//{
			if (GetKeyState(VK_SPACE) < 0)
			{
				for (i = 0; i < 20; i++)
				{
					if (tama[i] == 0 && atari[i] == 0 && kazu < 20 && count==0)
					{

						x2[i] = x1;
						y2[i] = 21;
						tama[i] = 1;
						kazu++;
						count=10;
						break;
					}
				}
			}
			if ((GetKeyState(VK_NUMPAD1) < 0 || GetKeyState(VK_LEFT)<0) && x1 >= 1)
			{
				x1--;

			}else
				if ((GetKeyState(VK_NUMPAD3) < 0 || GetKeyState(VK_RIGHT)<0) && x1 <= 67)
				{
					x1++;

				}else
					if (GetKeyState(0x58) < 0)
					{
						locate(40, 10);
						printf("終了\n");


					}
					//count=3;
		//}




		for (i = 0; i < 10; i++)
		{
			if (x[i] == 0 && s == 1)
			{
				d[i] = ~d[i] + 1;
			}
			else if (x[i] == 68)
			{
				d[i] = ~d[i] + 1;
			}


			if (y[i] == 0 && s == 1)
			{
				e[i] = ~e[i] + 1;
			}
			else if (y[i] == 20)
			{
				e[i] = ~e[i] + 1;
			}
		}

		if (s == 0)
		{
			s = 1;
		}
		if(count>0)
		{
		count--;
		}
	}
}