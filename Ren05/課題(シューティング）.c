#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include "console.h"

#pragma warning(disable:4996)

//extern   int yomi(int x1, int x2);

//����͈�(�ŏ��O�A�ő�X�j�̈ꌅ�̐��������͂��ꂽ�Ƃ��͂��̒l��Ԃ��B
//����ȊO�̐����╶���񂪓��͂��ꂽ�Ƃ��͂P�O��Ԃ�


int yomi(int x1, int x2){
	char a[100];
	int b;

	scanf("%s", &a);

	//fgets(a, sizeof(a), stdin);
	b = strlen(a);

	if (b == 1){

		b = atoi(a);
		if (b >= x1 && b <= x2){
			return (b);
		}

	}

	return 10;

}


void main(){

	int x[10], y[10];//�I�̍��W
	int x1 = 40;//���@�̂����W
	int tama[20] = { 0 };//�e���o�Ă��邩�ǂ����̔���
	int x2[20], y2[20];//�e�̍��W
	int atari[20] = { 0 };//�e���I�ɓ����������ǂ���
	int muki[10];//�e�̌���
	unsigned int ten = 0;//�X�R�A

	unsigned int limit = 50;//���̐����𒴂�����Q�[���I��

	int d[10], e[10];//���Ƃ������̐i�ޒl
	int s = 0;//�ŏ��́i�O�C�O�j���W�𖳎����邽�߂̃X�C�b�`
	//char c;//�L�[�󂯎��p
	int kazu = 0;//�e��
	int i, j;//���[�v�p
	int f = 0, g = 0;//���[�v���I������Ƃ��̉񐔂�����ϐ�
	int ty[10];//�I�̂��ꂼ��̋���������z��

	int speed_orig[10];//�I�̃X�s�[�h�����I���W�i��
	int speed[10];//�I�̃X�s�[�h����
	int count[2] = { 0 };//�L�[�`�F�b�N�̕p�x����

	int matocount[10] = { 0 };//�I�ɒe������������

	clock_t start, end = 0;//�^�C�}�[

	int t = 1;//���v���C�p

	int timer = 0;//�^�C�}�[�ۑ��p

	int k;//�ǂݎ��p

	int o_count = 1000;//�I�[�v�j���O�_�ŗp

	int time_limit = 30;//��������
	int n_time;//�c�莞��
	int e_time;//�o�ߎ���

	int z = 1;

	//�I�[�v�j���O���

	printf("\n");
	printf("	����������                  ��������      ������������������������\n");
	printf("	����������                  ��������      ������������������������\n");
	printf("	������������������������������������  ����      ������������������\n");
	printf("	������������������������������������������    ������    ����\n");
	printf("	��������������������        ������  ����������������    ���� \n");
	printf("	��������������������        ������    ������������      ���� \n");


	printf("\n\n\n");
	//locate(30,10);
	printf("               ������@\n");
	//locate(24,11);
	printf("        ���@�̑���   �F���@���@\n");
	//locate(24,12);
	printf("        �e���o��     �FSpace\n");
	printf("\n\n\n");

	printf("�@�@�@�@�@�@  �G�L�����Љ�\n");
	printf("�@�@�@�@�@�R:   �R�_\n");
	printf("�@�@�@�@�@�U: �@�U�_\n");
	printf("�@�@�@�@�@�I:�@ �P�O�_�i�Q�񌂂āj\n\n");

	printf("     ���R�O�b�ȓ��T�O�_�ȏ�ŃN���A");


	//�h�X�y�[�X�L�[�������Ă��������h��_�ł�����
	setCursor(0);

	while (1){
		if (o_count <= 1000 && o_count>500 ){
			o_count--;
			color(FOREGROUND_GREEN);
			locate(40, 20);
			printf("   �X�y�[�X�L�[�������Ă�������");

		}
		else if (o_count <= 500 && o_count >0){
			o_count--;
			color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			locate(40, 20);
			printf("   �X�y�[�X�L�[�������Ă�������");

		}else
			if (o_count <= 0){
				o_count = 1000;
			}

			if (GetKeyState(VK_SPACE) <0){
				color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				clear();
				break;

			}

	}



Label://while�E�o�p
	//�Q�[���X�^�[�g

	while (t){

		for (i = 0; i < 10; i++){
			ty[i] = rand() % 3 + 1;//�G�̋����������_���Ō��߂�
			if (ty[i] == 1){
				speed_orig[i] = 10;
			}
			else if (ty[i] == 2){
				speed_orig[i] = 4;
			}
			else if (ty[i] == 3){
				speed_orig[i] = 2;
			}
			speed[i] = speed_orig[i];
		}


		for (i = 0; i < 20; i++){
			x2[i] = -100;
			y2[i] = -100;

		}

		//�e�̏����ʒu�ƌ����������_���Ō��߂�
		srand((unsigned)time(NULL));

		for (i = 0; i < 10; i++){
			x[i] = rand() % 66 + 2;
			y[i] = rand() % 18 + 2;
			muki[i] = rand() % 4 + 1;
			switch (muki[i]){
			case 1:
				d[i] = 1;
				e[i] = 1;
				break;
			case 2:
				d[i] = 1;
				e[i] = -1;
				break;
			case 3:
				d[i] = -1;
				e[i] = -1;
				break;
			case 4:
				d[i] = -1;
				e[i] = -1;
				break;
			}

		}


		start = clock();//�^�C�}�[�X�^�[�g

		while (1){
			//�_���\��
			locate(70, 2);
			printf("���_:%d�_", ten);

			//�^�C���\��
			e_time = clock();//�^�C�}�[
			n_time = time_limit - (e_time - start) / 1000;
			locate(70, 4);
			printf("�c��%d�b", n_time);
			setCursor(0);


			//�I�̕\��

			for (i = 0; i < 10; i++){
				locate(x[i], y[i]);
				if (ty[i] == 1){

					printf("3");

				}
				else if (ty[i] == 2){

					printf("6");
				}
				else if (ty[i] == 3 && matocount[i] == 0){

					printf("�I");
				}
				else if (ty[i] == 3 && matocount[i] == 1){

					printf("10");
				}

				locate(x[i], y[i]);
				printf("�@");


				if (speed[i] == 0){
					x[i] += d[i];
					y[i] += e[i];
					speed[i] = speed_orig[i];
				}
				else{
					speed[i]--;
				}




				locate(x[i], y[i]);
				if (ty[i] == 1){

					printf("3");

				}
				else if (ty[i] == 2){

					printf("6");
				}
				else if (ty[i] == 3 && matocount[i] == 0){

					printf("�I");
				}
				else if (ty[i] == 3 && matocount[i] == 1){
					printf("10");
				}

			}




			locate(x1, 21);
			printf("��");

			//�e�̕\��
			for (i = 0; i<20; i++){
				if (tama[i] == 1 && atari[i] == 0){
					if (y2[i]>0){
						locate(x2[i], y2[i]);
						printf(" ");
						y2[i]--;
						locate(x2[i], y2[i]);
						printf("��");
					}
					else{
						locate(x2[i], y2[i]);
						printf(" ");
						kazu--;
						tama[i] = 0;

					}
				}
			}

			//�e�ƓI�̍��W����v������

			for (i = 0; i < 20; i++){
				for (j = 0; j < 10; j++){
					if (tama[i] == 1 && atari[i] == 0){

						if (ty[j] == 1 && x2[i] == x[j] && y2[i] == y[j]){
							atari[i] = 1;
							ten += 3;
							f = i;
							g = j;
							break;
						}
						else if (ty[j] == 3 && x2[i] >= x[j] - 1 && x2[i] <= x[j] + 1 && y2[i] == y[j]){
							if (matocount[j] == 1){
								atari[i] = 1;
								ten += 10;
								f = i;
								g = j;
								matocount[j] = 0;
								break;
							}
							else{
								tama[i] = 0;
								matocount[j]++;
							}
						}
						else if (ty[j] == 2 && x2[i] == x[j] && y2[i] == y[j]){
							atari[i] = 1;
							ten += 6;
							f = i;
							g = j;
							break;

						}

					}
				}
			}

			//�e�������������̓���
			if (atari[f] == 1){
				kazu = 0;
				for (i = 0; i < 10; i++){
					locate(x[i], y[i]);
					printf("�@");
				}
				for (i = 0; i < 20; i++){
					tama[i] = 0;
					atari[i] = 0;
					locate(x2[i], y2[i]);
					printf("�@");
					x2[i] = -100; y2[i] = -100;

				}

				if (ty[g] == 1){
					locate(35, 10);
					printf("Hit! +3");
					Sleep(1000);
					locate(35, 10);
					printf("       ");
				}
				else if (ty[g] == 3){
					locate(35, 10);					printf("Hit! +10");
					Sleep(1000);
					locate(35, 10);
					printf("        ");
				}
				else if (ty[g] == 2){
					locate(35, 10);
					printf("Hit! +6");
					Sleep(1000);
					locate(35, 10);
					printf("       ");
				}



				for (i = 0; i < 10; i++){//�P�O�̓�����񐔂�߂�
					matocount[i] = 0;
				}
				for (i = 0; i < 10; i++){//�����_���ňʒu�����߂�
					x[i] = rand() % 65 + 2;
					y[i] = rand() % 16 + 2;

					muki[i] = rand() % 4 + 1;
					switch (muki[i]){
					case 1:
						d[i] = 1;
						e[i] = 1;
						break;
					case 2:
						d[i] = 1;
						e[i] = -1;
						break;
					case 3:
						d[i] = -1;
						e[i] = -1;
						break;
					case 4:
						d[i] = -1;
						e[i] = -1;
						break;
					}

				}

			}






			//�L�[��t
			if (ten < limit){

				if (GetKeyState(VK_SPACE) < 0){
					for (i = 0; i < 20; i++){
						if (tama[i] == 0 && atari[i] == 0 && kazu < 20 && count[0] == 0){
							x2[i] = x1;
							y2[i] = 21;
							tama[i] = 1;
							kazu++;
							count[0] = 10;
							break;
						}
					}
				}
				if ((GetKeyState(VK_NUMPAD1) < 0 || GetKeyState(VK_LEFT) < 0) && x1 >= 1 && count[1] == 0){
					x1--;
					count[1] = 3;

				}
				else
					if ((GetKeyState(VK_NUMPAD3) < 0 || GetKeyState(VK_RIGHT) < 0) && x1 <= 67 && count[1] == 0){
						x1++;
						count[1] = 3;
					}
					else
						if (GetKeyState(0x58) < 0){
							clear();
							locate(40, 10);
							printf("�I��\n\n\n\n");
							exit(0);
							//t = 0;
							break;

						}

			}

			//�G����ʒ[�ɍs�������̓���
			for (i = 0; i < 10; i++){
				if (x[i] <= 0 && s == 1){
					d[i] = ~d[i] + 1;
				}
				else if (x[i] >= 68){
					d[i] = ~d[i] + 1;
				}


				if (y[i] <= 0 && s == 1){
					e[i] = ~e[i] + 1;
				}
				else if (y[i] >= 20){
					e[i] = ~e[i] + 1;
				}
			}


			//�_�������ɒB������

			if (ten >= limit || n_time == 0){
				end = clock();
				Sleep(100);

				clear();
				if (n_time > 0){

					printf("\n\n");
					printf("�@�@�@�@ �@�@�@�@�@�@ �@ /   \n");
					Sleep(100);
					printf("�@�@�]�_r�,   i� '�i.�,  !   \n");
					Sleep(100);
					printf("�@�@�@�@�P�@�@!i �R �    i  \n");
					Sleep(100);
					printf("�@�@�@�@ �@   .!i��@�@   |  \n");
					Sleep(100);
					printf("�@�@�@�@   �._�Q_)�j'   /   \n");
					Sleep(100);
					printf("�@�@�@�@�@ �Q.i'I.._   /  \n");
					Sleep(100);
					printf("�@�@�@�@ -�L=�F�=,`�@ /�[�\�]\n");
					Sleep(100);
					printf("�@�@�@�@�@�@�@ �P�@  /       \n");
					Sleep(1000);
					printf("\n\n");
					printf("        ���߂łƂ��I!\n\n");


					Sleep(1000);



				}
				else{
					printf("\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("	�c�O�I���Ԑ؂�I\n\n");

				}




				while (1){
					printf("%	�X�R�A:%d�_\n", ten);
					Sleep(100);
					printf("	�v���C���ԁF%d�b\n\n", (end - start) / 1000);
					Sleep(100);
					printf("	1:�I��\n	2:������x\n");
					Sleep(100);
					printf("	:");

					while (kbhit()){
						getch();
					}

					k = yomi(1, 2);//�P�`�Q�܂ł̐�����ǂݎ��B��͒e��
					//scanf("%d", &k);

					if (k == 1){
						system("cls");

						t = 0;
						exit(0);

					}
					else if (k == 2){
						system("cls");
						clear();


						for (i = 0; i < 10; i++){//�P�O�̓�����񐔂�߂�
							matocount[i] = 0;
						}

						n_time = time_limit;
						ten = 0;
						goto Label;

					}
					else{
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n\n\n\n");
					}

				}

			}


			//�ŏ�����
			if (s == 0){
				s = 1;
			}

			//�X�s�[�h����
			for (i = 0; i<2; i++){
				if (count[i]>0){
					count[i]--;

				}
			}

		}
	}
}
