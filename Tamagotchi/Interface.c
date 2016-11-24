#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include"Character.h"
#include"Interface.h"
#include"Display.h"
#include"SaveLoad.h"
#include"BinaryTree.h"
#include"Monster.h"

#pragma warning(disable:4996) // warning C4996�� ��� ���� �ڵ�, ������ http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266

/*

2012244063 ������
2012244009 �̴�� �ڵ����� �� �߰�
������ https://dojang.io/mod/page/view.php?id=716
���ӿ� �ʿ��� �������̽� ����

*/

void interfaceMain() {
	int select = 0, save = 0;
	const int x = 40, y = 15;
	ChStat *chStat;

	system("cls");
	select = selectStart(); // ���� �������̽����� ����

	if (select == 1) {
		chStat = character(1); // �ʱ�ȭ
		gotoxy(x, y);
		printf("�г����� �Է��ϼ��� : ");
		gotoxy(x + 25, y);
		fgets(chStat->name, 20, stdin); // �̸�����

		strcpy(chStat->condition, "�����");
		strcpy(chStat->digimon, "�ڿ��");

		menu(chStat);
	}

	else if (select == 2) { // �̾��ϱ�� �ҷ�����
		chStat = character(1); // �ʱ�ȭ
		save = selectLoad(chStat);
		chStat = LoadGame(chStat, save);
		if (!chStat->agility) {
			wait();
			interfaceMain();
			wait();
		}
		else {
			character(chStat->lv);
			menu(chStat);
		}
	}
}
void menu(ChStat* chStat) {
	int monLv = 0, number = 0, exp = 0, save = 0;
	const int x = 35, y = 15;

	system("cls");

	while (1) {
		digimonDisplay(chStat->lv);
		showStat();

		number = selectMove();

		switch (number) {
		case 1:
			monLv = selectAdventure(chStat->lv);

			exp = fight(chStat, monLv);
			chStat->exp += exp;
			addExp(chStat->exp);
			chStat = levelUp(chStat->lv);

			Sleep(1000);
			system("cls");
			break;
		case 2:
			save = selectSave(chStat->lv);
			SaveGame(chStat, save);
			break;
		case 3:
			digimonDisplay(chStat->lv);
			showStat();
			skillDescription(chStat);
			system("cls");
			break;
		case 4:
			digimonDisplay(chStat->lv);
			showAllStat();
			wait();
			system("cls");
			break;
		case 5:
			break;
		case 6:
			printf("����Ǿ����ϴ�\n");
			exit(0);
		case 7:
			save = selectLoad(chStat);
			chStat = LoadGame(chStat, save);
			if (!chStat->agility) {
				wait();
				menu(chStat);
			}
			break;
		}
	}
}
int selectStart() { // ���� �ʱ� �������̽� ����
	const int x = 45, y = 15; // ������ ��ǥ;
	int selectNum = 1;

	while (1) {
		int key = 1; // �ʱ�ȭ�� ���ϸ� if������ ������ ���Ƿ�, �ƹ� ���̳� �ʱ�ȭ.
		if (_kbhit()) // Ű �Է� ���� Ȯ�� ->http://showmiso.tistory.com/8
			key = _getch(); // Ű�� �Է� ����. ���ϴ� Ű������ ó�� ��ó

		if (key == UP) { // �� 72
			if (selectNum == 2) // selectNum�� 1���� Ŭ���(2 �̻�)
				selectNum -= 1;
			else continue; // �ƴϸ� ��� ����
		}
		else if (key == DOWN) { // �Ʒ� 80
			if (selectNum == 1) // selectNUm�� 2���� �������(2 ����)
				selectNum += 1;
			else continue; // �ƴϸ� ��� ����
		}

		else if (key == ENTER) { // ������ �ƽ�Ű��. ���Ͱ� �ԷµǾ�����, Ÿ��Ʋ�� Ż��. �� selectNum�� �ش��ϴ� ���� ����.
			system("cls"); // �޴� ��ħ ����
			break;
		}

		gotoxy(x, y);

		switch (selectNum) {
		case 1:
			printf("�� ó���ϱ�\n");
			gotoxy(x, y + 1);
			printf("   �̾��ϱ�\n");
			break;
		case 2:
			printf("   ó���ϱ�\n");
			gotoxy(x, y + 1);
			printf("�� �̾��ϱ�\n");
			break;
		}
	}
	return selectNum;
}
int selectMove(){ // ���ӻ� ���� �������̽� ����
	const int x = 60, y = 10;
	int selectNum = 1;
	
	while (1) {
		int key = 1; // �ʱ�ȭ�� ���ϸ� if������ ������ ���Ƿ�, �ƹ� ���̳� �ʱ�ȭ.

		if (_kbhit()) // Ű �Է� ���� Ȯ�� ->http://showmiso.tistory.com/8
			key = _getch(); // Ű�� �Է� ����. ���ϴ� Ű������ ó�� ��ó

		if (key == UP) { // �� 72
			if (selectNum >= 4) // selectNum�� 1,2,3���� Ŭ ���
				selectNum -= 3;
			else continue; // �ƴϸ� ��� ����
		}
		else if (key == DOWN) { // �Ʒ� 80
			if (selectNum <= 4) // selectNUm�� 4,5,6���� ���� ���
				selectNum += 3;
			else continue; // �ƴϸ� ��� ����
		}
		else if (key == LEFT) {
			if (selectNum > 1) // selectNum�� 1���� Ŭ ���
				selectNum -= 1;
			else continue; // �ƴϸ� ��� ����
		}
		else if (key == RIGHT) {
			if (selectNum < 7) // selectNUm�� 7���� ���� ���
				selectNum += 1;
			else continue; // �ƴϸ� ��� ����
		}
		else if (key == ENTER) { // ������ �ƽ�Ű��. ���Ͱ� �ԷµǾ�����, Ÿ��Ʋ�� Ż��. �� selectNum�� �ش��ϴ� ���� ����
			system("cls"); // �޴� ��ħ ����
			break;
		}

		gotoxy(x, y);

		switch (selectNum) {
		case 1:
			printf("�� ����     ����     ��ų");
			gotoxy(x, y + 1);
			printf("   ����     ����     ����");
			gotoxy(x, y + 2);
			printf("   �ҷ����� ");
			break;
		case 2:
			printf("   ����  �� ����     ��ų");
			gotoxy(x, y + 1);
			printf("   ����     ����     ����");
			gotoxy(x, y + 2);
			printf("   �ҷ����� ");
			break;
		case 3:
			printf("   ����     ����  �� ��ų");
			gotoxy(x, y + 1);
			printf("   ����     ����     ����");
			gotoxy(x, y + 2);
			printf("   �ҷ����� ");
			break;
		case 4:
			printf("   ����     ����     ��ų");
			gotoxy(x, y + 1);
			printf("�� ����     ����     ����");
			gotoxy(x, y + 2);
			printf("   �ҷ����� ");
			break;
		case 5:
			printf("   ����     ����     ��ų");
			gotoxy(x, y + 1);
			printf("   ����  �� ����     ����");
			gotoxy(x, y + 2);
			printf("   �ҷ����� ");
			break;
		case 6:
			printf("   ����     ����     ��ų");
			gotoxy(x, y + 1);
			printf("   ����     ����  �� ����");
			gotoxy(x, y + 2);
			printf("   �ҷ����� ");
			break;
		case 7:
			printf("   ����     ����     ��ų");
			gotoxy(x, y + 1);
			printf("   ����     ����     ����");
			gotoxy(x, y + 2);
			printf("�� �ҷ����� ");
			break;
		}
	}
	return selectNum;
}
int selectAdventure(int lv) { // ���輱�� �������̽�, �̴�� �߰�
	digimonDisplay(lv);
	showStat();
	int selectNum = 1;

	while (1) {
		int key = 1; // �ʱ�ȭ�� ���ϸ� if������ ������ ���Ƿ�, �ƹ� ���̳� �ʱ�ȭ.
		if (_kbhit()) // Ű �Է� ���� Ȯ�� ->http://showmiso.tistory.com/8
			key = _getch(); // Ű�� �Է� ����. ���ϴ� Ű������ ó�� ��ó

		if (key == UP) { // �� 72
			if (selectNum > 1) // selectNum�� 1���� Ŭ���(2 �̻�)
				selectNum -= 1;
			else continue; // �ƴϸ� ��� ����
		}
		else if (key == DOWN) { // �Ʒ� 80
			if (selectNum < 10) // selectNUm�� 2���� �������(2 ����)
				selectNum += 1;
			else continue; // �ƴϸ� ��� ����
		}

		else if (key == ENTER) { // ������ �ƽ�Ű��. ���Ͱ� �ԷµǾ�����, Ÿ��Ʋ�� Ż��. �� selectNum�� �ش��ϴ� ���� ����.
			system("cls"); // �޴� ��ħ ����
			break;
		}

		int x = 75, y = 8;
		gotoxy(x, y);

		switch (selectNum) {
		case 1:
			printf("�� ���� 1\n");
			gotoxy(x, ++y + 1);
			printf("   ���� 2\n");
			gotoxy(x, ++y + 2);
			printf("   ���� 3\n");
			gotoxy(x, ++y + 3);
			printf("   ���� 4\n");
			gotoxy(x, ++y + 4);
			printf("   ���� 5\n");
			gotoxy(x, ++y + 5);
			printf("   ���� 6\n");
			gotoxy(x, ++y + 6);
			printf("   ���� 7\n");
			gotoxy(x, ++y + 7);
			printf("   ���� 8\n");
			gotoxy(x, ++y + 8);
			printf("   ���� 9\n");
			gotoxy(x, ++y + 9);
			printf("   ���� 10\n");
			break;
		case 2:
			printf("   ���� 1\n");
			gotoxy(x, ++y + 1);
			printf("�� ���� 2\n");
			gotoxy(x, ++y + 2);
			printf("   ���� 3\n");
			gotoxy(x, ++y + 3);
			printf("   ���� 4\n");
			gotoxy(x, ++y + 4);
			printf("   ���� 5\n");
			gotoxy(x, ++y + 5);
			printf("   ���� 6\n");
			gotoxy(x, ++y + 6);
			printf("   ���� 7\n");
			gotoxy(x, ++y + 7);
			printf("   ���� 8\n");
			gotoxy(x, ++y + 8);
			printf("   ���� 9\n");
			gotoxy(x, ++y + 9);
			printf("   ���� 10\n");
			break;
		case 3:
			printf("   ���� 1\n");
			gotoxy(x, ++y + 1);
			printf("   ���� 2\n");
			gotoxy(x, ++y + 2);
			printf("�� ���� 3\n");
			gotoxy(x, ++y + 3);
			printf("   ���� 4\n");
			gotoxy(x, ++y + 4);
			printf("   ���� 5\n");
			gotoxy(x, ++y + 5);
			printf("   ���� 6\n");
			gotoxy(x, ++y + 6);
			printf("   ���� 7\n");
			gotoxy(x, ++y + 7);
			printf("   ���� 8\n");
			gotoxy(x, ++y + 8);
			printf("   ���� 9\n");
			gotoxy(x, ++y + 9);
			printf("   ���� 10\n");
			break;
		case 4:
			printf("   ���� 1\n");
			gotoxy(x, ++y + 1);
			printf("   ���� 2\n");
			gotoxy(x, ++y + 2);
			printf("   ���� 3\n");
			gotoxy(x, ++y + 3);
			printf("�� ���� 4\n");
			gotoxy(x, ++y + 4);
			printf("   ���� 5\n");
			gotoxy(x, ++y + 5);
			printf("   ���� 6\n");
			gotoxy(x, ++y + 6);
			printf("   ���� 7\n");
			gotoxy(x, ++y + 7);
			printf("   ���� 8\n");
			gotoxy(x, ++y + 8);
			printf("   ���� 9\n");
			gotoxy(x, ++y + 9);
			printf("   ���� 10\n");
			break;
		case 5:
			printf("   ���� 1\n");
			gotoxy(x, ++y + 1);
			printf("   ���� 2\n");
			gotoxy(x, ++y + 2);
			printf("   ���� 3\n");
			gotoxy(x, ++y + 3);
			printf("   ���� 4\n");
			gotoxy(x, ++y + 4);
			printf("�� ���� 5\n");
			gotoxy(x, ++y + 5);
			printf("   ���� 6\n");
			gotoxy(x, ++y + 6);
			printf("   ���� 7\n");
			gotoxy(x, ++y + 7);
			printf("   ���� 8\n");
			gotoxy(x, ++y + 8);
			printf("   ���� 9\n");
			gotoxy(x, ++y + 9);
			printf("   ���� 10\n");
			break;
		case 6:
			printf("   ���� 1\n");
			gotoxy(x, ++y + 1);
			printf("   ���� 2\n");
			gotoxy(x, ++y + 2);
			printf("   ���� 3\n");
			gotoxy(x, ++y + 3);
			printf("   ���� 4\n");
			gotoxy(x, ++y + 4);
			printf("   ���� 5\n");
			gotoxy(x, ++y + 5);
			printf("�� ���� 6\n");
			gotoxy(x, ++y + 6);
			printf("   ���� 7\n");
			gotoxy(x, ++y + 7);
			printf("   ���� 8\n");
			gotoxy(x, ++y + 8);
			printf("   ���� 9\n");
			gotoxy(x, ++y + 9);
			printf("   ���� 10\n");
			break;
		case 7:
			printf("   ���� 1\n");
			gotoxy(x, ++y + 1);
			printf("   ���� 2\n");
			gotoxy(x, ++y + 2);
			printf("   ���� 3\n");
			gotoxy(x, ++y + 3);
			printf("   ���� 4\n");
			gotoxy(x, ++y + 4);
			printf("   ���� 5\n");
			gotoxy(x, ++y + 5);
			printf("   ���� 6\n");
			gotoxy(x, ++y + 6);
			printf("�� ���� 7\n");
			gotoxy(x, ++y + 7);
			printf("   ���� 8\n");
			gotoxy(x, ++y + 8);
			printf("   ���� 9\n");
			gotoxy(x, ++y + 9);
			printf("   ���� 10\n");
			break;
		case 8:
			printf("   ���� 1\n");
			gotoxy(x, ++y + 1);
			printf("   ���� 2\n");
			gotoxy(x, ++y + 2);
			printf("   ���� 3\n");
			gotoxy(x, ++y + 3);
			printf("   ���� 4\n");
			gotoxy(x, ++y + 4);
			printf("   ���� 5\n");
			gotoxy(x, ++y + 5);
			printf("   ���� 6\n");
			gotoxy(x, ++y + 6);
			printf("   ���� 7\n");
			gotoxy(x, ++y + 7);
			printf("�� ���� 8\n");
			gotoxy(x, ++y + 8);
			printf("   ���� 9\n");
			gotoxy(x, ++y + 9);
			printf("   ���� 10\n");
			break;
		case 9:
			printf("   ���� 1\n");
			gotoxy(x, ++y + 1);
			printf("   ���� 2\n");
			gotoxy(x, ++y + 2);
			printf("   ���� 3\n");
			gotoxy(x, ++y + 3);
			printf("   ���� 4\n");
			gotoxy(x, ++y + 4);
			printf("   ���� 5\n");
			gotoxy(x, ++y + 5);
			printf("   ���� 6\n");
			gotoxy(x, ++y + 6);
			printf("   ���� 7\n");
			gotoxy(x, ++y + 7);
			printf("   ���� 8\n");
			gotoxy(x, ++y + 8);
			printf("�� ���� 9\n");
			gotoxy(x, ++y + 9);
			printf("   ���� 10\n");
			break;
		case 10:
			printf("   ���� 1\n");
			gotoxy(x, ++y + 1);
			printf("   ���� 2\n");
			gotoxy(x, ++y + 2);
			printf("   ���� 3\n");
			gotoxy(x, ++y + 3);
			printf("   ���� 4\n");
			gotoxy(x, ++y + 4);
			printf("   ���� 5\n");
			gotoxy(x, ++y + 5);
			printf("   ���� 6\n");
			gotoxy(x, ++y + 6);
			printf("   ���� 7\n");
			gotoxy(x, ++y + 7);
			printf("   ���� 8\n");
			gotoxy(x, ++y + 8);
			printf("   ���� 9\n");
			gotoxy(x, ++y + 9);
			printf("�� ���� 10\n");
			break;
		}
	}
	return selectNum;
}
int selectMotion() {
	int selectNum = 1; //selectNum �ʱ�ȭ
	const int x = 38, y = 19;
	
	while (1) {
		int key = 1; // �ʱ�ȭ�� ���ϸ� if������ ������ ���Ƿ�, �ƹ� ���̳� �ʱ�ȭ.

		if (_kbhit()) // Ű �Է� ���� Ȯ�� ->http://showmiso.tistory.com/8
			key = _getch(); // Ű�� �Է� ����. ���ϴ� Ű������ ó�� ��ó

		if (key == LEFT) {
			if (selectNum > 1) // selectNum�� 1���� Ŭ���(1 �̻�)
				selectNum -= 1;
			else continue; // �ƴϸ� ��� ����
		}
		else if (key == RIGHT) {
			if (selectNum < 4) // selectNUm�� 4���� �������(3 ����)
				selectNum += 1;
			else continue; // �ƴϸ� ��� ����
		}
		else if (key == ENTER) { // ������ �ƽ�Ű��. ���Ͱ� �ԷµǾ�����, Ÿ��Ʋ�� Ż��. �� selectNum�� �ش��ϴ� ���� ����
								 //system("cls"); // �޴� ��ħ ����
			break;
		}

		gotoxy(x, y);

		switch (selectNum) {
		case 1:
			printf("�� ����     ��ų     ����\n");
			break;
		case 2:
			printf("   ����  �� ��ų     ����\n");
			break;
		case 3:
			printf("   ����     ��ų  �� ����\n");
			break;
		}
	}
	return selectNum;
}
int selectSkill(ChStat *chStat) { // ��ų ���� �������̽�, �̴�� �߰�
	int selectNum = 1;
	const int x = 40, y = 25;

	while (1) {
		int key = 1; // �ʱ�ȭ�� ���ϸ� if������ ������ ���Ƿ�, �ƹ� ���̳� �ʱ�ȭ.

		if (_kbhit()) // Ű �Է� ���� Ȯ�� ->http://showmiso.tistory.com/8
			key = _getch(); // Ű�� �Է� ����. ���ϴ� Ű������ ó�� ��ó

		if (key == LEFT) {
			if (selectNum > 1) // selectNum�� 1���� Ŭ���(1 �̻�)
				selectNum -= 1;
			else continue; // �ƴϸ� ��� ����
		}
		else if (key == RIGHT) {
			if (selectNum < 2) // selectNUm�� 2���� �������(2 ����)
				selectNum += 1;
			else continue; // �ƴϸ� ��� ����
		}
		else if (key == ENTER) { // ������ �ƽ�Ű��. ���Ͱ� �ԷµǾ�����, Ÿ��Ʋ�� Ż��. �� selectNum�� �ش��ϴ� ���� ����
			//system("cls"); // �޴� ��ħ ����
			break;
		}
		gotoxy(x, y);

		if (!strcmp(chStat->digimon, "�ڿ��")) {
			printf("�� �����ġ��");
		}
		if (!strcmp(chStat->digimon, "�Ʊ���")) {
			switch (selectNum) {
			case 1:
				printf("�� �����Ҳ�       ����ȭ��\n");
				break;
			case 2:
				printf("   �����Ҳ�    �� ����ȭ��\n");
				break;
			}
		}
		else if (!strcmp(chStat->digimon, "�׷��̸�")) {
			switch (selectNum) {
			case 1:
				printf("�� ȭ�� ��        �ް�ȭ��\n");
				break;
			case 2:
				printf("   ȭ�� ��     �� �ް�ȭ��\n");
				break; 
			}
		}
		else if (!strcmp(chStat->digimon, "��Ż�׷��̸�")) {
			switch (selectNum) {
			case 1:
				printf("�� �ٿ��� �Ҳ�       �Ⱑ ��Ƽ���̾�\n");
				break;
			case 2:
				printf("   �ٿ��� �Ҳ�    �� �Ⱑ ��Ƽ���̾�\n");
				break;
			}
		}
		else if (!strcmp(chStat->digimon, "���׷��̸�")) {
			switch (selectNum) {
			case 1:
				printf("�� �׶󱤼�       ���̾�����\n");
				break;
			case 2:
				printf("   �׶󱤼�    �� ���̾�����\n");
				break;
			}
		}
		else if (!strcmp(chStat->digimon, "���ް���")) {
			switch (selectNum) {
			case 1:
				printf("�� �׷��̰�       ����ĳ��\n");
				break;
			case 2:
				printf("   �׷��̰�    �� ����ĳ��\n");
				break;
			}
		}
	}
	return selectNum;
}
int selectSave(int lv) {
	digimonDisplay(lv);
	showStat();
	
	int selectNum = 1;
	Name *name = (Name*)malloc(sizeof(Name)); // ����ü������ �������� �Ҵ�
	FILE *fp1 = fopen("save1.txt", "rt");
	FILE *fp2 = fopen("save2.txt", "rt");
	FILE *fp3 = fopen("save3.txt", "rt");

	if (fp1 == NULL) strcpy(name->name1, "��");
	else fscanf(fp1, "%s", name->name1);

	if (fp2 == NULL) strcpy(name->name2, "��");
	else fscanf(fp2, "%s", name->name2);

	if (fp3 == NULL) strcpy(name->name3, "��");
	else fscanf(fp3, "%s", name->name3);

	if (!strcmp(name->name1, "�����") || !strcmp(name->name1, "�����") || !strcmp(name->name1, "������") || !strcmp(name->name1, "����ü") ||
		!strcmp(name->name1, "�ñ�ü") || !strcmp(name->name1, "�ʱñ�ü")) // �̸��� ������ ���� ����ó��
		strcpy(name->name1, " ");
	else if (!strcmp(name->name2, "�����") || !strcmp(name->name2, "�����") || !strcmp(name->name2, "������") || !strcmp(name->name2, "����ü") ||
		!strcmp(name->name2, "�ñ�ü") || !strcmp(name->name2, "�ʱñ�ü")) // �̸��� ������ ���� ����ó��
		strcpy(name->name2, " ");
	else if (!strcmp(name->name3, "�����") || !strcmp(name->name3, "�����") || !strcmp(name->name3, "������") || !strcmp(name->name3, "����ü") ||
		!strcmp(name->name3, "�ñ�ü") || !strcmp(name->name3, "�ʱñ�ü")) // �̸��� ������ ���� ����ó��
		strcpy(name->name3, " ");
		
	while (1) {
		int key = 1; // �ʱ�ȭ�� ���ϸ� if������ ������ ���Ƿ�, �ƹ� ���̳� �ʱ�ȭ.
		if (_kbhit()) // Ű �Է� ���� Ȯ�� ->http://showmiso.tistory.com/8
			key = _getch(); // Ű�� �Է� ����. ���ϴ� Ű������ ó�� ��ó

		if (key == UP) { // �� 72
			if (selectNum > 1) // selectNum�� 1���� Ŭ���(2 �̻�)
				selectNum -= 1;

			else continue; // �ƴϸ� ��� ����
		}
		else if (key == DOWN) { // �Ʒ� 80
			if (selectNum < 3) // selectNUm�� 3���� �������(3 ����)
				selectNum += 1;

			else continue; // �ƴϸ� ��� ����
		}

		else if (key == ENTER) { // ������ �ƽ�Ű��. ���Ͱ� �ԷµǾ�����, Ÿ��Ʋ�� Ż��. �� selectNum�� �ش��ϴ� ���� ����.
			system("cls"); // �޴� ��ħ ����
			break;
		}
		int x = 75, y = 8;
		gotoxy(x, y);

		switch (selectNum) {
		case 1:
			printf("�� %s ����", name->name1);
			gotoxy(x, ++y + 1);
			printf("   %s ����", name->name2);
			gotoxy(x, ++y + 2);
			printf("   %s ����", name->name3);
			break;
		case 2:
			printf("   %s ����", name->name1);
			gotoxy(x, ++y + 1);
			printf("�� %s ����", name->name2);
			gotoxy(x, ++y + 2);
			printf("   %s ����", name->name3);
			break;
		case 3:
			printf("   %s ����", name->name1);
			gotoxy(x, ++y + 1);
			printf("   %s ����", name->name2);
			gotoxy(x, ++y + 2);
			printf("�� %s ����", name->name3);
			break;
		}
	}
	int count1 = 1, count2 = 1, count3 = 1;

	if (!strcmp(name->name1, "��")) count1--;
	if (!strcmp(name->name2, "��")) count2--;
	if (!strcmp(name->name3, "��")) count3--;

	if (count1) fclose(fp1);
	if (count2) fclose(fp2);
	if (count3) fclose(fp3);

	free(name);

	return selectNum;
}
int selectLoad(ChStat *chStat) {
	int selectNum = 1;
	Name *name = (Name*)malloc(sizeof(Name)); // ����ü������ �������� �Ҵ�
	FILE *fp1 = fopen("save1.txt", "rt");
	FILE *fp2 = fopen("save2.txt", "rt");
	FILE *fp3 = fopen("save3.txt", "rt");

	if (fp1 == NULL) strcpy(name->name1, "��");
	else fscanf(fp1, "%s", name->name1);
	
	if (fp2 == NULL) strcpy(name->name2, "��");
	else fscanf(fp2, "%s", name->name2);

	if (fp3 == NULL) strcpy(name->name3, "��");
	else fscanf(fp3, "%s", name->name3);

	if (!strcmp(name->name1, "�����") || !strcmp(name->name1, "�����") || !strcmp(name->name1, "������") || !strcmp(name->name1, "����ü") ||
		!strcmp(name->name1, "�ñ�ü") || !strcmp(name->name1, "�ʱñ�ü")) // �̸��� ������ ���� ����ó��
		strcpy(name->name1, " ");
	else if (!strcmp(name->name2, "�����") || !strcmp(name->name2, "�����") || !strcmp(name->name2, "������") || !strcmp(name->name2, "����ü") ||
		!strcmp(name->name2, "�ñ�ü") || !strcmp(name->name2, "�ʱñ�ü")) // �̸��� ������ ���� ����ó��
		strcpy(name->name2, " ");
	else if (!strcmp(name->name3, "�����") || !strcmp(name->name3, "�����") || !strcmp(name->name3, "������") || !strcmp(name->name3, "����ü") ||
		!strcmp(name->name3, "�ñ�ü") || !strcmp(name->name3, "�ʱñ�ü")) // �̸��� ������ ���� ����ó��
		strcpy(name->name3, " ");

	while (1) {
		int key = 1; // �ʱ�ȭ�� ���ϸ� if������ ������ ���Ƿ�, �ƹ� ���̳� �ʱ�ȭ.
		if (_kbhit()) // Ű �Է� ���� Ȯ�� ->http://showmiso.tistory.com/8
			key = _getch(); // Ű�� �Է� ����. ���ϴ� Ű������ ó�� ��ó

		if (key == UP) { // �� 72
			if (selectNum > 1) // selectNum�� 1���� Ŭ���(2 �̻�)
				selectNum -= 1;

			else continue; // �ƴϸ� ��� ����
		}
		else if (key == DOWN) { // �Ʒ� 80
			if (selectNum < 3) // selectNUm�� 3���� �������(3 ����)
				selectNum += 1;

			else continue; // �ƴϸ� ��� ����
		}

		else if (key == ENTER) { // ������ �ƽ�Ű��. ���Ͱ� �ԷµǾ�����, Ÿ��Ʋ�� Ż��. �� selectNum�� �ش��ϴ� ���� ����.
			system("cls"); // �޴� ��ħ ����
			break;
		}

		int x = 44, y = 14;
		gotoxy(x, y);

		switch (selectNum) {
		case 1:
			printf("�� %s ����", name->name1);
			gotoxy(x, ++y + 1);
			printf("   %s ����", name->name2);
			gotoxy(x, ++y + 2);
			printf("   %s ����", name->name3);
			break;
		case 2:
			printf("   %s ����", name->name1);
			gotoxy(x, ++y + 1);
			printf("�� %s ����", name->name2);
			gotoxy(x, ++y + 2);
			printf("   %s ����", name->name3);
			break;
		case 3:
			printf("   %s ����", name->name1);
			gotoxy(x, ++y + 1);
			printf("   %s ����", name->name2);
			gotoxy(x, ++y + 2);
			printf("�� %s ����", name->name3);
			break;
		}
	}
	int count1 = 1, count2 = 1, count3 = 1;

	if (!strcmp(name->name1, "��")) count1--;
	if (!strcmp(name->name2, "��")) count2--;
	if (!strcmp(name->name3, "��")) count3--;

	if (count1) fclose(fp1);
	if (count2) fclose(fp2);
	if (count3) fclose(fp3);
	
	free(name);

	return selectNum;
}
void wait() { // ���� �Է� �� ���� ���, �̴�� �߰�
	int key = 1;

	while (1) {
		if (_kbhit()) // Ű �Է� ���� Ȯ�� ->http://showmiso.tistory.com/8
			key = _getch(); // Ű�� �Է� ����. ���ϴ� Ű������ ó�� ��ó

		if (key == ENTER) 
			break; // ������ �ƽ�Ű��, ���Ͱ� �ԷµǾ����� Ż��
	}
}
void printTitle()
{
	int x = 10, y = 3;

	system("mode con: cols=140 lines=28");//���� , ���� ->http://berabue.tistory.com/59
	gotoxy(x, y++);
	printf(" [(\\\?,                    +|             |!                    ?xCCY|I                      ^(YCCr[.  :$i          `J< \n");
	gotoxy(x, y++);
	printf(" $&xuXqq$$dl                 m$X           O$v                 `b$ku||nZ$0                   {$$Lu[jc#v  j$l          >$x \n");
	gotoxy(x, y++);
	printf(" &0       X$X                OW$;         +$8n                )$u                           a$<          j$l              \n");
	gotoxy(x, y++);
	printf(" &O        +$/      i~l      ZdX@         $18n      :~<      -$+                 >~i       d@            j$I  >~^         \n");
	gotoxy(x, y++);
	printf(" &O         w@   +@$pZ#$t    Z* $U       wW $n    o$aZd$w    @0               ~$$qmb$o^   <$!            j$jZ@Zm$$I    $} \n");
	gotoxy(x, y++);
	printf(" &O         ($^  ?;    i$~   Z* i$I     _$. $n   ,[     $J  l$>              f$?     n$I  C$             j$$+    O$    $] \n");
	gotoxy(x, y++);
	printf(" &O         }$,         @z   Z*  L$     $t  $n          J8  ]$:     {@&&#q  `$}       qW  dW             j$|     j$>   $] \n");
	gotoxy(x, y++);
	printf(" &O         u$    {O&8$#$z   Z*   $U   qW   $n    iJ*&$8@&  l$~         Y@  ($        )$  Q$             j$;     .$~   $] \n");
	gotoxy(x, y++);
	printf(" &O         $J   $a_    $X   Z*   l$l -$`   $n   w$1^   v$   @m         zB  |$        )$  ~$+            j$l     `$<   $] \n");
	gotoxy(x, y++);
	printf(" &O        &8   z$      $z   Z*    U@ $/    $n  !$j     a8   ?$)        cB  j$]       b*   d$.           j$l     `$<   $] \n");
	gotoxy(x, y++);
	printf(" &Q     !Y$0    f$`    *$z   Z*     @B#     $n  j$(    J$&    1$q:      O$   r$?     U$^    w$x       I  j$l     `$<   $] \n");
	gotoxy(x, y++);
	printf(" $$$B$$$Wv.      U$amM$.@C   d8     l$`     $z   [$Bmh$}X$      U$$$qW$$d[    _B$dwo$w       id$$MqB$$(  :$i     `$+   ${ \n");
	gotoxy(x, y++);
	printf("                   i<                              :<,             >>>           ><:            .>>l                      \n");

	gotoxy(60, y + 6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("Plese press EnterKey...");

	while (1)//---------------------------------------------------------------------------------Ÿ��Ʋ�� while��
	{
		if (_kbhit())//Ű �Է� ���� Ȯ�� ->http://showmiso.tistory.com/8
		{
			system("mode con: cols=100 lines=30");//���� , ���� ->http://berabue.tistory.com/59
												  //�ƹ�Ű �Է� �޾�����, ȣ��Ǵ� �Լ� �Է�
			wait();
			break;
		}
	}
}
/*
void fightInterface(ChStat *chStat, MonStat *mon) { // �ο�� ���÷���
	const int chX = 50, chY = 27, monX = 5, monY = 2; // hp�� ��ġ ����
	int i = 0;

	enemyDisplay(mon->lv);
	digimonDisplay(chStat->lv);

	gotoxy(chX - 14, chY);
	printf("%s hp : ", chStat->digimon);
	gotoxy(chX, chY);
	for (i = 1; i <= chStat->hp; i++) {
		printf("l");
		if (i == 50)
			gotoxy(chX, chY+1);
	}
	gotoxy(monX, monY);
	printf("���� hp : ");
	gotoxy(monX + 12, monY);
	for (i = 1; i <= mon->hp; i++)
		printf("l");
	gotoxy(75 , 25);
	printf("��� : ");
	gotoxy(83, 25);
	for (i = 1; i <= chStat->energy; i++)
		printf("��");
}
*/
void printUser(ChStat *chStat) { // �������� ������ ���� ���÷��� 2016 11 25 ������ ����
	const int chX = 5, chY = 2; // hp�� ��ġ ����
	int i = 0;


	digimonDisplay(chStat->lv);

	gotoxy(chX , chY);
	printf("%s hp : ", chStat->digimon);

	gotoxy(chX+12, chY);
	for (i = 1; i <= chStat->hp; i++) {
		printf("l");
		if (i == 50)
			gotoxy(chX, chY + 1);
	}


	gotoxy(75, 25);
	printf("��� : ");
	gotoxy(83, 25);
	for (i = 1; i <= chStat->energy; i++)
		printf("��");
}
void printMon(MonStat *mon)//�������� ������ ���� ���÷��� 2016 11 25 ������ ����
{
	const int monX = 5, monY = 2;
	int i = 0;

	enemyDisplay(mon->lv);//**

	gotoxy(monX, monY);//**
	printf("���� hp : ");
	gotoxy(monX + 12, monY);
	for (i = 1; i <= mon->hp; i++)
		printf("l");//**

}

void userAtMotion1()
{
	gotoxy(38, 19);//������ �������̽��� ����(���� ��� ����)
	printf("                           ");
	
	int x, y, speed;

	x = 30, y = 20, speed = 20;

	while (1)
	{
		gotoxy(x, y);
		printf("����");
		Sleep(speed);
		x += 1;
		if (x == 95)//ȭ���� ��
			break;
	}

	gotoxy(x, y);//������ ���ݸ��(ȭ����� ū ������ ����)�� ȭ�鿡�� �ʱ�ȭ
	printf("   ");

	x += 1;
	gotoxy(x, y);
	printf("���");
	Sleep(speed);


	gotoxy(x, y);//������ ���ݸ��(ȭ����� ū ������ ����)�� ȭ�鿡�� �ʱ�ȭ
	printf("   ");

	x += 1;
	gotoxy(x, y);
	printf("��");
	Sleep(speed);//ȭ��󿡼� ����������

	gotoxy(x, y);
	printf("  ");

}
void userAtMotion2()
{
	int x, y, speed;

	x = 0, y = 20, speed = 20;

	while (1)
	{
		gotoxy(x, y);
		printf("����");
		Sleep(speed);
		x += 1;
		if (x == 70)//���Ϳ� ��� ����
			break;
	}


	gotoxy(x, y); //������ ���ݸ���� ȭ�鿡�� �ʱ�ȭ
	printf("      ");

}
void monAtMotion()
{
	int x, y, speed;

	x = 70, y = 10, speed = 20;

	while (1)
	{
		gotoxy(x, y);
		printf("����");
		Sleep(speed);
		x -= 1;
		if (x == 0)//ȭ���� ��
			break;
	}

	gotoxy(x, y);//������ ���ݸ��(ȭ����� ū ������ ����)�� ȭ�鿡�� �ʱ�ȭ
	printf("         ");

	//x -= 1;
	gotoxy(x, y);
	printf("���");
	Sleep(speed);


	gotoxy(x, y);//������ ���ݸ��(ȭ����� ū ������ ����)�� ȭ�鿡�� �ʱ�ȭ
	printf("       ");

	//x-= 1;
	gotoxy(x, y);
	printf("��");
	Sleep(speed);

	gotoxy(x, y);
	printf("      ");
}
void disappear() { // goto���� �����̴� �ܼ��� Ŀ�� ����, ������ http://tip.daum.net/question/39372106
	HANDLE hConsole; // �ܼ� �ڵ�
	CONSOLE_CURSOR_INFO ConsoleCursor; // �ܼ�Ŀ�� ���� ����ü

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �ڵ��� ���ϰ�

	ConsoleCursor.bVisible = 0; // 1 ���� , 0 �Ⱥ���
	ConsoleCursor.dwSize = 1; // Ŀ�� ������

	SetConsoleCursorInfo(hConsole, &ConsoleCursor); // ����
}
void gotoxy(int x, int y) { // goto �Լ�����, ������ http://m.blog.naver.com/bestheroz/110240153
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}