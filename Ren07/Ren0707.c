#include<stdio.h>
#include<string.h>

#pragma warning(disable:4996)

void main(){

	FILE *fp=fopen("E:/kamada/DATA/2.txt","r");

	int i,j;//ÉãÅ[Év
	char buf[10][512];
	char buf_tmp[10][512];

	for(i=0;i<2;i++){
		fgets(buf[i],512,fp);
	}
	while(fgets(buf[2],512,fp)!=NULL){
		printf("%s",buf[0]);
		for(i=0;i<2;i++){			
			strcpy(buf[i],buf[i+1]);
		}
	}
	for(j=0;j<2;j++){
		for(i=0;i<512;i++){

			if(buf[j][i]==','){

				strncpy(buf_tmp[j],buf[j],i);
				buf_tmp[j][i]='\0';
			}
			
		}
		printf("%s",buf_tmp[j]);
		

	}

	printf("\n");




	fclose(fp);
}