#include<stdio.h>

void main(){
	
	FILE *fp=fopen("E:/kamada/DATA/1.txt","r");
	char buf[512];
	

	while(fgets(buf,512,fp)!=NULL){	
		printf("%s",buf);	
	}


	fclose(fp);	

}