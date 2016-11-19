#include<stdio.h>
#include<windows.h>
#include"Character.h"
#include"SaveLoad.h"
#pragma warning(disable:4996) // warning C4996을 잡기 위한 코드, 참고문헌 http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266

int main() {
	int monLv = 0, number = 0, exp = 0, select = 0, lv = 1;
	ChStat *chStat;

	printf("1.처음하기\t2.이어하기\n");
	scanf("%d", &select);

	switch (select) {
	case 1:
		chStat = character(1);
		break;
	case 2:
		chStat = LoadGame(character(0));
		lv = chStat->lv;
		break;
	}

	while (1) {
		printf("레벨 : %d hp : %d  공 : %d  방 : %d  크리 : %d  경험치 : %d\n", chStat->lv, chStat->hp, chStat->attack, chStat->sheild, chStat->critical, chStat->exp);

		printf("1.모험\t2.싸우기\t3.저장하기\t4.종료\n");
		scanf("%d", &number);

		switch (number) {
		case 1:
			printf("몬스터 레벨 설정 : ");
			scanf("%d", &monLv);

			exp = fight(chStat, monLv);
			chStat->exp += exp;
			addExp(chStat->exp);
			chStat->lv = levelUp(lv);

			Sleep(2000);
			system("cls");
			break;
		case 2:
			break;
		case 3:
			SaveGame(chStat);
			break;
		case 4:
			printf("종료되었습니다\n");
			exit(0);
		}
	}
	return 0;
}