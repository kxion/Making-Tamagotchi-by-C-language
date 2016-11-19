/*

2012244009 이대웅
참고문헌 https://dojang.io/mod/page/view.php?id=716
몬스터와 싸움

*/
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include"Fight.h"
#pragma warning(disable:4996) // warning C4996을 잡기 위한 코드, 참고문헌 http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266

int fight(ChStat *chStat, int monLv) {
	int chSelect = 0, hp = 0;

	srand((unsigned)time(NULL));
	/*  
		seed값 사용, 참고문헌 http://www.jynote.net/64
		time_h에서 unsigned int 데이터 손실 경고, 참고문헌 http://m.cafe.daum.net/dotax/D8UA/274782?q=D_LhkOVB62tSZesOix-5K71w00&
	 */

	MonStat *mon = monster(monLv);
	hp = chStat->hp;

	while (mon->hp > 0 && chStat->hp > 0) { // 몬스터, 유저중 hp가 0이 되면 종료

		printf("1.공격\t2.도망\n");
		scanf("%d", &chSelect);
		
		printf("공격 !!!\n");
		Sleep(1000);

		switch (chSelect) {
		case 1:
			if (rand() % 100 < mon->sheild) // 방어율보다 낮은 난수 발생시 방어 성공
				printf("몬스터 방어성공 !!!\n\n");
			else {
				if (rand() % 100 < chStat->critical) { // 크리티커율보다 낮은 난수 발생시 크리티컬 발생
					printf("크리티컬 발생!!!\n\n");
					mon->hp = mon->hp - (chStat->attack + (chStat->critical * 3) - mon->sheild); // 공격력 = 공격력 + 크리댐 - 상대방어력
				}
				else
					mon->hp = mon->hp - (chStat->attack - mon->sheild); // 공격력 = 공격력 - 상대방어력
				printf("몬스터hp : %d\n\n", mon->hp);

			}
			break;
		case 2:
			break;
		}

		Sleep(1000);

		if (mon->hp <= 0) break; // 몬스터가 죽으면 break;

		printf("몬스터 공격!!!\n");
		Sleep(1000);
		if (rand() % 100 < chStat->sheild) // 방어율보다 낮은 난수 발생시 방어 성공
			printf("유저 방어성공 !!!\n");
		else {
			if (rand() % 100 < mon->critical) { // 크리티커율보다 낮은 난수 발생시 크리티컬 발생
				printf("크리티컬 발생!!!\n");
				chStat->hp = chStat->hp - (mon->attack + (mon->critical * 3) - chStat->sheild); // 공격력 = 공격력 + 크리댐 - 상대방어력
			}
			else
				chStat->hp = chStat->hp - (mon->attack - chStat->sheild); // 공격력 = 공격력 - 상대방어력
			printf("유저hp : %d\n", chStat->hp);
		}

		if (chStat->hp <= 0) break; // 유저가 죽으면 break

		Sleep(1000);
		system("cls");

		printf("남은 hp\n");
		printf("유저hp : %d\n", chStat->hp);
		printf("몬스터hp : %d\n", mon->hp);

		Sleep(2000);
		system("cls");

		getchar();
	}

	if (mon->hp <= 0) {
		printf("유저 승리 !\n");
		chStat->hp = hp; // hp 회복
		return 30 * monLv; // 몬스터 레벨에 알맞은 경험치 반환
	}
	else if (mon->hp < 0 && chStat->hp < 0) {
		chStat->hp = hp;
		printf("무승부....\n");
		return 0;
	}
	else {
		printf("사냥 실패 !\n");
		chStat->hp = hp; // hp 회복
		return -30 * monLv; // 몬스터 레벨에 알맞은 -경험치 반환
	}
}
