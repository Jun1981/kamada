#include<stdio.h>
#include<string.h>



void main(){
	
	char *s="abcde‚†‚³‚Ó‚Ÿ‚“,3";

		printf("%p\n",s);
	printf("%p\n",(s+1));


	printf("%c\n",*s);
	printf("%c\n",*(s+1));

	*(s+1)='z';

	printf("%c\n",*(s+1));

	

	printf("%s\n",s);
}
