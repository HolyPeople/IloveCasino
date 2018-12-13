#include "ui.h"
#include "console_control.h"
#include "fice_connect.h"

int five_connect() {

	five_connect_intor();
	system("cls");
	game_control();

	return 0;
}

void move_arrow_key(char key, int *x1, int *y1) {

	switch (key)

	{
	case UP:
		*y1 = *y1 - 1;
		if (*y1 < 1) *y1 = 1;
		break;
	case LEFT:
		*x1 = *x1 - 2;
		if (*x1 < 1) *x1 = 1;
		break;
	case RIGHT:
		*x1 = *x1 + 2;
		if (*x1 > 37) *x1 = 37;
		break;
	case DOWN:
		*y1 = *y1 + 1;
		if (*y1 > 19) *y1 = 19;
		break;

	default:
		return;
	}
}

void game_control() {

	int x = 1, y = 1, other = 0;
	int preX = 1, preY = 1;
	int matrix[2][20][20] = { 0 };
	char key;
	char *stone[2] = { "○", "●" };

	gotoxy(0, 19);
	printf("방향키로 움직이고 ");
	printf("스페이스 키를 누르시오.");

	gotoxy(0, 20);
	printf("돌을 놓았으면 상대방 차례입니다. ");
	gotoxy(0, 0);
	draw_check();

	do {
		gotoxy(x - 1, y - 1);

		printf("%s", stone[other]);
		key = _getch();
		display_stone(matrix);

		if (key == ESC) exit(0);

		else if (key == SPACE) {
			if (matrix[1][(x + 1) / 2][y] || matrix[0][(x + 1) / 2][y]) continue;

			matrix[other][(x + 1) / 2][y] = 1;
			display_stone(matrix);
			other = 1 - other;
		}

		else if (key >= UP) {
			if (!matrix[1][(x + 1) / 2][y] && !matrix[0][(x + 1) / 2][y]) {
				gotoxy(x - 1, y - 1);
				if ((x + 1) / 2 == 1 && y == 1) printf("%c%c", 0xa6, 0xa3);
				else if ((x + 1) / 2 == 19 && y == 1) printf("%c%c", 0xa6, 0xa4);
				else if ((x + 1) / 2 == 1 && y == 19) printf("%c%c", 0xa6, 0xa6);
				else if ((x + 1) / 2 == 19 && y == 19) printf("%c%c", 0xa6, 0xa5);
				else if (y == 1) printf("%c%c", 0xa6, 0xa8);
				else if (y == 19) printf("%c%c", 0xa6, 0xaa);
				else if ((x + 1) / 2 == 1) printf("%c%c", 0xa6, 0xa7);
				else if ((x + 1) / 2 == 19) printf("%c%c", 0xa6, 0xa9);
				else printf("%c%c", 0xa6, 0xab);
			}

			move_arrow_key(key, &x, &y);
		}

		if (game_end(matrix) == 1) {
			gotoxy(0, 23);
			printf("흑돌이 이겼습니다\n");
			break;
		}
		else if (game_end(matrix) == 2) {

			gotoxy(0, 23);
			printf("백돌이 이겼습니다\n");
			break;
		}

	} while (1);

}

void display_stone(int matrix[][20][20]) {

	int i, x, y;
	char *stone[2] = { "○", "●" };

	for (i = 0; i < 2; i++)
		for (x = 1; x < 20; x++)
			for (y = 1; y < 20; y++)
				if (matrix[i][x][y] == 1) {
					gotoxy(x * 2 - 2, y - 1);
					printf("%s", stone[i]);
				}
}

int game_end(int matrix[][20][20]) {
	int i, y, x, temp1, temp2, j;
	int count = 0;

	for (i = 0; i < 2; i++) {
		for (y = 1; y < 20; y++) {
			count = 0;
			for (x = 1; x < 20; x++) {
				if (matrix[i][x][y]) count++;
				else count = 0;
				if (count == 5)	return (i + 1);
			}
		}
	}

	for (int i = 0; i < 2; i++) {

		for (x = 1; x < 20; x++) {
			count = 0;
			for (y = 1; y < 20; y++) {
				if (matrix[i][x][y]) count++;
				else count = 0;
				if (count == 5)	return (i + 1);
			}
		}
	}

	for (i = 0; i < 2; i++) {
		for (x = 1; x < 16; x++) {
			count = 0;
			for (y = 1; y < 16; y++) {
				temp1 = x;
				temp2 = y;
				for (j = 0; j < 5; j++) {
					if (matrix[i][temp1++][temp2++]) count++;
					else count = 0;
				}
				if (count == 5)	return (i + 1);
			}
		}
	}

	for (i = 0; i < 2; i++) {
		for (x = 1; x < 16; x++) {
			count = 0;
			for (y = 5; y < 20; y++) {
				temp1 = x;
				temp2 = y;
				for (j = 0; j < 5; j++) {
					if (matrix[i][temp1++][temp2--]) count++;
					else count = 0;
				}
				if (count == 5)	return (i + 1);
			}
		}
	}
	return 0;
}
