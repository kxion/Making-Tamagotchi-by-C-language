#ifndef CHARACTER_H // CHARACTER_H�� ���ǵǾ� ���� �ʴٸ�
#define CHARACTER_H // CHARACTER_H ��ũ�� ����

/*

2012244009 �̴��
������ https://dojang.io/mod/page/view.php?id=716
ĳ���Ϳ� ���õ� �ҽ� ( ����, ���� )

*/

typedef struct chStat { // ĳ���͵� ����
	int lv;
	int attack;
	int sheild;
	int hp;
	int critical;
	int exp;
}ChStat;

ChStat* character(int lv); //  ĳ���� ������ �ش��ϴ� ����
void addExp(int exp); // ��� ������ ����ġ ����
void delExp(int exp); // ��� ���н� ����ġ �ս� 
int levelUp(int lv); // ���� ���� Ȯ��


#endif // #ifndef CHARACTER_H ����
