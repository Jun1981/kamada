#include<stdio.h>


typedef struct{

	int x0;
	int y0;
	int x1;
	int y1;
}Region;

int* calcArea (Region* region){

	int  width=region->x1 -region->x0;
	int height=region->y1-region->y0;
	int area=width *height;
	int *parea =&area;
	if(area<0){
		area *=(-1);
	}
	return parea;
}

void main (void){
	Region rect={10,30,40,100};
	int  area = *calcArea(&rect);
	printf("–ÊÏ‚ÍA");
	printf("%d‚Å‚·B",area);
}