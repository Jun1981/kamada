#include <stdio.h>
#include<string.h>
#pragma warning(disable: 4996)

void main(){
	int i,j;//���[�v�p
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
	//buf[0]��buf[1]��','��'\0'�ɕϊ�
	for(i=0;i<2;i++){
		for(j=0;j<512;j++){
			if(buf[i][j]==','){		
				buf[i][j]='\0';
			}
		}
	}
	printf("%s %s\n",buf[0],buf[1]);//�I��������ׂĕ\��

	fclose(fp);//�g���I�������K��close����B
}