#include <stdio.h>
#include<string.h>
#pragma warning(disable: 4996)
void main(){
	int i=0,j;//���[�v�p
	int w_cnt=0,c_cnt=0,l_cnt=0;


	FILE*    fp=fopen("../DATA/1.txt","r");
	char buf[512];//�T�P�Q�́A��x�ɓǂݍ��܂��ő�o�C�g���{�P


	while( fgets(buf,512,fp)!=NULL){
		printf("%s",buf);

	}


	fclose(fp);//�g���I�������K��close����B

}