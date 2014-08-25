#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"

#pragma warning(disable:4996)														



struct shikaku														
{																	
	int x;//ｘ座標													
	int y;//ｙ座標													
	int d_cnt;//落下スピードカウンタ(大きいほど遅い）				
	int s_cnt;//横移動カウンタ										
	int flag;//フラグ												
	int shoki_x;//ｘ座標初期値										
	int shoki_y;//ｙ座標初期値										

};																	


//構造体宣言														
struct shikaku rakka;//落ちてくる■構造体							


int d_cnt_s=800;//落下■の落ちるスピード/初期値（でかいほど遅い）	
int s_cnt_s=600;//落下■の横移動スピード/初期値（でかいほど遅い）	

int tsumi[25][25] = {0};//積み上がった■構造体						

int i;//ループ用													



//関数プロトタイプ宣言
void init(void);//初期化




void main (){	
	setCursor(0);//カーソルを表示しない
	init();//初期化




	//右端に線を引く
	for(i=0;i<25;i++){

		locate(26,i);
		printf("|");
		locate(i,23);
		printf("-");


	}



	while(1){//while2




		//■を落とす///////////////////////////////////////
		locate(rakka.x,rakka.y);//四角を画面上方に表示
		printf("■\n");
		if(rakka.d_cnt==0){
			locate(rakka.x ,rakka.y);//四角を消す
			printf("  \n");
			rakka.y++;//四角を下に落とす
			rakka.d_cnt=d_cnt_s;
			//locate(rakka.x,rakka.y);//四角を再び表示
			//printf("■\n");

		}

		//キー入力部分
		if(rakka.s_cnt==0){

			//横移動
			if( (GetKeyState(VK_NUMPAD4)<0 || GetKeyState(VK_LEFT)<0) && rakka.x>=2 && tsumi[rakka.x-2][rakka.y]!=1){
				locate(rakka.x,rakka.y);//四角を消す
				printf("  \n");
				rakka.x-=2;
				//locate(rakka.x,rakka.y);//四角を再び表示
				//printf("■\n");
			}
			if( (GetKeyState(VK_NUMPAD6)<0  || GetKeyState(VK_RIGHT)<0 ) && rakka.x+2<=25 && tsumi[rakka.x+2][rakka.y]!=1){
				locate(rakka.x,rakka.y);//四角を消す
				printf("  \n");
				rakka.x+=2;
				//locate(rakka.x,rakka.y);//四角を再び表示
				//printf("■\n");
			}

			//終了
			if(GetKeyState(0x58)<0){
				exit(0);
			}
			rakka.s_cnt=s_cnt_s;
		}


		//落下■が下に達したら
		if(rakka.y==22){
			tsumi[rakka.x][rakka.y]=1;
			locate(rakka.x,rakka.y);//四角を画面上方に表示
			printf("■\n");
			rakka.x=12;
			rakka.y=0;
			/*locate(rakka.x,rakka.y);
			printf("　");*/

		}else if(tsumi[rakka.x][rakka.y+1]==1){
			tsumi[rakka.x][rakka.y]=1;
			locate(rakka.x,rakka.y);//四角を画面上方に表示
			printf("■\n");
			rakka.x=12;
			rakka.y=0;
		}

		rakka.d_cnt--;//カウンタマイナス
		rakka.s_cnt--;//


	}
}




//初期化
void init(){


	//落ちてくる■初期値

	rakka.x = 13 - 1;
	rakka.y = 0;
	rakka.d_cnt = d_cnt_s;
	rakka.s_cnt = s_cnt_s;
	rakka.shoki_x = 12;
	rakka.shoki_y = 0;


}


