#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"

#pragma warning(disable:4996)


//#define shoki 1000;//�l�p�̃X�s�[�h�����l
void main ()

{	
	//�l�p�̍\���̐ݒ�

	int sd_shoki=5000;//���̃X�s�[�h/�����l�i�ł����قǒx���j
	int sw_shoki=1000;
	struct shikaku
	{
		int x;//�����W
		int y;//�����W
		//int sc_s;//�X�s�[�h�J�E���^�����l
		int s_d;//�����X�s�[�h�J�E���^(�傫���قǒx���j
		int s_w;//���ړ����x
	} sq={40,0,sd_shoki}; 



	
	
	
	setCursor(0);//�J�[�\����\�����Ȃ�
	while(sq.y<22)
	{

		//���𗎂Ƃ�///////////////////////////////////////
		    locate(sq.x,sq.y);//�l�p����ʏ���ɕ\��
			printf("��\n");
		if(sq.s_d==0)
		{
			 locate(sq.x,sq.y);//�l�p����ʏ���ɕ\��
			printf("  \n");
			sq.y++;//�l�p�����ɗ��Ƃ�
			sq.s_d=sd_shoki;
			 locate(sq.x,sq.y);//�l�p����ʏ���ɕ\��
			printf("��\n");
					
		}

		//�L�[���͕���
		if(sq.s_w==0)
		{
		if(GetKeyState(VK_NUMPAD4)<0 && sq.x>0)
		{
			locate(sq.x,sq.y);//�l�p����ʏ���ɕ\��
			printf("  \n");
			sq.x--;
			 locate(sq.x,sq.y);//�l�p����ʏ���ɕ\��
			printf("��\n");
		}
		if(GetKeyState(VK_NUMPAD6)<0 && sq.x+1<24)
		{
			locate(sq.x,sq.y);//�l�p����ʏ���ɕ\��
			printf("  \n");
			sq.x++;
			 locate(sq.x,sq.y);//�l�p����ʏ���ɕ\��
			printf("��\n");
		}
		sq.s_w=sw_shoki;
		}


		sq.s_d--;//�J�E���^�}�C�i�X
		sq.s_w--;//





	}



}