#include<stdio.h>

int func (int v){
	int i=0;//���[�v�p
	int s=0;//���v
	for(i=0;i<v;i++){
		s+=i+1;
	}
	return s;
}

void main(void){
	printf("���ʂ́A%d\n",func(10) );
}