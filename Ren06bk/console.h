#include <stdio.h>
#include <conio.h>
#include <windows.h>

#if !defined( __CONSOLE_H__ )
#define	__CONSOLE_H__

void	locate( int x, int y );			/* 座標指定 */
void	color( WORD 	wAttributes );	/* 色指定 */
void	setCursor( int 	sw );			/* カーソル表示/非表示切り替え */
void 	clear( void );					/* 画面消去 */

#endif
