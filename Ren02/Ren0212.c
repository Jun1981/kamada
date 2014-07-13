#include<stdio.h>
#include<stdlib.h>

void main (void)
{

	char str0[7];
	char str1[7];
	int total = 0;
	printf ("一つ目の値を入力してください（６桁以内の数字）：");
	gets (str0);
	printf("２つ目の値を入力してください（６桁以内の数字）：");
	gets (str1);
	total = atoi (str0) + atoi (str1);
	printf("二つの値を加えると、%dです。",total);
}