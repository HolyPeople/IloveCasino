#include "console_control.h"

// 
// ----------------------------------------------------------------------------------------------------
// 함수 정의 시작  : 역시 화일을 구분하여 사용하도록 하세요 


void gotoxy(int x, int y)		// 커서를 x,y좌표로 이동
{
	COORD pos = { x, y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int wherex()					// 커서의 x 좌표를 조사
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);

	return BufInfo.dwCursorPosition.X;
}

int wherey()					// 커서의 y좌표를 조사
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);

	return BufInfo.dwCursorPosition.Y;
}

void setcursortype(int cur_t)	// 커서 숨기기
{
	CONSOLE_CURSOR_INFO ccInfo;

	if (cur_t == 0)		// NOCURSOR
	{
		ccInfo.dwSize = 20;
		ccInfo.bVisible = FALSE;
	}
	else if (cur_t == 1)	// SOLIDCURSOR
	{
		ccInfo.dwSize = 100;
		ccInfo.bVisible = TRUE;
	}
	else				// NORMALCURSOR
	{
		ccInfo.dwSize = 20;
		ccInfo.bVisible = TRUE;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ccInfo);
}

BOOL gettext(int left, int top, int right, int bottom, void *destin)    // 영역 저장하기
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordBufSize = { right - left + 1, bottom - top + 1 };
	COORD coordBufCoord = { 0, 0 };
	SMALL_RECT region = { left, top, right, bottom };

	return ReadConsoleOutput(hConsole, destin, coordBufSize, coordBufCoord, &region);
}

BOOL puttext(int left, int top, int right, int bottom, void *source)    // 저장한 영역 되돌리기
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordBufSize = { right - left + 1, bottom - top + 1 };
	COORD coordBufCoord = { 0, 0 };
	SMALL_RECT region = { left, top, right, bottom };

	return WriteConsoleOutput(hConsole, source, coordBufSize, coordBufCoord, &region);
}

int getscr(int x, int y)    // x, y 좌표 지점의 아스키코드를 조사
{
	CHAR_INFO dest;

	gettext(x, y, x, y, &dest);

	return dest.Char.AsciiChar;
}

int getattr(int x, int y)   // x, y 좌표 지점의 속성(색상)을 조사
{
	CHAR_INFO dest;

	gettext(x, y, x, y, &dest);

	return dest.Attributes;
}

int getcolor(int x, int y)	// 글자 색상 설정 getcolor(글자색);
{
	short   attr;
	DWORD   dummy;
	COORD   pos = { x, y };

	ReadConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), &attr, 1, pos, &dummy);

	return (attr & 0xf);
}

int getbkcolor(int x, int y)	// 배경 색상 설정 getcolor(배경색);
{
	short   attr;
	DWORD   dummy;
	COORD   pos = { x, y };

	ReadConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), &attr, 1, pos, &dummy);

	return (attr & 0xf0) >> 4;
}

void textattr(int color)		// 색상 설정 : textattr(글자색|배경색<<4)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)(color));
}

void setcolor(int textcolor)    // 글자 색상 설정 setcolor(글자색);
{
	WORD    attr;
	DWORD   dummy;
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(hConsole, &BufInfo);
	ReadConsoleOutputAttribute(hConsole, &attr, 1, BufInfo.dwCursorPosition, &dummy);

	attr = textcolor | (attr & 0xf0);
	SetConsoleTextAttribute(hConsole, (WORD)(attr));

}

void setbkcolor(int color)        // 배경 색상 설정 setbkcolor(배경색);
{
	WORD    attr;
	DWORD   dummy;
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(hConsole, &BufInfo);
	ReadConsoleOutputAttribute(hConsole, &attr, 1, BufInfo.dwCursorPosition, &dummy);

	attr = (attr & 0xf) | (color << 4);
	SetConsoleTextAttribute(hConsole, (WORD)(attr));

}

int getkey()
{
	int ch;
	if ((ch = _getch()) == 0xE0)
		ch = _getch();
	return ch;
}

void setColor(int color, int bgcolor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((bgcolor & 0xf) << 4) | (color & 0xf));
}

//글자색 기본값
inline void resetTextColor() {
	setcolor(7);
}

//배경색 기본값
inline void resetBgColor() {
	setbkcolor(0);
}

//글자색 & 배경색 기본값
inline void resetColor() {
	setColor(7, 0);
}

void setTextColor(int color) {
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (info.wAttributes & 0xf0) | (color & 0xf));
}