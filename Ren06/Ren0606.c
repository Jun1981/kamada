#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"

#pragma warning(disable:4996)														



struct shikaku														
{																	
	int x;//�����W													
	int y;//�����W													
	int d_cnt;//�����X�s�[�h�J�E���^(�傫���قǒx���j				
	int s_cnt;//���ړ��J�E���^										
	int flag;//�t���O												
	int shoki_x;//�����W�����l										
	int shoki_y;//�����W�����l										

};																	


//�\���̐錾														
struct shikaku rakka;//�����Ă��遡�\����							


int d_cnt_s=800;//�������̗�����X�s�[�h/�����l�i�ł����قǒx���j	
int s_cnt_s=600;//�������̉��ړ��X�s�[�h/�����l�i�ł����قǒx���j	

int tsumi[25][25] = {0};//�ςݏオ�������\����						

int i;//���[�v�p													



//�֐��v���g�^�C�v�錾
void init(void);//������




void main (){	
	setCursor(0);//�J�[�\����\�����Ȃ�
	init();//������




	//�E�[�ɐ�������
	for(i=0;i<25;i++){

		locate(26,i);
		printf("|");
		locate(i,23);
		printf("-");


	}



	while(1){//while2




		//���𗎂Ƃ�///////////////////////////////////////
		locate(rakka.x,rakka.y);//�l�p����ʏ���ɕ\��
		printf("��\n");
		if(rakka.d_cnt==0){
			locate(rakka.x ,rakka.y);//�l�p������
			printf("  \n");
			rakka.y++;//�l�p�����ɗ��Ƃ�
			rakka.d_cnt=d_cnt_s;
			//locate(rakka.x,rakka.y);//�l�p���Ăѕ\��
			//printf("��\n");

		}

		//�L�[���͕���
		if(rakka.s_cnt==0){

			//���ړ�
			if( (GetKeyState(VK_NUMPAD4)<0 || GetKeyState(VK_LEFT)<0) && rakka.x>=2 && tsumi[rakka.x-2][rakka.y]!=1){
				locate(rakka.x,rakka.y);//�l�p������
				printf("  \n");
				rakka.x-=2;
				//locate(rakka.x,rakka.y);//�l�p���Ăѕ\��
				//printf("��\n");
			}
			if( (GetKeyState(VK_NUMPAD6)<0  || GetKeyState(VK_RIGHT)<0 ) && rakka.x+2<=25 && tsumi[rakka.x+2][rakka.y]!=1){
				locate(rakka.x,rakka.y);//�l�p������
				printf("  \n");
				rakka.x+=2;
				//locate(rakka.x,rakka.y);//�l�p���Ăѕ\��
				//printf("��\n");
			}

			//�I��
			if(GetKeyState(0x58)<0){
				exit(0);
			}
			rakka.s_cnt=s_cnt_s;
		}


		//�����������ɒB������
		if(rakka.y==22){
			tsumi[rakka.x][rakka.y]=1;
			locate(rakka.x,rakka.y);//�l�p����ʏ���ɕ\��
			printf("��\n");
			rakka.x=12;
			rakka.y=0;
			/*locate(rakka.x,rakka.y);
			printf("�@");*/

		}else if(tsumi[rakka.x][rakka.y+1]==1){
			tsumi[rakka.x][rakka.y]=1;
			locate(rakka.x,rakka.y);//�l�p����ʏ���ɕ\��
			printf("��\n");
			rakka.x=12;
			rakka.y=0;
		}

		rakka.d_cnt--;//�J�E���^�}�C�i�X
		rakka.s_cnt--;//


	}
}




//������
void init(){


	//�����Ă��遡�����l

	rakka.x = 13 - 1;
	rakka.y = 0;
	rakka.d_cnt = d_cnt_s;
	rakka.s_cnt = s_cnt_s;
	rakka.shoki_x = 12;
	rakka.shoki_y = 0;


}


