#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"

#pragma warning(disable:4996)

//�ϐ��錾
int i,j;//���[�v�p

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
		

	}sq;

//////////////////////////////////////////


//�v���g�^�C�v�֐��錾
void init(void);//�ϐ��Ȃǂ̏�����
void yokosen(void);//���ɐ���
void hyouji(void);//�\���֐�
void kesu(void);//�����֐�
void rakka(void);//�ړ��֐�

void S_chk(void);//���Ƀu���b�N�����邩�`�F�b�N
void key_chk(void);//�L�[�`�F�b�N

void counter(void);//�J�E���^

void main (){	
	init();//������
	yokosen();//����������

	//�Q�[�����[�v
	while(1){
		hyouji();//�\��		
		key_chk();//�L�[�`�F�b�N			
		rakka();//�ړ�		
		counter();//�J�E���^		
	}	
}

void init(){
	sq.x_S = 12;//���������W
	sq.y_S = 0;	//���������W
	sq.x = sq.x_S;
	sq.y = sq.y_S;
	sq.sd_S = 2000;//�����X�s�[�h�����l
	sq.sd = sq.sd_S;//�����X�s�[�h�����l���

	sq.sw_S = 1000;//�X�s�[�h�������l
	sq.sw = sq.sw_S;//�X�s�[�h�����l���
	
	setCursor(0);//�J�[�\����\�����Ȃ�


}

void yokosen(){
	locate(0,23);//�Q�Q�s�ڂɉ���������
		for(i=0;i<80;i++){
		printf("~");
		}
		for (i = 23; i < 25; i++){
			locate(25, i);
			puts("|");
		}
}

void hyouji(){
	locate(sq.x,sq.y);//�l�p����ʏ���ɕ\��
	printf("��\n");
}


//���Ƀu���b�N�����邩�`�F�b�N


void rakka(){
	if (sq.sd <= 0){		
		if (sq.y < 22){
			sq.sd = sq.sd_S;//�����l
			locate(sq.x, sq.y);//�l�p����ʏ���ɕ\��
			printf("�@");//�󔒂�}��
			sq.y++;//�l�p�����ɗ��Ƃ�
			hyouji();//�Ăс��\��
		}
else
{
	sq.x = sq.x_S;
	sq.y = sq.y_S;

}

	}
}







void key_chk(){
	if (sq.sw <= 0){
		//���ړ�
		if (GetKeyState(VK_NUMPAD4) < 0 || GetKeyState(VK_LEFT) < 0 && sq.x >= 2){
			
				sq.sw = sq.sw_S;
				locate(sq.x, sq.y);//�l�p������			
				printf("�@");
				sq.x -= 2;//����
				locate(sq.x, sq.y);//�l�p����ʏ���ɕ\��
				printf("��\n");
			

		}
		//�E�ړ�
		if (GetKeyState(VK_NUMPAD6) < 0 || GetKeyState(VK_RIGHT) < 0 && sq.x <= 21) {
			
				sq.sw = sq.sw_S;
				locate(sq.x, sq.y);//�l�p������
				printf("�@");
				sq.x += 2;
				locate(sq.x, sq.y);//�l�p����ʏ���ɕ\��
				printf("��\n");
			

		}
	}

}

void counter(){
		sq.sd--;//�X�s�[�h�J�E���^�}�C�i�X	
		sq.sw--;//���X�s�[�h�J�E���^�}�C�i�X

}

