#ifndef SAVELOAD_H  // CHARACTER_H가 정의되어 있지 않다면
#define SAVELOAD_H  // CHARACTER_H 매크로 정의

/*

2012244009 이대웅
참고문헌 https://dojang.io/mod/page/view.php?id=716
게임 저장 및 불러오기


*/
#include"Character.h"

void SaveGame(ChStat *chStat, int number); // 세이브
ChStat* LoadGame(ChStat *chStat, int number); // 불러오기

#endif // #ifndef CHARACTER_H 종료

