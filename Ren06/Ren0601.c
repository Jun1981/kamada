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

	int shoki=1000;//���̃X�s�[�h/�����l�i�ł����قǒx���j
	struct shikaku
	{
		int x;//�����W
		int y;//�����W
		//int sc_s;//�X�s�[�h�J�E���^�����l
		int sc;//�X�s�[�h�J�E���^(�傫���قǒx���j

	} sq={40,0,shoki}; 



	
	
	
	setCursor(0);//�J�[�\����\�����Ȃ�
	while(sq.y<22)
	{
		    locate(sq.x,sq.y);//�l�p����ʏ���ɕ\��
			printf("��\n");
		if(sq.sc==0)
		{
			 locate(sq.x,sq.y);//�l�p����ʏ���ɕ\��
			printf("  \n");
			sq.y++;//�l�p�����ɗ��Ƃ�
			sq.sc=shoki;
		}
		sq.sc--;//�J�E���^�}�C�i�X
	}



}