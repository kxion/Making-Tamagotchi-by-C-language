
/*

2012244009 �̴��
������ https://dojang.io/mod/page/view.php?id=716
ĳ���Ϳ� ���õ� �ҽ� ( ����, ���� )

*/


#include<stdio.h>
#include<Windows.h>
#include"Character.h"
#include"Interface.h"


ChStat chStat; // ĳ���� ������ ������ ����ü ����
ChStat *pChStat = &chStat; // ĳ���� ������ ����ü ����
int hp = 0, exp = 0;

ChStat* character(int lv) { // ĳ���� ������ �ش��ϴ� ����
	chStat.lv = lv; // ����
	chStat.attack = 2 * lv; // ���ݷ�
	chStat.health = 1 * lv; // ����
	chStat.hp = 7 * lv ; // ��
	chStat.agility = 0 + lv; // ũ��Ƽ�� Ȯ��
	chStat.gauge = 0; // ������ 0���� �ʱ�ȭ
	
	hp = chStat.hp;
	exp = chStat.lv * 50;

	return pChStat;
}
void addExp(int exp) { // ��� ������ ����ġ ����
	chStat.exp = exp;
}
void delExp(int exp) { // ��� ���н� ����ġ �ս�
	chStat.exp = exp;
}
ChStat* levelUp(int lv) { // ���� ���� Ȯ��
	if (chStat.exp >= lv * 50) {
		printf("���� ��!!!\n");
		printf("LEVEL : %d�� �Ǿ����ϴ� !!\n", ++lv);
		chStat.exp = 0;
		character(lv);
	}
	else if (lv == 30) // �ִ뷹�� 10���� ����
		lv = 30;

	return pChStat;
}
void showStat() {
	const int x = 35, y = 20;

	gotoxy(x, y);
	printf("�̸� : %s", chStat.name);

	gotoxy(x, y + 1);
	printf("���� : %s", chStat.condition);

	gotoxy(x, y+2);
	printf("���� : %d", chStat.lv);

	gotoxy(x, y+3);
	printf("ü�� : %d / %d", chStat.hp, hp);
	
	gotoxy(x, y+4);
	printf("������ : %d", chStat.gauge);

	gotoxy(x, y + 5);
	printf("����ġ : %d / %d", chStat.exp, exp);

	gotoxy(x, y + 6);
	printf("������ : %d", chStat.money);
}
void showAllStat() {
	const int x = 50, y = 18;

	gotoxy(x+5, y);
	printf(" [ %s�� ����â ] ", chStat.name);

	gotoxy(x, y + 1);
	printf("=============================");

	gotoxy(x, y + 2);
	printf("�̸� : %s	���� : %s", chStat.name, chStat.condition);
	
	gotoxy(x, y + 3);
	printf("���� : %d", chStat.lv);

	gotoxy(x, y + 4);
	printf("-----------------------------");

	gotoxy(x, y + 5);
	printf("ü�� : %d / %d", chStat.hp, hp);

	gotoxy(x, y + 6);
	printf("������ : %d / %d", chStat.gauge, 1 * chStat.lv);

	gotoxy(x, y + 7);
	printf("����ġ : %d / %d", chStat.exp, exp);

	gotoxy(x, y + 8);
	printf("-----------------------------");

	gotoxy(x + 5, y + 10);
	printf(" [ %s�� �ɷ�ġ ] ", chStat.name);

	gotoxy(x, y + 11);
	printf("=============================");

	gotoxy(x, y + 12);
	printf("���� : %d	�ǰ� : %d", chStat.attack, chStat.health);

	gotoxy(x, y + 13);
	printf("��ø : %d", chStat.agility);

	gotoxy(x, y + 14);
	printf("=============================");

	gotoxy(x, y + 15);
	printf("������ : %d", chStat.money);


}