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
	fprintf(fp, "%s %s %s %d %d %d %d %d %d %d %d", chStat->name, chStat->condition, chStat->digimon, chStat->lv, chStat->hp, chStat->energy,
		chStat->exp, chStat->money, chStat->attack, chStat->health, chStat->agility); // ���ݵ� ����
	fclose(fp);
}
ChStat* LoadGame(ChStat *chStat, int number) {
	FILE *fp;
	switch (number) {
		case 1: fp = fopen("save1.txt", "rt"); break;
		case 2: fp = fopen("save2.txt", "rt"); break;
		case 3: fp = fopen("save3.txt", "rt"); break;
	}
	if (fp == NULL) {
		gotoxy(45, 16);
		printf("�� �����Դϴ�");
		chStat->agility = 0;
	}
	else {
		fscanf(fp, "%s", chStat->name);
		if (!strcmp(chStat->name, "�����") || !strcmp(chStat->name, "�����") || !strcmp(chStat->name, "������") || !strcmp(chStat->name, "����ü") ||
			!strcmp(chStat->name, "�ñ�ü") || !strcmp(chStat->name, "�ʱñ�ü")) { // �̸��� ������ ���� ����ó��
			strcpy(chStat->condition, chStat->name);
			strcpy(chStat->name, " ");
			fscanf(fp, "%s %d %d %d %d %d %d %d %d", chStat->digimon, &chStat->lv, &chStat->hp, &chStat->energy, &chStat->exp, &chStat->money,
			&chStat->attack, &chStat->health, &chStat->agility); // ���ݿ� �� �ҷ�����
		}
		else fscanf(fp, "%s %s %d %d %d %d %d %d %d %d", chStat->condition, chStat->digimon, &chStat->lv, &chStat->hp, &chStat->energy,
			&chStat->exp, &chStat->money,&chStat->attack, &chStat->health, &chStat->agility); // ���ݿ� �� �ҷ�����
		fclose(fp);
	}
	return chStat;
}