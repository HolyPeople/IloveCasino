#pragma once
#include "taisai.h"

extern void show_logo();
extern void show_betting_table();
extern void betted_area_lighting(Point pos);
extern void show_dice(int pos, char dice[][3]);
extern void won_area_lighting(Point pos);
extern void clean_dice(int);
extern void ui(int x, int y, int scale, int a[4], int b[][7], int db, int m); //UIǥ��
extern int roll();//ENTER �Է� ��, �귿�� ������ �Լ�
extern void showMenu();
extern void showMoney(int);
extern void five_connect_intor();
extern void draw_check();
