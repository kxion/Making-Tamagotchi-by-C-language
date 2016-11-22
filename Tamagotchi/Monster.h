#ifndef MONSTER_H  // MONSTER_H가 정의되어 있지 않다면
#define MONSTER_H  // MONSTER_H 매크로 정의

/*

2012244009 이대웅
참고문헌 https://dojang.io/mod/page/view.php?id=716
캐릭터에 관련된 소스 ( 스텟, 렙업 )

*/

typedef struct monStat { // 몬스터들 스텟
	int lv;
	int attack;
	int sheild;
	int hp;
	int critical;
}MonStat;

MonStat* monster(int lv); // 몬스터 레벨에 맞는 스텟

#endif // #ifndef MONSTER_H 종료

