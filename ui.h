#pragma once
#include "taisai.h"

extern void show_logo();
extern void show_betting_table();
extern void betted_area_lighting(Point pos);
extern void show_dice(int pos, char dice[][3]);
extern void won_area_lighting(Point pos);
extern void clean_dice(int);
extern void ui(int x, int y, int scale, int a[4], int b[][7], int db, int m); //UI표시
extern int roll();//ENTER 입력 시, 룰렛을 돌리는 함수
extern void showMenu();
extern void showMoney(int);
extern void five_connect_intor();
extern void draw_check();
