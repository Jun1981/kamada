#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"

#pragma warning(disable:4996)

#define sq_num 100

//#define shoki 1000;//�l�p�̃X�s�[�h�����l

struct shikaku
{
	int x;//�����W
	int y;//�����W
	int s_d;//�����X�s�[�h(�傫���قǒx���j
	int s_w;//���ړ����x
	int flag;//�t���O
};

void main ()

{	
	//�l�p�̍\���̐ݒ�

	int i;//���[�v�p
	int sd_shoki=2000;//���̃X�s�[�h/�����l�i�ł����قǒx���j
	int sw_shoki=1000;

	struct shikaku sq[sq_num];

	//for(i=0;i<sq_num;i++)
	//{
	//	sq[i]=
	//	{
	//		{ 
	//			{40},
	//			{0},
	//			{sd_shoki},
	//			{sw_shoki}}
	//	};
	//	

	//}

	//�\���̏������
	for(i=0;i<sq_num;i++)
	{
		sq[i].x=13;
		sq[i].y=0;
		sq[i].s_d=sd_shoki;
		sq[i].s_w=sw_shoki;
		sq[i].flag=0;
	}


	sq[0].flag=1;//�ŏ��́��t���O�𗧂Ă�


	setCursor(0);//�J�[�\����\�����Ȃ�

	i=0;
	//while(1)//while(1)
	//{

		for(i=0;i<sq_num;i++)//for1
		{
			while(1)//while2
			{


				//���𗎂Ƃ�///////////////////////////////////////
				locate(sq[i].x,sq[i].y);//�l�p����ʏ���ɕ\��
				printf("��\n");
				if(sq[i].s_d==0)
				{
					locate(sq[i].x,sq[i].y);//�l�p����ʏ���ɕ\��
					printf("  \n");
					sq[i].y++;//�l�p�����ɗ��Ƃ�
					sq[i].s_d=sd_shoki;
					locate(sq[i].x,sq[i].y);//�l�p����ʏ���ɕ\��
					printf("��\n");

				}

				//�L�[���͕���
				if(sq[i].s_w==0)
				{
					if( (GetKeyState(VK_NUMPAD4)<0 || GetKeyState(VK_LEFT)<0) && sq[i].x>0)
					{
						locate(sq[i].x,sq[i].y);//�l�p����ʏ���ɕ\��
						printf("  \n");
						sq[i].x--;
						locate(sq[i].x,sq[i].y);//�l�p����ʏ���ɕ\��
						printf("��\n");
					}
					if( (GetKeyState(VK_NUMPAD6)<0  || GetKeyState(VK_RIGHT)<0 ) && sq[i].x+1<24)
					{
						locate(sq[i].x,sq[i].y);//�l�p����ʏ���ɕ\��
						printf("  \n");
						sq[i].x++;
						locate(sq[i].x,sq[i].y);//�l�p����ʏ���ɕ\��
						printf("��\n");
					}
					sq[i].s_w=sw_shoki;
				}

		




			sq[i].s_d--;//�J�E���^�}�C�i�X
			sq[i].s_w--;//



			if(sq[i].y==22)
			{
				//sq[i].flag=0;
				sq[i+1].flag=1;//���̎l�p�̃t���O�𗧂Ă�
				break;
			}
				}//while2
		}//for1
	//}//while1
}





