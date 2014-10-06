#include <console.h>
/*
** ���W�w��
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
** �F�w��
**	wAttributes : FOREGROUND_RED, FOREGROUND_GREEN,
**			FOREGROUND_BLUE �̑g�ݍ��킹���w��
*/
void	color( WORD 	wAttributes )
{
	SetConsoleTextAttribute(
			GetStdHandle(STD_OUTPUT_HANDLE),
			wAttributes);
}

/*
** �J�[�\���\��/��\���؂�ւ�
**		sw == 0 : �J�[�\��OFF
**		sw != 0 : �J�[�\��ON
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
** ��ʏ���
*/
void 	clear( void )
{
	system ( "cls" );
}