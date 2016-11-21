#ifndef INTERFACE_H // CHARACTER_H�� ���ǵǾ� ���� �ʴٸ�
#define INTERFACE_H // CHARACTER_H ��ũ�� ����

/*

2012244063 ������
2012244009 �̴�� �ڵ�����
������ https://dojang.io/mod/page/view.php?id=716
���ӿ� �ʿ��� �������̽� ����

*/

#define ENTER 13 // �ƽ�Ű�� ����
#define UP 72 // �ƽ�Ű�� ����
#define DOWN 80 // �ƽ�Ű�� ����
#define RIGHT 77 // �ƽ�Ű�� ����
#define LEFT 75 // �ƽ�Ű�� ����

int selectStart(); // ���� �ʱ� �������̽� ����
int selectMove(); // ���ӻ� ���� �������̽� ����
int selectAdventure(); // ���輱�� �������̽�
void fightInterface(int chHp, int monHp); // �ο�� �������̽�
int selectMotion(); // ����, ��ų, ���� �������̽�
int selectSkill(); // ��ų ���� �������̽�
int wait(); // ���� ������ ��ٸ��� �Լ�
void disappear(); // goto���� �����̴� �ܼ��� Ŀ�� ����
void gotoxy(int x, int y); // goto �Լ� ����

#endif // #ifndef INTERFACE_H ����