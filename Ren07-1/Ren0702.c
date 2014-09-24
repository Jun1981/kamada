#include <stdio.h>
#pragma warning(disable: 4996)
void main(){
	int i;//ループ用

	FILE*    fp=fopen("../c/Ren07-1/Ren0702.c","r");
	char buf[512];//５１２は、一度に読み込まれる最大バイト数＋１

	for(i=0;i<3;i++){
	fgets(buf,512,fp);//一行読み込み
	printf("%d行目は、%s",i+1,buf);
	}

	fclose(fp);//使い終わったら必ずcloseする。

}