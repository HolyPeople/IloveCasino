#include "taisai.h"
#include "console_control.h"
#include "ui.h"

void show_logo() {
	int i;
	char * art[17] = {
" ___          __       ________  ___      ___ _______      ",
"|\\  \\        |\\  \\     |\\   __  \\|\\  \\    /  /|\\  ___ \\     ",
"\\ \\  \\       \\ \\  \\    \\ \\  \\|\\  \\ \\  \\  /  / | \\   __/|    ",
" \\ \\  \\       \\ \\  \\    \\ \\  \\\\\\  \\ \\  \\/  / / \\ \\  \\_|/__  ",
"  \\ \\  \\       \\ \\  \\____\\ \\  \\\\\\  \\ \\    / /   \\ \\  \\_|\\ \\ ",
"   \\ \\__\\       \\ \\_______\\ \\_______\\ \\__/ /     \\ \\_______\\",
"    \\|__|        \\|_______|\\|_______|\\|__|/       \\|_______|",
"                                                            ",
"                                                            ",
" ________  ________  ________  ___  ________   ________     ",
"|\\   ____\\|\\   __  \\|\\   ____\\|\\  \\|\\   ___  \\|\\   __  \\    ",
"\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\___|\\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\   ",
" \\ \\  \\    \\ \\   __  \\ \\_____  \\ \\  \\ \\  \\\\ \\  \\ \\  \\\\\\  \\  ",
"  \\ \\  \\____\\ \\  \\ \\  \\|____|\\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\\\\\  \\ ",
"   \\ \\_______\\ \\__\\ \\__\\____\\_\\  \\ \\__\\ \\__\\\\ \\__\\ \\_______\\",
"    \\|_______|\\|__|\\|__|\\_________\\|__|\\|__| \\|__|\\|_______|",
"                       \\|_________|                         " };

	for (i = 0; i < 17; i++) {
		gotoxy(25, 3 + i);
		printf("%s", art[i]);
		Sleep(100);
	}

	gotoxy(45, 22);
	printf("Please Press Any Key~!");

	while (1) {
		if (_kbhit()) break;
	}

}

void show_betting_table()
{
	printf("    忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("    弛                             <<TaiSai(棻檜餌檜) Table>>                             弛\n");
	printf("    戍式式成式式式式式式成式式式式式式式成式式式式式式式成式式式式式式式式式式式式式式式式扣\n");
	printf("    弛  A 弛 1 WINS 1   弛     BIG (A1) 弛    SMALL (A2)弛                                弛\n");
	printf("    弛    弛            弛   11 ~ 17    弛    4 ~ 10    弛                                弛\n");
	printf("    弛    弛            弛      ﹤      弛      ﹤      弛                                弛\n");
	printf("    戍式式托式式式式式式托式式式式式式式托式式式式式式式托式式式式式式式式式式式式式式式式扣\n");
	printf("    弛  B 弛 1 WINS 1   弛    EVEN (B1) 弛     ODD (B2) 弛                                弛\n");
	printf("    弛    弛            弛              弛              弛                                弛\n");
	printf("    弛    弛            弛      ﹤      弛      ﹤      弛                                弛\n");
	printf("    戍式式托式式式式式式托式式式式式式式扛式式式式式式式扛式式式式式式式式式式式式式式式式扣\n");
	printf("    弛  C 弛 1 WINS 8   弛   1,1   弛   2,2   弛   3,3   弛   4,4   弛   5,5   弛   6,6   弛\n");
	printf("    弛    弛            弛   ﹤    弛   ﹤    弛   ﹤    弛   ﹤    弛   ﹤    弛   ﹤    弛\n");
	printf("    戍式式托式式式式式式托式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("    弛  D 弛 1 WINS 24  弛    1,1,1    2,2,2    3,3,3    4,4,4    5,5,5    6,6,6     弛   弛\n");
	printf("    弛    弛            弛                            ﹤                             弛   弛\n");
	printf("    戍式式托式式式式式式托式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("    弛  E 弛 1 WINS 150 弛  1,1,1  弛  2,2,2  弛  3,3,3  弛  4,4,4  弛  5,5,5  弛  6,6,6  弛\n");
	printf("    弛    弛            弛   ﹤    弛   ﹤    弛   ﹤    弛   ﹤    弛   ﹤    弛   ﹤    弛\n");
	printf("    戍式式托式式式式式式托式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("    弛  F 弛   4 & 17   弛  5 & 16    弛  6 & 15   弛  7 & 14   弛  8 & 13   弛  9 ~ 12   弛\n");
	printf("    弛    弛 1 WINS 50  弛 1 WINS 30  弛 1 WINS 18 弛 1 WINS 12 弛 1 WINS 8  弛 1 WINS 6  弛\n");
	printf("    弛    弛     ﹤     弛    ﹤      弛    ﹤     弛    ﹤     弛    ﹤     弛    ﹤     弛\n");
	printf("    戍式式托式式式式式式托式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("    弛  G 弛 1 WINS 5   弛 1,2 弛 1,3 弛 1,4 弛 1,5 弛 1,6 弛 2,3 弛 2,4 弛 2,5 弛 2,6 弛 弛\n");
	printf("    弛    弛            弛 ﹤  弛 ﹤  弛 ﹤  弛 ﹤  弛 ﹤  弛 ﹤  弛 ﹤  弛 ﹤  弛 ﹤  弛 弛\n");
	printf("    弛    弛            戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("    弛    弛            弛 3,4 弛 3,5 弛 3,6 弛 4,5 弛 4,6 弛 5,6 弛                      弛\n");
	printf("    弛    弛            弛 ﹤  弛 ﹤  弛 ﹤  弛 ﹤  弛 ﹤  弛 ﹤  弛                      弛\n");
	printf("    戍式式托式式式式式式托式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("    弛  H 弛      1     弛     2      弛     3      弛     4      弛     5    弛     6    弛\n");
	printf("    弛    弛     ﹤     弛    ﹤      弛    ﹤      弛    ﹤      弛    ﹤    弛    ﹤    弛\n");
	printf("    戌式式扛式式式式式式扛式式式式式式扛式式式式式式扛式式式式式式扛式式式式式扛式式式式式戎\n");    //line 34
}

void betted_area_lighting(Point pos)
{
	gotoxy(pos.x, pos.y);
	setcolor(14); printf("﹥");
	resetColor();
}

void clean_dice(int pos) {
	int i;
	for (i = 0; i < 4; i++) {
		gotoxy(12 * pos + 2, 37 + i);
		printf("      ");
	}
}

void show_dice(int pos, char dice[][3]) {
	int i = 0, j = 0;

	gotoxy(12 * pos, 37);
	printf("忙式式式式忖\n");
	for (i = 0; i < 3; i++) {
		gotoxy(12 * pos, i + 38);
		printf("弛 ");
		for (j = 0; j < 3; j++) {
			if (dice[i][j] == 1) {
				printf("ㄟ");
			}
			else printf("  ");
		}
		printf(" 弛\n");
	}
	gotoxy(12 * pos, 41);
	printf("戌式式式式戎\n");
}

void won_area_lighting(Point pos)
{
	gotoxy((pos.x) - 2, pos.y);
	setbkcolor(15); setTextColor(0); printf(" >"); gotoxy((pos.x) + 2, pos.y); printf("< ");
	resetColor();
}

//ENTER 殮溘 衛, 瑙滇擊 給葬朝 л熱
int roll() {

	int r[38] = { 0, 2, 14, 35, 23, 4, 16, 33, 21, 6, 18, 31, 19, 8, 12, 20, 25, 10, 27, 50, 1, 13, 36, 24, 3, 15, 34, 22, 5, 17, 32, 29, 7, 11, 30, 26, 9, 28 }; //瑙滇 牖憮
	int x[38] = {
	   90,90,88,86,84,80,76,72,67,62,57,52,48,43,39,36,33,32,30,30,30,32,34,37,40,44,48,53,58,63,68,73,77,81,84,87,89,90
	};
	int y[38] = {
	   14,12,10,8,7,6,4,3,2,1,1,2,3,4,6,7,8,10,12,14,16,18,20,22,23,24,25,26,27,27,26,25,24,23,21,19,18,16
	};
	int random = 0;
	int i, j;
	int speed = 40;
	int flag = 0;
	int count = 0;

	srand((unsigned)time(NULL));

	for (i = 0; i < 38; i++) {
		gotoxy(x[i], y[i]);
		printf("%2d", r[i]);
	}
	random = rand() % 38;

	while (1) {

		for (j = 1; j < 39; j++) {
			if (j != 0) {
				gotoxy(x[j - 1], y[j - 1]);
				setbkcolor(BLACK);
				printf("%2d", r[j - 1]);
			}
			if (j != 38) {
				gotoxy(x[j], y[j]);
				setbkcolor(LIGHTMAGENTA);
				printf("%2d", r[j]);

			}
			else if (j == 38) {
				gotoxy(x[0], y[0]);
				setbkcolor(LIGHTMAGENTA);
				printf("%2d", r[0]);
			}

			if (flag) {
				if (count == 1 && random == r[j % 38]) break;
				if (count < 1) {
					speed += 10;
					if (random == r[j % 38]) count++;
				}
			}


			_sleep(speed);
		}

		if (GetAsyncKeyState(VK_SPACE)) {
			flag = 1;
		}
		if (count == 1 && random == r[j % 38]) break;
	}
	setbkcolor(BLACK);

	return random;
}

//UIル衛
void ui(int x, int y, int scale, int a[4], int b[][7], int db, int m) {

	int i, j;

	gotoxy(0, 10);
	printf("寞щ酈煎 檜翕, SPACE BAR煎 漆た, ENTER煎 煤, ESC煎 謙猿\n");
	printf("⑷營 嬪纂      x: %d  y: %d \n", x, y);
	printf("摹鷗и 熱 : \n");
	printf("寡渡 : X %2d  \n", scale);
	printf("⑷營 爾嶸 旎擋 : %d", m);

	gotoxy(0, 0);
	printf("忙式式式成式式式成式式式成式式式成式式式成式式式成式式式成式式式成式式式成式式式成式式式成式式式忖\n");
	printf("弛 01弛 04弛 07弛 10弛 13弛 16弛 19弛 22弛 25弛 28弛 31弛 34弛\n");
	printf("戍式式式托式式式托式式式托式式式托式式式托式式式托式式式托式式式托式式式托式式式托式式式托式式式扣\n");
	printf("弛 02弛 05弛 08弛 11弛 14弛 17弛 20弛 23弛 26弛 29弛 32弛 35弛\n");
	printf("戍式式式托式式式托式式式托式式式托式式式托式式式托式式式托式式式托式式式托式式式托式式式托式式式扣\n");
	printf("弛 03弛 06弛 09弛 12弛 15弛 18弛 21弛 24弛 27弛 30弛 33弛 36弛\n");
	printf("戌式式式扛式式式扛式式式扛式式式扛式式式扛式式式扛式式式扛式式式扛式式式扛式式式扛式式式扛式式式戎\n");

	gotoxy(60, 0);
	printf("⑷營 漆た 薑爾\n");
	gotoxy(60, 1);
	printf("忙式式式式式式式式式式式式式式式成式式式式式式成式式式式式成式式式式式式式式忖\n");
	gotoxy(60, 2);
	printf("弛   漆たи 璋濠 弛 擋熱 弛 寡渡弛   鼻旎 弛\n");
	gotoxy(60, 3);
	printf("戍式式式成式式式成式式式成式式式托式式式式式式托式式式式式托式式式式式式式式扣\n");

	//式弛忙忖戎戌戍成扣扛托ㄟㄠㄡㄢㄣㄤㄥㄦㄧㄨ

	for (i = 0; i < db; i++) {
		gotoxy(60, i + 4);
		for (j = 0; j < 4; j++) {
			if (b[i][j] == 0) {
				printf("弛   ");
			}
			else {
				printf("弛 %2d", b[i][j]);
			}
		}
		printf("弛 %5d弛  %2d 弛 %7d弛", b[i][4], b[i][5], b[i][6]);
		//gotoxy(60, i + 5);
		//printf("戍式式式托式式式托式式式托式式式托式式式式式式托式式式式式扣"); 
	}
	gotoxy(60, i + 4);
	printf("戌式式式扛式式式扛式式式扛式式式扛式式式式式式扛式式式式式扛式式式式式式式式戎\n");
}

void showMenu() {
	printf("≠≠≠≠≠≠≠≠≠≠≠≠≠≠\n");
	printf("≠≠≠(New)蝸煜該褐777≠≠≠\n");
	printf("≠≠≠≠≠≠≠≠≠≠≠≠≠≠\n");
}
void showMoney(int a) {
	printf("寡た旎擋: %d\n", a);
}

void five_connect_intor() {

	printf("螃跡 啪歜\n\n");
	printf("陛煎, 撮煎, �分� 渠陝摹戲煎 試盪 5偃曖 給擊 翱殖嬴 寡纂衛酈賊 檜晦朝 啪歜\n");
	printf("餌辨濠 2貲檜 廓陞嬴陛賊憮 給擊 寡纂衛霾棲棻\n");
	printf("寥給檜 試盪 衛濛м棲棻\n");
	system("pause");
}

void draw_check() {
	int size = 18;
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[12] = "";
	for (i = 1; i < 12; i++) {
		b[i] = 0xa0 + i;
	}
	printf("%c%c", a, b[3]);
	for (i = 0; i < size - 1; i++) {
		printf("%c%c", a, b[1]);
		printf("%c%c", a, b[8]);
	}

	printf("%c%c", a, b[1]);
	printf("%c%c", a, b[4]);
	printf("\n");
	for (i = 0; i < size - 1; i++) {
		printf("%c%c", a, b[7]);
		for (j = 0; j < size - 1; j++) {
			printf("%c%c", a, b[1]);
			printf("%c%c", a, b[11]);
		}
		printf("%c%c", a, b[1]);
		printf("%c%c", a, b[9]);
		printf("\n");
	}
	printf("%c%c", a, b[6]);
	for (i = 0; i < size - 1; i++) {
		printf("%c%c", a, b[1]);
		printf("%c%c", a, b[10]);
	}
	printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);

	printf("\n");

}