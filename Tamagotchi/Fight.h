#ifndef FIGHT_H  // FIGHT_H�� ���ǵǾ� ���� �ʴٸ�
#define FIGHT_H  // FIGHT_H ��ũ�� ����

/*

2012244009 �̴��
������ https://dojang.io/mod/page/view.php?id=716
���� ��ɿ� ���õ� �ڵ�

*/

#include"Character.h"
#include"Monster.h"

int fight(ChStat *chStat, int monLv); // ���� ���
int onlineFight(ChStat *myStat, ChStat *enemyStat);

#endif // #ifndef FIGHT_H ����

