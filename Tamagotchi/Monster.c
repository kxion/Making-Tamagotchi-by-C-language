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
	monStat.attack = 2 * lv; // ���ݷ�
	monStat.sheild = 1 * lv; // ����
	monStat.hp = 20 * lv; // ��
	monStat.critical = 3 * lv; // ũ��Ƽ�� Ȯ��

	return pMonStat;
}
