#include <stdio.h>
#include<string.h>
#pragma warning(disable: 4996)
void main(){
	int i=0,j;//ループ用

	int w_cnt=0,c_cnt=0,l_cnt=0;


	FILE*    fp=fopen("../DATA/TEST.txt","r");
	char buf[512];//５１２は、一度に読み込まれる最大バイト数＋１


	while( fgets(buf,512,fp)!=NULL){
		printf("%d行目は、%s",i+1,buf);


		for(j=0;j<512;j++){

			if(buf[j]==' '|| buf[j]=='\t'|| buf[j]=='.'||buf[j]==','||buf[j]=='\n'){
				w_cnt++;//単語数＋


			}

		}

		c_cnt+=strlen(buf);//改行文字も含まれる
		l_cnt++;//行数＋


		i++;
	}

	printf("\n文字数は%dです。\n",c_cnt);
	printf("単語数は%dです。\n",w_cnt);
	printf("行数は%dです。\n",l_cnt);


	fclose(fp);//使い終わったら必ずcloseする。

}