#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#pragma warning(disable:4996)


int input(int,int);//一桁の数字入力待ち
int y;//入力した数字を入れる変数

char next[2];//次の数字

void main(){



	int i,j;//ループ
	char buf[10][512];
	char buf_tmp[10][512];

	char next[2];//次の数字



	//ファイルオープン
	FILE *fp=fopen("E:/kamada/DATA/1.txt","r");
	while(1){

		if(y==1){

		
		}
		for(i=0;i<2;i++){
			fgets(buf[i],512,fp);
		}
		while(fgets(buf[2],512,fp)!=NULL){
			printf("%s",buf[0]);
			for(i=0;i<2;i++){			
				strcpy(buf[i],buf[i+1]);
			}
		}

		//文字列のコンマまでの文字列を一時変数に入れる
		for(j=0;j<2;j++){
			for(i=0;i<512;i++){

				if(buf[j][i]==','){
					strncpy(buf_tmp[j],buf[j],i);
					buf_tmp[j][i]='\0';
					next[j]=buf[j][i+1];
				}

			}
			printf("%s",buf_tmp[j]);


		}

		printf("\n\n");



		printf("数字を入力してください。\n:");
		y=input(1,2);


		while(1){
			if(y>=10){
				printf("1か２を入力してください。\n:");
				y=input(0,9);
			}else if(y>=0 && y<=9){
				break;
			}
		}


		if(y==1){ 
			FILE *fp=fopen("E:/kamada/DATA/2.txt","r");

		}
		if(y==2){
			FILE *fp=fopen("E:/kamada/DATA/3.txt","r");


		}



		fclose(fp);
	}
}



//ある範囲(最小０、最大９）の一桁の整数が入力されたときはその値を返す。
//それ以外の数字や文字列が入力されたときは１０を返す

//int yomi(int x1, int x2);

int input(int x1, int x2)
{
	char a[20];
	int b;

	scanf("%s",&a);
	b = strlen(a);

	if (b == 1)
	{

		b = atoi(a);
		if (b >= x1 && b <= x2)
		{
			return (b);
		}

	}

	return 10;

}