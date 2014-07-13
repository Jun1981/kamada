#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"

#pragma warning(disable:4996)

#define sq_num 100

//#define shoki 1000;//四角のスピード初期値

struct shikaku
{
	int x;//ｘ座標
	int y;//ｙ座標
	int s_d;//落下スピード(大きいほど遅い）
	int s_w;//横移動速度
	int flag;//フラグ
};

void main ()

{	
	//四角の構造体設定

	int i;//ループ用
	int sd_shoki=2000;//■のスピード/初期値（でかいほど遅い）
	int sw_shoki=1000;

	struct shikaku sq[sq_num];

	//for(i=0;i<sq_num;i++)
	//{
	//	sq[i]=
	//	{
	//		{ 
	//			{40},
	//			{0},
	//			{sd_shoki},
	//			{sw_shoki}}
	//	};
	//	

	//}

	//構造体初期代入
	for(i=0;i<sq_num;i++)
	{
		sq[i].x=13;
		sq[i].y=0;
		sq[i].s_d=sd_shoki;
		sq[i].s_w=sw_shoki;
		sq[i].flag=0;
	}


	sq[0].flag=1;//最初の■フラグを立てる


	setCursor(0);//カーソルを表示しない

	i=0;
	//while(1)//while(1)
	//{

		for(i=0;i<sq_num;i++)//for1
		{
			while(1)//while2
			{


				//■を落とす///////////////////////////////////////
				locate(sq[i].x,sq[i].y);//四角を画面上方に表示
				printf("■\n");
				if(sq[i].s_d==0)
				{
					locate(sq[i].x,sq[i].y);//四角を画面上方に表示
					printf("  \n");
					sq[i].y++;//四角を下に落とす
					sq[i].s_d=sd_shoki;
					locate(sq[i].x,sq[i].y);//四角を画面上方に表示
					printf("■\n");

				}

				//キー入力部分
				if(sq[i].s_w==0)
				{
					if( (GetKeyState(VK_NUMPAD4)<0 || GetKeyState(VK_LEFT)<0) && sq[i].x>0)
					{
						locate(sq[i].x,sq[i].y);//四角を画面上方に表示
						printf("  \n");
						sq[i].x--;
						locate(sq[i].x,sq[i].y);//四角を画面上方に表示
						printf("■\n");
					}
					if( (GetKeyState(VK_NUMPAD6)<0  || GetKeyState(VK_RIGHT)<0 ) && sq[i].x+1<24)
					{
						locate(sq[i].x,sq[i].y);//四角を画面上方に表示
						printf("  \n");
						sq[i].x++;
						locate(sq[i].x,sq[i].y);//四角を画面上方に表示
						printf("■\n");
					}
					sq[i].s_w=sw_shoki;
				}

		




			sq[i].s_d--;//カウンタマイナス
			sq[i].s_w--;//



			if(sq[i].y==22)
			{
				//sq[i].flag=0;
				sq[i+1].flag=1;//次の四角のフラグを立てる
				break;
			}
				}//while2
		}//for1
	//}//while1
}





