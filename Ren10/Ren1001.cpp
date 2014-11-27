#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include "../../DxLib/DxLib.h"

#pragma warning(disable:4996)

//変数宣言

const int EN = 30;//敵の数
int FontHandle1;//フォントハンドラ１
int white = GetColor(255, 255, 255);//白

//構造体定義

typedef struct{
	int x;
	int y;
} Position;


//プロトタイプ関数宣言

void key_check(void);//キーチェック
void game_main();//メイン

void init(Position[], int);//初期化
void sort(Position[], int);//ソート

void hyouji(Position[], int);//表示


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

	ChangeWindowMode(TRUE);                     // ウインドウモードに変更(ただし、２５６色)

	if (DxLib_Init() == -1) {                    // ＤＸライブラリ初期化処理
		return -1;                              // エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);              // 描画先を裏画面へ


	Position teki[EN];//敵座標の構造体宣言

	init(teki, EN);//初期化

	// ゲームシステム初期化
	//------ ゲームループ ------//
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) { // Escキーが押されるまでループ
		ClsDrawScreen();                        // 裏画面クリア


		//key_check();                            // キー情報取得
		//game_main();                            // ゲームコントロールメイン




		hyouji(teki, EN);

	

		sort(teki, EN);
		
		ScreenFlip();       // 裏画面を表画面へ

	
		if (ProcessMessage() == -1) {            // メッセージ処理
			break;                              // エラーが起きたらループから抜ける
		}
	}
	DxLib_End();// ＤＸライブラリ使用の終了処理
	return 0;// アプリケーションの終了

}



void init(Position x[], int y){

	FontHandle1 = CreateFontToHandle("ＭＳ ゴシック", 20, 9, DX_FONTTYPE_NORMAL);//フォントハンドラ１

	int i;//ループ用

	srand((unsigned)time(NULL));

	for (i = 0; i < y; i++){

		x[i].x = rand() % (640-16);
		x[i].y = rand() % (480-16);


	}

}



void sort(Position x[], int y){

	int i;//ループ用
	Position tmp;//一時
	for (i = 0; i < y - 1; i++){




		if (x[i].y > x[i + 1].y){

			//入れ替え
			tmp = x[i];
			x[i] = x[i + 1];
			x[i + 1] = tmp;
			break;


		}
		else if (x[i].y == x[i + 1].y){
			if (x[i].x > x[i + 1].x){
				//入れ替え
				tmp = x[i];
				x[i] = x[i + 1];
				x[i + 1] = tmp;

				break;
				
			}
			
		}

	}

}

void hyouji(Position x[], int y){
	int i;
	for (i = 0; i < EN; i++){
		DrawFormatStringToHandle(0,16*i, white, FontHandle1, "(%d,%d)",x[i].x,x[i].y);
	
	}

}