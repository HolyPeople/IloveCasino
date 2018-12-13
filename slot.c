#include "console_control.h"
#include "ui.h"
#include "slot.h"

int slot(void) {
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	int count = 0;
	int n= 0;
	int flag;
	char slot[size][10] = {
	   "int", "long", "long long", "float", "double", "char", "string"
	};
	char ch;
	int i = 0;
	int sc = 100;
	srand((unsigned)time(NULL));
	showMenu();
	while (1) {
		a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, count = 0, i = 0, sc = 100, n = 0, flag = 0;
		do {
			printf("배팅하실 금액을 입력해주세요\n");
			printf("100$ ~ 10000$\n");
			scanf("%d", &a);
			system("CLS");
		} while (a < 100 || a>10000);
		showMoney(a);

		printf("숫자 2개를 맞출경우 배팅금X2 : %d\n", a * 2);
		printf("숫자 3개를 맞출경우 배팅금X5 : %d\n", a * 5);

		printf("1).int   2).long   3).long long   4).float   5).double   6).char   7).string\n");

		scanf("%d", &b);
		system("cls");
		printf("□□□□□□□□□□□□□□□□□□□□□\n");
		gotoxy(0, 1);
		printf("□");
		gotoxy(40, 1);
		printf("□");
		gotoxy(0, 2);
		printf("□□□□□□□□□□□□□□□□□□□□□\n");
		gotoxy(40, 3);
		printf("  :멈추려면 아무키나 눌러주세요\n");

		while(1) {


			c = rand() % 7;
			d = rand() % 7;
			e = rand() % 7;

			gotoxy(2, 1);
			printf("           ");
			gotoxy(2, 1);
			printf("%10s |", slot[c]);

			if (flag) sc += 20;
			Sleep(sc);

			gotoxy(15, 1);
			printf("           ");
			gotoxy(15, 1);
			printf("%10s |", slot[d]);

			if (flag) sc += 20;
			Sleep(sc);

			gotoxy(28, 1);
			printf("           ");
			gotoxy(28, 1);
			printf("%10s ", slot[e]);

			if (flag) sc += 20;
			Sleep(sc);
			if (GetAsyncKeyState(VK_SPACE)) flag = 1;

			if (flag) {
				n++;
			}
			if (n > 12) break;
		}
		printf("\n");
		if (slot[c] == slot[d])
			count++;
		if (slot[d] == slot[e])
			count++;
		if (slot[c] == slot[e])
			count++;
		if (count == 3)
			a = a * 5;
		else if (count == 1)
			a = a * 2;
		gotoxy(0, 4);
		showMoney(a);
		do {
			printf("\n");
			printf("1).도박을 더한다.    2).도박을 손절한다.\n");
			scanf("%d", &f);

			if (f == 1) {
				system("CLS");
				break;
			}
		} while (f != 1 || f != 2);
		if (f == 2) break;
	}
	return 0;
}