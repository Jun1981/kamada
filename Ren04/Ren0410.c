#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void main()
{
	char c;
	int t;
	for(t=0;;t++)
	{
		printf("%d秒待ちました\r",t);
		_sleep(1000);
		if(_kbhit())
		{
			c=getch();
			if (c=='x')
			{	
				printf("入力された文字は、%c\n,c");
				printf("文字コードは、%x\n\n",c);
				break;
								
			}else if(c=='4')
			{
				printf("左\n");
				t=0;
			}else if(c=='6')
			{
				printf("右\n");
				t=0;
			}else if (c==' ')
			{
				printf("空白\n");
				t=0;
			}else
			{
				printf("入力された文字は、%c\n,c");
				printf("文字コードは、%x\n\n",c);
				t=0;
			}

		}
	}
}