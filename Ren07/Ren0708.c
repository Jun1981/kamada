#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#pragma warning(disable:4996)


int yomi(int,int);//ˆêŒ…‚Ì”š“ü—Í‘Ò‚¿
int y;//“ü—Í‚µ‚½”š‚ğ“ü‚ê‚é•Ï”

void main(){

	FILE *fp=fopen("E:/kamada/DATA/2.txt","r");

	int i,j;//ƒ‹[ƒv
	char buf[10][512];
	char buf_tmp[10][512];

	for(i=0;i<2;i++){
		fgets(buf[i],512,fp);
	}
	while(fgets(buf[2],512,fp)!=NULL){
		printf("%s",buf[0]);
		for(i=0;i<2;i++){			
			strcpy(buf[i],buf[i+1]);
		}
	}
	for(j=0;j<2;j++){
		for(i=0;i<512;i++){

			if(buf[j][i]==','){

				strncpy(buf_tmp[j],buf[j],i);
				buf_tmp[j][i]='\0';
			}

		}
		printf("%s",buf_tmp[j]);


	}

	printf("\n\n");



	printf("”š‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n:");
	y=yomi(0,9);
	

	while(1){
		if(y>=10){
			printf("‚P`‚X‚Ü‚Å‚Ì”š‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n:");
			y=yomi(0,9);
		}else if(y>=0 && y<=9){
			break;
		}
	}




	fclose(fp);
}



//‚ ‚é”ÍˆÍ(Å¬‚OAÅ‘å‚Xj‚ÌˆêŒ…‚Ì®”‚ª“ü—Í‚³‚ê‚½‚Æ‚«‚Í‚»‚Ì’l‚ğ•Ô‚·B
//‚»‚êˆÈŠO‚Ì”š‚â•¶š—ñ‚ª“ü—Í‚³‚ê‚½‚Æ‚«‚Í‚P‚O‚ğ•Ô‚·

//int yomi(int x1, int x2);

int yomi(int x1, int x2)
{
	char a[20];
	int b;

	scanf("%s",&a);
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