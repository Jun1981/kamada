#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"console.h"




#pragma warning(disable:4996)

typedef int value_type; /* �\�[�g����L�[�̌^ */

int s = 0;//�X�^�[�g�����

int tmp[3];//�X���b�v�p

clock_t start, end;

int i;



 struct h{
	int x[10];
	int y[10];
	int s[10];//���v�p


} kazu = { 
	{3,1,1,2,0,1,2,8,0,6},
	{4,2,3,4,1,4,4,3,6,8}
};




//�v���g�^�C�v�֐��錾

value_type med3(value_type , value_type, value_type);
void quicksort(struct h* , int , int );


void main(void){

	
	int i=0;//���[�v
	srand((unsigned)time(NULL));
	for (i = 0; i < 10; i++){
		kazu.x[i] = rand() % 10 + 1;
		kazu.y[i] = rand() % 10 + 1;
	}
	
	
	
	start = clock();
	
	//�ŏ��̕\��
	for (i = 0; i < 10; i++)	printf("%d,%d\n", kazu.x[i], kazu.y[i]);
	printf("\n");
	/////////////////////////////////////////////////////////
		
	
	

	//���בւ�
	quicksort(&kazu, 0, 10 - 1); 
	for (i = 0; i < 10; i++)	printf("%d,%d\n", kazu.x[i],kazu.y[i]);

	
	
	end = clock();
	printf("%0.5f�b������܂���\n", (double)(end - start)/CLOCKS_PER_SEC);
	
	printf("\n");
	
	

}




//���󋵂ɉ����Č^��ύX����
//typedef int value_type; /* �\�[�g����L�[�̌^ */

value_type med3(value_type x, value_type y, value_type z)
/* x, y, z �̒��Ԓl��Ԃ� */
{
	if (x < y)
		if (y < z) return y; else if (z < x) return x; else return z; else
			if (z < y) return y; else if (x < z) return x; else return z;
}



void quicksort(struct h *a, int left, int right){
	/* �N�C�b�N�\�[�g(�Q�������W�j
	�܂�Y���W�����������ɏォ����ёւ��AY���W���������͂����W��������������ɂ���B

	* a.x     : �\�[�g����z��i���j
	* a.y�@�@�@: �\�[�g����z��i���j
	*a.z   :Y*10�{X�@������
	* left  : �\�[�g����f�[�^�̊J�n�ʒu
	* right : �\�[�g����f�[�^�̏I���ʒu
	*/
	
	
	


	if (left < right) {

		
		
		if (s == 0){
			int youso = right - left + 1;//�v�f��
			//int *niji_sort;
			int l;//���[�v�p

			//niji_sort = (int*)malloc(sizeof(int)*youso);//�񎟔z���Y���P�O�{���̒l������
			for (l = 0; l < youso; l++){
				a->s[l] = a->y[l] * 10 + a->x[l];
			}
			s = 1;
		}



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

			tmp[0] = a->s[i]; a->s[i] = a->s[j]; a->s[j] = tmp[0]; /* a->s[i][i],a->s[i][j] ������ */
			tmp[1] = a->y[i]; a->y[i] = a->y[j]; a->y[j] = tmp[1]; /* a[i],a[j] ������ */
			tmp[2] = a->x[i]; a->x[i] = a->x[j]; a->x[j] = tmp[2]; /* a[i],a[j] ������ */

			i++; j--;
		}
		quicksort(a, left, i - 1); /* ���������E���ċA�I�Ƀ\�[�g */
		quicksort(a, j + 1, right); /* ���������E���ċA�I�Ƀ\�[�g */
		//quicksort(a, left, i - 1);  /* �������������ċA�I�Ƀ\�[�g */
		//quicksort(a, j + 1, right); /* ���������E���ċA�I�Ƀ\�[�g */



	}
	

}