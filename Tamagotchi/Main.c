#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include"Character.h"
#include"SaveLoad.h"
#include"Display.h"
#include"Interface.h"

#pragma warning(disable:4996) // warning C4996을 잡기 위한 코드, 참고문헌 http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266


int main() {
	int monLv = 0, number = 0, exp = 0, select = 0, lv = 1;
	const int x = 35, y = 15;
	ChStat *chStat;

	disappear(); // 콘솔에 커서 제거

	select = selectStart(); // 메인 인터페이스에서 선택
	
	if (select == 1) {
		chStat = character(1); // 초기화
		gotoxy(x, y);
		printf("닉네임을 입력하세요 : ");
		gotoxy(x + 25, y);
		gets(chStat->name);
		strcpy(chStat->condition, "유아기");
	}

	else if (select == 2) { // 이어하기시 불러오기
		chStat = character(1); // 초기화
		chStat = LoadGame(chStat);
		lv = chStat->lv;
		character(lv);
	}
	
	system("cls");

	while (1) {
		agumon();
		showStat();
		
		number = selectMove();

		switch (number) {
		case 1:
			monLv = selectAdventure();
			
			exp = fight(chStat, monLv);
			chStat->exp += exp;
			addExp(chStat->exp);
			chStat = levelUp(lv);

			Sleep(1000);
			system("cls");
			break;
		case 2:
			SaveGame(chStat);
			break;
		case 3:
			break;
		case 4:
			agumon();
			showAllStat();
			wait();
			system("cls");
			break;
		case 5:
			break;
		case 6:
			printf("종료되었습니다\n");
			exit(0);
		}
	}
	return 0;
}