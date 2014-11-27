#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include "../../DxLib/DxLib.h"

#pragma warning(disable:4996)

//�ϐ��錾

const int EN = 30;//�G�̐�
int FontHandle1;//�t�H���g�n���h���P
int white = GetColor(255, 255, 255);//��

//�\���̒�`

typedef struct{
	int x;
	int y;
} Position;


//�v���g�^�C�v�֐��錾

void key_check(void);//�L�[�`�F�b�N
void game_main();//���C��

void init(Position[], int);//������
void sort(Position[], int);//�\�[�g

void hyouji(Position[], int);//�\��


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

	ChangeWindowMode(TRUE);                     // �E�C���h�E���[�h�ɕύX(�������A�Q�T�U�F)

	if (DxLib_Init() == -1) {                    // �c�w���C�u��������������
		return -1;                              // �G���[���N�����璼���ɏI��
	}
	SetDrawScreen(DX_SCREEN_BACK);              // �`���𗠉�ʂ�


	Position teki[EN];//�G���W�̍\���̐錾

	init(teki, EN);//������

	// �Q�[���V�X�e��������
	//------ �Q�[�����[�v ------//
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) { // Esc�L�[���������܂Ń��[�v
		ClsDrawScreen();                        // ����ʃN���A


		//key_check();                            // �L�[���擾
		//game_main();                            // �Q�[���R���g���[�����C��




		hyouji(teki, EN);

	

		sort(teki, EN);
		
		ScreenFlip();       // ����ʂ�\��ʂ�

	
		if (ProcessMessage() == -1) {            // ���b�Z�[�W����
			break;                              // �G���[���N�����烋�[�v���甲����
		}
	}
	DxLib_End();// �c�w���C�u�����g�p�̏I������
	return 0;// �A�v���P�[�V�����̏I��

}



void init(Position x[], int y){

	FontHandle1 = CreateFontToHandle("�l�r �S�V�b�N", 20, 9, DX_FONTTYPE_NORMAL);//�t�H���g�n���h���P

	int i;//���[�v�p

	srand((unsigned)time(NULL));

	for (i = 0; i < y; i++){

		x[i].x = rand() % (640-16);
		x[i].y = rand() % (480-16);


	}

}



void sort(Position x[], int y){

	int i;//���[�v�p
	Position tmp;//�ꎞ
	for (i = 0; i < y - 1; i++){




		if (x[i].y > x[i + 1].y){

			//����ւ�
			tmp = x[i];
			x[i] = x[i + 1];
			x[i + 1] = tmp;
			break;


		}
		else if (x[i].y == x[i + 1].y){
			if (x[i].x > x[i + 1].x){
				//����ւ�
				tmp = x[i];
				x[i] = x[i + 1];
				x[i + 1] = tmp;

				break;
				
			}
			
		}

	}

}

void hyouji(Position x[], int y){
	int i;
	for (i = 0; i < EN; i++){
		DrawFormatStringToHandle(0,16*i, white, FontHandle1, "(%d,%d)",x[i].x,x[i].y);
	
	}

}