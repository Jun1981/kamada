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

	int shoki=1000;//■のスピード/初期値（でかいほど遅い）
	struct shikaku
	{
		int x;//ｘ座標
		int y;//ｙ座標
		//int sc_s;//スピードカウンタ初期値
		int sc;//スピードカウンタ(大きいほど遅い）

	} sq={40,0,shoki}; 



	
	
	
	setCursor(0);//カーソルを表示しない
	while(sq.y<22)
	{
		    locate(sq.x,sq.y);//四角を画面上方に表示
			printf("■\n");
		if(sq.sc==0)
		{
			 locate(sq.x,sq.y);//四角を画面上方に表示
			printf("  \n");
			sq.y++;//四角を下に落とす
			sq.sc=shoki;
		}
		sq.sc--;//カウンタマイナス
	}



}