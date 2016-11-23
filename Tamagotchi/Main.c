#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include"Character.h"
#include"SaveLoad.h"
#include"Display.h"
#include"Interface.h"
#include"BinaryTree.h"

#pragma warning(disable:4996) // warning C4996을 잡기 위한 코드, 참고문헌 http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266


int main() {
	int monLv = 0, number = 0, exp = 0, select = 0, lv = 1, save = 0;
	const int x = 35, y = 15;
	ChStat *chStat;

	setDigimonCondition();
	disappear(); // 콘솔에 커서 제거
	printTitle();
	
	select = selectStart(); // 메인 인터페이스에서 선택
	
	if (select == 1) {
		chStat = character(1); // 초기화
		gotoxy(x, y);
		printf("닉네임을 입력하세요 : ");
		gotoxy(x + 25, y);
		fgets(chStat->name, 10, stdin); /* gets(string); XXX: gets 함수는 string의 크기가 어느 정도인지 알지 못한다. 따라서 STRING_SIZE 이상의 길이를 가진 문자열 입력시 정상 작동을 보장할 수 없다. https://kldp.org/node/75467 */
		strcpy(chStat->condition, "유아기");
		strcpy(chStat->digimon, "코요몬");
	}

	else if (select == 2) { // 이어하기시 불러오기
		chStat = character(1); // 초기화
		save = selectLoad(chStat);
		chStat = LoadGame(chStat, save);
		lv = chStat->lv;
		character(lv);
	}
	
	system("cls");

	while (1) {
		digimonDisplay(chStat->lv);
		showStat();
		
		number = selectMove();

		switch (number) {
		case 1:
			monLv = selectAdventure(chStat->lv);
			
			exp = fight(chStat, monLv);
			chStat->exp += exp;
			addExp(chStat->exp);
			chStat = levelUp(chStat->lv);

			Sleep(1000);
			system("cls");
			break;
		case 2:
			save = selectSave(chStat->lv);
			SaveGame(chStat, save);
			break;
		case 3:
			break;
		case 4:
			digimonDisplay(chStat->lv);
			showAllStat();
			wait();
			system("cls");
			break;
		case 5:
			break;
		case 6:
			printf("종료되었습니다\n");
			exit(0);
		case 7:
			save = selectLoad(chStat);
			chStat = LoadGame(chStat, save);
			break;
		}
	}
	return 0;
}