#include <stdio.h>
#include <time.h>
#include"console.h"

void main(void){
	int i,j,k,l;//ƒ‹[ƒv
	int BN[20];//ƒuƒƒbƒN‚Ì”‚ğ“ü‚ê‚é
	int tmp;//ˆê

	int cmp=0,swp=0;//”äŠrAŒğŠ·

	//ƒ‰ƒ“ƒ_ƒ€‚Å‚P`‚R‚O‚Ì”š‚ğ¶¬‚µA‚Q‚OŒÂ‚Ì”z—ñ‚É“ü‚ê‚éB
	srand((unsigned)time(NULL));
	for(i=0;i<20;i++){
		BN[i]=rand()%30+1;
	}

	//‰Šú•\¦//////////////////////////////////////////////////////////////////////////
	printf(" [##] data | compare = %d swap = %d\n",cmp,swp);
	printf(" -------------------------------------------------------------------------\n");
	for(i=0;i<20;i++){
		printf(" [%02d] %2d | ",i,BN[i]);
		for(k=0;k<BN[i];k++){
			printf("¡");
		}
		printf("\n");			
	}
	/////////////////////////////////////////////////////////////////////////////////////


	for(l=0;l<20;l++){
		for(j=0;j<20-1;j++){

			cmp++;//”äŠr{‚P
			if(BN[j]>BN[j+1]){

				swp++;//ŒğŠ·{‚P

				tmp =BN[j];
				BN[j]=BN[j+1];
				BN[j+1]=tmp;
			}

			clear();
			printf(" [##] data | compare = %d swap = %d\n",cmp,swp);
			printf(" -------------------------------------------------------------------------\n");


			for(i=0;i<20;i++){				
				if(i==j || i==j+1){
					color(FOREGROUND_GREEN);
				}else{
					color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				}

				printf(" [%02d] %2d | ",i,BN[i]);
				for(k=0;k<BN[i];k++){printf("¡");}
				printf("\n");		
				//Sleep(10);
			}
			//Sleep(100);
		}

	}
}





















