
/*

2012244009 �̴��
������ https://dojang.io/mod/page/view.php?id=716
ĳ���Ϳ� ���õ� �ҽ� ( ����, ���� )

*/

#include<stdio.h>
#include"Character.h"

ChStat chStat; // ĳ���� ������ ������ ����ü ����
ChStat *pChStat = &chStat; // ĳ���� ������ ����ü ����

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
