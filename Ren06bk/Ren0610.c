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

//struct shikaku{
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
	int d_type_N;//���̃u���b�N�p

	
//}sq;

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

void next(void);//���̃u���b�N�����߂�
void next_show(void);//�E��̃u���b�N�\��






void main(){
	init();//������
	yokosen();//����������

	next_show();//�E��Ɏ��̃u���b�N�\��

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
	//type_chk();//�ŏ��́��̃^�C�v�������_���Ō���
	//sq.type = 0;//�f�t�H���l�p
	x_S = 12;//���������W
	y_S = 0;	//���������W
	x = x_S;
	y = y_S;
	sd_S = 500;//�����X�s�[�h�����l
	sd = sd_S;//�����X�s�[�h�����l���

	sw_S = 500;//�X�s�[�h�������l
	sw = sw_S;//�X�s�[�h�����l���

	setCursor(0);//�J�[�\����\�����Ȃ�

	for (i = 0; i < 25; i += 2){
		for (j = 0; j < 23; j++){
			iti[i][j] = 0;
			line[j] = 0;
			b_type[i][j] = 0;//�S����

		}
	}

	for (i = 0; i < 23; i++){
		w_cnt[i] = b_cnt[i] = 0;
	}

	//�ŏ��̃u���b�N�^�C�v����
	if (rand() % 2 == 0){
		d_type_N = 0;//��
	}
	else{
		d_type_N = 1;//���i�������j
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
	
	locate(x, y);//�l�p����ʏ���ɕ\��
	if (d_type == 0){
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
	if (sd <= 0){
		if (iti[x][y + 1] == 0 && y < 22){
			locate(x, y);//�l�p����ʏ���ɕ\��
			puts("�@");//�󔒂�}��
			y++;//�l�p�����ɗ��Ƃ�
		
			d_hyouji();//�Ăс��\��
		}
		else if (iti[x][y + 1] == 1 || y == 22){
			
			iti[x][y] = 1;//�ʒu�t���O�I��	

			b_type[x][y] = d_type;//�ςނƂ����������߂�

			//�u���b�N�̃^�C�v���ƂɃJ�E���g
			if (b_type[x][y] == 0){
				w_cnt[y]++;//���{�{
			}
			else if (b_type[x][y] == 1){
				b_cnt[y]++;//���{�{
			}
			
			d_hyouji();//�ςݏオ�����n�_�ŕ\�����Ă���
			line_chk();//���`�F�b�N
			x = x_S; y = y_S;//���W������
			//type_chk();//���̔��������߂�

			d_type=d_type_N;//���̃u���b�N�^�C�v��K�p
			next();//���̃u���b�N�����߂�
			next_show();//�E��Ɏ��̃u���b�N�\��

		}
		sd = sd_S;//�J�E���^������
	}
}




void next(){
	if (rand() % 2 == 0){
		d_type_N = 0;//��
	}
	else{
		d_type_N = 1;//���i�������j
	}

	
}

void next_show(){	
	locate(60,3);
	if(d_type_N==0){
		
		puts("���@��");
	}else{
		
		puts("���@��");
	}


}






void key_chk(){
	if (sw <= 0){
		//���ړ�
		if (GetKeyState(VK_NUMPAD4) < 0 || GetKeyState(VK_LEFT) < 0 && x >= 2){

			if (iti[x - 2][y] == 0){
				sw = sw_S;
				locate(x, y);//�l�p������			
				printf("�@");
				x -= 2;//����
				//locate(x, y);//�l�p����ʏ���ɕ\��
				//printf("��\n");
				d_hyouji();
			}

		}
		//�E�ړ�
		if (GetKeyState(VK_NUMPAD6) < 0 || GetKeyState(VK_RIGHT) < 0 && x <= 23) {

			if (iti[x + 2][y] == 0){
				sw = sw_S;

				locate(x, y);//�l�p������

				printf("�@");
				x += 2;

				//locate(x, y);//�l�p����ʏ���ɕ\��
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
		if (iti[i][y] == 0){
			break;
		}
	}
	//if (i == 26){
	if (w_cnt[y] == 13 || b_cnt[y] == 13){
		line[y] = 1;//������ł���	

		//������
		for (i = 0; i < 25; i += 2){
			locate(i, y);
			puts("�@");//����
			iti[i][y] = 0;
			w_cnt[y] = 0;
			b_cnt[y] = 0;//�u���b�N�J�E���g�O
			
			//��̃u���b�N�̎�ނ𒲂ׂĈ�i���炷			
			for (j = 0; j < y; j++){
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
			for (j = 0; j < y; j++){

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
		for (i = 0; i < y; i++){

			w_cnt_tmp[i + 1] = w_cnt[i];
			w_cnt[i] = 0;

			b_cnt_tmp[i + 1] = b_cnt[i];
			b_cnt[i] = 0;
		}

		for (i = 0; i < y+1; i++){
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



void debug(){
	if (dbg_cnt <= 0){
		dbg_cnt = 10000;
		
		for (i = 0; i < 23; i++){
			locate(60, i);			
			printf("��%d,��%d",w_cnt[i], b_cnt[i]);
		}
	}

}

//
//void type_chk(){
//	if (rand() % 2 == 0){
//		d_type = 0;//��
//	}
//	else{
//		d_type = 1;//���i�������j
//	}
//	
//}

void counter(){
	sd--;//�X�s�[�h�J�E���^�}�C�i�X	
	sw--;//���X�s�[�h�J�E���^�}�C�i�X

	dbg_cnt--;

}

