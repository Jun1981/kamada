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
								
			}else
			{
				printf("���͂��ꂽ�����́A%c\n,c");
				printf("�����R�[�h�́A%x\n\n",c);
				t=0;
			}

		}
	}
}