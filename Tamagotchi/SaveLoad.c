/*

2012244009 이대웅
참고문헌 https ://dojang.io/mod/page/view.php?id=716
게임 저장 및 불러오기

*/
#include<stdio.h>
#include"SaveLoad.h"
#pragma warning(disable:4996) // warning C4996을 잡기 위한 코드, 참고문헌 http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266

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