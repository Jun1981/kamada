#include <stdio.h>

void main()
{
	FILE* fp=fopen("E:/kamada/c/Ren07/Ren0701.c","r");
	char buf[512];
	fgets(buf,512,fp);
	printf("‚Ps–Ú‚ÍA%s",buf);
	fclose(fp);
	
}