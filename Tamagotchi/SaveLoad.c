/*

2012244009 �̴��
������ https ://dojang.io/mod/page/view.php?id=716
���� ���� �� �ҷ�����

*/
#include<stdio.h>
#include"SaveLoad.h"
#pragma warning(disable:4996) // warning C4996�� ��� ���� �ڵ�, ������ http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266

void SaveGame(ChStat *chStat) {
	FILE *fp = fopen("save.txt", "wt");
	fprintf(fp, "%d %d %d %d %d %d", chStat->lv, chStat->hp, chStat->exp, chStat->attack, chStat->sheild, chStat->critical);
	fclose(fp);
}
ChStat* LoadGame(ChStat *chStat) {
	FILE *fp = fopen("save.txt", "rt");
	fscanf(fp, "%d %d %d %d %d %d", &chStat->lv, &chStat->attack, &chStat->sheild, &chStat->hp, &chStat->critical, &chStat->exp);
	fclose(fp);
	
	return chStat;
}