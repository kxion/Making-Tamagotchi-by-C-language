
/*

2012244009 �̴��
������ https://dojang.io/mod/page/view.php?id=716
���͵��� ����

*/
#include<stdio.h>
#include "Monster.h"

MonStat monStat; // ���� ������ ������ ����ü ����
MonStat *pMonStat = &monStat; // ���� ������ ����ü ����

MonStat* monster(int lv) { // ���� ������ �´� ����
	monStat.lv = lv; // ����
	monStat.attack = 10 * lv; // ���ݷ�
	monStat.sheild = 3 * lv; // ����
	monStat.hp = 30 * lv; // ��
	monStat.critical = 5 * lv; // ũ��Ƽ�� Ȯ��

	return pMonStat;
}

