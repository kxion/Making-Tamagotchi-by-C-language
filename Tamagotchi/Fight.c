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

#pragma warning(disable:4996) // warning C4996�� ��� ���� �ڵ�, ������ http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266

int fight(ChStat *chStat, int monLv) {
	const int x = 40, y = 27;
	int chSelect = 0, i = 0;

	srand((unsigned)time(NULL));
	/*  
		seed�� ���, ������ http://www.jynote.net/64
		time_h���� unsigned int ������ �ս� ���, ������ http://m.cafe.daum.net/dotax/D8UA/274782?q=D_LhkOVB62tSZesOix-5K71w00&
	 */

	MonStat *mon = monster(monLv);

	while (mon->hp > 0 && chStat->hp > 0) { // ����, ������ hp�� 0�� �Ǹ� ����
		fightInterface(chStat->hp, mon->hp);

		gotoxy(x, y);
		printf("1.����\t2.����\n");
		scanf("%d", &chSelect);
		
		gotoxy(x, y+2);
		printf("���� !!!\n");
		Sleep(1000);

		switch (chSelect) {
		case 1:
			gotoxy(x, y+3);
			if (rand() % 100 < mon->sheild) // ��������� ���� ���� �߻��� ��� ����
				printf("���� ���� !!!\n\n");
			else {
				if (rand() % 100 < chStat->critical) { // ũ��ƼĿ������ ���� ���� �߻��� ũ��Ƽ�� �߻�
					printf("ũ��Ƽ�� �߻�!!!\n\n");
					mon->hp = mon->hp - (chStat->attack + (chStat->critical * 3) - mon->sheild); // ���ݷ� = ���ݷ� + ũ���� - ������
				}
				else
					mon->hp = mon->hp - (chStat->attack - mon->sheild); // ���ݷ� = ���ݷ� - ������
				system("cls");
				fightInterface(chStat->hp, mon->hp);
			}
			break;
		case 2:
			break;
		}

		Sleep(1000);

		if (mon->hp <= 0) break; // ���Ͱ� ������ break;

		gotoxy(x, y+2);
		printf("���� ����!!!\n");
		Sleep(1000);

		gotoxy(x, y + 3);
		if (rand() % 100 < chStat->sheild) // ��������� ���� ���� �߻��� ��� ����
			printf("���� ���� !!!\n");
		else {
			if (rand() % 100 < mon->critical) { // ũ��ƼĿ������ ���� ���� �߻��� ũ��Ƽ�� �߻�
				printf("ũ��Ƽ�� �߻�!!!\n");
				chStat->hp = chStat->hp - (mon->attack + (mon->critical * 3) - chStat->sheild); // ���ݷ� = ���ݷ� + ũ���� - ������
			}
			else
				chStat->hp = chStat->hp - (mon->attack - chStat->sheild); // ���ݷ� = ���ݷ� - ������
			system("cls");
			fightInterface(chStat->hp, mon->hp);
		}

		if (chStat->hp <= 0) break; // ������ ������ break

		Sleep(1000);
		system("cls");

		getchar();
	}

	if (mon->hp <= 0) {
		printf("���� �¸� !\n");
		return 30 * monLv; // ���� ������ �˸��� ����ġ ��ȯ
	}
	else if (mon->hp < 0 && chStat->hp < 0) {
		printf("���º�....\n");
		return 0;
	}
	else {
		printf("��� ���� !\n");
		return -30 * monLv; // ���� ������ �˸��� -����ġ ��ȯ
	}
}
