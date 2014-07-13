#include<stdio.h>
#include<stdlib.h>

void main (void)
{

	char str0[7];
	int tax;

	printf("‹àŠz‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢F");
	
	gets(str0);
	
	tax = atoi(str0) * 5/100;
	printf("“ü—Í‚³‚ê‚½‹àŠz‚É‘Î‚·‚éÁ”ïÅ‚Í%d‰~‚Å‚·B\n",tax);
}