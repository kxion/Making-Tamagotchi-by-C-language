/*

2012244009 �̴��
������ https://dojang.io/mod/page/view.php?id=716
���Ϳ� �ο�

*/
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include"Fight.h"
#include"Interface.h"
#include"Skill.h"
#include"Display.h"


#pragma warning(disable:4996) // warning C4996�� ��� ���� �ڵ�, ������ http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266

int fight(ChStat *chStat, int monLv) {
	const int x = 38, y = 23;
	int chSelect = 0, money = 0, skSelect = 0, monHp = 0, chHp = 0, chAttack = 0, monAttack = 0;

	srand((unsigned)time(NULL));
	/*  
		seed�� ���, ������ http://www.jynote.net/64
		time_h���� unsigned int ������ �ս� ���, ������ http://m.cafe.daum.net/dotax/D8UA/274782?q=D_LhkOVB62tSZesOix-5K71w00&
	 */

	MonStat *mon = monster(monLv);

	monHp = mon->hp; // hp �ʱ�ȭ
	chHp = chStat->hp; // hp �ʱ�ȭ
	chAttack = chStat->attack; // ���ݰ� �ʱ�ȭ
	monAttack = mon->attack;

	while (mon->hp > 0 && chStat->hp > 0) { // ����, ������ hp�� 0�� �Ǹ� ����
		
		printUser(chStat);// �������� ������ ���� ���÷��� 2016 11 25 ������ ����
		//printMon(mon);//�������� ������ ���� ���÷��� 2016 11 25 ������ ����

		chSelect = selectMotion();
				
		switch (chSelect) {
		case 1:
			attackMotion();
			system("cls");
			printMon(mon);
			if (chStat->energy < 5)
				chStat->energy = chStat->energy + 1;
			break;
		case 2:
			skSelect = selectSkill(chStat);
			chStat = skillDisplay(chStat, skSelect);//****
			break;
		case 3:
			menu(chStat);
			break;
		}
		
		gotoxy(x, y);
		if (rand() % 100 < mon->sheild) { // ��������� ���� ���� �߻��� ��� ����
			printf("���� ���� !!!\n\n");
			Sleep(500);
		}
		else {
			if (rand() % 100 < chStat->agility) { // ũ��ƼĿ������ ���� ���� �߻��� ũ��Ƽ�� �߻�
				printf("ũ��Ƽ�� �߻�!!!\n\n");
				gotoxy(x, y+2);
				printf("������ : %2d", chStat->attack + chStat->agility - mon->sheild);
				Sleep(500);
				mon->hp = mon->hp - (chStat->attack + chStat->agility - mon->sheild); // ���ݷ� = ���ݷ� + ũ���� - ������
			}
			else {
				printf("������ : %2d", chStat->attack - mon->sheild);
				Sleep(500);
				mon->hp = mon->hp - (chStat->attack - mon->sheild); // ���ݷ� = ���ݷ� - ������
			}
			Sleep(500);
			system("cls");
			//printUser(chStat);// �������� ������ ���� ���÷��� 2016 11 25 ������ ����
			printMon(mon);//�������� ������ ���� ���÷��� 2016 11 25 ������ ����
		}

		Sleep(500);

		if (mon->hp <= 0) break; // ���Ͱ� ������ break;

		gotoxy(x, y+2);
		printf("���� ����!!!\n");
		Sleep(500);

		gotoxy(x, y);
		if (rand() % 100 < chStat->health) { // ��������� ���� ���� �߻��� ��� ����
			printf("���� ���� !!!\n");
			Sleep(500);
		}
		else {
			if (rand() % 100 < mon->critical) { // ũ��ƼĿ������ ���� ���� �߻��� ũ��Ƽ�� �߻�
				printf("ũ��Ƽ�� �߻�!!!\n");
				gotoxy(x, y + 2);
				Sleep(500);
				printf("������ : %2d", mon->attack + mon->critical - chStat->health);
				chStat->hp = chStat->hp - (mon->attack + mon->critical - chStat->health); // ���ݷ� = ���ݷ� + ũ���� - ������
			}
			else {
				chStat->hp = chStat->hp - (mon->attack - chStat->health); // ���ݷ� = ���ݷ� - ������
				printf("������ : %2d", mon->attack - chStat->health);
				Sleep(500);
			}
			system("cls");
			printUser(chStat);// �������� ������ ���� ���÷��� 2016 11 25 ������ ����
			printMon(mon);//�������� ������ ���� ���÷��� 2016 11 25 ������ ����
		}

		if (chStat->hp <= 0) break; // ������ ������ break
		chStat->energy;
		if (chStat->energy < 5)
			chStat->energy = chStat->energy + 1;
		Sleep(500);
		system("cls");

		chStat->attack = chAttack;
		mon->attack = monAttack;
	}

	//chStat->attack = chAttack;
	//mon->attack = monAttack;

	if (mon->hp <= 0) {
		printWin();//win �̹���
		chStat->money += 500 * monLv;
		mon->hp = monHp;
		chStat->hp = chHp;
		chStat->energy = 0;
		return 20 * monLv; // ���� ������ �˸��� ����ġ ��ȯ
	}
	else if (mon->hp < 0 && chStat->hp < 0) {
		printf("���º�....\n");
		mon->hp = monHp;
		chStat->hp = chHp;
		chStat->energy = 0;
		return 0;
	}
	else {
		printLose();//lose �̹���
		mon->hp = monHp;
		chStat->hp = chHp;
		chStat->energy = 0;
		return -30 * monLv; // ���� ������ �˸��� -����ġ ��ȯ
	}
}
