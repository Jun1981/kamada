#include <stdio.h>
#pragma warning(disable: 4996)
void main(){
	int i=0;//ループ用

	FILE*    fp=fopen("../DATA/TEST.txt","r");
	char buf[512];//５１２は、一度に読み込まれる最大バイト数＋１

	
	while( fgets(buf,512,fp)!=NULL){
	printf("%d行目は、%s",i+1,buf);
	i++;
	}

	fclose(fp);//使い終わったら必ずcloseする。

}