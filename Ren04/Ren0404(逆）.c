#include<stdio.h>

void main(void)
{

	int i,j,k=0,l,m=9;

	for (i=0;i<5;i++)
	{
		for(j=0;j<k;j++)
		{
			printf(" ");
		}
	
		k=k+1;

		for(l=0;l<m;l++)
		{
			printf("*");
		}

		m=m-2;
		printf("\n");
	}
}