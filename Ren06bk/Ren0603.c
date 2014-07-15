#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"

#pragma warning(disable:4996)

//変数宣言
int i;//ループ用

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
		

		char iti[23][23];//位置
		int iti_F[23][23];//位置フラグ

	}sq;

//////////////////////////////////////////


//プロトタイプ関数宣言
void init(void);//変数などの初期化
void yokosen(void);//下に線を
void hyouji(void);//表示関数
void rakka(void);//移動関数
void key_chk(void);//キーチェック

void counter(void);//カウンタ

void main (){	
	init();//初期化
	yokosen();//横線を引く

	//ゲームループ
	while(1){
		hyouji();//表示
		rakka();//移動
		key_chk();//キーチェック
		counter();//カウンタ		
	}	
}

void init(){
	sq.x_S=12;//初期ｘ座標
	sq.y_S=0;	//初期ｙ座標
	sq.x=sq.x_S;
	sq.y=sq.y_S;
	sq.sd_S=3000;//落下スピード初期値
	sq.sd=sq.sd_S;//落下スピード初期値代入

	sq.sw_S=1000;//スピード横初期値
	sq.sw=sq.sw_S;//スピード初期値代入


	setCursor(0);//カーソルを表示しない
		
}

void yokosen(){
	locate(0,23);//２２行目に横線を引く
		for(i=0;i<80;i++){
		printf("~");
		}
}

void hyouji(){

	locate(sq.x,sq.y);//四角を画面上方に表示
	printf("■\n");

	if(sq.sd==0 && sq.y!=22){
		locate(sq.x,sq.y);//四角を画面上方に表示
		printf("  \n");

	}
	if(sq.y==22){

		locate(sq.x,sq.y);//四角を画面上方に表示
		printf("■\n");
		getch();
		locate(11,12);
		printf("終了\n\n");
		exit(0);//終了

	}


}

void rakka(){
	if(sq.sd<=0 && sq.y!=22){
			sq.y++;//四角を下に落とす
			sq.sd=sq.sd_S;
		}



}

void key_chk(){
	if(sq.sw<=0){
		//横移動
		if( GetKeyState(VK_NUMPAD4)<0 || GetKeyState(VK_LEFT)<0 && sq.x>0){


			sq.sw=sq.sw_S;
			locate(sq.x,sq.y);//四角を消す
			
			printf("　");

			sq.x--;
			locate(sq.x,sq.y);//四角を画面上方に表示
			printf("■\n");

		}
		if( GetKeyState(VK_NUMPAD6)<0  || GetKeyState(VK_RIGHT)<0 && sq.x <23) {

			sq.sw=sq.sw_S;

			locate(sq.x,sq.y);//四角を消す
		
			printf("　");
			sq.x++;

			locate(sq.x,sq.y);//四角を画面上方に表示
			printf("■\n");

		}
	}

}



void counter(){
		sq.sd--;//スピードカウンタマイナス	
		sq.sw--;//横スピードカウンタマイナス

}

