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


#pragma warning(disable:4996) // warning C4996�� ��� ���� �ڵ�, ������ http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266

int fight(ChStat *chStat, int monLv) {
	const int x = 40, y = 27;
	int chSelect = 0, i = 0, money = 0, skSelect = 0, monHp = 0, chHp = 0, attack = 0;

	srand((unsigned)time(NULL));
	/*  
		seed�� ���, ������ http://www.jynote.net/64
		time_h���� unsigned int ������ �ս� ���, ������ http://m.cafe.daum.net/dotax/D8UA/274782?q=D_LhkOVB62tSZesOix-5K71w00&
	 */

	MonStat *mon = monster(monLv);

	monHp = mon->hp; // hp �ʱ�ȭ
	chHp = chStat->hp; // hp �ʱ�ȭ
	attack = chStat->attack; // ���ݰ� �ʱ�ȭ

	while (mon->hp > 0 && chStat->hp > 0) { // ����, ������ hp�� 0�� �Ǹ� ����
		fightInterface(chStat->hp, mon->hp, chStat->lv, mon->lv);

		chSelect = selectMotion();
				
		switch (chSelect) {
		case 1:
			gotoxy(x, y + 2);
			printf("���� !!!\n");
			Sleep(1000);
			break;
		case 2:
			skSelect = selectSkill();
			switch (skSelect) {
			case 1: 
				gotoxy(x, y + 4);
				printf("���� �Ҳ� !!!\n");
				chStat->attack = agumonSkill_1(chStat->attack);
				break;
			case 2: 
				gotoxy(x, y + 4);
				printf("���� ȭ�� !!!\n");
				chStat->attack = agumonSkill_2(chStat->attack);
				break;
			}
			break;
		case 3:
			break;
		}

		gotoxy(x, y + 3);
		if (rand() % 100 < mon->sheild) { // ��������� ���� ���� �߻��� ��� ����
			printf("���� ���� !!!\n\n");
			Sleep(1000);
		}
		else {
			if (rand() % 100 < chStat->agility) { // ũ��ƼĿ������ ���� ���� �߻��� ũ��Ƽ�� �߻�
				printf("ũ��Ƽ�� �߻�!!!\n\n");
				Sleep(1000);
				mon->hp = mon->hp - (chStat->attack + (chStat->agility * 3) - mon->sheild); // ���ݷ� = ���ݷ� + ũ���� - ������
			}
			else
				mon->hp = mon->hp - (chStat->attack - mon->sheild); // ���ݷ� = ���ݷ� - ������
			Sleep(1000);
			system("cls");
			chStat->attack = attack;
			fightInterface(chStat->hp, mon->hp, chStat->lv, mon->lv);
		}

		Sleep(1000);

		if (mon->hp <= 0) break; // ���Ͱ� ������ break;

		gotoxy(x, y+2);
		printf("���� ����!!!\n");
		Sleep(1000);

		gotoxy(x, y + 3);
		if (rand() % 100 < chStat->health) { // ��������� ���� ���� �߻��� ��� ����
			printf("���� ���� !!!\n");
			Sleep(1000);
		}
		else {
			if (rand() % 100 < mon->critical) { // ũ��ƼĿ������ ���� ���� �߻��� ũ��Ƽ�� �߻�
				printf("ũ��Ƽ�� �߻�!!!\n");
				Sleep(1000);
				chStat->hp = chStat->hp - (mon->attack + (mon->critical * 3) - chStat->health); // ���ݷ� = ���ݷ� + ũ���� - ������
			}
			else
				chStat->hp = chStat->hp - (mon->attack - chStat->health); // ���ݷ� = ���ݷ� - ������
			system("cls");
			fightInterface(chStat->hp, mon->hp, chStat->lv, mon->lv);
		}

		if (chStat->hp <= 0) break; // ������ ������ break

		Sleep(1000);
		system("cls");

	}

	if (mon->hp <= 0) {
		printf("���� �¸� !\n");
		chStat->money += 500 * monLv;
		mon->hp = monHp;
		chStat->hp = chHp;
		return 20 * monLv; // ���� ������ �˸��� ����ġ ��ȯ
	}
	else if (mon->hp < 0 && chStat->hp < 0) {
		printf("���º�....\n");
		mon->hp = monHp;
		chStat->hp = chHp;
		return 0;
	}
	else {
		printf("��� ���� !\n");
		mon->hp = monHp;
		chStat->hp = chHp;
		return -30 * monLv; // ���� ������ �˸��� -����ġ ��ȯ
	}
}
