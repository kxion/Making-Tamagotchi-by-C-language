#ifndef DISPLAY_H  // CHARACTER_H�� ���ǵǾ� ���� �ʴٸ�
#define DISPLAY_H // CHARACTER_H ��ũ�� ����

/*

2012244009 �̴��
������ https://dojang.io/mod/page/view.php?id=716
������ �� ���� �̹���

*/

#include"Character.h"

void coyomon(); // �ڿ�� �̹���
void agumon(); // �Ʊ��� �̹���
void greymon(); // �׷��̸� �̹���
void metalgreymon(); // ��Ż�׷��̸� �̹���
void wargraymon(); // ���׷��̸� �̹���
void omegamon(); // ���ް��� �̹���

void digimonDisplay(int lv);
void enemyDisplay(int monLv);
ChStat* skillDisplay(ChStat *chStat, int selectNum);
void skillDescription(ChStat *chStat);

void enemy1(); // �� 1
void enemy2(); // �� 2
void enemy3(); // �� 3
void enemy4(); // �� 4
void enemy5(); // �� 5
void enemy6(); // �� 6
void enemy7(); // �� 7
void enemy8(); // �� 8
void enemy9(); // �� 9
void enemy10(); // �� 10


#endif // #ifndef DISPLAY_H ����

