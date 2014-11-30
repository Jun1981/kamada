#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include "console.h"

#define TekiKazu 300



//�\���̒�`





typedef struct {
	

	int x[TekiKazu];
	int y[TekiKazu];
	int s[TekiKazu];//���v�p
}Position;
	

//�v���g�^�C�v�֐��錾

void init(Position*,int);
void sort(Position*,int,int);
void hyouji(Position*,int,int);
void zentai_hyouji(Position* ,int);



void main(void){
	int start,end;//���Ԍv���p
	
	Position P={0};//�\���̐錾

	init(&P,TekiKazu);//���W�f�[�^������

	

	zentai_hyouji(&P,TekiKazu); Sleep(2000);//�S�̕\�����ĂQ�b�܂�
		

	
	start=clock();
		sort(&P,0,TekiKazu-1);//�\�[�g�֐�
	end=clock();

	zentai_hyouji(&P,TekiKazu);	Sleep(3000);//�Ō�̊m�F�\��

	color(FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE);//��
	printf("\n�\�[�g�ɂ����������Ԃ�%.3f�b�ł��B\n",(end-start)*1.0/CLOCKS_PER_SEC);

}



void init(Position *a,int x){

	int i;//���[�v�p
	srand((unsigned)time(NULL));
	

	for(i=0;i<TekiKazu;i++){
		a->x[i]=rand()%60;   a->y[i]=rand()%21;//X���W��Y���W�Ƀ����_���Ő���������B
		a->s[i]= a->y[i]*100+ a->x[i]; //S=Y*10+X
	}


}

void hyouji(Position *a,int p,int q){

	int i=0;//���[�v�p

	setCursor(0);//�J�[�\����\�����Ȃ�
	clear();//��ʏ���

	//color(FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE);//��
	//for(i=0;i<TekiKazu;i++){
	//
	//	locate(a->x[i],a->y[i]);
	//	printf("*");
	//}

	color(FOREGROUND_GREEN);//��
	locate(a->x[p],a->y[p]);printf("*(%d)",p);

	//Sleep(100);

	color(FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE );//��
	locate(a->x[q],a->y[q]);printf("*(%d)",q);
			
			
	//for (l=0;l<TekiKazu;l++){
	//printf("%d,%d\n",a->x[l],a->y[l]);
	//}
	//
	

	//

	
	/////////////////////////////////////////////////////////


	//Sleep(100);

}


void zentai_hyouji(Position* a,int p){

	int i;//���[�v�p
	int c=0;//�F�؂�ւ�
		
	for(i=0;i<p;i++){
	
		if(i%2==0)
			color(FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE);//��
		else
			color(FOREGROUND_GREEN );//��

		locate(a->x[i],a->y[i]);
		printf("%d",i);
	}



}

int med3(int x, int y, int z)
/* x, y, z �̒��Ԓl��Ԃ� */
{
    if (x < y)
        if (y < z) return y; else if (z < x) return x; else return z; else
        if (z < y) return y; else if (x < z) return x; else return z;
}


void sort(Position *a, int left, int right){


	static int tmp[3];
	/* �N�C�b�N�\�[�g(�Q�������W�j
	�܂�Y���W�����������ɏォ����ёւ��AY���W���������͂����W��������������ɂ���B

	* a.x     : �\�[�g����z��i���j
	* a.y�@�@�@: �\�[�g����z��i���j
	* left  : �\�[�g����f�[�^�̊J�n�ʒu
	* right : �\�[�g����f�[�^�̏I���ʒu
	*/
	
	if (left < right) {		


		int i = left, j = right;
		int pivot = med3(a->s[i], a->s[i + (j - i) / 2], a->s[j]); /* (i+j)/2�ł̓I�[�o�[�t���[���Ă��܂� */

		
		while (1) { /* a->s[i] �� pivot �ȏ�ƈȉ��̏W�܂�ɕ������� */
			
			while (a->s[i] < pivot) { i++; } /* a->s[i][i] >= pivot �ƂȂ�ʒu������ */
			while (pivot < a->s[j]) { j--; } /* a->s[i][j] <= pivot �ƂȂ�ʒu������ */



			if (i >= j)  { break; }

			//if (  a->s[i] == a->s[j]==pivot ){
			//	tmp[1] = a->x[i]; a->x[i] = a->x[j]; a->x[j] = tmp[1]; /* a[i],a[j] ������ */
			//	i++; j--;
			//	break;
			//}//y���W���������Ă����W���E�̂ق����傫�����͓���ւ��Ȃ� 

			hyouji(a,i,j);//�\���֐�
			tmp[0] = a->s[i]; a->s[i] = a->s[j]; a->s[j] = tmp[0]; /* a->s[i][i],a->s[i][j] ������ */
			tmp[1] = a->y[i]; a->y[i] = a->y[j]; a->y[j] = tmp[1]; /* a[i],a[j] ������ */
			tmp[2] = a->x[i]; a->x[i] = a->x[j]; a->x[j] = tmp[2]; /* a[i],a[j] ������ */
			
			hyouji(a,i,j);//�\���֐�


			i++; j--;
		}
		sort(a, left, i - 1); /* ���������E���ċA�I�Ƀ\�[�g */
		sort(a, j + 1, right); /* ���������E���ċA�I�Ƀ\�[�g */
		


	}
	

}