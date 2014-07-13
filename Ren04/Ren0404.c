#include<stdio.h>

void main(void)
{

	int i,j,k=4,l,m=0;

	for (i=0;i<5;i++)
	{
		for(j=0;j<k;j++)
		{
			printf(" ");
		}
	
		k=k-1;

		for(l=0;l<m+1;l++)
		{
			printf("*");
		}

		m+=2;
		printf("\n");
	}
}