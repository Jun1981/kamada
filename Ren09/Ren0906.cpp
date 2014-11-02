#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include "../../DxLib/DxLib.h"

#pragma warning(disable:4996)

//変数宣言

int FontHandle1,FontHandle2;//フォントハンドラ

const int tekikazu = 100;//敵の数
const int j_tamakazu=100;//自機の弾の数
const int jt_kankaku = 3;//自機弾の発射間隔の初期値
const int jt_spd = 10;//自機弾スピード
int jt_cnt = jt_kankaku;//自機弾発射カウント


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

int d[tekikazu],e[tekikazu];//ｘとyに進む距離

int tamahaba=0;//弾の幅

//色
int white,green,red,blue,purple;


//////////

//プロトタイプ関数
void init(void);//初期化
void key_check(void);//キーチェック
void hyouji(void);//表示

int haji_chk(void);//端チェック
void game_main(void);//メイン

void idou(void);//敵移動関数

void jiki_shot(void);//自機の弾うち関数



void jikidan_idou(void);//自機弾移動

void  atari_chk(void);//自機弾と敵の当たりチェック


//構造体
struct par{
	int x;//自機の座標
	int y;//自機の座標
	int haji;//端フラグ

	int cnt;//何ループごとに動くか

	int haba;//幅

	int type;//敵のタイプ

	int x1,y1;//弾の座標

	int muki;//向き

	int sp_x,sp_y;//ｘｙ方向にいくら移動するか

	char num[3];//数字

	int ten;//点数

	int spd;//スピード

	int color;//色

	int tmf[j_tamakazu];//弾数

	int tx[j_tamakazu],ty[j_tamakazu];//弾座標

	char tamagura[10];//弾の画像

	int tamahaba;//自機弾の幅

	int dead;//死亡フラグ
	

};

struct par jiki;
struct par teki[tekikazu];

/////////////////////////////////////////////////////////

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
//
    ChangeWindowMode(TRUE);                     // ウインドウモードに変更(ただし、２５６色)
	
	if (DxLib_Init() == -1) {                    // ＤＸライブラリ初期化処理
		return -1;                              // エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);              // 描画先を裏画面へ

	init();//初期化


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
	DxLib_End();// ＤＸライブラリ使用の終了処理
	return 0;// アプリケーションの終了

}





void game_main(){
	idou();//移動関係
	jiki_shot();//自機弾
	//jikidan_idou();//自機弾移動
	atari_chk();//自機弾と敵の当たりチェック
	hyouji();//表示


	jt_cnt--;//自機弾カウント－１
}


void init(){	
	srand((unsigned)time(NULL));

	FontHandle1=CreateFontToHandle( "ＭＳ ゴシック", 20,  9, DX_FONTTYPE_NORMAL ) ;  

	white=GetColor(255,255,255);//白
	green=GetColor(0,255,0);//緑
	red=GetColor(255,0,0);//赤
	blue=GetColor(0,0,255);//青
	purple=GetColor(255,0,255);//紫


	et=0;//経過時間
	t_limit=60;//制限時間
	ten=0;//得点

	//自機の初期座標

	jiki.x=320,jiki.y=450;

	jiki.sp_x=3;//自機の速度

	jiki.haba=GetDrawStringWidth("▲",1);//自機の幅

	strcpy(jiki.tamagura,"↑");

	jiki.tamahaba=GetDrawStringWidth(jiki.tamagura,strlen(jiki.tamagura));//




	for (i = 0; i < tekikazu; i++){
		teki[i].type = rand() % 3 + 1;//敵の強さをランダムで決める
		if (teki[i].type == 1){
			teki[i].cnt = tekikazu;
			teki[i].spd=1;
			teki[i].color=green;//色

			teki[i].ten = 3;//点
			strcpy(teki[i].num,"3");
			teki[i].haba = GetDrawStringWidth("3", strlen("3"));
		}
		else if (teki[i].type == 2){
			teki[i].cnt = 4;
			teki[i].spd=2;
			
			teki[i].color=purple;//色


			teki[i].ten = 6;//点
			strcpy(teki[i].num, "6");
			teki[i].haba = GetDrawStringWidth("6", strlen("6"));
		}
		else if (teki[i].type == 3){
			teki[i].cnt = 2;
			teki[i].spd=3;
			teki[i].color=red;//色

			teki[i].ten = 10;//点
			strcpy(teki[i].num,"⑩");
			teki[i].haba = GetDrawStringWidth("⑩", strlen("⑩"));
		}




	}

	////弾の座標
	for (i = 0; i < tekikazu; i++){
		teki[i].x1 = -100;
		teki[i].y1 = -100;

	}
	////弾の初期位置と向きをランダムで決める


	for (i = 0; i < tekikazu; i++){
		teki[i].x = rand() % 500 + 20;
		teki[i].y = rand() % 400 + 20;
		teki[i].muki = rand() % 4 + 1;
		switch (teki[i].muki){
			case 1:
				d[i]=teki[i].spd;
				e[i] = teki[i].spd;
				break;
			case 2:
				d[i] = teki[i].spd;
				e[i] = ~teki[i].spd+1;
				break;
			case 3:
				d[i] = ~teki[i].spd+1;
				e[i] = teki[i].spd;
				break;
			case 4:
				d[i] = ~teki[i].spd+1;
				e[i] = ~teki[i].spd+1;
				break;
		}

	}	

	for (i = 0; i < tekikazu; i++){
		teki[i].dead = 0;//敵は生きている

	}


	//自機の弾フラグを０に
	for(i=0;i<j_tamakazu;i++){

		jiki.tmf[i]=0;
	
	}
	///////////////////////////

}
void hyouji(){


	//自機表示
	DrawFormatStringToHandle(jiki.x,jiki.y,white,FontHandle1,"▲");
	/////////////////////////////////////////////////

	//得点関係表示
	DrawFormatStringToHandle(540,20,green,FontHandle1,"%04d点",ten);
	//DrawFormatStringToHandle(540,40,white,FontHandle1,"残り%d秒",t_limit-et);
	/////////////////////////////////


	//キーチェック表示
	DrawFormatStringToHandle(540,60,white,FontHandle1,"%03d",Key_Info);
	DrawFormatStringToHandle(540,80,white,FontHandle1,"%03d",Key_Trg);

//////////////////////////////////////////////////////



	//敵表示


	for(i=0;i<tekikazu;i++){
		if (teki[i].dead == 0){
			DrawFormatStringToHandle(teki[i].x, teki[i].y, teki[i].color, FontHandle1, "%s", teki[i].num);
		}
	}


	//自機弾表示
	for(i=0;i<j_tamakazu;i++){

		if(jiki.tmf[i]==1){

			DrawFormatStringToHandle(jiki.tx[i],jiki.ty[i],white,FontHandle1,"%s",jiki.tamagura);




		}
		
	}
	////////////////////////////////////////////////////////////////
}


void idou(){

	if(jiki.x>0){
		//左
		if( (Key_Info & 0x01) == 0x01){
			jiki.x-=jiki.sp_x;

		}
	}if(jiki.x+jiki.haba<540){
		//右
		if( (Key_Info & 0x02) == 0x02){
			jiki.x+=jiki.sp_x;

		}
	}

	//敵
	for (i = 0; i < tekikazu; i++){

		if (teki[i].dead == 0){

			teki[i].x += d[i]; teki[i].y += e[i];//敵座標移動

			//端に来たら反転
			if (teki[i].x <= 0 || teki[i].x >= 520){
				d[i] = ~d[i] + 1;
			}
			if (teki[i].y <= 0 || teki[i].y >= 430){
				e[i] = ~e[i] + 1;
			}
			////////////////////////
		}
	}
	//自機弾移動
	for (i = 0; i<j_tamakazu; i++){

		if (jiki.tmf[i] == 1){

			jiki.ty[i] -= jt_spd;//弾を上に移動
		}

		//自機弾が上端に到達したら
		if (jiki.ty[i]<-1){
			jiki.tmf[i] = 0;//弾フラグ０
		}
		///////////////////////
	}

}

void key_check(){

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

void jiki_shot(){

	if (jt_cnt <= 0){
		////////////////////////////////自機弾のカウントが０になったら


		if ((Key_Trg & 0x10) == 0x10){
			for (i = 0; i < j_tamakazu; i++){
				if (jiki.tmf[i] == 0){
					jiki.tmf[i] = 1;
					jt_cnt = jt_kankaku;//自機弾カウント初期化

					jiki.tx[i] = jiki.x, jiki.ty[i] = jiki.y;//現在の自機座標を弾の初期位置に
					break;
				}
			}
		}
		
		if ((Key_Info & 0x20) == 0x20){//連射モード

			for (i = 0; i < j_tamakazu; i++){
				if (jiki.tmf[i] == 0){
					jiki.tmf[i] = 1;
					jt_cnt = jt_kankaku;//自機弾カウント初期化

					jiki.tx[i] = jiki.x, jiki.ty[i] = jiki.y;//現在の自機座標を弾の初期位置に
					break;
				}
			}
		}

		////////////////////////////////////
	}

}



//void jikidan_idou(void){
//
//	for (i = 0; i < j_tamakazu; i++){
//
//		if (jiki.tmf[i] == 1){
//
//			jiki.ty[i] -= jt_spd;//弾を上に移動
//		}
//
//		//自機弾が上端に到達したら
//		if (jiki.ty[i] < -1){
//			jiki.tmf[i] = 0;//弾フラグ０
//		}
//		///////////////////////
//	}
//
//
//
//}

void atari_chk(){


	for(i=0;i<j_tamakazu;i++){
		for(j=0;j<tekikazu;j++){


			if (jiki.tmf[i] == 1 && teki[j].dead==0){
				if  ( (jiki.tx[i] + jiki.tamahaba) > teki[j].x      &&    jiki.tx[i] < (teki[j].x + teki[j].haba) && jiki.ty[i] <= (teki[j].y + 5) && (jiki.ty[i] + 5) >= teki[j].y){//の当たり判定
					


						ten += teki[j].ten;
						jiki.tmf[i] = 0;//自機の弾フラグOFF
						jiki.tx[i] = jiki.ty[i] = -100;//自機弾座標を画面外
						
						teki[j].dead = 1;//敵死亡
						teki[j].x = teki[j].y = -100;//敵座標を画面外に
						break;

					}
				
			}
		}



	}
}