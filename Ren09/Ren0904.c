#include <stdio.h>
#include <time.h>
#include"console.h"

#define ARRAY_SIZE 20//�v�f��
#define wdth 30 //�O���t�̈�̕��i�S�p�������j
#define hdl  20//�w�b�_�����̍s�ԍ�
#define gfl  0//�O���t�����̈�ԏ�̍s�ԍ�


//�v���g�^�C�v�֐�

void init (int[],int);
void sort (int[],int);
void showHeader(int ,int);
void showGraph(int[],int,int);


int i=0,j=0,k=0,l=0;//���[�v�p

//void main(void){
//	int i,j,k,l;//���[�v
//	int data[x];//�u���b�N�̐�������
//	int tmp;//�ꎞ
//
//	int cmp=0,swp=0;//��r�A����
//
//	
//
//	//�����\��//////////////////////////////////////////////////////////////////////////
//	printf(" [%d] data | compare = %d swap = %d\n",hdl,cmp,swp);
//	printf(" -------------------------------------------------------------------------\n");
//	for(i=0;i<x;i++){
//		printf(" [%02d] %2d | ",i,data[i]);
//		for(k=0;k<data[i];k++){
//			printf("��");
//		}
//		printf("\n");			
//	}
//	/////////////////////////////////////////////////////////////////////////////////////
//
//
//	for(l=0;l<x;l++){
//		for(j=0;j<x-1-l;j++){
//
//			cmp++;//��r�{�P
//			if(data[j]>data[j+1]){
//
//				swp++;//�����{�P
//
//				tmp =data[j];
//				data[j]=data[j+1];
//				data[j+1]=tmp;
//			}
//
//			clear();
//			printf(" [%d] data | compare = %d swap = %d\n",hdl,cmp,swp);
//			printf(" -------------------------------------------------------------------------\n");
//
//
//			for(i=0;i<x;i++){				
//				if(i==j || i==j+1){
//					color(FOREGROUND_GREEN);
//				}else{
//					color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//				}
//
//				printf(" [%02d] %2d | ",i,data[i]);
//				for(k=0;k<data[i];k++){printf("��");}
//				printf("\n");		
//				Sleep(10);
//			}
//			//Sleep(100);
//		}
//
//	}
//}


void main(void){
	int data[ARRAY_SIZE];
	init (data,ARRAY_SIZE);
	sort(data,ARRAY_SIZE);


}


void init(int x[],int y){		
	//�����_���łP�`�R�O�̐����𐶐����A�Q�O�̔z��ɓ����B
	srand((unsigned)time(NULL));
	for(i=0; i < y; i++){
		x[i]=rand()%wdth+1;
	}
}

void sort(int bl[],int x){
	int tmp;//�ꎞ
	int cmp=0,swp=0;//��r�A����	

	showHeader(cmp, swp);
	showGraph(bl,ARRAY_SIZE,gfl);



	///////////////////////////////////
	for(l=0;l<x;l++){
		for(j=0;j<x-1-l;j++){
			cmp++;//��r�{�P
			if(bl[j]>bl[j+1]){
				swp++;//�����{�P
				tmp =bl[j];
				bl[j]=bl[j+1];
				bl[j+1]=tmp;
			}
			for(i=0;i<x;i++){				
				if(i==j || i==j+1){
					color(FOREGROUND_GREEN);
				}else{
					color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				}
			}
		}
	}
	///////////////////////////////////////////////



}



void showHeader(int x  ,int y){
	printf(" [%d] data | compare = %d swap = %d\n",hdl,x,y);
	printf(" -------------------------------------------------------------------------\n");
	
}

void showGraph(int x[],int y,int z){

	for(i=0;i<y;i++){
		printf(" [%02d] %2d | ",i,x[i]);
		for(k=0;k<x[i];k++){
			printf("��");
		}
		printf("\n");			
	}





}
















