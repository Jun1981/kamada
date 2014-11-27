#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"




#pragma warning(disable:4996)

#define bl_spd  3  //ブロックのスピード

//プロトタイプ関数宣言

void init(void);//場所指定関数
void hyouji(void);//表示関数
void idou(void);//移動関数


void key_chk(void);//キーチェック
///////////////////////////////////////




/////////グローバル変数コーナー//////////////////////////

//key_check()
int Key_Trg, Key_Info, Key_Old;   // キー情報
int ChkKAny;                             // とにかくキーが押されたらtrue
/////////////////////////////////////////////////

int GLpCnt;                             // ゲームループカウンタ
int i, j, k, l;//ループ用

int t_lim;//時間

int haji = 0;//端フラグ



int Key_Info, Key_Old, Key_Trg;//Key_Info押されているKey　Key_Old前フレームで押されていたKey　Key_Trg現在フレームではじめて押されたKey



// これがテトリスのブロックの溜まり場所

static char field[23][27] = { //;      // H22, W25
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,

};

//色
int white, green, red, blue, purple;
///////////////////////////////////////////////////

//構造体
struct  par{

	int x;
	int y;
	int s_cnt;//スピードカウント
	//int flag[22][25];//ブロック場所フラグ


}bl;//ブロックの構造体




void main(void){


	init();//場所設定
	//ゲームループ
	while (1){//Escが押されるまでループ

		key_chk();//キーチェック
		idou();//ブロック移動
		hyouji();//ブロック表示


		if (Key_Info == 0x04){//ｘが押されたら終了
			exit(0);
		}



		clear();//クリア




		//


	}



}


void init(void){

	setCursor(0);//カーソルを表示しない




	bl.x = 13 * 2, bl.y = 0;//ブロックの初期位置
	bl.s_cnt = bl_spd;//スピードカウンタ


};



void hyouji(void){



	// ブロックの表示
	for (i = 0; i < 23; i++) {              // 縦１５列分ループ
		for (j = 0; j < 27; j++) {          // 横１列分ループ
			if (field[i][j] == 1) {
				locate(j * 2, i);
				color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白

				printf("■");
			}
			else if (field[i][j] == 2){
				color(FOREGROUND_GREEN);//緑
				locate(j * 2, i);
				printf("■");
				color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白

			}
		}
	}

	locate(bl.x, bl.y);
	printf("■");





}

void idou(void){

	bl.s_cnt--;//ブロックスピードカウンターー
	//自動落下
	if (bl.s_cnt <= 0){//ブロックのｙ座標をしたに
		bl.s_cnt = bl_spd;//リセット

		if (bl.y < 21 && field[bl.y+1][bl.x/2]==0){
			bl.y++;//下に
		}
		else if (bl.y>=22 ||field[bl.y + 1][bl.x/2] !=0){
			field[bl.y][bl.x / 2] = 1;//
			bl.x = 13 * 2, bl.y = 0;//ブロックの初期位置
			bl.s_cnt = bl_spd;//スピードカウンタ
		}
	}

	//キー入力
	if (Key_Info == 0x01 && bl.x > 1 * 2){
		bl.x -= 2;//左に

	}
	//キー入力
	if (Key_Info == 0x02 && bl.x < 25 * 2){
		bl.x += 2;//右に
	}


}


void key_chk(void){

	//  0000 0001   0x01
	//  0000 0010   0x02
	//  0000 0100   0x04
	//  0000 1000   0x08
	//  0001 0000   0x10
	//  0010 0000   0x20
	//  0100 0000   0x40
	//  1000 0000   0x80
	Key_Trg = Key_Info = 0;


	if (GetKeyState(VK_LEFT) <0)
		Key_Info |= 0x01;
	if (GetKeyState(VK_RIGHT) <0)
		Key_Info |= 0x02;
	if (GetKeyState(0x58) <0)//x
		Key_Info |= 0x04;

	Key_Trg &= (Key_Info^Key_Old);//XOR

	Key_Old = Key_Info;//Key_Old更新

}




