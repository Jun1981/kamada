#include<stdio.h>
#include<string.h>

void main(){

	FILE *fp=fopen("E:/kamada/DATA/2.txt","r");

	int i;//ÉãÅ[Év
	char buf[10][512];

	for(i=0;i<2;i++){
		fgets(buf[i],512,fp);
	}
	while(fgets(buf[2],512,fp)!=NULL){
		printf("%s",buf[0]);
		for(i=0;i<2;i++){			
			strcpy(buf[i],buf[i+1]);
		}
	}

	fclose(fp);
}