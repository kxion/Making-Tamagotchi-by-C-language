
/*

2012244009 �̴��
������ https://dojang.io/mod/page/view.php?id=716
ĳ���Ϳ� ���õ� �ҽ� ( ����, ���� )

*/

#include<stdio.h>
#include<Windows.h>
#include"Character.h"

ChStat chStat; // ĳ���� ������ ������ ����ü ����
ChStat *pChStat = &chStat; // ĳ���� ������ ����ü ����
const int x = 35, y = 18;
int hp = 0, exp = 0;

ChStat* character(int lv) { // ĳ���� ������ �ش��ϴ� ����
	chStat.lv = lv; // ����
	chStat.attack = 10 * lv; // ���ݷ�
	chStat.sheild = 3 * lv; // ����
	chStat.hp = 50 * lv; // ��
	chStat.critical = 3 * lv; // ũ��Ƽ�� Ȯ��

	hp = chStat.hp;
	exp = chStat.lv * 100;

	return pChStat;
}
void addExp(int exp) { // ��� ������ ����ġ ����
	chStat.exp = exp;
}
void delExp(int exp) { // ��� ���н� ����ġ �ս�
	chStat.exp = exp;
}
int levelUp(int lv) { // ���� ���� Ȯ��
	if (chStat.exp > lv * 100) {
		printf("���� ��!!!\n");
		printf("LEVEL : %d�� �Ǿ����ϴ� !!\n", ++lv);
	}
	else if (lv == 10) // �ִ뷹�� 10���� ����
		lv = 10;
	
	return lv;
}
void showStat() {
	gotoxy(x, y+1);
	printf("���� : %d", chStat.lv);

	gotoxy(x, y+2);
	printf("ü�� : %d / %d", chStat.hp, hp);
	
	gotoxy(x, y+3);
	printf("����ġ : %d / %d", chStat.exp, exp);

	gotoxy(x, y+4);
	printf("���� : %d", chStat.attack);

	gotoxy(x, y+5);
	printf("��� : %d", chStat.sheild);

	gotoxy(x, y+6);
	printf("��ø : %d", chStat.critical);

}
