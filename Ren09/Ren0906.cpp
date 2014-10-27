#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<Windows.h>
#include "../../DxLib/DxLib.h"



//�ϐ��錾

int FontHandle1,FontHandle2;

int Key_Trg, Key_Info, Key_Old;   // �L�[���r
int ChkKAny;                             // �Ƃɂ����L�[�������ꂽ��true
int GLpCnt;                             // �Q�[�����[�v�J�E���^
int i, j, k,l;//���[�v�p
int title;//�^�C�g���摜�ǂݍ��ݗp
int bg; //�Q�[���{�Ҕw�i�摜�p
int GO;//�Q�[���I�[�o�[��ʓǂݎ��p
int cl;//�N���A��ʗp

int ten;//�_��
int et,t_limit;//����


int haji=0;//�[�t���O

//�F
int white,green;


//////////

//�v���g�^�C�v�֐�
void init(void);//������
void key_check(void);//�L�[�`�F�b�N
void hyouji(void);//�\��

int haji_chk(void);//�[�`�F�b�N
void game_main(void);//���C��


//�\����
struct par{
	int x;
	int y;
	int haji;//�[�t���O

	int cnt;//�����[�v���Ƃɓ�����

	int haba;//��

	int type;//�G�̃^�C�v

	int x1,y1;//�e�̍��W

	int muki;//����

	int sp_x,sp_y;//���������ɂ�����ړ����邩

};

struct par jiki;
struct par teki[10];

/////////////////////////////////////////////////////////

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);                     // �E�C���h�E���[�h�ɕύX(�������A�Q�T�U�F)
	if (DxLib_Init() == -1) {                    // �c�w���C�u��������������
		return -1;                              // �G���[���N�����璼���ɏI��
	}
	SetDrawScreen(DX_SCREEN_BACK);              // �`���𗠉�ʂ�

	init();//������

	FontHandle1 = CreateFontToHandle(NULL, 40, 4,-1);//�^�C�g���p�t�H���g�n���h��;//�t�H���g�n���h���P
	FontHandle2 = CreateFontToHandle(NULL, 16, 8,-1);//�Q�[���p�t�H���g�n���h��;//�t�H���g�n���h���Q

	//PlaySoundMem(S1, DX_PLAYTYPE_LOOP);

	// �Q�[���V�X�e��������
	//------ �Q�[�����[�v ------//
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) { // Esc�L�[���������܂Ń��[�v
		ClsDrawScreen();                        // ����ʃN���A
		key_check();                            // �L�[���擾
		game_main();                            // �Q�[���R���g���[�����C��

		ScreenFlip();                           // ����ʂ�\��ʂ�
		if (ProcessMessage() == -1) {            // ���b�Z�[�W����
			break;                              // �G���[���N�����烋�[�v���甲����
		}
	}
	DxLib_End();                                // �c�w���C�u�����g�p�̏I������
	return 0;                                        // �A�v���P�[�V�����̏I��

}





void game_main(){


	hyouji();//�\��

	if(jiki.x>0){
		//��
		if(Key_Info==0x01){
			jiki.x-=jiki.sp_x;

		}
	}if(jiki.x+jiki.haba<540){
		//�E
		if(Key_Info==0x02){
			jiki.x+=jiki.sp_x;

		}
	}
}


void init(){	
	srand((unsigned)time(NULL));
		
	white=GetColor(255,255,255);//��
	green=GetColor(0,255,0);//��

	et=0;//�o�ߎ���
	t_limit=60;//��������
	ten=0;//���_

	//���@�̏������W
	jiki.haji=0;//�[�ɂ��邩�ǂ���
	jiki.x=320,jiki.y=450;

	jiki.sp_x=3;//���@�̑��x

	jiki.haba=GetDrawStringWidth("��",1);




	for (i = 0; i < 10; i++){
			teki[i].type = rand() % 3 + 1;//�G�̋����������_���Ō��߂�
			if (teki[i].type == 1){
				teki[i].spd = 10;
			}
			else if (teki[i].type == 2){
				teki[i].spd = 4;
			}
			else if (teki[i].type == 3){
				teki[i].spd = 2;
			}
			
		}

	//�e�̍��W
		for (i = 0; i < 20; i++){
			teki[i].x1 = -100;
			teki[i].y1 = -100;

		}
	//�e�̏����ʒu�ƌ����������_���Ō��߂�
		

		for (i = 0; i < 10; i++){
			teki[i].x = rand() % 66 + 2;
			teki[i].y = rand() % 18 + 2;
			teki[i].muki = rand() % 4 + 1;
			switch (teki[i].muki){
			case 1:
				teki[i].spd = 1;
				e[i] = 1;
				break;
			case 2:
				d[i] = 1;
				e[i] = -1;
				break;
			case 3:
				d[i] = -1;
				e[i] = -1;
				break;
			case 4:
				d[i] = -1;
				e[i] = -1;
				break;
			}

		}


	

}
void hyouji(){
	
	DrawFormatString(jiki.x,jiki.y,white,"��");

	DrawFormatString(540,20,white,"���_:%d�_",ten);
	DrawFormatString(540,40,white,"�c��%d�b",t_limit-et);

}


void key_check()
{

	/*---------------------
	*    �L�[���擾    *
	*---------------------
	*
	*    LEFT  = 0000 0001
	*    RIGHT = 0000 0010
	*    UP    = 0000 0100
	*    DOWN  = 0000 1000
	*    key_trg�͉������u�Ԃ̏��
	*    key_info�͍��̏��
	*
	*/
	Key_Trg = Key_Info = 0;                                 // �L�[���N���A
	ChkKAny = false;
	if (CheckHitKey(KEY_INPUT_LEFT))   { Key_Info |= 0x01; }
	if (CheckHitKey(KEY_INPUT_RIGHT))  { Key_Info |= 0x02; }
	if (CheckHitKey(KEY_INPUT_UP))     { Key_Info |= 0x04; }
	if (CheckHitKey(KEY_INPUT_DOWN))   { Key_Info |= 0x08; }
	if (CheckHitKey(KEY_INPUT_SPACE))  { Key_Info |= 0x10; }
	if (CheckHitKey(KEY_INPUT_Z))      { Key_Info |= 0x20; }
	if (CheckHitKey(KEY_INPUT_ESCAPE)) { Key_Info |= 0x40; }
	if (CheckHitKeyAll()) { ChkKAny = true; }                    // ���Ɂ[
	Key_Trg = (Key_Info ^ Key_Old) & Key_Info;          // �L�[�g���K�[���Z�b�g
	Key_Old = Key_Info;                                     // �L�[���Z�[�u
}
