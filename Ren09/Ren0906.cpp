#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<Windows.h>
#include "../../DxLib/DxLib.h"



//変数宣言

int FontHandle1,FontHandle2;

int Key_Trg, Key_Info, Key_Old;   // キー情報r
int ChkKAny;                             // とにかくキーが押されたらtrue
int GLpCnt;                             // ゲームループカウンタ
int i, j, k,l;//ループ用
int title;//タイトル画像読み込み用
int bg; //ゲーム本編背景画像用
int GO;//ゲームオーバー画面読み取り用
int cl;//クリア画面用

int ten;//点数
int et,t_limit;//時間


int haji=0;//端フラグ

//色
int white,green;


//////////

//プロトタイプ関数
void init(void);//初期化
void key_check(void);//キーチェック
void hyouji(void);//表示

int haji_chk(void);//端チェック
void game_main(void);//メイン


//構造体
struct par{
	int x;
	int y;
	int haji;//端フラグ

	int cnt;//何ループごとに動くか

	int haba;//幅

	int type;//敵のタイプ

	int x1,y1;//弾の座標

	int muki;//向き

	int sp_x,sp_y;//ｘｙ方向にいくら移動するか

};

struct par jiki;
struct par teki[10];

/////////////////////////////////////////////////////////

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);                     // ウインドウモードに変更(ただし、２５６色)
	if (DxLib_Init() == -1) {                    // ＤＸライブラリ初期化処理
		return -1;                              // エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);              // 描画先を裏画面へ

	init();//初期化

	FontHandle1 = CreateFontToHandle(NULL, 40, 4,-1);//タイトル用フォントハンドラ;//フォントハンドラ１
	FontHandle2 = CreateFontToHandle(NULL, 16, 8,-1);//ゲーム用フォントハンドラ;//フォントハンドラ２

	//PlaySoundMem(S1, DX_PLAYTYPE_LOOP);

	// ゲームシステム初期化
	//------ ゲームループ ------//
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) { // Escキーが押されるまでループ
		ClsDrawScreen();                        // 裏画面クリア
		key_check();                            // キー情報取得
		game_main();                            // ゲームコントロールメイン

		ScreenFlip();                           // 裏画面を表画面へ
		if (ProcessMessage() == -1) {            // メッセージ処理
			break;                              // エラーが起きたらループから抜ける
		}
	}
	DxLib_End();                                // ＤＸライブラリ使用の終了処理
	return 0;                                        // アプリケーションの終了

}





void game_main(){


	hyouji();//表示

	if(jiki.x>0){
		//左
		if(Key_Info==0x01){
			jiki.x-=jiki.sp_x;

		}
	}if(jiki.x+jiki.haba<540){
		//右
		if(Key_Info==0x02){
			jiki.x+=jiki.sp_x;

		}
	}
}


void init(){	
	srand((unsigned)time(NULL));
		
	white=GetColor(255,255,255);//白
	green=GetColor(0,255,0);//緑

	et=0;//経過時間
	t_limit=60;//制限時間
	ten=0;//得点

	//自機の初期座標
	jiki.haji=0;//端にいるかどうか
	jiki.x=320,jiki.y=450;

	jiki.sp_x=3;//自機の速度

	jiki.haba=GetDrawStringWidth("▲",1);




	for (i = 0; i < 10; i++){
			teki[i].type = rand() % 3 + 1;//敵の強さをランダムで決める
			if (teki[i].type == 1){
				teki[i].spd = 10;
			}
			else if (teki[i].type == 2){
				teki[i].spd = 4;
			}
			else if (teki[i].type == 3){
				teki[i].spd = 2;
			}
			
		}

	//弾の座標
		for (i = 0; i < 20; i++){
			teki[i].x1 = -100;
			teki[i].y1 = -100;

		}
	//弾の初期位置と向きをランダムで決める
		

		for (i = 0; i < 10; i++){
			teki[i].x = rand() % 66 + 2;
			teki[i].y = rand() % 18 + 2;
			teki[i].muki = rand() % 4 + 1;
			switch (teki[i].muki){
			case 1:
				teki[i].spd = 1;
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
void hyouji(){
	
	DrawFormatString(jiki.x,jiki.y,white,"▲");

	DrawFormatString(540,20,white,"得点:%d点",ten);
	DrawFormatString(540,40,white,"残り%d秒",t_limit-et);

}


void key_check()
{

	/*---------------------
	*    キー情報取得    *
	*---------------------
	*
	*    LEFT  = 0000 0001
	*    RIGHT = 0000 0010
	*    UP    = 0000 0100
	*    DOWN  = 0000 1000
	*    key_trgは押した瞬間の情報
	*    key_infoは今の状態
	*
	*/
	Key_Trg = Key_Info = 0;                                 // キー情報クリア
	ChkKAny = false;
	if (CheckHitKey(KEY_INPUT_LEFT))   { Key_Info |= 0x01; }
	if (CheckHitKey(KEY_INPUT_RIGHT))  { Key_Info |= 0x02; }
	if (CheckHitKey(KEY_INPUT_UP))     { Key_Info |= 0x04; }
	if (CheckHitKey(KEY_INPUT_DOWN))   { Key_Info |= 0x08; }
	if (CheckHitKey(KEY_INPUT_SPACE))  { Key_Info |= 0x10; }
	if (CheckHitKey(KEY_INPUT_Z))      { Key_Info |= 0x20; }
	if (CheckHitKey(KEY_INPUT_ESCAPE)) { Key_Info |= 0x40; }
	if (CheckHitKeyAll()) { ChkKAny = true; }                    // あにー
	Key_Trg = (Key_Info ^ Key_Old) & Key_Info;          // キートリガー情報セット
	Key_Old = Key_Info;                                     // キー情報セーブ
}
