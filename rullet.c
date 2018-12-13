#include "rullet.h"
#include "ui.h"
#include "console_control.h"

//����
int insert(int m) {

	int coin = 0;

	printf("������ �ݾ��� ������ �ֽʽÿ�. : ");
	scanf("%d", &coin);

	if (coin > m) {
		while (1) {
			gotoxy(0, 23);
			printf("�ݾ��� �ʰ��߽��ϴ�. �ٽ� ������ �ֽʽÿ�. : ");
			scanf("%d", &coin);
			if (coin <= m) break;
		}
	}

	return coin;
}

//��� ���
int dot(int x, int y) {

	int a;

	if (x % 4 == 1 && y % 2 == 0) {
		a = 1;
	}
	else if (x % 4 == 1) {
		a = 2;
	}
	else if (y % 2 == 0) {
		a = 3;
	}
	else {
		a = 4;
	}

	return a;
}

//��� ���
int cal(int a[4], int x, int y) {

	int s, d;

	d = dot(x, y);

	switch (d) {
	case 1: a[0] = ((x - 2) / 4 * 3 + (y - 1) / 2 + 1); a[1] = ((x - 2) / 4 * 3 + (y + 1) / 2 + 1); a[2] = ((x + 2) / 4 * 3 + (y - 1) / 2 + 1); a[3] = ((x + 2) / 4 * 3 + (y + 1) / 2 + 1); s = 9; break;
	case 2: a[0] = ((x - 2) / 4 * 3 + y / 2 + 1); a[1] = ((x + 2) / 4 * 3 + y / 2 + 1); a[2] = a[3] = 0; s = 18; break;
	case 3: a[0] = (x / 4 * 3 + (y - 1) / 2 + 1); a[1] = (x / 4 * 3 + (y + 1) / 2 + 1); a[2] = a[3] = 0; s = 18; break;
	case 4: a[0] = (x / 4 * 3 + y / 2 + 1); a[1] = a[2] = a[3] = 0; s = 36; break;
	default: break;
	}

	return s;
}

//������ �� ǥ��
int dis(int a[4], int x, int y) {

	int i;
	int scale = 0;

	scale = cal(a, x, y);

	gotoxy(15, 12);
	for (i = 0; i < 4; i++) {
		printf("%2d   ", a[i]);
	}
	printf("\n");

	return scale;
}

//������ �� ����
void save(int a[4], int b[][7], int s, int db) {

	int i;

	for (i = 0; i < 4; i++) {
		b[db][i] = a[i];
	}
	b[db][4] = s;
}

//roll���� ���� ���� ���ϴ� �Լ�
int result(int d, int b[][7], int db) {

	int i, j, k, m, n, o;
	k = m = n = o = 0;

	for (i = 0; i < db; i++) {
		for (j = 0; j < 4; j++) {
			if (d == b[i][j]) {
				k = 1;
				m = i;
				n = j;
			}
		}
	}

	gotoxy(0, 23);
	if (k == 1) {
		printf("��÷�Ǿ����ϴ�! ����� %d�Դϴ�!", b[m][6]);
		o = b[m][n];
	}
	else {
		printf("�ƽ��Ե� ��÷���� ���߽��ϴ�.");
	}

	return o;
}

//�ʱ� �ݾ� ����
int m_input() {

	int i;

	printf("�ݾ��� ������ �ֽʽÿ�. : ");
	scanf("%d", &i);

	return i;
}

int reset(int b[][7], int db) {

	int i, j;

	for (i = 0; i < db; i++) {
		for (j = 0; j < 7; j++) {
			b[i][j] = 0;
		}
	}

	return 0;
}

void rullet() {

	//int r[38] = { 0, 2, 14, 35, 23, 4, 16, 33, 21, 6, 18, 31, 19, 8, 12, 20, 25, 10, 27, 50, 1, 13, 36, 24, 3, 15, 34, 22, 5, 17, 32, 29, 7, 11, 30, 26, 9, 28 }; //�귿 ����
	int a[4] = { 0 }; //������ ��
	int b[P][7] = { 0 }; //������ �� �� ����(b[][4]), ���(b[][5]), ���(b[][6])
	char c;
	int x, y, i;
	int bet = 0;
	int scale = 0; //���
	int money = 10000; //�ڱ�
	int d = 0; // �ɸ� ��
	int db = 0; //���� ǥ�� ī����
	x = 3;
	y = 1;
	i = 0;

	money = m_input();

	system("cls");

	while (1) {

		ui(x, y, scale, a, b, db, money);

		gotoxy(x, y);
		c = getkey();

		if (c == ESC) {
			gotoxy(0, 24);
			break;
		}

		switch (c) {
		case LEFT:  x -= 2; scale = dis(a, x, y);    break;
		case RIGHT: x += 2; scale = dis(a, x, y);    break;
		case UP:    y--; scale = dis(a, x, y);    break;
		case DOWN:  y++; scale = dis(a, x, y);    break;
		case ENTER:

			system("cls");

			d = roll();

			gotoxy(0, 22);
			printf("���� ���ڴ� %d�Դϴ�!!!!!", d);

			money += result(d, b, db);

			printf("������ ����Ϸ��� ");
			system("pause");
			//getchar();

			db = reset(b, db);

			system("cls");

			break;
		case SPACE:
			scale = dis(a, x, y);
			save(a, b, scale, db);

			gotoxy(0, 23);
			bet = insert(money);

			money -= bet;

			b[db][4] = bet;
			b[db][5] = scale;
			b[db][6] = bet * scale;

			db += 1;

			system("cls");

			break;
		default:  break;
		}

		if (x < 3) {
			x = 3;
		}
		if (x > 47) {
			x = 47;
		}
		if (y < 1) {
			y = 1;
		}
		if (y > 5) {
			y = 5;
		}

		gotoxy(x, y);

		x = wherex();
		y = wherey();

	}
}