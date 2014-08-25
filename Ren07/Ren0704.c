#include <stdio.h>
#include <string.h>

void main(){
	unsigned int i=0,j=0;
	int len=0;//文字数を入れる
	int w_cnt=0;//単語数


	FILE* fp=fopen("E:/kamada/text/Test.txt","r");
	char buf[512];

	while(fgets(buf,512,fp)!=NULL){

		printf("%d行目は、%s",i+1,buf);	
		len=len+strlen(buf);	

		for(j=0;j<strlen(buf);j++){
			if(buf[j]==' ' || buf[j]==',' || buf[j]=='\t' || buf[j]=='.'||buf[j]=='\n'){
				w_cnt++;
			}

		}

		i++;

	}
	printf("\n文字数は%dです。",len);
	printf("\n単語数は%dです。",w_cnt);
	printf("\n行数は%dです。",i);

	fclose(fp);	
}





