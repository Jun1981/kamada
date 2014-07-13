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
	
	int cd;//落下スピードカウンタ(大きいほど遅い）
	int cw;//横移動カウンタ
	int flag;//フラグ
	int flag_tmp;//
	int shoki_x;//ｘ座標初期値
	int shoki_y;//ｙ座標初期値


};
int cd_shoki=800;//落下■の落ちるスピード/初期値（でかいほど遅い）
int cw_shoki=600;//落下■の横移動スピード/初期値（でかいほど遅い）

int i,j,k;//ループ用


int line[23];//横並び数値


void main ()

{	

	//構造体宣言
	struct shikaku rakka;//落ちてくる■構造体
	struct shikaku tsumi[25][23];//積み上がった■構造体





	//落ちてくる■初期値

	rakka.x=13-1;
	rakka.y=0;
	rakka.cd=cd_shoki;
	rakka.cw=cw_shoki;
	rakka.shoki_x=12;
	rakka.shoki_y=0;
	//rakkaflag=1;//最初の■フラグを立てる


	setCursor(0);//カーソルを表示しない

	//右端に線を引く
	for(i=0;i<25;i++)
	{

		locate(26,i);
		printf("|");
		locate(i,23);
		printf("-");


	}



	while(1)//while2
	{


		for(i=0;i<25;i++)
		{
			for(j=0;j<23;j++)
			{
			}
		}



		//■を落とす///////////////////////////////////////
		locate(rakka.x,rakka.y);//四角を画面上方に表示
		printf("■\n");
		if(rakka.cd==0)
		{
			locate(rakka.x ,rakka.y);//四角を消す
			printf("  \n");
			rakka.y++;//四角を下に落とす
			rakka.cd=cd_shoki;
			//locate(rakka.x,rakka.y);//四角を再び表示
			//printf("■\n");

		}

		//キー入力部分
		if(rakka.cw==0)
		{

			//横移動
			if( (GetKeyState(VK_NUMPAD4)<0 || GetKeyState(VK_LEFT)<0) && rakka.x>=2 && tsumi[rakka.x-2][rakka.y].flag!=1)
			{
				locate(rakka.x,rakka.y);//四角を消す
				printf("  \n");
				rakka.x-=2;
				//locate(rakka.x,rakka.y);//四角を再び表示
				//printf("■\n");
			}
			if( (GetKeyState(VK_NUMPAD6)<0  || GetKeyState(VK_RIGHT)<0 ) && rakka.x+2<=25 && tsumi[rakka.x+2][rakka.y].flag!=1)
			{
				locate(rakka.x,rakka.y);//四角を消す
				printf("  \n");
				rakka.x+=2;
				//locate(rakka.x,rakka.y);//四角を再び表示
				//printf("■\n");
			}

			//終了
			if(GetKeyState(0x58)<0)
			{
				exit(0);
			}
			rakka.cw=cw_shoki;
		}


		//落下■が下に達したら
		if(rakka.y==22)
		{
			tsumi[rakka.x][rakka.y].flag=1;
			locate(rakka.x,rakka.y);//四角を画面上方に表示
			printf("■\n");
			rakka.x=12;
			rakka.y=0;
			/*locate(rakka.x,rakka.y);
			printf("　");*/
			line[22]++;//ライン値＋＋

		}else if(tsumi[rakka.x][rakka.y+1].flag==1)
		{
			tsumi[rakka.x][rakka.y].flag=1;
			locate(rakka.x,rakka.y);//四角を画面上方に表示
			printf("■\n");
			rakka.x=12;
			rakka.y=0;

			line[rakka.y]++;//ライン値＋＋
		}



		if(line[22]==13)//一列そろったら
		{
			line[22]=0;
			locate(0,22);
					printf("　　　　　　　　　　　　　");//消す
			for(j=0;j<22;j++)
			{			
				    locate(0,j);
					printf("　　　　　　　　　　　　　");//消す

				for(k=0;k<25;k++)
				{
					tsumi[k][22].flag_tmp=0;

						

					
					if(tsumi[k][j].flag==1)
					{
						
						tsumi[k][j].flag_tmp=0;
						tsumi[k][j+1].flag_tmp=1;
						line[j+1]++;
					

					}
				}


			}

			for(k=0;k<25;k++)
			{
				for(j=0;j<22;j++)
				{
				tsumi[k][j].flag=0;
				tsumi[k][j].flag=tsumi[k][j].flag_tmp;
				if(tsumi[k][j].flag==1)
				{
					locate(k,j);
					printf("■");
				}
				}
			}
			

		}





		rakka.cd--;//カウンタマイナス
		rakka.cw--;//




	}//while2


}





