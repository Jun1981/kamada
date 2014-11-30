#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include "console.h"

#define TekiKazu 300



//構造体定義





typedef struct {
	

	int x[TekiKazu];
	int y[TekiKazu];
	int s[TekiKazu];//合計用
}Position;
	

//プロトタイプ関数宣言

void init(Position*,int);
void sort(Position*,int,int);
void hyouji(Position*,int,int);
void zentai_hyouji(Position* ,int);



void main(void){
	int start,end;//時間計測用
	
	Position P={0};//構造体宣言

	init(&P,TekiKazu);//座標データ初期化

	

	zentai_hyouji(&P,TekiKazu); Sleep(2000);//全体表示して２秒まつ
		

	
	start=clock();
		sort(&P,0,TekiKazu-1);//ソート関数
	end=clock();

	zentai_hyouji(&P,TekiKazu);	Sleep(3000);//最後の確認表示

	color(FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE);//白
	printf("\nソートにかかった時間は%.3f秒です。\n",(end-start)*1.0/CLOCKS_PER_SEC);

}



void init(Position *a,int x){

	int i;//ループ用
	srand((unsigned)time(NULL));
	

	for(i=0;i<TekiKazu;i++){
		a->x[i]=rand()%60;   a->y[i]=rand()%21;//X座標とY座標にランダムで数字を入れる。
		a->s[i]= a->y[i]*100+ a->x[i]; //S=Y*10+X
	}


}

void hyouji(Position *a,int p,int q){

	int i=0;//ループ用

	setCursor(0);//カーソルを表示しない
	clear();//画面消去

	//color(FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE);//白
	//for(i=0;i<TekiKazu;i++){
	//
	//	locate(a->x[i],a->y[i]);
	//	printf("*");
	//}

	color(FOREGROUND_GREEN);//緑
	locate(a->x[p],a->y[p]);printf("*(%d)",p);

	//Sleep(100);

	color(FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE );//白
	locate(a->x[q],a->y[q]);printf("*(%d)",q);
			
			
	//for (l=0;l<TekiKazu;l++){
	//printf("%d,%d\n",a->x[l],a->y[l]);
	//}
	//
	

	//

	
	/////////////////////////////////////////////////////////


	//Sleep(100);

}


void zentai_hyouji(Position* a,int p){

	int i;//ループ用
	int c=0;//色切り替え
		
	for(i=0;i<p;i++){
	
		if(i%2==0)
			color(FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE);//白
		else
			color(FOREGROUND_GREEN );//緑

		locate(a->x[i],a->y[i]);
		printf("%d",i);
	}



}

int med3(int x, int y, int z)
/* x, y, z の中間値を返す */
{
    if (x < y)
        if (y < z) return y; else if (z < x) return x; else return z; else
        if (z < y) return y; else if (x < z) return x; else return z;
}


void sort(Position *a, int left, int right){


	static int tmp[3];
	/* クイックソート(２次元座標）
	まずY座標を小さい順に上から並び替え、Y座標が同じ時はｘ座標が小さい方を上にする。

	* a.x     : ソートする配列（ｘ）
	* a.y　　　: ソートする配列（ｙ）
	* left  : ソートするデータの開始位置
	* right : ソートするデータの終了位置
	*/
	
	if (left < right) {		


		int i = left, j = right;
		int pivot = med3(a->s[i], a->s[i + (j - i) / 2], a->s[j]); /* (i+j)/2ではオーバーフローしてしまう */

		
		while (1) { /* a->s[i] を pivot 以上と以下の集まりに分割する */
			
			while (a->s[i] < pivot) { i++; } /* a->s[i][i] >= pivot となる位置を検索 */
			while (pivot < a->s[j]) { j--; } /* a->s[i][j] <= pivot となる位置を検索 */



			if (i >= j)  { break; }

			//if (  a->s[i] == a->s[j]==pivot ){
			//	tmp[1] = a->x[i]; a->x[i] = a->x[j]; a->x[j] = tmp[1]; /* a[i],a[j] を交換 */
			//	i++; j--;
			//	break;
			//}//y座標が等しくてｘ座標が右のほうが大きい時は入れ替えない 

			hyouji(a,i,j);//表示関数
			tmp[0] = a->s[i]; a->s[i] = a->s[j]; a->s[j] = tmp[0]; /* a->s[i][i],a->s[i][j] を交換 */
			tmp[1] = a->y[i]; a->y[i] = a->y[j]; a->y[j] = tmp[1]; /* a[i],a[j] を交換 */
			tmp[2] = a->x[i]; a->x[i] = a->x[j]; a->x[j] = tmp[2]; /* a[i],a[j] を交換 */
			
			hyouji(a,i,j);//表示関数


			i++; j--;
		}
		sort(a, left, i - 1); /* 分割した右を再帰的にソート */
		sort(a, j + 1, right); /* 分割した右を再帰的にソート */
		


	}
	

}