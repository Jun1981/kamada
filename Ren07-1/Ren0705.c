#include <stdio.h>
#include<string.h>
#pragma warning(disable: 4996)
void main(){
	int i=0,j;//ループ用
	int w_cnt=0,c_cnt=0,l_cnt=0;


	FILE*    fp=fopen("../DATA/1.txt","r");
	char buf[512];//５１２は、一度に読み込まれる最大バイト数＋１


	while( fgets(buf,512,fp)!=NULL){
		printf("%s",buf);

	}


	fclose(fp);//使い終わったら必ずcloseする。

}