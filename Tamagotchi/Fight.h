#ifndef FIGHT_H  // FIGHT_H가 정의되어 있지 않다면
#define FIGHT_H  // FIGHT_H 매크로 정의

/*

2012244009 이대웅
참고문헌 https://dojang.io/mod/page/view.php?id=716
몬스터 사냥에 관련된 코드

*/

#include"Character.h"
#include"Monster.h"

int fight(ChStat *chStat, int monLv); // 몬스터 사냥
int onlineFight(ChStat *myStat, ChStat *enemyStat);

#endif // #ifndef FIGHT_H 종료

