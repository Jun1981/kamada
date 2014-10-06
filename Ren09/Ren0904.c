#include <stdio.h>
#include <time.h>
#include"console.h"

#define ARRAY_SIZE 20//要素数
#define wdth 30 //グラフ領域の幅（全角文字数）
#define hdl  20//ヘッダ部分の行番号
#define gfl  0//グラフ部分の一番上の行番号


//プロトタイプ関数

void init (int[],int);
void sort (int[],int);
void showHeader(int ,int);
void showGraph(int[],int,int);


int i=0,j=0,k=0,l=0;//ループ用

//void main(void){
//	int i,j,k,l;//ループ
//	int data[x];//ブロックの数を入れる
//	int tmp;//一時
//
//	int cmp=0,swp=0;//比較、交換
//
//	
//
//	//初期表示//////////////////////////////////////////////////////////////////////////
//	printf(" [%d] data | compare = %d swap = %d\n",hdl,cmp,swp);
//	printf(" -------------------------------------------------------------------------\n");
//	for(i=0;i<x;i++){
//		printf(" [%02d] %2d | ",i,data[i]);
//		for(k=0;k<data[i];k++){
//			printf("■");
//		}
//		printf("\n");			
//	}
//	/////////////////////////////////////////////////////////////////////////////////////
//
//
//	for(l=0;l<x;l++){
//		for(j=0;j<x-1-l;j++){
//
//			cmp++;//比較＋１
//			if(data[j]>data[j+1]){
//
//				swp++;//交換＋１
//
//				tmp =data[j];
//				data[j]=data[j+1];
//				data[j+1]=tmp;
//			}
//
//			clear();
//			printf(" [%d] data | compare = %d swap = %d\n",hdl,cmp,swp);
//			printf(" -------------------------------------------------------------------------\n");
//
//
//			for(i=0;i<x;i++){				
//				if(i==j || i==j+1){
//					color(FOREGROUND_GREEN);
//				}else{
//					color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//				}
//
//				printf(" [%02d] %2d | ",i,data[i]);
//				for(k=0;k<data[i];k++){printf("■");}
//				printf("\n");		
//				Sleep(10);
//			}
//			//Sleep(100);
//		}
//
//	}
//}


void main(void){
	int data[ARRAY_SIZE];
	init (data,ARRAY_SIZE);
	sort(data,ARRAY_SIZE);


}


void init(int x[],int y){		
	//ランダムで１～３０の数字を生成し、２０個の配列に入れる。
	srand((unsigned)time(NULL));
	for(i=0; i < y; i++){
		x[i]=rand()%wdth+1;
	}
}

void sort(int bl[],int x){
	int tmp;//一時
	int cmp=0,swp=0;//比較、交換	

	showHeader(cmp, swp);
	showGraph(bl,ARRAY_SIZE,gfl);



	///////////////////////////////////
	for(l=0;l<x;l++){
		for(j=0;j<x-1-l;j++){
			cmp++;//比較＋１
			if(bl[j]>bl[j+1]){
				swp++;//交換＋１
				tmp =bl[j];
				bl[j]=bl[j+1];
				bl[j+1]=tmp;
			}
			for(i=0;i<x;i++){				
				if(i==j || i==j+1){
					color(FOREGROUND_GREEN);
				}else{
					color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				}
			}
		}
	}
	///////////////////////////////////////////////



}



void showHeader(int x  ,int y){
	printf(" [%d] data | compare = %d swap = %d\n",hdl,x,y);
	printf(" -------------------------------------------------------------------------\n");
	
}

void showGraph(int x[],int y,int z){

	for(i=0;i<y;i++){
		printf(" [%02d] %2d | ",i,x[i]);
		for(k=0;k<x[i];k++){
			printf("■");
		}
		printf("\n");			
	}





}
















