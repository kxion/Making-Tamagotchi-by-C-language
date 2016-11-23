/*

2012244009 이대웅
참고문헌 https://dojang.io/mod/page/view.php?id=716
몬스터들의 스텟

*/
#include<stdio.h>
#include "Monster.h"


MonStat monStat; // 몬스터 스텟을 저장할 구조체 변수
MonStat *pMonStat = &monStat; // 몬스터 포인터 구조체 변수

MonStat* monster(int lv) { // 몬스터 레벨에 맞는 스텟
	monStat.lv = lv; // 레벨
	monStat.attack = 2 * lv; // 공격력
	monStat.sheild = 1 * lv; // 방어력
	monStat.hp = 20 * lv; // 피
	monStat.critical = 3 * lv; // 크리티컬 확률

	return pMonStat;
}
