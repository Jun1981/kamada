#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"

#pragma warning(disable:4996)

//変数宣言
int i, j;//ループ用

///構造体/////////////////////////////////
//四角の構造体

struct shikaku{
	int x;//ｘ座標
	int y;//ｙ座標
	int x_S;//ｘ座標初期値
	int y_S;//ｙ座標初期値
	//int sc_s;//スピードカウンタ初期値
	int sd;//スピードカウンタ(大きいほど遅い）
	int sd_S;//スピード初期値(大きいほど遅い）
	int sw;//スピードカウンタ(横）
	int sw_S;//スピードカウンタ初期値

	int line[23];//一列チェック用
	int iti[25][23];//位置
}sq;

//////////////////////////////////////////


//プロトタイプ関数宣言
void init(void);//変数などの初期化
void yokosen(void);//下に線を
void hyouji(void);//表示関数
void kesu(void);//消去関数
void rakka(void);//移動関数

void S_chk(void);//下にブロックがいるかチェック
void line_chk(void);//一列ならんだかどうかチェック
void key_chk(void);//キーチェック

void counter(void);//カウンタ

void main(){
	init();//初期化
	yokosen();//横線を引く

	//ゲームループ
	while (1){
		hyouji();//表示		
		key_chk();//キーチェック			
		rakka();//移動
		//line_chk();//一列並んでるかどうかチェック
		counter();//カウンタ		
	}
}

void init(){
	sq.x_S = 12;//初期ｘ座標
	sq.y_S = 0;	//初期ｙ座標
	sq.x = sq.x_S;
	sq.y = sq.y_S;
	sq.sd_S = 1000;//落下スピード初期値
	sq.sd = sq.sd_S;//落下スピード初期値代入

	sq.sw_S = 1000;//スピード横初期値
	sq.sw = sq.sw_S;//スピード初期値代入

	setCursor(0);//カーソルを表示しない

	for (i = 0; i < 25; i += 2){
		for (j = 0; j < 23; j++){
			sq.iti[i][j] = 0;
			sq.line[j] = 0;

		}
	}
}

void yokosen(){
	locate(0, 23);//２２行目に横線を引く
	for (i = 0; i<80; i++){
		printf("~");
	}
	for (i = 23; i < 25; i++){
		locate(25, i);
		puts("|");
	}
}


void hyouji(){
	locate(sq.x, sq.y);//四角を画面上方に表示
	printf("■\n");
}


//下にブロックがあるかチェック


void rakka(){
	if (sq.sd <= 0){
		if (sq.iti[sq.x][sq.y + 1] == 0 && sq.y < 22){
			locate(sq.x, sq.y);//四角を画面上方に表示
			printf("　");//空白を挿入
			sq.y++;//四角を下に落とす
			hyouji();//再び■表示
		}
		else if (sq.iti[sq.x][sq.y + 1] == 1 || sq.y == 22){
			sq.iti[sq.x][sq.y] = 1;//位置フラグオン			
			hyouji();//積み上がった地点で表示しておく
			line_chk();//一列チェック
			sq.x = sq.x_S; sq.y = sq.y_S;//座標初期化

		}
		sq.sd = sq.sd_S;//カウンタ初期化
	}
}







void key_chk(){
	if (sq.sw <= 0){
		//左移動
		if (GetKeyState(VK_NUMPAD4) < 0 || GetKeyState(VK_LEFT) < 0 && sq.x >= 2){

			if (sq.iti[sq.x - 2][sq.y] == 0){
				sq.sw = sq.sw_S;
				locate(sq.x, sq.y);//四角を消す			
				printf("　");
				sq.x -= 2;//左へ
				locate(sq.x, sq.y);//四角を画面上方に表示
				printf("■\n");
			}

		}
		//右移動
		if (GetKeyState(VK_NUMPAD6) < 0 || GetKeyState(VK_RIGHT) < 0 && sq.x <= 23) {

			if (sq.iti[sq.x + 2][sq.y] == 0){
				sq.sw = sq.sw_S;

				locate(sq.x, sq.y);//四角を消す

				printf("　");
				sq.x += 2;

				locate(sq.x, sq.y);//四角を画面上方に表示
				printf("■\n");
			}

		}
		if (GetKeyState(0x58) < 0){//ｘが押されたら終了

			puts("終了\n");
			exit(0);//終了


		}
	}

}

void line_chk(){
	for (i = 0; i < 25; i += 2){
		if (sq.iti[i][sq.y] == 0){
			break;
		}
	}

	if (i == 26){
		sq.line[sq.y] = 1;//一列並んでいる

		for (i = 0; i < 25; i += 2){
			locate(i, sq.y);
			puts("　");//一列空白
			sq.iti[i][sq.y] = 0;
		}
	}




}






void counter(){
	sq.sd--;//スピードカウンタマイナス	
	sq.sw--;//横スピードカウンタマイナス

}

