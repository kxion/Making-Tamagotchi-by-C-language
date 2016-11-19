#ifndef SAVELOAD_H  // CHARACTER_H가 정의되어 있지 않다면
#define SAVELOAD_H  // CHARACTER_H 매크로 정의

/*

2012244009 이대웅
참고문헌 https://dojang.io/mod/page/view.php?id=716
게임 저장 및 불러오기

*/
#include"Character.h"

void SaveGame(ChStat *chStat);
ChStat* LoadGame(ChStat *chStat);

#endif // #ifndef CHARACTER_H 종료

