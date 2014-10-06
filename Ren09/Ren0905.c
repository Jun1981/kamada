#include <stdio.h>
#include <time.h>
#include"console.h"

#define ARRAY_SIZE 20//要素数
#define wdth 30 //グラフ領域の幅（全角文字数）
#define hdl  20//ヘッダ部分の行番号
#define gfl  0//グラフ部分の一番上の行番号

//プロトタイプ関数
void init(int[], int);
void sort(int[], int);
void showHeader(int, int);
void showGraph(int[], int, int);


//////メイン////////////////////////////////////////////////////////////////////////////

void main(void){
	int data[ARRAY_SIZE];
	init(data, ARRAY_SIZE);
	sort(data, ARRAY_SIZE);
}

//////////////////////////////////////////////////////




void init(int x[], int y){

	int i;//ループ用
	//ランダムで１～３０の数字を生成し、２０個の配列に入れる。
	srand((unsigned)time(NULL));
	for (i = 0; i < y; i++){
		x[i] = rand() % wdth + 1;
	}
}

void sort(int bl[], int x){
	int tmp;//一時
	int cmp = 0, swp = 0;//比較、交換	
	int i, j;//ループ用
	//比較///////////////////////////////////
	for (i = 0; i<x; i++){
		for (j = 0; j<x - 1 - i; j++){
			cmp++;//比較＋１			
			clear();
			showHeader(cmp, swp);
			showGraph(bl, ARRAY_SIZE, j);

			if (bl[j]>bl[j + 1]){
				swp++;//交換＋１
				tmp = bl[j];
				bl[j] = bl[j + 1];
				bl[j + 1] = tmp;
			}
			//Sleep(100);
		}
	}
	///////////////////////////////////////////////

}

void showHeader(int x, int y){
	printf(" [%d] data | compare = %d swap = %d\n", hdl, x, y);
	printf(" -------------------------------------------------------------------------\n");

}

void showGraph(int x[], int y, int z){

	int i, j;//ループ用
	for (i = 0; i<y; i++){
		if (i == z || i == z + 1){
			color(FOREGROUND_GREEN);
		}
		else{
			color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		printf(" [%02d] %2d | ", i, x[i]);
		for (j = 0; j<x[i]; j++){
			printf("■");
		}
		printf("\n");
	}
}
















