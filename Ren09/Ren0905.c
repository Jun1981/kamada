#include <stdio.h>
#include <time.h>
#include"console.h"

#define ARRAY_SIZE 20//�v�f��
#define wdth 30 //�O���t�̈�̕��i�S�p�������j
#define hdl  20//�w�b�_�����̍s�ԍ�
#define gfl  0//�O���t�����̈�ԏ�̍s�ԍ�

//�v���g�^�C�v�֐�
void init(int[], int);
void sort(int[], int);
void showHeader(int, int);
void showGraph(int[], int, int);


//////���C��////////////////////////////////////////////////////////////////////////////

void main(void){
	int data[ARRAY_SIZE];
	init(data, ARRAY_SIZE);
	sort(data, ARRAY_SIZE);
}

//////////////////////////////////////////////////////




void init(int x[], int y){

	int i;//���[�v�p
	//�����_���łP�`�R�O�̐����𐶐����A�Q�O�̔z��ɓ����B
	srand((unsigned)time(NULL));
	for (i = 0; i < y; i++){
		x[i] = rand() % wdth + 1;
	}
}

void sort(int bl[], int x){
	int tmp;//�ꎞ
	int cmp = 0, swp = 0;//��r�A����	
	int i, j;//���[�v�p
	//��r///////////////////////////////////
	for (i = 0; i<x; i++){
		for (j = 0; j<x - 1 - i; j++){
			cmp++;//��r�{�P			
			clear();
			showHeader(cmp, swp);
			showGraph(bl, ARRAY_SIZE, j);

			if (bl[j]>bl[j + 1]){
				swp++;//�����{�P
				tmp = bl[j];
				bl[j] = bl[j + 1];
				bl[j + 1] = tmp;
			}
			//Sleep(100);
		}
	}
	///////////////////////////////////////////////

}

void showHeader(int x, int y){
	printf(" [%d] data | compare = %d swap = %d\n", hdl, x, y);
	printf(" -------------------------------------------------------------------------\n");

}

void showGraph(int x[], int y, int z){

	int i, j;//���[�v�p
	for (i = 0; i<y; i++){
		if (i == z || i == z + 1){
			color(FOREGROUND_GREEN);
		}
		else{
			color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		printf(" [%02d] %2d | ", i, x[i]);
		for (j = 0; j<x[i]; j++){
			printf("��");
		}
		printf("\n");
	}
}
















