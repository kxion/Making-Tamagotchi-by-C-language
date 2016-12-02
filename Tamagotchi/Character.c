
/*

2012244009 이대웅
참고문헌 https://dojang.io/mod/page/view.php?id=716
캐릭터에 관련된 소스 ( 스텟, 렙업 )

*/


#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include"Character.h"
#include"Interface.h"
#include"BinaryTree.h"
#include"Display.h"

ChStat chStat; // 캐릭터 스텟을 저장할 구조체 변수
ChStat *pChStat = &chStat; // 캐릭터 포인터 구조체 변수
int hp = 0, exp = 0;

ChStat* character(int lv) { // 캐릭터 레벨에 해당하는 스텟
	chStat.lv = lv; // 레벨
	chStat.attack = 2 * lv; // 공격력
	chStat.health = 1 * lv; // 방어력
	chStat.hp = 10 * lv ; // 피
	chStat.agility = 0 + lv; // 크리티컬 확률
	chStat.energy = 0; // 게이지 0으로 초기화
	
	hp = chStat.hp; // hp 저장
	exp = chStat.lv * 50; // 경험치량 

	return pChStat;
}
void addExp(int exp) { // 사냥 성공시 경험치 축적
	chStat.exp = exp;
}
void delExp(int exp) { // 사냥 실패시 경험치 손실
	chStat.exp = exp;
}
ChStat* levelUp(int lv) { // 렙업 유무 확인
	TreeNode *name;
	int i = 0;

	if (chStat.exp >= lv * 1) {
		printLvUp();
		++lv;

		if (lv % 5 == 0) {
			lv = lv - 1;
			for (i = 0; i < 3; i++) { // 렙업 임팩트
				system("cls");
				Sleep(500);
				digimonDisplay(lv);
				Sleep(500);
			}
			++lv;
		}
		chStat.exp = 0;
		name = searchName(lv); // 성장,디지몬명 찾기
		strcpy(pChStat->condition, name->name); // 찾은 성장 스텟에 저장
		strcpy(pChStat->digimon, name->digimon); // 찾은 디지몬명 스텟에 저장
		character(lv); // 캐릭터 불러오기
	}
	else if (lv == 30) // 최대레벨 10으로 설정
		lv = 30;

	return pChStat;
}
void showStat() { // 대략적인 스텟창
	const int x = 35, y = 18;

	gotoxy(x, y);
	printf("이름   : %s", chStat.name);

	gotoxy(x, y + 1);
	printf("디지몬 : %s", chStat.digimon);
	
	gotoxy(x, y + 2);
	printf("성장   : %s", chStat.condition);

	gotoxy(x, y + 3);
	printf("레벨   : %d", chStat.lv);

	gotoxy(x, y + 4);
	printf("체력   : %d / %d", chStat.hp, hp);
	
	gotoxy(x, y + 5);
	printf("기력   : %d / %d", chStat.energy, 5);

	gotoxy(x, y + 6);
	printf("경험치 : %d / %d", chStat.exp, exp);

	gotoxy(x, y + 7);
	printf("소지금 : %d", chStat.money);
}
void showAllStat() { // 세부적인 스텟창
	const int x = 50, y = 13, i = 1;

	gotoxy(x+5, y);
	printf(" [ %s의 상태창 ] ", chStat.name);

	gotoxy(x, y + 1);
	printf("-----------------------------");

	gotoxy(x, y + 2);
	printf("디지몬 : %s", chStat.digimon);

	gotoxy(x, y + 3);
	printf("-----------------------------");

	gotoxy(x, y + 4);
	printf("이름 : %s	 성장 : %s", chStat.name, chStat.condition);
	
	gotoxy(x, y + 5);
	printf("레벨 : %d", chStat.lv);

	gotoxy(x, y + 6);
	printf("-----------------------------");

	gotoxy(x, y + 7);
	printf("체력   : %d / %d", chStat.hp, hp);

	gotoxy(x, y + 8);
	printf("기력   : %d / %d", chStat.energy, 5);

	gotoxy(x, y + 9);
	printf("경험치 : %d / %d", chStat.exp, exp);

	gotoxy(x, y + 10);
	printf("-----------------------------");

	gotoxy(x + 5, y + 11);
	printf(" [ %s의 능력치 ] ", chStat.name);

	gotoxy(x, y + 12);
	printf("=============================");

	gotoxy(x, y + 13);
	printf("공격 : %d	건강 : %d", chStat.attack, chStat.health);

	gotoxy(x, y + 14);
	printf("민첩 : %d", chStat.agility);

	gotoxy(x, y + 15);
	printf("-----------------------------");

	gotoxy(x, y + 16);
	printf("소지금 : %d", chStat.money);
}