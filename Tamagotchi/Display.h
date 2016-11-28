#ifndef DISPLAY_H  // CHARACTER_H가 정의되어 있지 않다면
#define DISPLAY_H // CHARACTER_H 매크로 정의

/*

2012244009 이대웅
참고문헌 https://dojang.io/mod/page/view.php?id=716
디지몬 및 몬스터 이미지

*/

#include"Character.h"
#include"Monster.h"

void coyomon(); // 코요몬 이미지
void agumon(); // 아구몬 이미지
void greymon(); // 그레이몬 이미지
void metalgreymon(); // 메탈그레이몬 이미지
void wargraymon(); // 워그레이몬 이미지
void omegamon(); // 오메가몬 이미지

void digimonDisplay(int lv); // 디지몬 이미지
void enemyDisplay(int monLv); // 적 이미지
ChStat* skillDisplay(ChStat *chStat, MonStat *mon, int selectNum); // 스킬 선택
void skillDescription(ChStat *chStat); // 디지몬명에 따른 스킬 선택
void printWin();//윈 이미지
void printLose();//로즈 이미지
void printLvUp();//레벨업 이미지

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

void damaged();

void monAt1(MonStat *mon);
void monAt2(ChStat *chStat);

void baseAt1(ChStat *chStat);
void baseAt2(MonStat *mon);

void skAt1_1_1(ChStat *chStat);
void skAt1_1_2(MonStat *mon);

void onlineAttack(ChStat *enemyStat);
void onlineAttack2(ChStat *chStat);

void skAt2_1_1(ChStat *chStat);
void skAt2_1_2(MonStat *mon);
void skAt2_2_1(ChStat *chStat);
void skAt2_2_2(MonStat *mon);

void skAt3_1_1(ChStat *chStat);
void skAt3_1_2(MonStat *mon);
void skAt3_2_1(ChStat *chStat);
void skAt3_2_2(MonStat *mon);

void skAt4_1_1(ChStat *chStat);
void skAt4_1_2(MonStat *mon);
void skAt4_2_1(ChStat *chStat);
void skAt4_2_2(MonStat *mon);

void skAt5_1_1(ChStat *chStat);
void skAt5_1_2(MonStat *mon);
void skAt5_2_1(ChStat *chStat);
void skAt5_2_2(MonStat *mon);

void skAt6_1_1(ChStat *chStat);
void skAt6_1_2(MonStat *mon);
void skAt6_2_1(ChStat *chStat);
void skAt6_2_2(MonStat *mon);
#endif // #ifndef DISPLAY_H 종료

