#include "taisai.h"
#include "ui.h"
#include "console_control.h"
#include "rullet.h"
#include "slot.h"
#include "fice_connect.h"

int main() {
	int menu = 0;

	show_logo();
	
	while (1) {
		system("cls");
		printf("0. ���� 1. ���̻��̰��� 2. �귿 ���� 3. ���Ըӽ� 4. ����");
		menu = get_only_one_char_or_number_xy(0, 1, '0', '4');
		system("cls");
		switch (menu) {
		case 0: exit(0);
		case 1: taisai(); break;
		case 2: rullet(); break;
		case 3: slot(); break;
		case 4: five_connect(); break;
		}
	}
	return 0;
}
