#include <stdio.h>
#include<string.h>
#pragma warning(disable: 4996)

void main(){
	int i=0,j;//���[�v�p
	FILE*    fp=fopen("../DATA/2.txt","r");
	char buf[3][512];//�T�P�Q�́A��x�ɓǂݍ��܂��ő�o�C�g���{�P

	for(i=0;i<2;i++){
		fgets(buf[i],512,fp);		
	}

	while( fgets(buf[2],512,fp)!=NULL ){	
		printf("%s",buf[0]);

		for(i=0;i<2;i++){
			strcpy(buf[i],buf[i+1]);
		}
	}	
	fclose(fp);//�g���I�������K��close����B
}