/*

2012244009 �̴��
������ https ://dojang.io/mod/page/view.php?id=716
���� ���� �� �ҷ�����

*/

#include<stdio.h>
#include"SaveLoad.h"
#pragma warning(disable:4996) // warning C4996�� ��� ���� �ڵ�, ������ http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266

void SaveGame(ChStat *chStat, int number) {
	FILE *fp;
	switch (number) {
		case 1: fp = fopen("save1.txt", "wt"); break;
		case 2: fp = fopen("save2.txt", "wt"); break;
		case 3: fp = fopen("save3.txt", "wt"); break;
	}
	fprintf(fp, "%s %s %s %d %d %d %d %d %d %d %d", chStat->name, chStat->condition, chStat->digimon, chStat->lv, chStat->hp, chStat->gauge,
		chStat->exp, chStat->money, chStat->attack, chStat->health, chStat->agility);
	fclose(fp);
}
ChStat* LoadGame(ChStat *chStat, int number) {
	FILE *fp;
	switch (number) {
		case 1: fp = fopen("save1.txt", "rt"); break;
		case 2: fp = fopen("save2.txt", "rt"); break;
		case 3: fp = fopen("save3.txt", "rt"); break;
	}
		fscanf(fp, "%s %s %s %d %d %d %d %d %d %d %d", chStat->name, chStat->condition, chStat->digimon, &chStat->lv, &chStat->hp, &chStat->gauge, 
		&chStat->exp, &chStat->money, &chStat->attack, &chStat->health, &chStat->agility);
	fclose(fp);
	
	return chStat;
}