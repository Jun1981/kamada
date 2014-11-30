#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include "console.h"
#pragma warning(disable:4996)

#define TekiKazu 300



//構造体定義
typedef struct {
	int x;
	int y;
	int s;//合計用
}Position;


//プロトタイプ関数宣言

void init(Position*);
void sort(Position*, int, int);
void hyouji(Position*, int, int);
void zentai_hyouji(Position*);

//入力された検索データをPosition構造体に入れて返す
Position input(void);//検索関数

//指定されたデータを検索して、配列番号を返す。存在しない時は、－１を返す
int search(Position *   , Position*, int);



void main(void){
	int start, end;//時間計測用
	
	int m;//検索したデータが何番にあるか
	

	Position P[TekiKazu] = { 0 };//構造体宣言

	Position input_data;//入力した値を入れる
	


	init(P);//座標データ初期化

	zentai_hyouji(P); Sleep(2000);//全体表示して２秒まつ

	start = clock();
	sort(P, 0, TekiKazu - 1);//ソート関数
	end = clock();

	zentai_hyouji(P);	Sleep(3000);//最後の確認表示

	color(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);//白
	printf("\nソートにかかった時間は%.3f秒です。\n", (end - start)*1.0 / CLOCKS_PER_SEC);

	

	//入力して検索
	clear();
	input_data = input();//入力した値を構造体に入れる
	m = search(&input_data, P, TekiKazu);
	printf("検索した座標は%d番目にあります。\n", m);
	Sleep(10000);





}



void init(Position *a){

	int i;//ループ用
	srand((unsigned)time(NULL));

	for (i = 0; i<TekiKazu; i++){
		(a + i)->x = rand() % 60;   (a + i)->y = rand() % 21;//X座標とY座標にランダムで数字を入れる。
		(a + i)->s = (a + i)->y * 100 + (a + i)->x; //S=Y*10+X
	}

}

Position input(void){
	Position in = { 0 };//入力した値を入れる
	printf("検索したいデータのｘ座標を入力してください。\n");
	scanf("%d",&in.x);
	printf("検索したいデータのｙ座標を入力してください。\n");
	scanf("%d",&in.y);


	return in;//構造体を返す




}

int search(Position *I , Position *D, int n){

	int i = 0;
	for (i = 0; i < n; i++){
		if (I->x == (D + i)->x){
			if (I->y == (D + i)->y){

				return i;//一致する座標を返す

				break;



			}


		}


	}
	return -1;//一致しない
}

void hyouji(Position *a, int p, int q){

	setCursor(0);//カーソルを表示しない

	color(FOREGROUND_GREEN);//緑
	locate((a + p)->x, (a + p)->y); printf("*(%d)", p);

	color(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);//白
	locate((a + q)->x, (a + q)->y); printf("*(%d)", q);

	clear();//画面消去

}


void zentai_hyouji(Position* a){

	int i;//ループ用
	int c = 0;//色切り替え

	for (i = 0; i<TekiKazu; i++){

		if (i % 2 == 0)
			color(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);//白
		else
			color(FOREGROUND_GREEN);//緑

		locate((a + i)->x, (a + i)->y);
		printf("%d", i);
	}
}

int med3(int x, int y, int z){/* x, y, z の中間値を返す */
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
		int pivot = med3((a + i)->s, (a + (i + (j - i) / 2))->s, (a + j)->s); /* (i+j)/2ではオーバーフローしてしまう */


		while (1) { /* (a+i)->s を pivot 以上と以下の集まりに分割する */

			while ((a + i)->s < pivot) { i++; } /* (a+i)->s[i] >= pivot となる位置を検索 */
			while (pivot < (a + j)->s) { j--; } /* (a+i)->s[j] <= pivot となる位置を検索 */

			if (i >= j)  { break; }

			hyouji(a, i, j);//表示関数
			tmp[0] = (a + i)->s; (a + i)->s = (a + j)->s; (a + j)->s = tmp[0]; /* (a+i)->s[i],(a+i)->s[j] を交換 */
			tmp[1] = (a + i)->y; (a + i)->y = (a + j)->y; (a + j)->y = tmp[1]; /* a[i],a[j] を交換 */
			tmp[2] = (a + i)->x; (a + i)->x = (a + j)->x; (a + j)->x = tmp[2]; /* a[i],a[j] を交換 */

			hyouji(a, i, j);//表示関数

			i++; j--;
		}
		sort(a, left, i - 1); /* 分割した左を再帰的にソート */
		sort(a, j + 1, right); /* 分割した右を再帰的にソート */

	}

}