#ifndef MONSTER_H  // CHARACTER_H�� ���ǵǾ� ���� �ʴٸ�
#define MONSTER_H  // CHARACTER_H ��ũ�� ����

/*

2012244009 �̴��
������ https://dojang.io/mod/page/view.php?id=716
ĳ���Ϳ� ���õ� �ҽ� ( ����, ���� )

*/

typedef struct monStat { // ���͵� ����
	int lv;
	int attack;
	int sheild;
	int hp;
	int critical;
}MonStat;

MonStat* monster(int lv); // ���� ������ �´� ����


#endif // #ifndef CHARACTER_H ����

