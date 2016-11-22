/*

2012244009 이대웅
참고문헌 https://dojang.io/mod/page/view.php?id=716
몬스터와 싸움

*/
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include"Fight.h"
#include"Interface.h"
#include"Skill.h"


#pragma warning(disable:4996) // warning C4996을 잡기 위한 코드, 참고문헌 http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266

int fight(ChStat *chStat, int monLv) {
	const int x = 40, y = 27;
	int chSelect = 0, i = 0, money = 0, skSelect = 0, monHp = 0, chHp = 0, attack = 0;

	srand((unsigned)time(NULL));
	/*  
		seed값 사용, 참고문헌 http://www.jynote.net/64
		time_h에서 unsigned int 데이터 손실 경고, 참고문헌 http://m.cafe.daum.net/dotax/D8UA/274782?q=D_LhkOVB62tSZesOix-5K71w00&
	 */

	MonStat *mon = monster(monLv);

	monHp = mon->hp; // hp 초기화
	chHp = chStat->hp; // hp 초기화
	attack = chStat->attack; // 공격값 초기화

	while (mon->hp > 0 && chStat->hp > 0) { // 몬스터, 유저중 hp가 0이 되면 종료
		fightInterface(chStat->hp, mon->hp, chStat->lv, mon->lv);

		chSelect = selectMotion();
				
		switch (chSelect) {
		case 1:
			gotoxy(x, y + 2);
			printf("공격 !!!\n");
			Sleep(1000);
			break;
		case 2:
			skSelect = selectSkill();
			switch (skSelect) {
			case 1: 
				gotoxy(x, y + 4);
				printf("꼬마 불꽃 !!!\n");
				chStat->attack = agumonSkill_1(chStat->attack);
				break;
			case 2: 
				gotoxy(x, y + 4);
				printf("꼬마 화염 !!!\n");
				chStat->attack = agumonSkill_2(chStat->attack);
				break;
			}
			break;
		case 3:
			break;
		}

		gotoxy(x, y + 3);
		if (rand() % 100 < mon->sheild) { // 방어율보다 낮은 난수 발생시 방어 성공
			printf("몬스터 방어성공 !!!\n\n");
			Sleep(1000);
		}
		else {
			if (rand() % 100 < chStat->agility) { // 크리티커율보다 낮은 난수 발생시 크리티컬 발생
				printf("크리티컬 발생!!!\n\n");
				Sleep(1000);
				mon->hp = mon->hp - (chStat->attack + (chStat->agility * 3) - mon->sheild); // 공격력 = 공격력 + 크리댐 - 상대방어력
			}
			else
				mon->hp = mon->hp - (chStat->attack - mon->sheild); // 공격력 = 공격력 - 상대방어력
			Sleep(1000);
			system("cls");
			chStat->attack = attack;
			fightInterface(chStat->hp, mon->hp, chStat->lv, mon->lv);
		}

		Sleep(1000);

		if (mon->hp <= 0) break; // 몬스터가 죽으면 break;

		gotoxy(x, y+2);
		printf("몬스터 공격!!!\n");
		Sleep(1000);

		gotoxy(x, y + 3);
		if (rand() % 100 < chStat->health) { // 방어율보다 낮은 난수 발생시 방어 성공
			printf("유저 방어성공 !!!\n");
			Sleep(1000);
		}
		else {
			if (rand() % 100 < mon->critical) { // 크리티커율보다 낮은 난수 발생시 크리티컬 발생
				printf("크리티컬 발생!!!\n");
				Sleep(1000);
				chStat->hp = chStat->hp - (mon->attack + (mon->critical * 3) - chStat->health); // 공격력 = 공격력 + 크리댐 - 상대방어력
			}
			else
				chStat->hp = chStat->hp - (mon->attack - chStat->health); // 공격력 = 공격력 - 상대방어력
			system("cls");
			fightInterface(chStat->hp, mon->hp, chStat->lv, mon->lv);
		}

		if (chStat->hp <= 0) break; // 유저가 죽으면 break

		Sleep(1000);
		system("cls");

	}

	if (mon->hp <= 0) {
		printf("유저 승리 !\n");
		chStat->money += 500 * monLv;
		mon->hp = monHp;
		chStat->hp = chHp;
		return 20 * monLv; // 몬스터 레벨에 알맞은 경험치 반환
	}
	else if (mon->hp < 0 && chStat->hp < 0) {
		printf("무승부....\n");
		mon->hp = monHp;
		chStat->hp = chHp;
		return 0;
	}
	else {
		printf("사냥 실패 !\n");
		mon->hp = monHp;
		chStat->hp = chHp;
		return -30 * monLv; // 몬스터 레벨에 알맞은 -경험치 반환
	}
}
