#include<stdio.h>

//構造体定義
typedef struct{
	int x;
	int y;
}Enemy;

//プロトタイプ宣言

void move (Enemy* enemy);

void main (void)
{
	Enemy e={10,3};

	move(&e);
	printf("e=(%d,%d)\n",e.x,e.y);
}

void move(Enemy* enemy)
{
	enemy->x++;
	enemy->y++;

	if(enemy->x>70){
		enemy->x=0;
	}
	if(enemy->y>20){
		enemy->y=0;
	}
	
}