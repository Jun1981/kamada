#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<Windows.h>
#include "../../DxLib/DxLib.h"

#define ARRAY_SIZE 20//�v�f��
#define wdth 30 //�O���t�̈�̕��i�S�p�������j
#define hdl  20//�w�b�_�����̍s�ԍ�
#define gfl  0//�O���t�����̈�ԏ�̍s�ԍ�
#define bw   16 //�u���b�N�̕�


//�ϐ��錾
int data[ARRAY_SIZE];//
int FontHandle1;

//�v���g�^�C�v�֐�
void init (int[],int);
void sort (int[],int);
void showHeader(int ,int);
void showGraph(int[],int,int);




int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);                     // �E�C���h�E���[�h�ɕύX(�������A�Q�T�U�F)
	if (DxLib_Init() == -1) {                    // �c�w���C�u��������������
		return -1;                              // �G���[���N�����璼���ɏI��
	}
	
	init (data,ARRAY_SIZE);//������
	sort(data,ARRAY_SIZE);	//���C��
	

	 WaitKey() ;
	DxLib_End();                                // �c�w���C�u�����g�p�̏I������
	return 0;                                  // �A�v���P�[�V�����̏I��
	
}



void init(int x[],int y){		

	FontHandle1 = CreateFontToHandle(NULL, 16, 8,-1);//�Q�[���p�t�H���g�n���h��;//�t�H���g�n���h��1

	int i;//���[�v�p
	//�����_���łP�`�R�O�̐����𐶐����A�Q�O�̔z��ɓ����B
	srand((unsigned)time(NULL));
	for(i=0; i < y; i++){
		x[i]=rand()%wdth+1;
	}
}

void sort(int bl[],int x){
	int tmp;//�ꎞ
	int cmp=0,swp=0;//��r�A����	
	int i, j;//���[�v�p
		
	for(i=0;i<x;i++){//x=20
		for(j=0;j<(x-1)-i;j++){
			SetDrawScreen(DX_SCREEN_BACK); // �`���𗠉�ʂ�
			ClsDrawScreen(); //����ʏ���
			cmp++;//��r�{�P			



			if(bl[j]>bl[j+1]){
				swp++;//�����{�P
				tmp =bl[j];
				bl[j]=bl[j+1];
				bl[j+1]=tmp;
			}



			showHeader(cmp, swp);//�w�b�_�[�\��
			showGraph(bl, ARRAY_SIZE, j);//�\��

			//_sleep(10);

			ScreenFlip();                           // ����ʂ�\��ʂ�
			

		}
	}
	///////////////////////////////////////////////

}

void showHeader(int x  ,int y){

	DrawFormatStringToHandle(0,0,GetColor(255,255,255),FontHandle1, "[##] data | compare = %d swap = %d",x,y);
	DrawFormatStringToHandle(0,20,GetColor(255,255,255),FontHandle1, " ------------------------------------------------------------------------",x,y);

}

void showGraph(int x[],int y,int z){

	int i, j;//���[�v�p
	for(i=0;i<y;i++){

		if(i==z || i== z+1){

			DrawFormatStringToHandle( 0, 40+20*i, GetColor(0, 255, 0), FontHandle1, "[%02d] %2d | ",i,x[i]);

			for(j=0;j<x[i];j++){
				DrawFormatStringToHandle( 90+j*bw, 40+20*i, GetColor(0, 255, 0), FontHandle1, "��");

			}

		}else{
			DrawFormatStringToHandle( 0, 40+20*i, GetColor(255, 255, 255), FontHandle1, "[%02d] %2d | ",i,x[i]);
			for(j=0;j<x[i];j++){
				DrawFormatStringToHandle( 90+bw*j, 40+20*i, GetColor(255, 255, 255), FontHandle1, "��");

			}


		}
	}
}
