#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"

#pragma warning(disable:4996)

//�ϐ��錾
int i,j;//���[�v�p

char iti[23][25];//

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

	}sq;

//////////////////////////////////////////


//�v���g�^�C�v�֐��錾
void init(void);//�ϐ��Ȃǂ̏�����
void yokosen(void);//���ɐ���
void hyouji(void);//�\���֐�
void idou(void);//�ړ��֐�

void main (){	
	init();//������
	

	for(i=0;i<23;i++){
		
		iti[i][]="0000000000000000000000";
		
	}

	iti[10][10]='3';

	for(i=0;i<23;i++){
			puts(iti[i][0]);

	}


	yokosen();//����������

	//�Q�[�����[�v
	while(1){
			
		

		//hyouji();//�\��
		//idou();//�ړ�
		//sq.sp--;//�J�E���^�}�C�i�X		
	}	
}

void init(){
	sq.x_S=12;//���������W
	sq.y_S=0;	//���������W
	sq.x=sq.x_S;
	sq.y=sq.y_S;
	sq.sp_S=1000;//�X�s�[�h�����l
	sq.sp=sq.sp_S;//�X�s�[�h�����l���

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

	if(sq.sp==0 && sq.y!=22){
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

void idou(){
	if(sq.sp==0 && sq.y!=22){
			sq.y++;//�l�p�����ɗ��Ƃ�
			sq.sp=sq.sp_S;
		}



}




