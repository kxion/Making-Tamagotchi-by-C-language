#include<stdio.h>
#include<windows.h>
#include"Character.h"
#pragma warning(disable:4996) // scanf ������ ��� ���� ���, ������ http://enter.tistory.com/14

int main() {
	int lv = 0, monLv = 0, number = 0, exp = 0;

	printf("lv ���� : ");
	scanf("%d", &lv);

	while (1) {
		ChStat *chStat = character(lv);

		printf("���� : %d hp : %d  �� : %d  �� : %d  ũ�� : %d  ����ġ : %d\n", lv, chStat->hp, chStat->attack, chStat->sheild, chStat->critical, chStat->exp);
		
		printf("1.����\t2.�ο��\t3.�����ϱ�\n");
		scanf("%d", &number);
		
		switch (number) {
		case 1:
			printf("���� ���� ���� : ");
			scanf("%d", &monLv);

			exp = fight(chStat, monLv);
			chStat->exp += exp;
			addExp(chStat->exp);
			lv = levelUp(lv);

			Sleep(2000);
			system("cls");
			break;
		case 2:
			break;
		case 3:
			printf("����\n");
			exit(0);
		}
	}
	
	return 0;
}