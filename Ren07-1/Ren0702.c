#include <stdio.h>
#pragma warning(disable: 4996)
void main(){
	int i;//���[�v�p

	FILE*    fp=fopen("../c/Ren07-1/Ren0702.c","r");
	char buf[512];//�T�P�Q�́A��x�ɓǂݍ��܂��ő�o�C�g���{�P

	for(i=0;i<3;i++){
	fgets(buf,512,fp);//��s�ǂݍ���
	printf("%d�s�ڂ́A%s",i+1,buf);
	}

	fclose(fp);//�g���I�������K��close����B

}