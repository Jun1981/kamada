#include <stdio.h>
#include <conio.h>
#include <windows.h>

#if !defined( __CONSOLE_H__ )
#define	__CONSOLE_H__

void	locate( int x, int y );			/* ���W�w�� */
void	color( WORD 	wAttributes );	/* �F�w�� */
void	setCursor( int 	sw );			/* �J�[�\���\��/��\���؂�ւ� */
void 	clear( void );					/* ��ʏ��� */

#endif
