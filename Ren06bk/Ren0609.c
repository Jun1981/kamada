#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include<console.h>


#pragma warning(disable:4996)

//�ϐ��錾
int i, j;//���[�v�p

int w_cnt[23] = { 0 }, b_cnt[23] = { 0 };//���Ɓ��̐�
int w_cnt_tmp[23] = { 0 }, b_cnt_tmp[23] = { 0 };//�̕ۑ��p

int iti[25][23];//�ʒu
int iti_tmp[25][23];//�ʒu�t���O�ꎞ�ۊǗp

int b_type[25][23]; //�ςݏオ�����u���b�N�̃^�C�v
int b_type_tmp[25][23];//�u���b�N�^�C�v�ꎞ�ۑ��p

int w_cnt[23], b_cnt[23];
int w_cnt_tmp[23], b_cnt_tmp[23];

int dbg_cnt=10000;//�f�o�b�N�p�J�E���^



///�\����/////////////////////////////////
//�l�p�̍\����

struct shikaku{
	int x;//�����W
	int y;//�����W
	int x_S;//�����W�����l
	int y_S;//�����W�����l
	//int sc_s;//�X�s�[�h�J�E���^�����l
	int sd;//�X�s�[�h�J�E���^(�傫���قǒx���j
	int sd_S;//�X�s�[�h�����l(�傫���قǒx���j
	int sw;//�X�s�[�h�J�E���^(���j
	int sw_S;//�X�s�[�h�J�E���^�����l
	int line[23];//���`�F�b�N�p
	
	int d_type;//�������ʗp

	
}sq;

//////////////////////////////////////////


//�v���g�^�C�v�֐��錾
void init(void);//�ϐ��Ȃǂ̏�����
void yokosen(void);//���ɐ���
void d_hyouji(void);//�����\���֐�
void b_hyouji(int i,int j);//�ς݃u���b�N�\���֐�

void kesu(void);//�����֐�
void rakka(void);//�ړ��֐�

void S_chk(void);//���Ƀu���b�N�����邩�`�F�b�N
void line_chk(void);//���Ȃ�񂾂��ǂ����`�F�b�N
void key_chk(void);//�L�[�`�F�b�N
void type_chk(void);//�����`�F�b�N�֐�

void debug(void);

void counter(void);//�J�E���^

void main(){
	init();//������
	yokosen();//����������

	//�Q�[�����[�v
	while (1){
		
		//debug();

		d_hyouji();//�\��		
		key_chk();//�L�[�`�F�b�N			
		rakka();//�ړ�
		//line_chk();//������ł邩�ǂ����`�F�b�N
		counter();//�J�E���^		
	}
}

void init(){
	srand((unsigned)time(NULL));//���Ԃ��烉���_��
	type_chk();//�ŏ��́��̃^�C�v�������_���Ō���
	//sq.type = 0;//�f�t�H���l�p
	sq.x_S = 12;//���������W
	sq.y_S = 0;	//���������W
	sq.x = sq.x_S;
	sq.y = sq.y_S;
	sq.sd_S = 500;//�����X�s�[�h�����l
	sq.sd = sq.sd_S;//�����X�s�[�h�����l���

	sq.sw_S = 1000;//�X�s�[�h�������l
	sq.sw = sq.sw_S;//�X�s�[�h�����l���

	setCursor(0);//�J�[�\����\�����Ȃ�

	for (i = 0; i < 25; i += 2){
		for (j = 0; j < 23; j++){
			iti[i][j] = 0;
			sq.line[j] = 0;
			b_type[i][j] = 0;//�S����

		}
	}

	for (i = 0; i < 23; i++){
		w_cnt[i] = b_cnt[i] = 0;
	}



}

void yokosen(){
	locate(0, 23);//�Q�Q�s�ڂɉ���������
	for (i = 0; i<80; i++){
		printf("~");
	}
	for (i = 23; i < 25; i++){
		locate(25, i);
		puts("|");
	}
}


void d_hyouji(){
	locate(sq.x, sq.y);//�l�p����ʏ���ɕ\��
	if (sq.d_type == 0){
		puts("��\n");
	}
	else{
		puts("��");
	}	
}

void b_hyouji(int i,int j){

	locate(i, j + 1);//�ꏊ

	if (b_type[i][j + 1] == 0){
		puts("��\n");
	}
	else{
		puts("��");
	}

}


//���Ƀu���b�N�����邩�`�F�b�N


void rakka(){
	if (sq.sd <= 0){
		if (iti[sq.x][sq.y + 1] == 0 && sq.y < 22){
			locate(sq.x, sq.y);//�l�p����ʏ���ɕ\��
			puts("�@");//�󔒂�}��
			sq.y++;//�l�p�����ɗ��Ƃ�
		
			d_hyouji();//�Ăс��\��
		}
		else if (iti[sq.x][sq.y + 1] == 1 || sq.y == 22){
			
			iti[sq.x][sq.y] = 1;//�ʒu�t���O�I��	

			b_type[sq.x][sq.y] = sq.d_type;//�ςނƂ����������߂�

			//�u���b�N�̃^�C�v���ƂɃJ�E���g
			if (b_type[sq.x][sq.y] == 0){
				w_cnt[sq.y]++;//���{�{
			}
			else if (b_type[sq.x][sq.y] == 1){
				b_cnt[sq.y]++;//���{�{
			}
			
			d_hyouji();//�ςݏオ�����n�_�ŕ\�����Ă���
			line_chk();//���`�F�b�N
			sq.x = sq.x_S; sq.y = sq.y_S;//���W������
			type_chk();//���̔��������߂�

		}
		sq.sd = sq.sd_S;//�J�E���^������
	}
}







void key_chk(){
	if (sq.sw <= 0){
		//���ړ�
		if (GetKeyState(VK_NUMPAD4) < 0 || GetKeyState(VK_LEFT) < 0 && sq.x >= 2){

			if (iti[sq.x - 2][sq.y] == 0){
				sq.sw = sq.sw_S;
				locate(sq.x, sq.y);//�l�p������			
				printf("�@");
				sq.x -= 2;//����
				//locate(sq.x, sq.y);//�l�p����ʏ���ɕ\��
				//printf("��\n");
				d_hyouji();
			}

		}
		//�E�ړ�
		if (GetKeyState(VK_NUMPAD6) < 0 || GetKeyState(VK_RIGHT) < 0 && sq.x <= 23) {

			if (iti[sq.x + 2][sq.y] == 0){
				sq.sw = sq.sw_S;

				locate(sq.x, sq.y);//�l�p������

				printf("�@");
				sq.x += 2;

				//locate(sq.x, sq.y);//�l�p����ʏ���ɕ\��
				//printf("��\n");
				d_hyouji();
			}

		}
		if (GetKeyState(0x58) < 0){//���������ꂽ��I��

			puts("�I��\n");
			exit(0);//�I��


		}
	}

}

void line_chk(){
	for (i = 0; i < 25; i += 2){
		if (iti[i][sq.y] == 0){
			break;
		}
	}
	//if (i == 26){
	if (w_cnt[sq.y] == 13 || b_cnt[sq.y] == 13){
		sq.line[sq.y] = 1;//������ł���	

		//������
		for (i = 0; i < 25; i += 2){
			locate(i, sq.y);
			puts("�@");//����
			iti[i][sq.y] = 0;
			w_cnt[sq.y] = 0;
			b_cnt[sq.y] = 0;//�u���b�N�J�E���g�O
			
			//��̃u���b�N�̎�ނ𒲂ׂĈ�i���炷			
			for (j = 0; j < sq.y; j++){
				if (iti[i][j] == 1){
					iti_tmp[i][j] = 1;//�ꎞ�I�Ɉʒu�t���O���Ă�
					iti[i][j] = 0;//�{�t���O�I�t

					b_type_tmp[i][j] = b_type[i][j];//�ꎞ�I�Ƀ^�C�v������
					b_type[i][j] = -1;
					locate(i, j);//�ꏊ
					puts("�@");//����						
				}
			}
		}
		//}
		//���ꂼ��̑���������炷
		for (i = 0; i < 25; i += 2){
			for (j = 0; j < sq.y; j++){

				if (b_type_tmp[i][j] == 1){

					b_type[i][j + 1] = b_type_tmp[i][j];
					b_type_tmp[i][j] = -1;
				}

				if (iti_tmp[i][j] == 1){
					iti[i][j + 1] = 1;
					b_type[i][j + 1] = b_type_tmp[i][j];
					b_hyouji(i, j);//�u���b�N�\���֐�
					iti_tmp[i][j] = -1;
				}
			}

		}

		//�u���b�N�J�E���g����i���炷
		for (i = 0; i < sq.y; i++){

			w_cnt_tmp[i + 1] = w_cnt[i];
			w_cnt[i] = 0;

			b_cnt_tmp[i + 1] = b_cnt[i];
			b_cnt[i] = 0;
		}

		for (i = 0; i < sq.y+1; i++){
			w_cnt[i] = w_cnt_tmp[i];
			b_cnt[i] = b_cnt_tmp[i];
		}
		////////////////////////////////////




		//�ꎞ�t���O�ɑS��0������
		for (i = 0; i < 25; i += 2){
			for (j = 0; j < 23; j++){
				iti_tmp[i][j] = 0;
			}
		}


	}
}

void type_chk(){
	if (rand() % 2 == 0)
		sq.d_type = 0;//��
	else
		sq.d_type = 1;//���i�������j
}



void debug(){
	if (dbg_cnt <= 0){
		dbg_cnt = 10000;
		
		for (i = 0; i < 23; i++){
			locate(60, i);			
			printf("��%d,��%d",w_cnt[i], b_cnt[i]);
		}
	}

}



void counter(){
	sq.sd--;//�X�s�[�h�J�E���^�}�C�i�X	
	sq.sw--;//���X�s�[�h�J�E���^�}�C�i�X

	dbg_cnt--;

}

