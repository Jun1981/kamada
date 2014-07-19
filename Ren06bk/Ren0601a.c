#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"

#pragma warning(disable:4996)

//変数宣言
int i,j;//ループ用

char iti[23][25];//

///構造体/////////////////////////////////
//四角の構造体

struct shikaku{
		int x;//ｘ座標
		int y;//ｙ座標
		int x_S;//ｘ座標初期値
		int y_S;//ｙ座標初期値
		//int sc_s;//スピードカウンタ初期値
		int sp;//スピードカウンタ(大きいほど遅い）
		int sp_S;//スピード初期値(大きいほど遅い）

		char *iti[23][23];//位置
		int iti_F[23][23];//位置フラグ

	}sq;

//////////////////////////////////////////


//プロトタイプ関数宣言
void init(void);//変数などの初期化
void yokosen(void);//下に線を
void hyouji(void);//表示関数
void idou(void);//移動関数

void main (){	
	init();//初期化
	

	for(i=0;i<23;i++){
		
		iti[i][]="0000000000000000000000";
		
	}

	iti[10][10]='3';

	for(i=0;i<23;i++){
			puts(iti[i][0]);

	}


	yokosen();//横線を引く

	//ゲームループ
	while(1){
			
		

		//hyouji();//表示
		//idou();//移動
		//sq.sp--;//カウンタマイナス		
	}	
}

void init(){
	sq.x_S=12;//初期ｘ座標
	sq.y_S=0;	//初期ｙ座標
	sq.x=sq.x_S;
	sq.y=sq.y_S;
	sq.sp_S=1000;//スピード初期値
	sq.sp=sq.sp_S;//スピード初期値代入

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

	if(sq.sp==0 && sq.y!=22){
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

void idou(){
	if(sq.sp==0 && sq.y!=22){
			sq.y++;//四角を下に落とす
			sq.sp=sq.sp_S;
		}



}




