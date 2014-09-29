#include <stdio.h>

//構造体定義

#define EnemySize 3

typedef struct{
	int x;
	int y;
}Enemy;

//プロトタイプ宣言
void move (Enemy enemy[]);

void main (void)
{
	int i;
	Enemy e[EnemySize]={ {10,3},{2,5},{3,7}    };

	move(e);



	for (i=0;i<sizeof(e)/8;i++){
		printf("e[%d]=(%2d,%2d)\n",i,e[i].x,e[i].y);
	}
}


void move (Enemy enemy[])
{
	int i;
	for (i=0;i<EnemySize;i++){
		enemy[i].x++;
		enemy[i].y++;
		if(enemy[i].x>70){enemy[i].x=0;}
		if(enemy[i].y>20){enemy[i].y=0;}
	}
}
