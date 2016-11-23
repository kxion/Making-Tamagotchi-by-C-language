#ifndef INTERFACE_H // CHARACTER_H�� ���ǵǾ� ���� �ʴٸ�
#define INTERFACE_H // CHARACTER_H ��ũ�� ����

/*

2012244063 ������
2012244009 �̴�� �ڵ�����
������ https://dojang.io/mod/page/view.php?id=716
���ӿ� �ʿ��� �������̽� ����

*/
#include"Character.h"
#include"Monster.h"

typedef struct name {
	char name1[20];
	char name2[20];
	char name3[20];
}Name;

#define ENTER 13 // �ƽ�Ű�� ����
#define UP 72 // �ƽ�Ű�� ����
#define DOWN 80 // �ƽ�Ű�� ����
#define RIGHT 77 // �ƽ�Ű�� ����
#define LEFT 75 // �ƽ�Ű�� ����

void interfaceMain();
int selectStart(); // ���� �ʱ� �������̽� ����
int selectMove(); // ���ӻ� ���� �������̽� ����
int selectAdventure(int lv); // ���輱�� �������̽�
void fightInterface(ChStat *chStat, MonStat *mon); // �ο�� �������̽�
int selectMotion(); // ����, ��ų, ���� �������̽�
int selectSkill(ChStat* chStat); // ��ų ���� �������̽�
int selectSave(int lv);
int selectLoad(ChStat *chStat);
void menu(ChStat* chStat);
void printTitle();
void wait(); // ���� ������ ��ٸ��� �Լ�
void disappear(); // goto���� �����̴� �ܼ��� Ŀ�� ����
void gotoxy(int x, int y); // goto �Լ� ����

#endif // #ifndef INTERFACE_H ����