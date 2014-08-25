#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include<console.h>


#pragma warning(disable:4996)

//変数宣言
int i, j;//ループ用

int w_cnt[23] = { 0 }, b_cnt[23] = { 0 };//■と□の数
int w_cnt_tmp[23] = { 0 }, b_cnt_tmp[23] = { 0 };//の保存用

int iti[25][23];//位置
int iti_tmp[25][23];//位置フラグ一時保管用

int b_type[25][23]; //積み上がったブロックのタイプ
int b_type_tmp[25][23];//ブロックタイプ一時保存用

int w_cnt[23], b_cnt[23];
int w_cnt_tmp[23], b_cnt_tmp[23];

int dbg_cnt=10000;//デバック用カウンタ



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
	int line[23];//一列チェック用
	
	int d_type;//白黒識別用

	
}sq;

//////////////////////////////////////////


//プロトタイプ関数宣言
void init(void);//変数などの初期化
void yokosen(void);//下に線を
void d_hyouji(void);//落下表示関数
void b_hyouji(int i,int j);//積みブロック表示関数

void kesu(void);//消去関数
void rakka(void);//移動関数

void S_chk(void);//下にブロックがいるかチェック
void line_chk(void);//一列ならんだかどうかチェック
void key_chk(void);//キーチェック
void type_chk(void);//白黒チェック関数

void debug(void);

void counter(void);//カウンタ

void main(){
	init();//初期化
	yokosen();//横線を引く

	//ゲームループ
	while (1){
		
		//debug();

		d_hyouji();//表示		
		key_chk();//キーチェック			
		rakka();//移動
		//line_chk();//一列並んでるかどうかチェック
		counter();//カウンタ		
	}
}

void init(){
	srand((unsigned)time(NULL));//時間からランダム
	type_chk();//最初の□のタイプをランダムで決定
	//sq.type = 0;//デフォ黒四角
	sq.x_S = 12;//初期ｘ座標
	sq.y_S = 0;	//初期ｙ座標
	sq.x = sq.x_S;
	sq.y = sq.y_S;
	sq.sd_S = 500;//落下スピード初期値
	sq.sd = sq.sd_S;//落下スピード初期値代入

	sq.sw_S = 1000;//スピード横初期値
	sq.sw = sq.sw_S;//スピード初期値代入

	setCursor(0);//カーソルを表示しない

	for (i = 0; i < 25; i += 2){
		for (j = 0; j < 23; j++){
			iti[i][j] = 0;
			sq.line[j] = 0;
			b_type[i][j] = 0;//全部■

		}
	}

	for (i = 0; i < 23; i++){
		w_cnt[i] = b_cnt[i] = 0;
	}



}

void yokosen(){
	locate(0, 23);//２２行目に横線を引く
	for (i = 0; i<80; i++){
		printf("~");
	}
	for (i = 23; i < 25; i++){
		locate(25, i);
		puts("|");
	}
}


void d_hyouji(){
	locate(sq.x, sq.y);//四角を画面上方に表示
	if (sq.d_type == 0){
		puts("■\n");
	}
	else{
		puts("□");
	}	
}

void b_hyouji(int i,int j){

	locate(i, j + 1);//場所

	if (b_type[i][j + 1] == 0){
		puts("■\n");
	}
	else{
		puts("□");
	}

}


//下にブロックがあるかチェック


void rakka(){
	if (sq.sd <= 0){
		if (iti[sq.x][sq.y + 1] == 0 && sq.y < 22){
			locate(sq.x, sq.y);//四角を画面上方に表示
			puts("　");//空白を挿入
			sq.y++;//四角を下に落とす
		
			d_hyouji();//再び■表示
		}
		else if (iti[sq.x][sq.y + 1] == 1 || sq.y == 22){
			
			iti[sq.x][sq.y] = 1;//位置フラグオン	

			b_type[sq.x][sq.y] = sq.d_type;//積むとき白黒を決める

			//ブロックのタイプごとにカウント
			if (b_type[sq.x][sq.y] == 0){
				w_cnt[sq.y]++;//■＋＋
			}
			else if (b_type[sq.x][sq.y] == 1){
				b_cnt[sq.y]++;//□＋＋
			}
			
			d_hyouji();//積み上がった地点で表示しておく
			line_chk();//一列チェック
			sq.x = sq.x_S; sq.y = sq.y_S;//座標初期化
			type_chk();//次の白黒を決める

		}
		sq.sd = sq.sd_S;//カウンタ初期化
	}
}







void key_chk(){
	if (sq.sw <= 0){
		//左移動
		if (GetKeyState(VK_NUMPAD4) < 0 || GetKeyState(VK_LEFT) < 0 && sq.x >= 2){

			if (iti[sq.x - 2][sq.y] == 0){
				sq.sw = sq.sw_S;
				locate(sq.x, sq.y);//四角を消す			
				printf("　");
				sq.x -= 2;//左へ
				//locate(sq.x, sq.y);//四角を画面上方に表示
				//printf("■\n");
				d_hyouji();
			}

		}
		//右移動
		if (GetKeyState(VK_NUMPAD6) < 0 || GetKeyState(VK_RIGHT) < 0 && sq.x <= 23) {

			if (iti[sq.x + 2][sq.y] == 0){
				sq.sw = sq.sw_S;

				locate(sq.x, sq.y);//四角を消す

				printf("　");
				sq.x += 2;

				//locate(sq.x, sq.y);//四角を画面上方に表示
				//printf("■\n");
				d_hyouji();
			}

		}
		if (GetKeyState(0x58) < 0){//ｘが押されたら終了

			puts("終了\n");
			exit(0);//終了


		}
	}

}

void line_chk(){
	for (i = 0; i < 25; i += 2){
		if (iti[i][sq.y] == 0){
			break;
		}
	}
	//if (i == 26){
	if (w_cnt[sq.y] == 13 || b_cnt[sq.y] == 13){
		sq.line[sq.y] = 1;//一列並んでいる	

		//一列消す
		for (i = 0; i < 25; i += 2){
			locate(i, sq.y);
			puts("　");//一列空白
			iti[i][sq.y] = 0;
			w_cnt[sq.y] = 0;
			b_cnt[sq.y] = 0;//ブロックカウント０
			
			//上のブロックの種類を調べて一段ずらす			
			for (j = 0; j < sq.y; j++){
				if (iti[i][j] == 1){
					iti_tmp[i][j] = 1;//一時的に位置フラグたてる
					iti[i][j] = 0;//本フラグオフ

					b_type_tmp[i][j] = b_type[i][j];//一時的にタイプを入れる
					b_type[i][j] = -1;
					locate(i, j);//場所
					puts("　");//消す						
				}
			}
		}
		//}
		//それぞれの属性を一個ずらす
		for (i = 0; i < 25; i += 2){
			for (j = 0; j < sq.y; j++){

				if (b_type_tmp[i][j] == 1){

					b_type[i][j + 1] = b_type_tmp[i][j];
					b_type_tmp[i][j] = -1;
				}

				if (iti_tmp[i][j] == 1){
					iti[i][j + 1] = 1;
					b_type[i][j + 1] = b_type_tmp[i][j];
					b_hyouji(i, j);//ブロック表示関数
					iti_tmp[i][j] = -1;
				}
			}

		}

		//ブロックカウントを一段ずらす
		for (i = 0; i < sq.y; i++){

			w_cnt_tmp[i + 1] = w_cnt[i];
			w_cnt[i] = 0;

			b_cnt_tmp[i + 1] = b_cnt[i];
			b_cnt[i] = 0;
		}

		for (i = 0; i < sq.y+1; i++){
			w_cnt[i] = w_cnt_tmp[i];
			b_cnt[i] = b_cnt_tmp[i];
		}
		////////////////////////////////////




		//一時フラグに全部0を入れる
		for (i = 0; i < 25; i += 2){
			for (j = 0; j < 23; j++){
				iti_tmp[i][j] = 0;
			}
		}


	}
}

void type_chk(){
	if (rand() % 2 == 0)
		sq.d_type = 0;//白
	else
		sq.d_type = 1;//白（中抜き）
}



void debug(){
	if (dbg_cnt <= 0){
		dbg_cnt = 10000;
		
		for (i = 0; i < 23; i++){
			locate(60, i);			
			printf("白%d,黒%d",w_cnt[i], b_cnt[i]);
		}
	}

}



void counter(){
	sq.sd--;//スピードカウンタマイナス	
	sq.sw--;//横スピードカウンタマイナス

	dbg_cnt--;

}

