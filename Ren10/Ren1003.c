#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include "console.h"
#pragma warning(disable:4996)

#define TekiKazu 300



//�\���̒�`
typedef struct {
	int x;
	int y;
	int s;//���v�p
}Position;


//�v���g�^�C�v�֐��錾

void init(Position*);
void sort(Position*, int, int);
void hyouji(Position*, int, int);
void zentai_hyouji(Position*);

//���͂��ꂽ�����f�[�^��Position�\���̂ɓ���ĕԂ�
Position input(void);//�����֐�

//�w�肳�ꂽ�f�[�^���������āA�z��ԍ���Ԃ��B���݂��Ȃ����́A�|�P��Ԃ�
int search(Position *   , Position*, int);



void main(void){
	int start, end;//���Ԍv���p
	
	int m;//���������f�[�^�����Ԃɂ��邩
	

	Position P[TekiKazu] = { 0 };//�\���̐錾

	Position input_data;//���͂����l������
	


	init(P);//���W�f�[�^������

	zentai_hyouji(P); Sleep(2000);//�S�̕\�����ĂQ�b�܂�

	start = clock();
	sort(P, 0, TekiKazu - 1);//�\�[�g�֐�
	end = clock();

	zentai_hyouji(P);	Sleep(3000);//�Ō�̊m�F�\��

	color(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);//��
	printf("\n�\�[�g�ɂ����������Ԃ�%.3f�b�ł��B\n", (end - start)*1.0 / CLOCKS_PER_SEC);

	

	//���͂��Č���
	clear();
	input_data = input();//���͂����l���\���̂ɓ����
	m = search(&input_data, P, TekiKazu);
	printf("�����������W��%d�Ԗڂɂ���܂��B\n", m);
	Sleep(10000);





}



void init(Position *a){

	int i;//���[�v�p
	srand((unsigned)time(NULL));

	for (i = 0; i<TekiKazu; i++){
		(a + i)->x = rand() % 60;   (a + i)->y = rand() % 21;//X���W��Y���W�Ƀ����_���Ő���������B
		(a + i)->s = (a + i)->y * 100 + (a + i)->x; //S=Y*10+X
	}

}

Position input(void){
	Position in = { 0 };//���͂����l������
	printf("�����������f�[�^�̂����W����͂��Ă��������B\n");
	scanf("%d",&in.x);
	printf("�����������f�[�^�̂����W����͂��Ă��������B\n");
	scanf("%d",&in.y);


	return in;//�\���̂�Ԃ�




}

int search(Position *I , Position *D, int n){

	int i = 0;
	for (i = 0; i < n; i++){
		if (I->x == (D + i)->x){
			if (I->y == (D + i)->y){

				return i;//��v������W��Ԃ�

				break;



			}


		}


	}
	return -1;//��v���Ȃ�
}

void hyouji(Position *a, int p, int q){

	setCursor(0);//�J�[�\����\�����Ȃ�

	color(FOREGROUND_GREEN);//��
	locate((a + p)->x, (a + p)->y); printf("*(%d)", p);

	color(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);//��
	locate((a + q)->x, (a + q)->y); printf("*(%d)", q);

	clear();//��ʏ���

}


void zentai_hyouji(Position* a){

	int i;//���[�v�p
	int c = 0;//�F�؂�ւ�

	for (i = 0; i<TekiKazu; i++){

		if (i % 2 == 0)
			color(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);//��
		else
			color(FOREGROUND_GREEN);//��

		locate((a + i)->x, (a + i)->y);
		printf("%d", i);
	}
}

int med3(int x, int y, int z){/* x, y, z �̒��Ԓl��Ԃ� */
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
		int pivot = med3((a + i)->s, (a + (i + (j - i) / 2))->s, (a + j)->s); /* (i+j)/2�ł̓I�[�o�[�t���[���Ă��܂� */


		while (1) { /* (a+i)->s �� pivot �ȏ�ƈȉ��̏W�܂�ɕ������� */

			while ((a + i)->s < pivot) { i++; } /* (a+i)->s[i] >= pivot �ƂȂ�ʒu������ */
			while (pivot < (a + j)->s) { j--; } /* (a+i)->s[j] <= pivot �ƂȂ�ʒu������ */

			if (i >= j)  { break; }

			hyouji(a, i, j);//�\���֐�
			tmp[0] = (a + i)->s; (a + i)->s = (a + j)->s; (a + j)->s = tmp[0]; /* (a+i)->s[i],(a+i)->s[j] ������ */
			tmp[1] = (a + i)->y; (a + i)->y = (a + j)->y; (a + j)->y = tmp[1]; /* a[i],a[j] ������ */
			tmp[2] = (a + i)->x; (a + i)->x = (a + j)->x; (a + j)->x = tmp[2]; /* a[i],a[j] ������ */

			hyouji(a, i, j);//�\���֐�

			i++; j--;
		}
		sort(a, left, i - 1); /* �������������ċA�I�Ƀ\�[�g */
		sort(a, j + 1, right); /* ���������E���ċA�I�Ƀ\�[�g */

	}

}