#pragma once
#define N_GAME 8
#define N_SUB_GAME 15
#define N_DICE 3
#define MAX 3	//한 번에 베팅할 수 있는 영역의 최대 개수

typedef struct _pointxy {
	int x;
	int y;
}Point;

extern void show_betting_table();
extern void choose_betting_area(char **, int, Point *, Point[44]);
extern void betted_area_lighting(Point);
extern void dice_shaker(int[N_DICE], int *);
extern void check_won_area(char **, int[N_DICE], int, Point[44], int[6]);
extern void bubble_sort(int[], int);
extern int calculate(char ***, char **, int*, int, int **, int[6]);
extern void init_divided_rate(int***);
extern void free_divided_rate(int***);
extern int get_only_one_char_or_number_xy(int, int, int, int);
extern int taisai();
