#include "taisai.h"
#include "console_control.h"
#include "ui.h"

#pragma warning (disable : 4996)

int taisai()
{
	Point positions[44] = {
	{32, 7}, {48, 7},
	{32,11}, {48,11},
	{29,14}, {40,14}, {51,14}, {62,14}, {73,14}, {84,14},
	{54,17},
	{29,20}, {40,20}, {51,20}, {62,20}, {73,14}, {84,14},
	{17,24}, {30,24}, {44,24}, {57,24}, {70,24}, {83,24},
	{27,27}, {34,27}, {41,27}, {48,27}, {55,27}, {62,27}, {69,27}, {76,27}, {83,27}, {27,30}, {34,30}, {41,30}, {48,30}, {55,30}, {62,30},
	{17,33}, {30,33}, {44,33}, {58,33}, {72,33}, {84,33},
	};

	int start = 0;		//���� ���
	int money = 0;    //���� �÷��� ���� ���
	int turn = 0;
	int i = 0, j = 0;
	int ���ð��� = 0;
	int c;

	Point pos;
	int x = 0, y = 0;

	int dice[N_DICE] = { 0 };
	int diceSum = 0;
	int count[6] = { 0 };	//�ֻ��� �� �� 1~6 ������ ����

	char temp[8] = { 2,2,6,1,6,6,15,6 };
	char *** betting_area;
	char ** won_area;
	int **divided_rate = NULL;
	int *betting_amount = NULL;

	gotoxy(10, 5);
	printf("�������! �̰������� TaiSai ������ ����˴ϴ�. \n          ");
	system("pause");
	system("cls");

	printf("���� ��� : ");
	scanf("%d", &start); getchar();
	money = start;

	while (1)
	{
		system("cls");
		printf("���� ��� : %d", start);
		betting_area = (char***)malloc(sizeof(char**) * MAX);
		for (i = 0; i < 3; i++)
			betting_area[i] = (char **)calloc(N_GAME, sizeof(char *));

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 8; j++)
				betting_area[i][j] = (char*)calloc(temp[j], sizeof(char));
		}

		won_area = (char**)malloc(sizeof(char*) * N_GAME);
		for (i = 0; i < 8; i++)
			won_area[i] = (char*)calloc(temp[i], sizeof(char));

		init_divided_rate(&divided_rate);

		gotoxy(0, 2);
		show_betting_table();    //���� ���̺��� �����ش�.

		gotoxy(95, 3);
		printf("���� ��� : %d��", money);

		gotoxy(0, 36);
		printf("�� ���� �� ���� ������ �����Ͻðڽ��ϱ�? (�ִ� 3��)");
		���ð��� = get_only_one_char_or_number_xy(0, 37, '0', '3'); //������ ������ ���� �޴´�.

		betting_amount = (int *)calloc(���ð���, sizeof(int));

		for (i = 0; i < ���ð���; i++)
		{
			choose_betting_area(betting_area[i], i + 1, &pos, positions);
			betted_area_lighting(pos);
			gotoxy(0, 40);
			printf("%d��°�� ������ �ش� ������ ������ �ݾ��� �Է��ϼ���. : ", i + 1);
			scanf("%d", &betting_amount[i]);
			getchar();

			money -= betting_amount[i];

			gotoxy(95, 3);
			printf("                                   ");
			gotoxy(95, 3);
			printf("���� ��� : %d��\n", money);

			gotoxy(95, 36 + i);
			printf("���� �ݾ� : %d", betting_amount[i]);

			gotoxy(0, 38);
			printf("                                                                 \n");
			printf("                                                                 \n");
			printf("                                                                 \n");
			gotoxy(0, 38);
		}

		gotoxy(0, 36);
		printf("                                                                 \n");
		printf("                                                                 \n");
		gotoxy(0, 36);
		printf("No More Bet ! \n");
		//Sleep(2000);
		printf("���� �ֻ����� �����ڽ��ϴ�.\n");
		//Sleep(2000);
		dice_shaker(dice, &diceSum);

		check_won_area(won_area, dice, diceSum, positions, count);

		money += calculate(betting_area, won_area, betting_amount, ���ð���, divided_rate, count);

		free_divided_rate(&divided_rate);

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 8; j++)
				free(betting_area[i][j]);
			free(betting_area[i]);
		}
		free(betting_area);

		free(betting_amount);
		printf("����Ͻ÷��� ���͸� �����ּ���");
		while (getchar() != '\n');
		gotoxy(0, 42);
		printf("�ٽ� �÷����Ϸ��� Enter, �����Ϸ��� Esc�� ��������.");
		c = getkey();
		if (c == ESC);
			break;
		//getchar();
	}

	return 0;
}

//rate ���� 
void init_divided_rate(int*** divided_rate) {
	char temp[8] = { 2,2,6,1,6,6,15,6 };
	unsigned char rate[44] = { 1,1,1,1,8,8,8,8,8,8,24,150,150,150,150,150,150,50,30,18,12,8,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,1,1,1,1,1 };
	int k = 0;
	int i, j;
	*divided_rate = (int**)malloc(sizeof(int*) * 8);
	for (i = 0; i < 8; i++) {
		(*divided_rate)[i] = (int*)malloc(sizeof(int) * temp[i]);
	}
	for (i = 0; i < 8; i++) {
		for (j = 0; j < temp[i]; j++) {
			(*divided_rate)[i][j] = rate[k++];
		}
	}
}

//rate �ݳ� 
void free_divided_rate(int*** divided_rate) {
	int i;
	for (i = 0; i < 8; i++) {
		free((*divided_rate)[i]);
	}
	free(*divided_rate);
}

//x,y��ġ���� n ���� m���� �Է¹޴� �Լ�
int get_only_one_char_or_number_xy(int x, int y, int n, int m) {
	char ch = 0;
	char t = 0;
	int i = 0;
	gotoxy(x, y);
	printf("�Է� (%c~%c) : ", n, m);
	while (1) {
		scanf_s("%c", &t, 1);
		if (t == '\n') break;
		ch = t;
		i++;
	}
	if ((n <= ch && ch <= m) && i == 1) {
		if (n < 'A') return  ch - '0';
		else return ch;
	}
	else {
		printf("�߸��� �Է��Դϴ�.\n");
		system("pause");
		gotoxy(x, y);
		for (i = 0; i < 3; i++) {
			printf("                                         \n");
		}
		return get_only_one_char_or_number_xy(x, y, n, m);
	}
}

void choose_betting_area(char ** betting_area, int n, Point *pos, Point positions[44])
{
	char n_pos[8] = { 0, 2, 4, 10, 11, 17, 23, 38 };

	char c;
	int t = 0;
	int num = 0;
	int a = 0;
	char* msg[] = {
		"BIG(1), SMALL(2) ���� : ",
		"¦��(1), Ȧ��(2) ���� : ",
		"������ ���� �Է� : ",
		"������ ���� ����(�� ��) �Է� : "
	};

	printf("%d��° ������ ������ �����ϼ���. : ", n);

	c = (char)get_only_one_char_or_number_xy(36, 38, 'A', 'H');

	if (c == 'D') {
		betting_area[3][0] = 1;
		*pos = positions[10];
		return;
	}


	switch (c)
	{
	case 'A':
		printf("%s", msg[0]);
		break;

	case 'B':
		printf("%s", msg[1]);
		break;

	case 'C': case 'E': case 'F': case 'H':
		printf("%s", msg[2]);
		break;

	case 'G':
		printf("%s", msg[3]);
		break;
	}

	scanf("%d", &num);
	switch (c)
	{
	case 'A': case 'B': case 'C': case 'E': case 'H':
		t = num - 1;
		break;

	case 'F':
		if (num < 10) t = num - 5;
		else t = -(num - 17);
		break;

	case 'G':
		a = num / 10;
		t = num - ((24 + (a - 1) * (11 + (a - 1))) / 2);
		//��ȭ��
		break;
	}

	betting_area[c - 'A'][t] = 1;
	*pos = positions[n_pos[c - 'A'] + t];

	gotoxy(70, 35 + n);
	printf("%d��° ���� ���� : %c%d", n, c, num);

}

void dice_shaker(int picked_number[N_DICE], int * diceSum)
{
	int i = 0;
	int flag = 0;
	int speed = 50;
	int count = 0;
	char dice[6][3][3] = {
	   { { 0, 0, 0 },{ 0,1,0 },{ 0, 0, 0 } },
	   { { 1, 0, 0 },{ 0,0,0 },{ 0, 0, 1 } },
	   { { 1, 0, 0 },{ 0,1,0 },{ 0, 0, 1 } },
	   { { 1, 0, 1 },{ 0,0,0 },{ 1, 0, 1 } },
	   { { 1, 0, 1 },{ 0,1,0 },{ 1, 0, 1 } },
	   { { 1, 0, 1 },{ 1,0,1 },{ 1, 0, 1 } },
	};
	srand((unsigned)time(NULL));

	gotoxy(0, 36);
	for (i = 0; i < 5; i++)
		printf("                                                                 \n");
	gotoxy(0, 36);
	printf("�����̽� �ٸ� ������ �ֻ����� ������ ����ϴ�.\n");

	while (1) {
		if (!flag) {
			for (i = 0; i < 3; i++) {
				picked_number[i] = rand() % 6;
				clean_dice(i);
				show_dice(i, dice[picked_number[i]]);
			}
			_sleep(speed);
		}
		else {
			for (i = 0; i < 3; i++) {
				picked_number[i] = rand() % 6;
				clean_dice(i);
				show_dice(i, dice[picked_number[i]]);
				_sleep(speed);
				if (count < 16) {
					speed += 50;
					count++;
				}
			}
		}
		if (count > 15) break;
		if (GetAsyncKeyState(VK_SPACE)) {
			flag = 1;
		}
	}
	for (i = 0; i < N_DICE; i++)
		*diceSum += ++picked_number[i];

	Sleep(1000);
	gotoxy(0, 36);
	for (i = 0; i < 6; i++)
		printf("                                                                 \n");
	gotoxy(0, 36);
	printf("�ֻ����� ���� %d, %d, %d �Դϴ�. ���� ���� %d �Դϴ�.\n", picked_number[0], picked_number[1], picked_number[2], *diceSum);
}

void bubble_sort(int arr[], int count)    // �Ű������� ������ �迭�� ����� ������ ����
{
	int temp;

	for (int i = 0; i < count; i++)    // ����� ������ŭ �ݺ�
	{
		for (int j = 0; j < count - 1; j++)   // ����� ���� - 1��ŭ �ݺ�
		{
			if (arr[j] > arr[j + 1])          // ���� ����� ���� ���� ����� ���� ���Ͽ�
			{                                 // ū ����
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;            // ���� ��ҷ� ����
			}
		}
	}

	gotoxy(0, 37);
	printf("������������ �����ϸ� %d, %d, %d���Դϴ�.", arr[0], arr[1], arr[2]);
}

void check_won_area(char ** won_area, int dice[N_DICE], int diceSum, Point positions[44], int count[6])
{
	int i = 0, j = 0;

	int �����ڸ� = 0, �����ڸ� = 0;
	int num[3] = { 0 };
	int temp = 0;

	for (j = 0; j < 6; j++)
	{
		for (i = 0; i < N_DICE; i++)
		{
			if ((j + 1) == dice[i])
				count[j]++;
		}
	}

	if (diceSum >= 11 && diceSum <= 17) {
		won_area[0][0] = 1;
		won_area_lighting(positions[0]);
	}
	if (diceSum >= 4 && diceSum <= 10) {
		won_area[0][1] = 1;
		won_area_lighting(positions[1]);
	}

	if ((diceSum % 2) == 0) {
		won_area[1][0] = 1;
		won_area_lighting(positions[2]);
	}
	else {
		won_area[1][1] = 1;
		won_area_lighting(positions[3]);
	}

	for (j = 0; j < 6; j++)
	{
		if (count[j] == 2)
		{
			won_area[2][j] = 1;
			won_area_lighting(positions[4 + j]);
		}
	}

	if (count[j] == 3)
	{
		won_area[3][0] = 1;
		won_area_lighting(positions[10]);
	}

	for (j = 0; j < 6; j++)
	{
		if (count[j] == 3)
		{
			won_area[4][j] = 1;
			won_area_lighting(positions[11 + j]);
		}
	}

	for (i = 0; i < 6; i++)
	{
		if (diceSum == (4 + i) || diceSum == (17 - i))
		{
			won_area[5][i] = 1;
			won_area_lighting(positions[17 + i]);
		}
	}

	bubble_sort(dice, N_DICE);

	for (i = 0; i < 2; i++)
	{
		if (dice[i] != dice[i + 1])
		{
			num[i] = (dice[i] * 10 + dice[i + 1]);

			temp = num[i] - ((24 + (dice[i] - 1) * (11 + (dice[i] - 1))) / 2);

			won_area[6][temp] = 1;
			won_area_lighting(positions[23 + temp]);
		}
	}

	if (dice[0] != dice[2])
	{
		num[2] = (dice[0] * 10 + dice[2]);

		temp = num[2] - ((24 + (dice[0] - 1) * (11 + (dice[2] - 1))) / 2);

		won_area[6][temp] = 1;
		won_area_lighting(positions[23 + temp]);
	}

	for (j = 0; j < 6; j++)
	{
		for (i = 0; i < N_DICE; i++)
		{
			if (dice[i] == (j + 1)) {
				won_area[7][j] = 1;
				won_area_lighting(positions[38 + j]);
			}
		}
	}

}

int calculate(char ***betting_area, char **won_area, int *betting_amount, int ���ð���, int **divided_rate, int count[6])
{
	int sum = 0;
	int i = 0, j = 0, k = 0;
	char temp[8] = { 2, 2, 6, 1, 6, 6, 15, 6 };

	gotoxy(0, 38);
	printf("�¸� �� ���� ��� : ���� �ݾ� * (1 + �����) = ȹ�� �ݾ�\n");

	while (k < ���ð���)
	{
		for (i = 0; i < 7; i++)
		{
			for (j = 0; j < temp[i]; j++)
			{
				if (betting_area[k][i][j] * won_area[i][j] == 1)
				{
					printf("%d��° ���� ���� : %d * (1 + %d) = %d�� ȹ��\n", k + 1, betting_amount[k], divided_rate[i][j], betting_amount[k] * (divided_rate[i][j] + 1));
					sum += betting_amount[k] * (divided_rate[i][j] + 1);
				}
			}
		}
		for (j = 0; j < temp[7]; j++)
		{
			if (betting_area[k][7][j] * won_area[7][j] == 1)
			{
				printf("%d��° ���� ���� : %d * (1 + %d) = %d�� ȹ��\n", k + 1, betting_amount[k], divided_rate[i][j], betting_amount[k] * (divided_rate[i][j] + 1));
				sum += betting_amount[k] * (divided_rate[7][j] + 1) * count[j];
			}
		}

		k++;
	}

	return sum;
}
