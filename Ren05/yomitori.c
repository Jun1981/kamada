#include<stdio.h>
#include<stdlib.h>//atoi
#include<string.h>//strlen
#pragma warning(disable:4996)

//‚ ‚é”ÍˆÍ(Å¬‚OAÅ‘å‚Xj‚ÌˆêŒ…‚Ì®”‚ª“ü—Í‚³‚ê‚½‚Æ‚«‚Í‚»‚Ì’l‚ð•Ô‚·B
//‚»‚êˆÈŠO‚Ì”Žš‚â•¶Žš—ñ‚ª“ü—Í‚³‚ê‚½‚Æ‚«‚Í‚P‚O‚ð•Ô‚·

//int yomi(int x1, int x2);

int yomi(int x1, int x2)
{
	char a[100];
	int b;
			
	scanf("%s",&a);

	//fgets(a, sizeof(a), stdin);
	b = strlen(a);

	if (b == 1)
	{

		b = atoi(a);
		if (b >= x1 && b <= x2)
		{
			return (b);
		}

	}

	return 10;
		
}