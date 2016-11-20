
/*

2012244009 이대웅
참고문헌 https://dojang.io/mod/page/view.php?id=716
캐릭터에 관련된 소스 ( 스텟, 렙업 )

*/

#include<stdio.h>
#include<Windows.h>
#include"Character.h"

ChStat chStat; // 캐릭터 스텟을 저장할 구조체 변수
ChStat *pChStat = &chStat; // 캐릭터 포인터 구조체 변수
const int x = 35;
int y = 18;

ChStat* character(int lv) { // 캐릭터 레벨에 해당하는 스텟
	chStat.lv = lv; // 레벨
	chStat.attack = 10 * lv; // 공격력
	chStat.sheild = 3 * lv; // 방어력
	chStat.hp = 50 * lv; // 피
	chStat.critical = 3 * lv; // 크리티컬 확률

	return pChStat;
}
void addExp(int exp) { // 사냥 성공시 경험치 축적
	chStat.exp = exp;
}
void delExp(int exp) { // 사냥 실패시 경험치 손실
	chStat.exp = exp;
}
int levelUp(int lv) { // 렙업 유무 확인
	if (chStat.exp > lv * 100) {
		printf("레벨 업!!!\n");
		printf("LEVEL : %d가 되었습니다 !!\n", ++lv);
	}
	else if (lv == 10) // 최대레벨 10으로 설정
		lv = 10;
	
	return lv;
}
void showStat() {
	gotoxy(x, y++);
	printf("lv : %d", chStat.lv);

	gotoxy(x, y++);
	printf("attack : %d", chStat.attack);

	gotoxy(x, y++);
	printf("sheild : %d", chStat.sheild);

	gotoxy(x, y++);
	printf("critical : %d", chStat.critical);

	gotoxy(x, y);
	printf("exp : %d", chStat.exp);
}
void gotoxy(int x, int y) { // goto 함수선언, 참고문헌 http://m.blog.naver.com/bestheroz/110240153
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
