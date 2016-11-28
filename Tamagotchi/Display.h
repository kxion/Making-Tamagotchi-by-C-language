#ifndef DISPLAY_H  // CHARACTER_H�� ���ǵǾ� ���� �ʴٸ�
#define DISPLAY_H // CHARACTER_H ��ũ�� ����

/*

2012244009 �̴��
������ https://dojang.io/mod/page/view.php?id=716
������ �� ���� �̹���

*/

#include"Character.h"
#include"Monster.h"

void coyomon(); // �ڿ�� �̹���
void agumon(); // �Ʊ��� �̹���
void greymon(); // �׷��̸� �̹���
void metalgreymon(); // ��Ż�׷��̸� �̹���
void wargraymon(); // ���׷��̸� �̹���
void omegamon(); // ���ް��� �̹���

void digimonDisplay(int lv); // ������ �̹���
void enemyDisplay(int monLv); // �� �̹���
ChStat* skillDisplay(ChStat *chStat, MonStat *mon, int selectNum); // ��ų ����
void skillDescription(ChStat *chStat); // ������� ���� ��ų ����
void printWin();//�� �̹���
void printLose();//���� �̹���
void printLvUp();//������ �̹���

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

void damaged();

void monAt1(MonStat *mon);
void monAt2(ChStat *chStat);

void baseAt1(ChStat *chStat);
void baseAt2(MonStat *mon);

void skAt1_1_1(ChStat *chStat);
void skAt1_1_2(MonStat *mon);

void onlineAttack(ChStat *enemyStat);
void onlineAttack2(ChStat *chStat);

void skAt2_1_1(ChStat *chStat);
void skAt2_1_2(MonStat *mon);
void skAt2_2_1(ChStat *chStat);
void skAt2_2_2(MonStat *mon);

void skAt3_1_1(ChStat *chStat);
void skAt3_1_2(MonStat *mon);
void skAt3_2_1(ChStat *chStat);
void skAt3_2_2(MonStat *mon);

void skAt4_1_1(ChStat *chStat);
void skAt4_1_2(MonStat *mon);
void skAt4_2_1(ChStat *chStat);
void skAt4_2_2(MonStat *mon);

void skAt5_1_1(ChStat *chStat);
void skAt5_1_2(MonStat *mon);
void skAt5_2_1(ChStat *chStat);
void skAt5_2_2(MonStat *mon);

void skAt6_1_1(ChStat *chStat);
void skAt6_1_2(MonStat *mon);
void skAt6_2_1(ChStat *chStat);
void skAt6_2_2(MonStat *mon);
#endif // #ifndef DISPLAY_H ����

