#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void main()
{
	char c;
	int t;
	for(t=0;;t++)
	{
		printf("%d�b�҂��܂���\r",t);
		_sleep(1000);
		if(_kbhit())
		{
			c=getch();
			if (c=='x')
			{	
				printf("���͂��ꂽ�����́A%c\n,c");
				printf("�����R�[�h�́A%x\n\n",c);
				break;
								
			}else if(c=='4')
			{
				printf("��\n");
				t=0;
			}else if(c=='6')
			{
				printf("�E\n");
				t=0;
			}else if (c==' ')
			{
				printf("��\n");
				t=0;
			}else
			{
				printf("���͂��ꂽ�����́A%c\n,c");
				printf("�����R�[�h�́A%x\n\n",c);
				t=0;
			}

		}
	}
}