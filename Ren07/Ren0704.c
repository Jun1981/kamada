#include <stdio.h>
#include <string.h>

void main(){
	unsigned int i=0,j=0;
	int len=0;//������������
	int w_cnt=0;//�P�ꐔ


	FILE* fp=fopen("E:/kamada/text/Test.txt","r");
	char buf[512];

	while(fgets(buf,512,fp)!=NULL){

		printf("%d�s�ڂ́A%s",i+1,buf);	
		len=len+strlen(buf);	

		for(j=0;j<strlen(buf);j++){
			if(buf[j]==' ' || buf[j]==',' || buf[j]=='\t' || buf[j]=='.'||buf[j]=='\n'){
				w_cnt++;
			}

		}

		i++;

	}
	printf("\n��������%d�ł��B",len);
	printf("\n�P�ꐔ��%d�ł��B",w_cnt);
	printf("\n�s����%d�ł��B",i);

	fclose(fp);	
}





