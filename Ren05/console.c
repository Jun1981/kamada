#include <console.h>
/*
** 座標指定
*/
void	locate( int x, int y )
{
	COORD 		dwPos;
	dwPos.X = (SHORT)x;
	dwPos.Y = (SHORT)y;
	SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE),
			dwPos );
}

/*
** 色指定
**	wAttributes : FOREGROUND_RED, FOREGROUND_GREEN,
**			FOREGROUND_BLUE の組み合わせを指定
*/
void	color( WORD 	wAttributes )
{
	SetConsoleTextAttribute(
			GetStdHandle(STD_OUTPUT_HANDLE),
			wAttributes);
}

/*
** カーソル表示/非表示切り替え
**		sw == 0 : カーソルOFF
**		sw != 0 : カーソルON
*/
void	setCursor( int 	sw )
{
	CONSOLE_CURSOR_INFO	info;
	GetConsoleCursorInfo (
			GetStdHandle ( STD_OUTPUT_HANDLE ),
			&info );
	if ( sw != 0 ){
		info.bVisible = TRUE;
	} else {
		info.bVisible = FALSE;
	}
	SetConsoleCursorInfo (
			GetStdHandle ( STD_OUTPUT_HANDLE ),
			&info );
}

/*
** 画面消去
*/
void 	clear( void )
{
	system ( "cls" );
}