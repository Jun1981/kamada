#include <stdio.h>
#include<string.h>
#pragma warning(disable: 4996)
void main(){
	int i=0,j;//���[�v�p

	int w_cnt=0,c_cnt=0,l_cnt=0;


	FILE*    fp=fopen("../DATA/TEST.txt","r");
	char buf[512];//�T�P�Q�́A��x�ɓǂݍ��܂��ő�o�C�g���{�P


	while( fgets(buf,512,fp)!=NULL){
		printf("%d�s�ڂ́A%s",i+1,buf);


		for(j=0;j<512;j++){

			if(buf[j]==' '|| buf[j]=='\t'|| buf[j]=='.'||buf[j]==','||buf[j]=='\n'){
				w_cnt++;//�P�ꐔ�{


			}

		}

		c_cnt+=strlen(buf);//���s�������܂܂��
		l_cnt++;//�s���{


		i++;
	}

	printf("\n��������%d�ł��B\n",c_cnt);
	printf("�P�ꐔ��%d�ł��B\n",w_cnt);
	printf("�s����%d�ł��B\n",l_cnt);


	fclose(fp);//�g���I�������K��close����B

}