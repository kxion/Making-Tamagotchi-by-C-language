#include<stdio.h>
#include<windows.h>
#include"Character.h"
#include"SaveLoad.h"
#include"Display.h"
#include"Interface.h"

#pragma warning(disable:4996) // warning C4996을 잡기 위한 코드, 참고문헌 http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266

int main() {
	int monLv = 0, number = 0, exp = 0, select = 0, lv = 1;
	ChStat *chStat;

	disappear(); // 콘솔에 커서 제거

	select = selectStart();

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
		RightAgumon();
		showStat();
		
		number = selectMove();

		switch (number) {
		case 1:
			monLv = selectAdventure();
			
			exp = fight(chStat, monLv);
			chStat->exp += exp;
			addExp(chStat->exp);
			chStat->lv = levelUp(lv);

			Sleep(1000);
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