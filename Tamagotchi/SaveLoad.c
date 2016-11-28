/*

2012244009 이대웅
참고문헌 https ://dojang.io/mod/page/view.php?id=716
게임 저장 및 불러오기

*/

#include<stdio.h>
#include"SaveLoad.h"
#pragma warning(disable:4996) // warning C4996을 잡기 위한 코드, 참고문헌 http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266

void SaveGame(ChStat *chStat, int number) {
	FILE *fp;
	switch (number) {
		case 1: fp = fopen("save1.txt", "wt"); break;
		case 2: fp = fopen("save2.txt", "wt"); break;
		case 3: fp = fopen("save3.txt", "wt"); break;
	}
	fprintf(fp, "%s %s %s %d %d %d %d %d %d %d %d", chStat->name, chStat->condition, chStat->digimon, chStat->lv, chStat->hp, chStat->energy,
		chStat->exp, chStat->money, chStat->attack, chStat->health, chStat->agility); // 스텟들 저장
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
		printf("빈 슬롯입니다");
		chStat->agility = 0;
	}
	else {
		fscanf(fp, "%s", chStat->name);
		if (!strcmp(chStat->name, "유년기") || !strcmp(chStat->name, "성장기") || !strcmp(chStat->name, "성숙기") || !strcmp(chStat->name, "완전체") ||
			!strcmp(chStat->name, "궁극체") || !strcmp(chStat->name, "초궁극체")) { // 이름이 공백일 떄의 예외처리
			strcpy(chStat->condition, chStat->name);
			strcpy(chStat->name, " ");
			fscanf(fp, "%s %d %d %d %d %d %d %d %d", chStat->digimon, &chStat->lv, &chStat->hp, &chStat->energy, &chStat->exp, &chStat->money,
			&chStat->attack, &chStat->health, &chStat->agility); // 스텟에 값 불러오기
		}
		else fscanf(fp, "%s %s %d %d %d %d %d %d %d %d", chStat->condition, chStat->digimon, &chStat->lv, &chStat->hp, &chStat->energy,
			&chStat->exp, &chStat->money,&chStat->attack, &chStat->health, &chStat->agility); // 스텟에 값 불러오기
		fclose(fp);
	}
	return chStat;
}