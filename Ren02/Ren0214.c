#include<stdio.h>
#include<stdlib.h>

void main (void)
{

	char str0[7];
	int tax;

	printf("���z����͂��Ă��������F");
	
	gets(str0);
	
	tax = atoi(str0) * 5/100;
	printf("���͂��ꂽ���z�ɑ΂������ł�%d�~�ł��B\n",tax);
}