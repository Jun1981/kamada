#include<stdio.h>
#include<stdlib.h>

void main (void)
{

	char str0[7];
	char str1[7];
	int total = 0;
	printf ("��ڂ̒l����͂��Ă��������i�U���ȓ��̐����j�F");
	gets (str0);
	printf("�Q�ڂ̒l����͂��Ă��������i�U���ȓ��̐����j�F");
	gets (str1);
	total = atoi (str0) + atoi (str1);
	printf("��̒l��������ƁA%d�ł��B",total);
}