#ifndef INTERFACE_H // CHARACTER_H가 정의되어 있지 않다면
#define INTERFACE_H // CHARACTER_H 매크로 정의

/*

2012244063 한진오
2012244009 이대웅 코드통합
참고문헌 https://dojang.io/mod/page/view.php?id=716
게임에 필요한 인터페이스 구현

*/
#include"Character.h"
#include"Monster.h"

typedef struct name {
	char name1[20];
	char name2[20];
	char name3[20];
}Name;

#define ENTER 13 // 아스키값 선언
#define UP 72 // 아스키값 선언
#define DOWN 80 // 아스키값 선언
#define RIGHT 77 // 아스키값 선언
#define LEFT 75 // 아스키값 선언

void interfaceMain();
int selectStart(); // 게임 초기 인터페이스 동작
int selectMove(); // 게임상 메인 인터페이스 동작
int selectAdventure(int lv); // 모험선택 인터페이스
//void fightInterface(ChStat *chStat, MonStat *mon); // 싸움시 인터페이스
void printUser(ChStat *chStat);// 오프라인 대전시 유저 디스플레이 2016 11 25 한진오 수정
void printUser2(ChStat *chStat);//기력 표시가 안되는, 디스플레이 
void printMon(MonStat *mon);//오프라인 대전시 몬스터 디스플레이 2016 11 25 한진오 수정
void userAtMotion1();//유저 공격 모션  2016 11 25 한진오
void userAtMotion2();//유저 공격 모션  2016 11 25 한진오
void monAtMotion1();//몬스터 공격 모션  2016 11 25 한진오
void monAtMotion2();//몬스터 공격 모션  2016 11 25 한진오
int selectMotion();// 공격, 스킬, 도망 인터페이스
int selectSkill(ChStat* chStat); // 스킬 선택 인터페이스
int selectSave(int lv);
int selectLoad(ChStat *chStat);
void menu(ChStat* chStat);
void printTitle();
void wait(); // 엔터 전까지 기다리는 함수
void disappear(); // goto사용시 깜박이는 콘솔의 커서 제거
void gotoxy(int x, int y); // goto 함수 선언

#endif // #ifndef INTERFACE_H 종료