#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"

#pragma warning(disable:4996)

//�ϐ��錾
int i;//���[�v�p

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
		

		char iti[23][23];//�ʒu
		int iti_F[23][23];//�ʒu�t���O

	}sq;

//////////////////////////////////////////


//�v���g�^�C�v�֐��錾
void init(void);//�ϐ��Ȃǂ̏�����
void yokosen(void);//���ɐ���
void hyouji(void);//�\���֐�
void rakka(void);//�ړ��֐�
void key_chk(void);//�L�[�`�F�b�N

void counter(void);//�J�E���^

void main (){	
	init();//������
	yokosen();//����������

	//�Q�[�����[�v
	while(1){
		hyouji();//�\��
		rakka();//�ړ�
		key_chk();//�L�[�`�F�b�N
		counter();//�J�E���^		
	}	
}

void init(){
	sq.x_S=12;//���������W
	sq.y_S=0;	//���������W
	sq.x=sq.x_S;
	sq.y=sq.y_S;
	sq.sd_S=3000;//�����X�s�[�h�����l
	sq.sd=sq.sd_S;//�����X�s�[�h�����l���

	sq.sw_S=1000;//�X�s�[�h�������l
	sq.sw=sq.sw_S;//�X�s�[�h�����l���


	setCursor(0);//�J�[�\����\�����Ȃ�
		
}

void yokosen(){
	locate(0,23);//�Q�Q�s�ڂɉ���������
		for(i=0;i<80;i++){
		printf("~");
		}
}

void hyouji(){

	locate(sq.x,sq.y);//�l�p����ʏ���ɕ\��
	printf("��\n");

	if(sq.sd==0 && sq.y!=22){
		locate(sq.x,sq.y);//�l�p����ʏ���ɕ\��
		printf("  \n");

	}
	if(sq.y==22){

		locate(sq.x,sq.y);//�l�p����ʏ���ɕ\��
		printf("��\n");
		getch();
		locate(11,12);
		printf("�I��\n\n");
		exit(0);//�I��

	}


}

void rakka(){
	if(sq.sd<=0 && sq.y!=22){
			sq.y++;//�l�p�����ɗ��Ƃ�
			sq.sd=sq.sd_S;
		}



}

void key_chk(){
	if(sq.sw<=0){
		//���ړ�
		if( GetKeyState(VK_NUMPAD4)<0 || GetKeyState(VK_LEFT)<0 && sq.x>0){


			sq.sw=sq.sw_S;
			locate(sq.x,sq.y);//�l�p������
			
			printf("�@");

			sq.x--;
			locate(sq.x,sq.y);//�l�p����ʏ���ɕ\��
			printf("��\n");

		}
		if( GetKeyState(VK_NUMPAD6)<0  || GetKeyState(VK_RIGHT)<0 && sq.x <23) {

			sq.sw=sq.sw_S;

			locate(sq.x,sq.y);//�l�p������
		
			printf("�@");
			sq.x++;

			locate(sq.x,sq.y);//�l�p����ʏ���ɕ\��
			printf("��\n");

		}
	}

}



void counter(){
		sq.sd--;//�X�s�[�h�J�E���^�}�C�i�X	
		sq.sw--;//���X�s�[�h�J�E���^�}�C�i�X

}

