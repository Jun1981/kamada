#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"

#pragma warning(disable:4996)

//�ϐ��錾
int i,j;//���[�v�p

int  iti_flag[23][26];

int KeyInfo=0,KeyOld=0,KeyTrg=0;//�L�[�֌W

char iti[23][26];//������ϐ�

///�\����/////////////////////////////////
//�l�p�̍\����

struct shikaku{
		int x;//�����W
		int y;//�����W
		int x_S;//�����W�����l
		int y_S;//�����W�����l
		//int sc_s;//�X�s�[�h�J�E���^�����l
		int sp;//�X�s�[�h�J�E���^(�傫���قǒx���j
		int sp_S;//�X�s�[�h�����l(�傫���قǒx���j
	
		char *iti[23][23];//�ʒu
		int iti_F[23][23];//�ʒu�t���O

		int w;//���̉��ړ�����

	}sq;

//////////////////////////////////////////


//�v���g�^�C�v�֐��錾
void init(void);//�ϐ��Ȃǂ̏�����
void yokosen(void);//���ɐ���
void hyouji(void);//�\���֐�
void kesu(void);//����
void idou(void);//�ړ��֐�

void KeyChk(void);

void Shuuryou(void);

void main (){	
	init();//������
	yokosen();//����������

	//�Q�[�����[�v
	while(1){

		/*locate(40,20);
		printf("%07d\n",KeyTrg);
		locate(40,21);
		printf("%07d\n",KeyInfo);*/
		
		
		hyouji();//�\��
		KeyChk();//�L�[�`�F�b�N
				
		//kesu();
		idou();//�ړ�
		hyouji();//�\��
	
		Shuuryou();//�I���`�F�b�N
		
		sq.sp--;//�J�E���^�}�C�i�X		
		
	}	
}

void init(){
	setCursor(0);//�J�[�\����\�����Ȃ�

	sq.x_S=40;//���������W
	sq.y_S=0;	//���������W
	sq.x=sq.x_S;
	sq.y=sq.y_S;
	sq.sp_S=2000;//�X�s�[�h�����l
	sq.sp=sq.sp_S;//�X�s�[�h�����l���	

	sq.w=2;//���ړ����

		
}

void yokosen(){
	locate(0,23);//�Q�Q�s�ڂɉ���������
		for(i=0;i<80;i++){
		printf("~");
		}
}

void hyouji(){		
		locate(sq.x,sq.y);//�l�p����ʏ���ɕ\��
	    puts("��");
			
}

void kesu(){

	locate(sq.x,sq.y);//�l�p����ʏ���ɕ\��
		puts("�@");
}

void idou(){




	if(sq.sp<=0 && sq.y<22){
			kesu();
		sq.y++;//�l�p�����ɗ��Ƃ�
		sq.sp=sq.sp_S;

		

	}		
		if(sq.x>=sq.w){
			if(KeyTrg==0x80){
					kesu();
				sq.x-=2;
			}
		}if(sq.x<=77-sq.w){
			if(KeyTrg==0x01){
					kesu();
				sq.x+=2;
				
			}
		}

			if(KeyInfo==0x81) sq.sp-=4;	
}


void KeyChk(){		

	////// ���@0x80
	////// ���@0x01
		KeyTrg=KeyInfo=0;

		if(  GetKeyState(VK_NUMPAD4)<0 || GetKeyState(VK_LEFT) <0 ){
			KeyInfo |= 0x80;
		}
		if(  GetKeyState(VK_NUMPAD6)<0 || GetKeyState(VK_RIGHT)<0 ){
		KeyInfo |=  0x01;
		}
		KeyTrg=(KeyOld^KeyInfo)&KeyInfo;
		KeyOld=KeyInfo;
}

void Shuuryou(){

	if(sq.y>=22){
		locate(sq.x,sq.y);//�l�p����ʏ���ɕ\��
		puts("��");
		getch();
		locate(11,12);
		printf("�I��\n\n");
		exit(0);//�I��

	}
}


