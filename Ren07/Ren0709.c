#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#pragma warning(disable:4996)


int input(int,int);//�ꌅ�̐������͑҂�
int y;//���͂�������������ϐ�

char next[2];//���̐���

void main(){



	int i,j;//���[�v
	char buf[10][512];
	char buf_tmp[10][512];

	char next[2];//���̐���



	//�t�@�C���I�[�v��
	FILE *fp=fopen("E:/kamada/DATA/1.txt","r");
	while(1){

		if(y==1){

		
		}
		for(i=0;i<2;i++){
			fgets(buf[i],512,fp);
		}
		while(fgets(buf[2],512,fp)!=NULL){
			printf("%s",buf[0]);
			for(i=0;i<2;i++){			
				strcpy(buf[i],buf[i+1]);
			}
		}

		//������̃R���}�܂ł̕�������ꎞ�ϐ��ɓ����
		for(j=0;j<2;j++){
			for(i=0;i<512;i++){

				if(buf[j][i]==','){
					strncpy(buf_tmp[j],buf[j],i);
					buf_tmp[j][i]='\0';
					next[j]=buf[j][i+1];
				}

			}
			printf("%s",buf_tmp[j]);


		}

		printf("\n\n");



		printf("��������͂��Ă��������B\n:");
		y=input(1,2);


		while(1){
			if(y>=10){
				printf("1���Q����͂��Ă��������B\n:");
				y=input(0,9);
			}else if(y>=0 && y<=9){
				break;
			}
		}


		if(y==1){ 
			FILE *fp=fopen("E:/kamada/DATA/2.txt","r");

		}
		if(y==2){
			FILE *fp=fopen("E:/kamada/DATA/3.txt","r");


		}



		fclose(fp);
	}
}



//����͈�(�ŏ��O�A�ő�X�j�̈ꌅ�̐��������͂��ꂽ�Ƃ��͂��̒l��Ԃ��B
//����ȊO�̐����╶���񂪓��͂��ꂽ�Ƃ��͂P�O��Ԃ�

//int yomi(int x1, int x2);

int input(int x1, int x2)
{
	char a[20];
	int b;

	scanf("%s",&a);
	b = strlen(a);

	if (b == 1)
	{

		b = atoi(a);
		if (b >= x1 && b <= x2)
		{
			return (b);
		}

	}

	return 10;

}