#ifndef CHARACTER_H // CHARACTER_H가 정의되어 있지 않다면
#define CHARACTER_H // CHARACTER_H 매크로 정의

/*

2012244009 이대웅
참고문헌 https://dojang.io/mod/page/view.php?id=716
캐릭터에 관련된 소스 ( 스텟, 렙업 )

*/


typedef struct chStat { // 캐릭터들 스텟
	char name[30];
	char condition[30];
	char digimon[30];
	int lv;
	int attack;
	int health;
	int hp;
	int agility;
	int energy;
	int exp;
	int money;
}ChStat;

ChStat* character(int lv); //  디지몬 레벨에 해당하는 스텟
void addExp(int exp); // 사냥 성공시 경험치 축적
void delExp(int exp); // 사냥 실패시 경험치 손실 
ChStat* levelUp(int lv); // 렙업 유무 확인
void showStat(); // 해당하는 디지몬 기본 스텟창
void showAllStat(); // 해당하는 디지몬의 모든 스텟창

#endif // #ifndef CHARACTER_H 종료
