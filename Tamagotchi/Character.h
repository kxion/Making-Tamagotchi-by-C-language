#ifndef CHARACTER_H // CHARACTER_H�� ���ǵǾ� ���� �ʴٸ�
#define CHARACTER_H // CHARACTER_H ��ũ�� ����

/*

2012244009 �̴��
������ https://dojang.io/mod/page/view.php?id=716
ĳ���Ϳ� ���õ� �ҽ� ( ����, ���� )

*/


typedef struct chStat { // ĳ���͵� ����
	char name[30];
	char condition[30];
	char digimon[30];
	int lv;
	int attack;
	int health;
	int hp;
	int agility;
	int energy;
	int exp;
	int money;
}ChStat;

ChStat* character(int lv); //  ������ ������ �ش��ϴ� ����
void addExp(int exp); // ��� ������ ����ġ ����
void delExp(int exp); // ��� ���н� ����ġ �ս� 
ChStat* levelUp(int lv); // ���� ���� Ȯ��
void showStat(); // �ش��ϴ� ������ �⺻ ����â
void showAllStat(); // �ش��ϴ� �������� ��� ����â

#endif // #ifndef CHARACTER_H ����
