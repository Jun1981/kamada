#include <stdio.h>
void main(){


	FILE*    fp=fopen("../c/Ren07-1/Ren0701.c","r");
	char buf[512];//�T�P�Q�́A��x�ɓǂݍ��܂��ő�o�C�g���{�P
	fgets(buf,512,fp);//��s�ǂݍ���
	printf("1�s�ڂ́A%s",buf);

	fclose(fp);//�g���I�������K��close����B

}