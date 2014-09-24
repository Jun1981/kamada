#include <stdio.h>
void main(){


	FILE*    fp=fopen("../c/Ren07-1/Ren0701.c","r");
	char buf[512];//５１２は、一度に読み込まれる最大バイト数＋１
	fgets(buf,512,fp);//一行読み込み
	printf("1行目は、%s",buf);

	fclose(fp);//使い終わったら必ずcloseする。

}