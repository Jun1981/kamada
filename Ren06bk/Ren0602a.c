#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"

#pragma warning(disable:4996)

//変数宣言
int i,j;//ループ用

int  iti_flag[23][26];

int KeyInfo=0,KeyOld=0,KeyTrg=0;//キー関係

char iti[23][26];//文字列変数

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

		int w;//一回の横移動距離

	}sq;

//////////////////////////////////////////


//プロトタイプ関数宣言
void init(void);//変数などの初期化
void yokosen(void);//下に線を
void hyouji(void);//表示関数
void kesu(void);//消す
void idou(void);//移動関数

void KeyChk(void);

void Shuuryou(void);

void main (){	
	init();//初期化
	yokosen();//横線を引く

	//ゲームループ
	while(1){

		/*locate(40,20);
		printf("%07d\n",KeyTrg);
		locate(40,21);
		printf("%07d\n",KeyInfo);*/
		
		
		hyouji();//表示
		KeyChk();//キーチェック
				
		//kesu();
		idou();//移動
		hyouji();//表示
	
		Shuuryou();//終了チェック
		
		sq.sp--;//カウンタマイナス		
		
	}	
}

void init(){
	setCursor(0);//カーソルを表示しない

	sq.x_S=40;//初期ｘ座標
	sq.y_S=0;	//初期ｙ座標
	sq.x=sq.x_S;
	sq.y=sq.y_S;
	sq.sp_S=2000;//スピード初期値
	sq.sp=sq.sp_S;//スピード初期値代入	

	sq.w=2;//横移動一回文

		
}

void yokosen(){
	locate(0,23);//２２行目に横線を引く
		for(i=0;i<80;i++){
		printf("~");
		}
}

void hyouji(){		
		locate(sq.x,sq.y);//四角を画面上方に表示
	    puts("■");
			
}

void kesu(){

	locate(sq.x,sq.y);//四角を画面上方に表示
		puts("　");
}

void idou(){




	if(sq.sp<=0 && sq.y<22){
			kesu();
		sq.y++;//四角を下に落とす
		sq.sp=sq.sp_S;

		

	}		
		if(sq.x>=sq.w){
			if(KeyTrg==0x80){
					kesu();
				sq.x-=2;
			}
		}if(sq.x<=77-sq.w){
			if(KeyTrg==0x01){
					kesu();
				sq.x+=2;
				
			}
		}

			if(KeyInfo==0x81) sq.sp-=4;	
}


void KeyChk(){		

	////// ←　0x80
	////// →　0x01
		KeyTrg=KeyInfo=0;

		if(  GetKeyState(VK_NUMPAD4)<0 || GetKeyState(VK_LEFT) <0 ){
			KeyInfo |= 0x80;
		}
		if(  GetKeyState(VK_NUMPAD6)<0 || GetKeyState(VK_RIGHT)<0 ){
		KeyInfo |=  0x01;
		}
		KeyTrg=(KeyOld^KeyInfo)&KeyInfo;
		KeyOld=KeyInfo;
}

void Shuuryou(){

	if(sq.y>=22){
		locate(sq.x,sq.y);//四角を画面上方に表示
		puts("■");
		getch();
		locate(11,12);
		printf("終了\n\n");
		exit(0);//終了

	}
}


