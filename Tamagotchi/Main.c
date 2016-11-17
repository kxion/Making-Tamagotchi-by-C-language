#include<stdio.h>
#include<windows.h>
#include"Character.h"
#pragma warning(disable:4996) // scanf 오류를 잡기 위해 사용, 참고문헌 http://enter.tistory.com/14

int main() {
	int lv = 0, monLv = 0, number = 0, exp = 0;

	printf("lv 설정 : ");
	scanf("%d", &lv);

	while (1) {
		ChStat *chStat = character(lv);

		printf("레벨 : %d hp : %d  공 : %d  방 : %d  크리 : %d  경험치 : %d\n", lv, chStat->hp, chStat->attack, chStat->sheild, chStat->critical, chStat->exp);
		
		printf("1.모험\t2.싸우기\t3.저장하기\n");
		scanf("%d", &number);
		
		switch (number) {
		case 1:
			printf("몬스터 레벨 설정 : ");
			scanf("%d", &monLv);

			exp = fight(chStat, monLv);
			chStat->exp += exp;
			addExp(chStat->exp);
			lv = levelUp(lv);

			Sleep(2000);
			system("cls");
			break;
		case 2:
			break;
		case 3:
			printf("종료\n");
			exit(0);
		}
	}
	
	return 0;
}