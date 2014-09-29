#include<stdio.h>

//定数定義
#define EnemySize 3//Enemy構造体配列の要素数
//構造体定義

typedef struct{
	int x;
	int y;
}Enemy;


//プロトタイプ宣言
void move(Enemy enemy[]);

void main (void)
{
	int i;
	Enemy e[EnemySize]
	={  {10,3},{2,5},{3,7}     };


	move(e);
	for (i=0;i<EnemySize; i++){
		printf("e[%d]=(%2d,%2d)\n",i,e[i].x,e[i].y);
	}
}

void move (Enemy enemy[])
{
	Enemy* p;
	for (p=enemy;p-enemy<EnemySize;p++){
		p->x++;
		p->y++;
		if(p->x >70){p->x=0;}
        if(p->y >20){p->y=0;}

	}
}