#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"

#pragma warning(disable:4996)

//�ϐ��錾
int i, j;//���[�v�p

///�\����/////////////////////////////////
//�l�p�̍\����

struct shikaku{
	int x;//�����W
	int y;//�����W
	int x_S;//�����W�����l
	int y_S;//�����W�����l
	//int sc_s;//�X�s�[�h�J�E���^�����l
	int sd;//�X�s�[�h�J�E���^(�傫���قǒx���j
	int sd_S;//�X�s�[�h�����l(�傫���قǒx���j
	int sw;//�X�s�[�h�J�E���^(���j
	int sw_S;//�X�s�[�h�J�E���^�����l

	int line[23];//���`�F�b�N�p
	int iti[25][23];//�ʒu
	int iti_tmp[25][23];//�ʒu�t���O�ꎞ�ۊǗp
}sq;

//////////////////////////////////////////


//�v���g�^�C�v�֐��錾
void init(void);//�ϐ��Ȃǂ̏�����
void yokosen(void);//���ɐ���
void hyouji(void);//�\���֐�
void kesu(void);//�����֐�
void rakka(void);//�ړ��֐�

void S_chk(void);//���Ƀu���b�N�����邩�`�F�b�N
void line_chk(void);//���Ȃ�񂾂��ǂ����`�F�b�N
void key_chk(void);//�L�[�`�F�b�N

void counter(void);//�J�E���^

void main(){
	init();//������
	yokosen();//����������

	//�Q�[�����[�v
	while (1){
		hyouji();//�\��		
		key_chk();//�L�[�`�F�b�N			
		rakka();//�ړ�
		//line_chk();//������ł邩�ǂ����`�F�b�N
		counter();//�J�E���^		
	}
}

void init(){
	sq.x_S = 12;//���������W
	sq.y_S = 0;	//���������W
	sq.x = sq.x_S;
	sq.y = sq.y_S;
	sq.sd_S = 1000;//�����X�s�[�h�����l
	sq.sd = sq.sd_S;//�����X�s�[�h�����l���

	sq.sw_S = 1000;//�X�s�[�h�������l
	sq.sw = sq.sw_S;//�X�s�[�h�����l���

	setCursor(0);//�J�[�\����\�����Ȃ�

	for (i = 0; i < 25; i += 2){
		for (j = 0; j < 23; j++){
			sq.iti[i][j] = 0;
			sq.line[j] = 0;

		}
	}
}

void yokosen(){
	locate(0, 23);//�Q�Q�s�ڂɉ���������
	for (i = 0; i<80; i++){
		printf("~");
	}
	for (i = 23; i < 25; i++){
		locate(25, i);
		puts("|");
	}
}


void hyouji(){
	locate(sq.x, sq.y);//�l�p����ʏ���ɕ\��
	printf("��\n");
}


//���Ƀu���b�N�����邩�`�F�b�N


void rakka(){
	if (sq.sd <= 0){
		if (sq.iti[sq.x][sq.y + 1] == 0 && sq.y < 22){
			locate(sq.x, sq.y);//�l�p����ʏ���ɕ\��
			printf("�@");//�󔒂�}��
			sq.y++;//�l�p�����ɗ��Ƃ�
			hyouji();//�Ăс��\��
		}
		else if (sq.iti[sq.x][sq.y + 1] == 1 || sq.y == 22){
			sq.iti[sq.x][sq.y] = 1;//�ʒu�t���O�I��			
			hyouji();//�ςݏオ�����n�_�ŕ\�����Ă���
			line_chk();//���`�F�b�N
			sq.x = sq.x_S; sq.y = sq.y_S;//���W������

		}
		sq.sd = sq.sd_S;//�J�E���^������
	}
}







void key_chk(){
	if (sq.sw <= 0){
		//���ړ�
		if (GetKeyState(VK_NUMPAD4) < 0 || GetKeyState(VK_LEFT) < 0 && sq.x >= 2){

			if (sq.iti[sq.x - 2][sq.y] == 0){
				sq.sw = sq.sw_S;
				locate(sq.x, sq.y);//�l�p������			
				printf("�@");
				sq.x -= 2;//����
				locate(sq.x, sq.y);//�l�p����ʏ���ɕ\��
				printf("��\n");
			}

		}
		//�E�ړ�
		if (GetKeyState(VK_NUMPAD6) < 0 || GetKeyState(VK_RIGHT) < 0 && sq.x <= 23) {

			if (sq.iti[sq.x + 2][sq.y] == 0){
				sq.sw = sq.sw_S;

				locate(sq.x, sq.y);//�l�p������

				printf("�@");
				sq.x += 2;

				locate(sq.x, sq.y);//�l�p����ʏ���ɕ\��
				printf("��\n");
			}

		}
		if (GetKeyState(0x58) < 0){//���������ꂽ��I��

			puts("�I��\n");
			exit(0);//�I��


		}
	}

}

void line_chk(){
	for (i = 0; i < 25; i += 2){
		if (sq.iti[i][sq.y] == 0){
			break;
		}
	}


	if (i == 26){
		sq.line[sq.y] = 1;//������ł���

		for (i = 0; i < 25; i += 2){
			locate(i, sq.y);
			puts("�@");//����
			sq.iti[i][sq.y] = 0;
			//��̃u���b�N����i���Ƃ�			
			for (j = 0; j < sq.y; j++){

				if (sq.iti[i][j] == 1){
					sq.iti_tmp[i][j] = 1;//�ꎞ�I�Ɉʒu�t���O���Ă�
					sq.iti[i][j] = 0;//�{�t���O�I�t
					locate(i, j);//�ꏊ
					puts("�@");//����						
				}

			}
		}
		for (i = 0; i < 25; i += 2){
			for (j = 0; j < sq.y; j++){
				if (sq.iti_tmp[i][j] == 1){
					sq.iti[i][j + 1] = 1;
					locate(i, j + 1);//�ꏊ
					puts("��");//�\��	


				}
			}

		}
		//�ꎞ�t���O�ɑS��0������
		for (i = 0; i < 25; i += 2){
			for (j = 0; j < 23; j++){
				sq.iti_tmp[i][j] = 0;
			}
		}


	}
}






void counter(){
	sq.sd--;//�X�s�[�h�J�E���^�}�C�i�X	
	sq.sw--;//���X�s�[�h�J�E���^�}�C�i�X

}
