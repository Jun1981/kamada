#include <stdio.h>
void main()
{
	int i;

	FILE* fp=fopen("E:/kamada/c/Ren07/Ren0702.c","r");
	char buf[512];	

	for(i=0;i<3;i++){
	fgets(buf,512,fp);
	printf("%ds–Ú‚ÍA%s",i+1,buf);	
	}
	
	fclose(fp);
	
}