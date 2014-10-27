#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<Windows.h>
#include "../../DxLib/DxLib.h"

#define ARRAY_SIZE 20//要素数
#define wdth 30 //グラフ領域の幅（全角文字数）
#define hdl  20//ヘッダ部分の行番号
#define gfl  0//グラフ部分の一番上の行番号
#define bw   16 //ブロックの幅


//変数宣言
int data[ARRAY_SIZE];//
int FontHandle1;

//プロトタイプ関数
void init (int[],int);
void sort (int[],int);
void showHeader(int ,int);
void showGraph(int[],int,int);




int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);                     // ウインドウモードに変更(ただし、２５６色)
	if (DxLib_Init() == -1) {                    // ＤＸライブラリ初期化処理
		return -1;                              // エラーが起きたら直ちに終了
	}
	
	init (data,ARRAY_SIZE);//初期化
	sort(data,ARRAY_SIZE);	//メイン
	

	 WaitKey() ;
	DxLib_End();                                // ＤＸライブラリ使用の終了処理
	return 0;                                  // アプリケーションの終了
	
}



void init(int x[],int y){		

	FontHandle1 = CreateFontToHandle(NULL, 16, 8,-1);//ゲーム用フォントハンドラ;//フォントハンドラ1

	int i;//ループ用
	//ランダムで１～３０の数字を生成し、２０個の配列に入れる。
	srand((unsigned)time(NULL));
	for(i=0; i < y; i++){
		x[i]=rand()%wdth+1;
	}
}

void sort(int bl[],int x){
	int tmp;//一時
	int cmp=0,swp=0;//比較、交換	
	int i, j;//ループ用
		
	for(i=0;i<x;i++){//x=20
		for(j=0;j<(x-1)-i;j++){
			SetDrawScreen(DX_SCREEN_BACK); // 描画先を裏画面へ
			ClsDrawScreen(); //裏画面消去
			cmp++;//比較＋１			



			if(bl[j]>bl[j+1]){
				swp++;//交換＋１
				tmp =bl[j];
				bl[j]=bl[j+1];
				bl[j+1]=tmp;
			}



			showHeader(cmp, swp);//ヘッダー表示
			showGraph(bl, ARRAY_SIZE, j);//表示

			//_sleep(10);

			ScreenFlip();                           // 裏画面を表画面へ
			

		}
	}
	///////////////////////////////////////////////

}

void showHeader(int x  ,int y){

	DrawFormatStringToHandle(0,0,GetColor(255,255,255),FontHandle1, "[##] data | compare = %d swap = %d",x,y);
	DrawFormatStringToHandle(0,20,GetColor(255,255,255),FontHandle1, " ------------------------------------------------------------------------",x,y);

}

void showGraph(int x[],int y,int z){

	int i, j;//ループ用
	for(i=0;i<y;i++){

		if(i==z || i== z+1){

			DrawFormatStringToHandle( 0, 40+20*i, GetColor(0, 255, 0), FontHandle1, "[%02d] %2d | ",i,x[i]);

			for(j=0;j<x[i];j++){
				DrawFormatStringToHandle( 90+j*bw, 40+20*i, GetColor(0, 255, 0), FontHandle1, "■");

			}

		}else{
			DrawFormatStringToHandle( 0, 40+20*i, GetColor(255, 255, 255), FontHandle1, "[%02d] %2d | ",i,x[i]);
			for(j=0;j<x[i];j++){
				DrawFormatStringToHandle( 90+bw*j, 40+20*i, GetColor(255, 255, 255), FontHandle1, "■");

			}


		}
	}
}
