
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
const int x = 35;
int y = 18;

ChStat* character(int lv) { // ĳ���� ������ �ش��ϴ� ����
	chStat.lv = lv; // ����
	chStat.attack = 10 * lv; // ���ݷ�
	chStat.sheild = 3 * lv; // ����
	chStat.hp = 50 * lv; // ��
	chStat.critical = 3 * lv; // ũ��Ƽ�� Ȯ��

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
	gotoxy(x, y++);
	printf("lv : %d", chStat.lv);

	gotoxy(x, y++);
	printf("attack : %d", chStat.attack);

	gotoxy(x, y++);
	printf("sheild : %d", chStat.sheild);

	gotoxy(x, y++);
	printf("critical : %d", chStat.critical);

	gotoxy(x, y);
	printf("exp : %d", chStat.exp);
}
void gotoxy(int x, int y) { // goto �Լ�����, ������ http://m.blog.naver.com/bestheroz/110240153
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
