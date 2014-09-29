#include<stdio.h>

int func (int v){
	int i=0;//ループ用
	int s=0;//合計
	for(i=0;i<v;i++){
		s+=i+1;
	}
	return s;
}

void main(void){
	printf("結果は、%d\n",func(10) );
}