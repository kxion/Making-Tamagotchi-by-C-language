#ifndef DISPLAY_H  // CHARACTER_H가 정의되어 있지 않다면
#define DISPLAY_H // CHARACTER_H 매크로 정의

/*

2012244009 이대웅
참고문헌 https://dojang.io/mod/page/view.php?id=716
디지몬 및 몬스터 이미지

*/

#include"Character.h"

void coyomon(); // 코요몬 이미지
void agumon(); // 아구몬 이미지
void greymon(); // 그레이몬 이미지
void metalgreymon(); // 메탈그레이몬 이미지
void wargraymon(); // 워그레이몬 이미지
void omegamon(); // 오메가몬 이미지

void digimonDisplay(int lv);
void enemyDisplay(int monLv);
ChStat* skillDisplay(ChStat *chStat, int selectNum);
void skillDescription(ChStat *chStat);

void enemy1(); // 적 1
void enemy2(); // 적 2
void enemy3(); // 적 3
void enemy4(); // 적 4
void enemy5(); // 적 5
void enemy6(); // 적 6
void enemy7(); // 적 7
void enemy8(); // 적 8
void enemy9(); // 적 9
void enemy10(); // 적 10


#endif // #ifndef DISPLAY_H 종료

