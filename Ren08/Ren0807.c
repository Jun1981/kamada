#include<stdio.h>

void func (int** a ,int** b){

	int **s=a;
	a=b;
	b=s;


}

void main (void){
	int v0=10;
	int v1=20;
	int* p0=&v0;
	int* p1=&v1;

	func(&p0,&p1);
	printf("v0=%d,v1=%d\n",v0,v1);
	printf("p0=%d,p1=%d\n",*p0,*p1);
}