#ifndef SAVELOAD_H  // CHARACTER_H�� ���ǵǾ� ���� �ʴٸ�
#define SAVELOAD_H  // CHARACTER_H ��ũ�� ����

/*

2012244009 �̴��
������ https://dojang.io/mod/page/view.php?id=716
���� ���� �� �ҷ�����


*/
#include"Character.h"

void SaveGame(ChStat *chStat, int number); // ���̺�
ChStat* LoadGame(ChStat *chStat, int number); // �ҷ�����

#endif // #ifndef CHARACTER_H ����

