#include <stdio.h>

//プロトタイプ

void hai(int (*)[2]);


void main(void){


	int a[3][2] = {
		{ 1, 2 },
		{ 3, 4 },
		{ 5, 6 }
	};
	
	
	hai(a);



	printf("%d", a[0][0]);


	return;


}
void hai(int(*b)[2]){

	b[0][0]+=10;


}