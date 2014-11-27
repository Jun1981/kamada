#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"




#pragma warning(disable:4996)

typedef int value_type; /* ソートするキーの型 */

int s = 0;//スタート時一回

int tmp[3];//スワップ用

clock_t start, end;

int i;



 struct h{
	int x[10];
	int y[10];
	int s[10];//合計用


} kazu = { 
	{3,1,1,2,0,1,2,8,0,6},
	{4,2,3,4,1,4,4,3,6,8}
};




//プロトタイプ関数宣言

value_type med3(value_type , value_type, value_type);
void quicksort(struct h* , int , int );


void main(void){

	
	int i=0;//ループ
	srand((unsigned)time(NULL));
	for (i = 0; i < 10; i++){
		kazu.x[i] = rand() % 10 + 1;
		kazu.y[i] = rand() % 10 + 1;
	}
	
	
	
	start = clock();
	
	//最初の表示
	for (i = 0; i < 10; i++)	printf("%d,%d\n", kazu.x[i], kazu.y[i]);
	printf("\n");
	/////////////////////////////////////////////////////////
		
	
	

	//並べ替え
	quicksort(&kazu, 0, 10 - 1); 
	for (i = 0; i < 10; i++)	printf("%d,%d\n", kazu.x[i],kazu.y[i]);

	
	
	end = clock();
	printf("%0.5f秒かかりました\n", (double)(end - start)/CLOCKS_PER_SEC);
	
	printf("\n");
	
	

}




//＊状況に応じて型を変更する
//typedef int value_type; /* ソートするキーの型 */

value_type med3(value_type x, value_type y, value_type z)
/* x, y, z の中間値を返す */
{
	if (x < y)
		if (y < z) return y; else if (z < x) return x; else return z; else
			if (z < y) return y; else if (x < z) return x; else return z;
}



void quicksort(struct h *a, int left, int right){
	/* クイックソート(２次元座標）
	まずY座標を小さい順に上から並び替え、Y座標が同じ時はｘ座標が小さい方を上にする。

	* a.x     : ソートする配列（ｘ）
	* a.y　　　: ソートする配列（ｙ）
	*a.z   :Y*10＋X　を入れる
	* left  : ソートするデータの開始位置
	* right : ソートするデータの終了位置
	*/
	
	
	


	if (left < right) {

		
		
		if (s == 0){
			int youso = right - left + 1;//要素数
			//int *niji_sort;
			int l;//ループ用

			//niji_sort = (int*)malloc(sizeof(int)*youso);//二次配列のY＊１０＋ｘの値を入れる
			for (l = 0; l < youso; l++){
				a->s[l] = a->y[l] * 10 + a->x[l];
			}
			s = 1;
		}



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

			tmp[0] = a->s[i]; a->s[i] = a->s[j]; a->s[j] = tmp[0]; /* a->s[i][i],a->s[i][j] を交換 */
			tmp[1] = a->y[i]; a->y[i] = a->y[j]; a->y[j] = tmp[1]; /* a[i],a[j] を交換 */
			tmp[2] = a->x[i]; a->x[i] = a->x[j]; a->x[j] = tmp[2]; /* a[i],a[j] を交換 */

			i++; j--;
		}
		quicksort(a, left, i - 1); /* 分割した右を再帰的にソート */
		quicksort(a, j + 1, right); /* 分割した右を再帰的にソート */
		//quicksort(a, left, i - 1);  /* 分割した左を再帰的にソート */
		//quicksort(a, j + 1, right); /* 分割した右を再帰的にソート */



	}
	

}