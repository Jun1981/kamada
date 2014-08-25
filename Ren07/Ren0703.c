#include <stdio.h>
void main(){
	int i=0;

	FILE* fp=fopen("E:/kamada/c/Ren07/Ren0703.c","r");
	char buf[512];

	while(fgets(buf,512,fp)!=NULL){		
		printf("%dçsñ⁄ÇÕÅA%s",i+1,buf);	
		i++;
	}	
	fclose(fp);	
}