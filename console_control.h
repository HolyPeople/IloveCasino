#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <WinDef.h>


enum color_info
{
	BLACK,			// 검은색
	BLUE,			// 파란색
	GREEN,			// 녹색
	CYAN,			// 하늘색
	RED,			// 빨간색
	MAGENTA,		// 분홍색
	BROWN,			// 갈색
	LIGHTGRAY,		// 연회색
	DARKGRAY,		// 진회색
	LIGHTBLUE,		// 연파랑
	LIGHTGREEN,		// 연두색
	LIGHTCYAN,		// 연하늘색
	LIGHTRED,		// 연빨강
	LIGHTMAGENTA,	// 연분홍
	YELLOW,			// 노란
	WHITE,			// 흰색
};

enum cursor_info
{
	NOCURSOR,       // 커서 사라지기
	SOLIDCURSOR,    // 큰 커서
	NORMALCURSOR,   // 일반 커서
};
//------------------------------------------//

//------------------------------------------
// key

#define ESC			27
#define BS			0xe
#define TAB			0xf
#define ENTER		13
#define SPACE		0x20
#define HOME		0x47
#define END			0x4f
#define PGUP		0x49
#define PGDN		0x51
#define INS			0x52
#define DEL			0x53

#define UP		0x48
#define DOWN		0x50
#define LEFT		0x4b
#define RIGHT		0x4d
#define LSHIFT		0x2a
#define RSHIFT		0x36
#define CTRL		0x1d
#define ALT			0x38

#define F1			0x3b
#define F2			0x3c
#define F3			0x3d
#define F4			0x3e
#define F5			0x3f
#define F6			0x40
#define F7			0x41
#define F8			0x42
#define F9			0x43
#define F10			0x44
#define F11			0x57
#define F12			0x58
//-----------------------------------------------//

extern void gotoxy(int, int);                       // 커서를 x,y좌표로 이동
extern int wherex();                                // 커서의 x 좌표를 조사
extern int wherey();                                // 커서의 y좌표를 조사

extern void setcursortype(int);	                    // 커서 숨기기

extern BOOL gettext(int, int, int, int, void *);    // 영역 저장하기
extern BOOL puttext(int, int, int, int, void *);    // 저장한 영역 되돌리기

extern int getscr(int, int);                        // x, y 좌표 지점의 아스키코드를 조사
extern int getattr(int, int);                       // x, y 좌표 지점의 속성(색상)을 조사

extern int getcolor(int, int);	                    // 글자 색상 설정 getcolor(글자색);
extern int getbkcolor(int, int);                    // 배경 색상 설정 getcolor(배경색);

extern void setcolor(int);                          // 글자 색상 설정 setcolor(글자색);
extern void setbkcolor(int);                        // 배경 색상 설정 setbkcolor(배경색);

extern void textattr(int);	                        // 색상 설정 : textattr(글자색|배경색<<4)

extern int getkey();

extern void setTextColor(int);

extern inline void resetTextColor();
extern inline void resetBgColor();
extern inline void resetColor() ;