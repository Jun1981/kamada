#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"

#pragma warning(disable:4996)


//#define shoki 1000;//四角のスピード初期値
void main ()

{	
	//四角の構造体設定

	int sd_shoki=5000;//■のスピード/初期値（でかいほど遅い）
	int sw_shoki=1000;
	struct shikaku
	{
		int x;//ｘ座標
		int y;//ｙ座標
		//int sc_s;//スピードカウンタ初期値
		int s_d;//落下スピードカウンタ(大きいほど遅い）
		int s_w;//横移動速度
	} sq={40,0,sd_shoki}; 



	
	
	
	setCursor(0);//カーソルを表示しない
	while(sq.y<22)
	{

		//■を落とす///////////////////////////////////////
		    locate(sq.x,sq.y);//四角を画面上方に表示
			printf("■\n");
		if(sq.s_d==0)
		{
			 locate(sq.x,sq.y);//四角を画面上方に表示
			printf("  \n");
			sq.y++;//四角を下に落とす
			sq.s_d=sd_shoki;
			 locate(sq.x,sq.y);//四角を画面上方に表示
			printf("■\n");
					
		}

		//キー入力部分
		if(sq.s_w==0)
		{
		if(GetKeyState(VK_NUMPAD4)<0 && sq.x>0)
		{
			locate(sq.x,sq.y);//四角を画面上方に表示
			printf("  \n");
			sq.x--;
			 locate(sq.x,sq.y);//四角を画面上方に表示
			printf("■\n");
		}
		if(GetKeyState(VK_NUMPAD6)<0 && sq.x+1<24)
		{
			locate(sq.x,sq.y);//四角を画面上方に表示
			printf("  \n");
			sq.x++;
			 locate(sq.x,sq.y);//四角を画面上方に表示
			printf("■\n");
		}
		sq.s_w=sw_shoki;
		}


		sq.s_d--;//カウンタマイナス
		sq.s_w--;//





	}



}