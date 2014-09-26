#include <stdio.h>
#include<string.h>
#pragma warning(disable: 4996)

void main(){
	int i=0,j;//ループ用
	FILE*    fp=fopen("../DATA/2.txt","r");
	char buf[3][512];//５１２は、一度に読み込まれる最大バイト数＋１

	for(i=0;i<2;i++){
		fgets(buf[i],512,fp);		
	}

	while( fgets(buf[2],512,fp)!=NULL ){	
		printf("%s",buf[0]);

		for(i=0;i<2;i++){
			strcpy(buf[i],buf[i+1]);
		}
	}	
	fclose(fp);//使い終わったら必ずcloseする。
}