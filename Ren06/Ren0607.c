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
	
	int cd;//�����X�s�[�h�J�E���^(�傫���قǒx���j
	int cw;//���ړ��J�E���^
	int flag;//�t���O
	int flag_tmp;//
	int shoki_x;//�����W�����l
	int shoki_y;//�����W�����l


};
int cd_shoki=800;//�������̗�����X�s�[�h/�����l�i�ł����قǒx���j
int cw_shoki=600;//�������̉��ړ��X�s�[�h/�����l�i�ł����قǒx���j

int i,j,k;//���[�v�p


int line[23];//�����ѐ��l


void main ()

{	

	//�\���̐錾
	struct shikaku rakka;//�����Ă��遡�\����
	struct shikaku tsumi[25][23];//�ςݏオ�������\����





	//�����Ă��遡�����l

	rakka.x=13-1;
	rakka.y=0;
	rakka.cd=cd_shoki;
	rakka.cw=cw_shoki;
	rakka.shoki_x=12;
	rakka.shoki_y=0;
	//rakkaflag=1;//�ŏ��́��t���O�𗧂Ă�


	setCursor(0);//�J�[�\����\�����Ȃ�

	//�E�[�ɐ�������
	for(i=0;i<25;i++)
	{

		locate(26,i);
		printf("|");
		locate(i,23);
		printf("-");


	}



	while(1)//while2
	{


		for(i=0;i<25;i++)
		{
			for(j=0;j<23;j++)
			{
			}
		}



		//���𗎂Ƃ�///////////////////////////////////////
		locate(rakka.x,rakka.y);//�l�p����ʏ���ɕ\��
		printf("��\n");
		if(rakka.cd==0)
		{
			locate(rakka.x ,rakka.y);//�l�p������
			printf("  \n");
			rakka.y++;//�l�p�����ɗ��Ƃ�
			rakka.cd=cd_shoki;
			//locate(rakka.x,rakka.y);//�l�p���Ăѕ\��
			//printf("��\n");

		}

		//�L�[���͕���
		if(rakka.cw==0)
		{

			//���ړ�
			if( (GetKeyState(VK_NUMPAD4)<0 || GetKeyState(VK_LEFT)<0) && rakka.x>=2 && tsumi[rakka.x-2][rakka.y].flag!=1)
			{
				locate(rakka.x,rakka.y);//�l�p������
				printf("  \n");
				rakka.x-=2;
				//locate(rakka.x,rakka.y);//�l�p���Ăѕ\��
				//printf("��\n");
			}
			if( (GetKeyState(VK_NUMPAD6)<0  || GetKeyState(VK_RIGHT)<0 ) && rakka.x+2<=25 && tsumi[rakka.x+2][rakka.y].flag!=1)
			{
				locate(rakka.x,rakka.y);//�l�p������
				printf("  \n");
				rakka.x+=2;
				//locate(rakka.x,rakka.y);//�l�p���Ăѕ\��
				//printf("��\n");
			}

			//�I��
			if(GetKeyState(0x58)<0)
			{
				exit(0);
			}
			rakka.cw=cw_shoki;
		}


		//�����������ɒB������
		if(rakka.y==22)
		{
			tsumi[rakka.x][rakka.y].flag=1;
			locate(rakka.x,rakka.y);//�l�p����ʏ���ɕ\��
			printf("��\n");
			rakka.x=12;
			rakka.y=0;
			/*locate(rakka.x,rakka.y);
			printf("�@");*/
			line[22]++;//���C���l�{�{

		}else if(tsumi[rakka.x][rakka.y+1].flag==1)
		{
			tsumi[rakka.x][rakka.y].flag=1;
			locate(rakka.x,rakka.y);//�l�p����ʏ���ɕ\��
			printf("��\n");
			rakka.x=12;
			rakka.y=0;

			line[rakka.y]++;//���C���l�{�{
		}



		if(line[22]==13)//��񂻂������
		{
			line[22]=0;
			locate(0,22);
					printf("�@�@�@�@�@�@�@�@�@�@�@�@�@");//����
			for(j=0;j<22;j++)
			{			
				    locate(0,j);
					printf("�@�@�@�@�@�@�@�@�@�@�@�@�@");//����

				for(k=0;k<25;k++)
				{
					tsumi[k][22].flag_tmp=0;

						

					
					if(tsumi[k][j].flag==1)
					{
						
						tsumi[k][j].flag_tmp=0;
						tsumi[k][j+1].flag_tmp=1;
						line[j+1]++;
					

					}
				}


			}

			for(k=0;k<25;k++)
			{
				for(j=0;j<22;j++)
				{
				tsumi[k][j].flag=0;
				tsumi[k][j].flag=tsumi[k][j].flag_tmp;
				if(tsumi[k][j].flag==1)
				{
					locate(k,j);
					printf("��");
				}
				}
			}
			

		}





		rakka.cd--;//�J�E���^�}�C�i�X
		rakka.cw--;//




	}//while2


}





