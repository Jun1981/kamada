#include <stdio.h>
#pragma warning(disable: 4996)
void main(){
	int i=0;//���[�v�p

	FILE*    fp=fopen("../DATA/TEST.txt","r");
	char buf[512];//�T�P�Q�́A��x�ɓǂݍ��܂��ő�o�C�g���{�P

	
	while( fgets(buf,512,fp)!=NULL){
	printf("%d�s�ڂ́A%s",i+1,buf);
	i++;
	}

	fclose(fp);//�g���I�������K��close����B

}