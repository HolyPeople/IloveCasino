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

	int start = 0;		//시작 재산
	int money = 0;    //게임 플레이 도중 재산
	int turn = 0;
	int i = 0, j = 0;
	int 베팅개수 = 0;
	int c;

	Point pos;
	int x = 0, y = 0;

	int dice[N_DICE] = { 0 };
	int diceSum = 0;
	int count[6] = { 0 };	//주사위 눈 중 1~6 각각의 개수

	char temp[8] = { 2,2,6,1,6,6,15,6 };
	char *** betting_area;
	char ** won_area;
	int **divided_rate = NULL;
	int *betting_amount = NULL;

	gotoxy(10, 5);
	printf("어서오세요! 이곳에서는 TaiSai 게임이 진행됩니다. \n          ");
	system("pause");
	system("cls");

	printf("시작 재산 : ");
	scanf("%d", &start); getchar();
	money = start;

	while (1)
	{
		system("cls");
		printf("시작 재산 : %d", start);
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
		show_betting_table();    //베팅 테이블을 보여준다.

		gotoxy(95, 3);
		printf("현재 재산 : %d원", money);

		gotoxy(0, 36);
		printf("한 번에 몇 개의 영역에 베팅하시겠습니까? (최대 3개)");
		베팅개수 = get_only_one_char_or_number_xy(0, 37, '0', '3'); //베팅할 영역의 수를 받는다.

		betting_amount = (int *)calloc(베팅개수, sizeof(int));

		for (i = 0; i < 베팅개수; i++)
		{
			choose_betting_area(betting_area[i], i + 1, &pos, positions);
			betted_area_lighting(pos);
			gotoxy(0, 40);
			printf("%d번째로 선택한 해당 영역에 베팅할 금액을 입력하세요. : ", i + 1);
			scanf("%d", &betting_amount[i]);
			getchar();

			money -= betting_amount[i];

			gotoxy(95, 3);
			printf("                                   ");
			gotoxy(95, 3);
			printf("현재 재산 : %d원\n", money);

			gotoxy(95, 36 + i);
			printf("베팅 금액 : %d", betting_amount[i]);

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
		printf("이제 주사위를 굴리겠습니다.\n");
		//Sleep(2000);
		dice_shaker(dice, &diceSum);

		check_won_area(won_area, dice, diceSum, positions, count);

		money += calculate(betting_area, won_area, betting_amount, 베팅개수, divided_rate, count);

		free_divided_rate(&divided_rate);

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 8; j++)
				free(betting_area[i][j]);
			free(betting_area[i]);
		}
		free(betting_area);

		free(betting_amount);
		printf("계속하시려면 엔터를 눌러주세요");
		while (getchar() != '\n');
		gotoxy(0, 42);
		printf("다시 플레이하려면 Enter, 종료하려면 Esc를 누르세요.");
		c = getkey();
		if (c == ESC);
			break;
		//getchar();
	}

	return 0;
}

//rate 생성 
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

//rate 반납 
void free_divided_rate(int*** divided_rate) {
	int i;
	for (i = 0; i < 8; i++) {
		free((*divided_rate)[i]);
	}
	free(*divided_rate);
}

//x,y위치에서 n 부터 m까지 입력받는 함수
int get_only_one_char_or_number_xy(int x, int y, int n, int m) {
	char ch = 0;
	char t = 0;
	int i = 0;
	gotoxy(x, y);
	printf("입력 (%c~%c) : ", n, m);
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
		printf("잘못된 입력입니다.\n");
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
		"BIG(1), SMALL(2) 선택 : ",
		"짝수(1), 홀수(2) 선택 : ",
		"배팅할 숫자 입력 : ",
		"베팅할 숫자 조합(두 개) 입력 : "
	};

	printf("%d번째 베팅할 영역을 선택하세요. : ", n);

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
		//점화식
		break;
	}

	betting_area[c - 'A'][t] = 1;
	*pos = positions[n_pos[c - 'A'] + t];

	gotoxy(70, 35 + n);
	printf("%d번째 베팅 영역 : %c%d", n, c, num);

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
	printf("스페이스 바를 누르면 주사위가 서서히 멈춥니다.\n");

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
	printf("주사위의 눈은 %d, %d, %d 입니다. 눈의 합은 %d 입니다.\n", picked_number[0], picked_number[1], picked_number[2], *diceSum);
}

void bubble_sort(int arr[], int count)    // 매개변수로 정렬할 배열과 요소의 개수를 받음
{
	int temp;

	for (int i = 0; i < count; i++)    // 요소의 개수만큼 반복
	{
		for (int j = 0; j < count - 1; j++)   // 요소의 개수 - 1만큼 반복
		{
			if (arr[j] > arr[j + 1])          // 현재 요소의 값과 다음 요소의 값을 비교하여
			{                                 // 큰 값을
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;            // 다음 요소로 보냄
			}
		}
	}

	gotoxy(0, 37);
	printf("오름차순으로 정렬하면 %d, %d, %d순입니다.", arr[0], arr[1], arr[2]);
}

void check_won_area(char ** won_area, int dice[N_DICE], int diceSum, Point positions[44], int count[6])
{
	int i = 0, j = 0;

	int 십의자리 = 0, 일의자리 = 0;
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

int calculate(char ***betting_area, char **won_area, int *betting_amount, int 베팅개수, int **divided_rate, int count[6])
{
	int sum = 0;
	int i = 0, j = 0, k = 0;
	char temp[8] = { 2, 2, 6, 1, 6, 6, 15, 6 };

	gotoxy(0, 38);
	printf("승리 시 정산 방식 : 베팅 금액 * (1 + 베당률) = 획득 금액\n");

	while (k < 베팅개수)
	{
		for (i = 0; i < 7; i++)
		{
			for (j = 0; j < temp[i]; j++)
			{
				if (betting_area[k][i][j] * won_area[i][j] == 1)
				{
					printf("%d번째 베팅 정산 : %d * (1 + %d) = %d원 획득\n", k + 1, betting_amount[k], divided_rate[i][j], betting_amount[k] * (divided_rate[i][j] + 1));
					sum += betting_amount[k] * (divided_rate[i][j] + 1);
				}
			}
		}
		for (j = 0; j < temp[7]; j++)
		{
			if (betting_area[k][7][j] * won_area[7][j] == 1)
			{
				printf("%d번째 베팅 정산 : %d * (1 + %d) = %d원 획득\n", k + 1, betting_amount[k], divided_rate[i][j], betting_amount[k] * (divided_rate[i][j] + 1));
				sum += betting_amount[k] * (divided_rate[7][j] + 1) * count[j];
			}
		}

		k++;
	}

	return sum;
}
