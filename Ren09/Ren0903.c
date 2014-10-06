#include <stdio.h>
#include <time.h>
#include"console.h"

#define elm 20//要素数
#define wdth 30 //グラフ領域の幅（全角文字数）
#define hdl  0//ヘッダ部分の行番号
#define grl  2//グラフ部分の一番上の行番号


void main(void){
	int i,j,k,l;//ループ
	int BN[elm];//ブロックの数を入れる
	int tmp;//一時

	int cmp=0,swp=0;//比較、交換

	//ランダムで１～３０の数字を生成し、２０個の配列に入れる。
	srand((unsigned)time(NULL));
	for(i=0; i < elm; i++){
		BN[i]=rand()%wdth+1;
	}

	//初期表示//////////////////////////////////////////////////////////////////////////
	printf(" [##] data | compare = %d swap = %d\n",cmp,swp);
	printf(" -------------------------------------------------------------------------\n");
	for(i=0;i<elm;i++){
		printf(" [%02d] %2d | ",i,BN[i]);
		for(k=0;k<BN[i];k++){
			printf("■");
		}
		printf("\n");			
	}
	/////////////////////////////////////////////////////////////////////////////////////


	for(l=0;l<elm;l++){
		for(j=0;j<elm-1-l;j++){

			cmp++;//比較＋１
			if(BN[j]>BN[j+1]){

				swp++;//交換＋１

				tmp =BN[j];
				BN[j]=BN[j+1];
				BN[j+1]=tmp;
			}

			clear();
			printf(" [##] data | compare = %d swap = %d\n",cmp,swp);
			printf(" -------------------------------------------------------------------------\n");


			for(i=0;i<elm;i++){				
				if(i==j || i==j+1){
					color(FOREGROUND_GREEN);
				}else{
					color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				}

				printf(" [%02d] %2d | ",i,BN[i]);
				for(k=0;k<BN[i];k++){printf("■");}
				printf("\n");		
				Sleep(10);
			}
			//Sleep(100);
		}

	}
}





















