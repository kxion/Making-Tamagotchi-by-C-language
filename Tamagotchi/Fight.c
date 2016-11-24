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
#include"Display.h"


#pragma warning(disable:4996) // warning C4996을 잡기 위한 코드, 참고문헌 http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266

int fight(ChStat *chStat, int monLv) {
	const int x = 38, y = 23;
	int chSelect = 0, money = 0, skSelect = 0, monHp = 0, chHp = 0, chAttack = 0, monAttack = 0;

	srand((unsigned)time(NULL));
	/*  
		seed값 사용, 참고문헌 http://www.jynote.net/64
		time_h에서 unsigned int 데이터 손실 경고, 참고문헌 http://m.cafe.daum.net/dotax/D8UA/274782?q=D_LhkOVB62tSZesOix-5K71w00&
	 */

	MonStat *mon = monster(monLv);

	monHp = mon->hp; // hp 초기화
	chHp = chStat->hp; // hp 초기화
	chAttack = chStat->attack; // 공격값 초기화
	monAttack = mon->attack;

	while (mon->hp > 0 && chStat->hp > 0) { // 몬스터, 유저중 hp가 0이 되면 종료
		
		printUser(chStat);// 오프라인 대전시 유저 디스플레이 2016 11 25 한진오 수정
		//printMon(mon);//오프라인 대전시 몬스터 디스플레이 2016 11 25 한진오 수정

		chSelect = selectMotion();
				
		switch (chSelect) {
		case 1:
			attackMotion();
			system("cls");
			printMon(mon);
			if (chStat->energy < 5)
				chStat->energy = chStat->energy + 1;
			break;
		case 2:
			skSelect = selectSkill(chStat);
			chStat = skillDisplay(chStat, skSelect);//****
			break;
		case 3:
			menu(chStat);
			break;
		}
		
		gotoxy(x, y);
		if (rand() % 100 < mon->sheild) { // 방어율보다 낮은 난수 발생시 방어 성공
			printf("몬스터 방어성공 !!!\n\n");
			Sleep(500);
		}
		else {
			if (rand() % 100 < chStat->agility) { // 크리티커율보다 낮은 난수 발생시 크리티컬 발생
				printf("크리티컬 발생!!!\n\n");
				gotoxy(x, y+2);
				printf("데미지 : %2d", chStat->attack + chStat->agility - mon->sheild);
				Sleep(500);
				mon->hp = mon->hp - (chStat->attack + chStat->agility - mon->sheild); // 공격력 = 공격력 + 크리댐 - 상대방어력
			}
			else {
				printf("데미지 : %2d", chStat->attack - mon->sheild);
				Sleep(500);
				mon->hp = mon->hp - (chStat->attack - mon->sheild); // 공격력 = 공격력 - 상대방어력
			}
			Sleep(500);
			system("cls");
			//printUser(chStat);// 오프라인 대전시 유저 디스플레이 2016 11 25 한진오 수정
			printMon(mon);//오프라인 대전시 몬스터 디스플레이 2016 11 25 한진오 수정
		}

		Sleep(500);

		if (mon->hp <= 0) break; // 몬스터가 죽으면 break;

		gotoxy(x, y+2);
		printf("몬스터 공격!!!\n");
		Sleep(500);

		gotoxy(x, y);
		if (rand() % 100 < chStat->health) { // 방어율보다 낮은 난수 발생시 방어 성공
			printf("유저 방어성공 !!!\n");
			Sleep(500);
		}
		else {
			if (rand() % 100 < mon->critical) { // 크리티커율보다 낮은 난수 발생시 크리티컬 발생
				printf("크리티컬 발생!!!\n");
				gotoxy(x, y + 2);
				Sleep(500);
				printf("데미지 : %2d", mon->attack + mon->critical - chStat->health);
				chStat->hp = chStat->hp - (mon->attack + mon->critical - chStat->health); // 공격력 = 공격력 + 크리댐 - 상대방어력
			}
			else {
				chStat->hp = chStat->hp - (mon->attack - chStat->health); // 공격력 = 공격력 - 상대방어력
				printf("데미지 : %2d", mon->attack - chStat->health);
				Sleep(500);
			}
			system("cls");
			printUser(chStat);// 오프라인 대전시 유저 디스플레이 2016 11 25 한진오 수정
			printMon(mon);//오프라인 대전시 몬스터 디스플레이 2016 11 25 한진오 수정
		}

		if (chStat->hp <= 0) break; // 유저가 죽으면 break
		chStat->energy;
		if (chStat->energy < 5)
			chStat->energy = chStat->energy + 1;
		Sleep(500);
		system("cls");

		chStat->attack = chAttack;
		mon->attack = monAttack;
	}

	//chStat->attack = chAttack;
	//mon->attack = monAttack;

	if (mon->hp <= 0) {
		printWin();//win 이미지
		chStat->money += 500 * monLv;
		mon->hp = monHp;
		chStat->hp = chHp;
		chStat->energy = 0;
		return 20 * monLv; // 몬스터 레벨에 알맞은 경험치 반환
	}
	else if (mon->hp < 0 && chStat->hp < 0) {
		printf("무승부....\n");
		mon->hp = monHp;
		chStat->hp = chHp;
		chStat->energy = 0;
		return 0;
	}
	else {
		printLose();//lose 이미지
		mon->hp = monHp;
		chStat->hp = chHp;
		chStat->energy = 0;
		return -30 * monLv; // 몬스터 레벨에 알맞은 -경험치 반환
	}
}
