/*

2012244009 �̴��
������ https://dojang.io/mod/page/view.php?id=716
���Ϳ� �ο�

*/
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include"Fight.h"
#pragma warning(disable:4996) // warning C4996�� ��� ���� �ڵ�, ������ http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266

int fight(ChStat *chStat, int monLv) {
	int chSelect = 0, hp = 0;

	srand((unsigned)time(NULL));
	/*  
		seed�� ���, ������ http://www.jynote.net/64
		time_h���� unsigned int ������ �ս� ���, ������ http://m.cafe.daum.net/dotax/D8UA/274782?q=D_LhkOVB62tSZesOix-5K71w00&
	 */

	MonStat *mon = monster(monLv);
	hp = chStat->hp;

	while (mon->hp > 0 && chStat->hp > 0) { // ����, ������ hp�� 0�� �Ǹ� ����

		printf("1.����\t2.����\n");
		scanf("%d", &chSelect);
		
		printf("���� !!!\n");
		Sleep(1000);

		switch (chSelect) {
		case 1:
			if (rand() % 100 < mon->sheild) // ��������� ���� ���� �߻��� ��� ����
				printf("���� ���� !!!\n\n");
			else {
				if (rand() % 100 < chStat->critical) { // ũ��ƼĿ������ ���� ���� �߻��� ũ��Ƽ�� �߻�
					printf("ũ��Ƽ�� �߻�!!!\n\n");
					mon->hp = mon->hp - (chStat->attack + (chStat->critical * 3) - mon->sheild); // ���ݷ� = ���ݷ� + ũ���� - ������
				}
				else
					mon->hp = mon->hp - (chStat->attack - mon->sheild); // ���ݷ� = ���ݷ� - ������
				printf("����hp : %d\n\n", mon->hp);

			}
			break;
		case 2:
			break;
		}

		Sleep(1000);

		if (mon->hp <= 0) break; // ���Ͱ� ������ break;

		printf("���� ����!!!\n");
		Sleep(1000);
		if (rand() % 100 < chStat->sheild) // ��������� ���� ���� �߻��� ��� ����
			printf("���� ���� !!!\n");
		else {
			if (rand() % 100 < mon->critical) { // ũ��ƼĿ������ ���� ���� �߻��� ũ��Ƽ�� �߻�
				printf("ũ��Ƽ�� �߻�!!!\n");
				chStat->hp = chStat->hp - (mon->attack + (mon->critical * 3) - chStat->sheild); // ���ݷ� = ���ݷ� + ũ���� - ������
			}
			else
				chStat->hp = chStat->hp - (mon->attack - chStat->sheild); // ���ݷ� = ���ݷ� - ������
			printf("����hp : %d\n", chStat->hp);
		}

		if (chStat->hp <= 0) break; // ������ ������ break

		Sleep(1000);
		system("cls");

		printf("���� hp\n");
		printf("����hp : %d\n", chStat->hp);
		printf("����hp : %d\n", mon->hp);

		Sleep(2000);
		system("cls");

		getchar();
	}

	if (mon->hp <= 0) {
		printf("���� �¸� !\n");
		chStat->hp = hp; // hp ȸ��
		return 30 * monLv; // ���� ������ �˸��� ����ġ ��ȯ
	}
	else if (mon->hp < 0 && chStat->hp < 0) {
		chStat->hp = hp;
		printf("���º�....\n");
		return 0;
	}
	else {
		printf("��� ���� !\n");
		chStat->hp = hp; // hp ȸ��
		return -30 * monLv; // ���� ������ �˸��� -����ġ ��ȯ
	}
}
