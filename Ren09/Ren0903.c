#include <stdio.h>
#include <time.h>
#include"console.h"

#define elm 20//�v�f��
#define wdth 30 //�O���t�̈�̕��i�S�p�������j
#define hdl  0//�w�b�_�����̍s�ԍ�
#define grl  2//�O���t�����̈�ԏ�̍s�ԍ�


void main(void){
	int i,j,k,l;//���[�v
	int BN[elm];//�u���b�N�̐�������
	int tmp;//�ꎞ

	int cmp=0,swp=0;//��r�A����

	//�����_���łP�`�R�O�̐����𐶐����A�Q�O�̔z��ɓ����B
	srand((unsigned)time(NULL));
	for(i=0; i < elm; i++){
		BN[i]=rand()%wdth+1;
	}

	//�����\��//////////////////////////////////////////////////////////////////////////
	printf(" [##] data | compare = %d swap = %d\n",cmp,swp);
	printf(" -------------------------------------------------------------------------\n");
	for(i=0;i<elm;i++){
		printf(" [%02d] %2d | ",i,BN[i]);
		for(k=0;k<BN[i];k++){
			printf("��");
		}
		printf("\n");			
	}
	/////////////////////////////////////////////////////////////////////////////////////


	for(l=0;l<elm;l++){
		for(j=0;j<elm-1-l;j++){

			cmp++;//��r�{�P
			if(BN[j]>BN[j+1]){

				swp++;//�����{�P

				tmp =BN[j];
				BN[j]=BN[j+1];
				BN[j+1]=tmp;
			}

			clear();
			printf(" [##] data | compare = %d swap = %d\n",cmp,swp);
			printf(" -------------------------------------------------------------------------\n");


			for(i=0;i<elm;i++){				
				if(i==j || i==j+1){
					color(FOREGROUND_GREEN);
				}else{
					color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				}

				printf(" [%02d] %2d | ",i,BN[i]);
				for(k=0;k<BN[i];k++){printf("��");}
				printf("\n");		
				Sleep(10);
			}
			//Sleep(100);
		}

	}
}





















