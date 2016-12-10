/*

2012244009 이대웅
참고문헌 https://dojang.io/mod/page/view.php?id=716
몬스터와 싸움

*/
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include"Fight.h"
#include"Interface.h"
#include"Skill.h"
#include"Display.h"
#pragma comment(lib, "winmm.lib")//PlaySound함수 구현을 위한 라이브러리 참조
#pragma warning(disable:4996) // warning C4996을 잡기 위한 코드, 참고문헌 http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266

int fight(ChStat *chStat, int monLv) { // 2012244009 이대웅
	const int x = 38, y = 23;
	int chSelect = 0, money = 0, skSelect = 0, monHp = 0, chHp = 0, chAttack = 0, monAttack = 0, speed = 750;
	PlaySound(NULL, 0, 0);//배경음악의 음악 종료

	srand((unsigned)time(NULL));
	/*  
		seed값 사용, 참고문헌 http://www.jynote.net/64
		time_h에서 unsigned int 데이터 손실 경고, 참고문헌 http://m.cafe.daum.net/dotax/D8UA/274782?q=D_LhkOVB62tSZesOix-5K71w00&
	 */

	MonStat *mon = monster(monLv); // 몬스터 스텟 설정

	monHp = mon->hp; // hp 초기화
	chHp = chStat->hp; // hp 초기화
	chAttack = chStat->attack; // 공격값 초기화
	monAttack = mon->attack; // 몬스터 공격값 초기화

	while (mon->hp > 0 && chStat->hp > 0) { // 몬스터, 유저중 hp가 0이 되면 종료
		
		printUser(chStat);// 오프라인 대전시 유저 디스플레이 2016 11 25 한진오 수정

		chSelect = selectMotion(); // 공격,스킬,도망 선택
		
		switch (chSelect) { 
		case 1: 
			baseAt1(chStat); // 모션
			baseAt2(mon); // 모션
			if (chStat->energy < 5)
				chStat->energy = chStat->energy + 1; // 공격시 기력추가
			break;
		case 2:
			skSelect = selectSkill(chStat); // 스킬 선택
			chStat = skillDisplay(chStat, mon, skSelect); // 스킬데미지 반환
			break;
		case 3:
			menu(chStat); // 돌아가기
			break;
		}
		
		gotoxy(x, y);
		if (rand() % 100 < mon->sheild) { // 방어율보다 낮은 난수 발생시 방어 성공
			system("cls"); // 공격모션 지움
			printMon(mon);
			PlaySound(TEXT("Defend.wav"), NULL, SND_FILENAME | SND_ASYNC); //음성 출력 한진오->http://breadlab.net/36
			gotoxy(x, y);
			printf("몬스터 방어성공 !!!\n\n");
			Sleep(speed);
			gotoxy(x, y);
			printf("                          ");//출력문 지우기
		}
		else {
			if (rand() % 100 < chStat->agility) { // 크리티커율보다 낮은 난수 발생시 크리티컬 발생
				mon->hp = mon->hp - (chStat->attack + chStat->agility - mon->sheild); // 공격력 = 공격력 + 크리댐 - 상대방어력
				PlaySound(TEXT("critical.wav"), NULL, SND_FILENAME | SND_ASYNC); //음성 출력 한진오->http://breadlab.net/36
				damaged();// 해골 모양 출력
				system("cls");

				printMon(mon);//오프라인 대전시 몬스터 및 hp 디스플레이 2016 11 25 한진오 수정

				
				gotoxy(x - 10, y);
				printf("크리티컬 발생!!!\n\n");
				gotoxy(x, y + 2);
				printf("데미지 : %2d", chStat->attack + chStat->agility - mon->sheild);
				Sleep(speed);
				gotoxy(x - 10, y);
				printf("                     ");//크리티컬 발생!!! 출력문 지우기
				gotoxy(x, y + 2);
				printf("              ");// 데미지 출력문 지우기
			}
			else {
				mon->hp = mon->hp - (chStat->attack - mon->sheild); // 공격력 = 공격력 - 상대방어력
				PlaySound(TEXT("damaged.wav"), NULL, SND_FILENAME | SND_ASYNC); //음성 출력 한진오->http://breadlab.net/36
				damaged();
				system("cls");

				printMon(mon);//오프라인 대전시 몬스터 및 hp 디스플레이 2016 11 25 한진오 수정

				
				gotoxy(x, y);
				printf("데미지 : %2d", chStat->attack - mon->sheild);
				Sleep(speed);
				gotoxy(x, y);
				printf("              ");//데미지 출력 초기화
			}
		}

		Sleep(speed);

		if (mon->hp <= 0) break; // 몬스터가 죽으면 break;

		monAt1(mon);//2016 11 25 한진오 수정
		system("cls");
		printUser(chStat);// 오프라인 대전시 유저 디스플레이 2016 11 25 한진오 수정
		monAt2(chStat);
		
		gotoxy(x, y);
		if (rand() % 100 < chStat->health) { // 방어율보다 낮은 난수 발생시 방어 성공
			system("cls");//공격모션 지움
			printUser(chStat);
			PlaySound(TEXT("Defend.wav"), NULL, SND_FILENAME | SND_ASYNC); //음성 출력 한진오->http://breadlab.net/36
			gotoxy(x, y);
			printf("유저 방어성공 !!!\n");
			Sleep(speed);
			gotoxy(x, y);
			printf("                          ");//출력문 지우기
		}
		else {
			if (rand() % 100 < mon->critical) { // 크리티커율보다 낮은 난수 발생시 크리티컬 발생
				chStat->hp = chStat->hp - (mon->attack + mon->critical - chStat->health); // 공격력 = 공격력 + 크리댐 - 상대방어력
				PlaySound(TEXT("critical.wav"), NULL, SND_FILENAME | SND_ASYNC); //음성 출력 한진오->http://breadlab.net/36
				damaged();
				system("cls");
				printUser(chStat);// 오프라인 대전시 유저 디스플레이 2016 11 25 한진오 수정
				
				gotoxy(x, y);
				printf("크리티컬 발생!!!\n");
				gotoxy(x, y + 2);
				printf("데미지 : %2d", mon->attack + mon->critical - chStat->health);
				Sleep(speed);
				gotoxy(x, y);
				printf("                     ");//크리티컬 발생!!! 출력문 지우기
				gotoxy(x, y + 2);
				printf("              ");// 데미지 출력문 지우기
			}
			else {
				chStat->hp = chStat->hp - (mon->attack - chStat->health); // 공격력 = 공격력 - 상대방어력
				PlaySound(TEXT("damaged.wav"), NULL, SND_FILENAME | SND_ASYNC); //음성 출력 한진오->http://breadlab.net/36
				damaged();
				system("cls");
				printUser(chStat);// 오프라인 대전시 유저 디스플레이 2016 11 25 한진오 수정
				
				gotoxy(x, y);
				printf("데미지 : %2d", mon->attack - chStat->health);
				Sleep(speed);
				gotoxy(x, y);
				printf("              ");//데미지 출력 초기화
			}
		}

		if (chStat->hp <= 0) break; // 유저가 죽으면 break
		chStat->energy;
		if (chStat->energy < 5)
			chStat->energy = chStat->energy + 1;
		Sleep(speed);
		system("cls");

		chStat->attack = chAttack;
		mon->attack = monAttack;
	}

	if (mon->hp <= 0) {
		PlaySound(TEXT("Win.wav"), NULL, SND_FILENAME | SND_ASYNC); //음성 출력 한진오->http://breadlab.net/36
		printWin(); // win 이미지
		chStat->money += 500 * monLv; // 몬스터 레벨이 비례하여 돈 획득
		mon->hp = monHp; // hp 초기화
		chStat->hp = chHp; // hp 초기화
		chStat->energy = 0; // 기력 초기화
		return 20 * monLv; // 몬스터 레벨에 알맞은 경험치 반환
	}
	else if (mon->hp < 0 && chStat->hp < 0) {
		PlaySound(TEXT("Draw.wav"), NULL, SND_FILENAME | SND_ASYNC); //음성 출력 한진오->http://breadlab.net/36
		printDraw();//무승부 이미지
		mon->hp = monHp; // hp 초기화
		chStat->hp = chHp; // hp 초기화
		chStat->energy = 0; // 기력 초기화
		return 0;
	}
	else {
		PlaySound(TEXT("Lose.wav"), NULL, SND_FILENAME | SND_ASYNC); //음성 출력 한진오->http://breadlab.net/36
		printLose(); // lose 이미지
		mon->hp = monHp; // hp 초기화
		chStat->hp = chHp; // hp 초기화
		chStat->energy = 0; // 기력 초기화
		return -30 * monLv; // 몬스터 레벨에 알맞은 -경험치 반환
	}
}
int onlineFight(ChStat *myStat, ChStat *enemyStat) { // 온라인 대전
	const int x = 38, y = 23;
	int mySelect = 0, money = 0, skSelect = 0, enemyHp = 0, myHp = 0, myAttack = 0, enemyAttack = 0, speed = 300;

	srand((unsigned)time(NULL));
	/*
	seed값 사용, 참고문헌 http://www.jynote.net/64
	time_h에서 unsigned int 데이터 손실 경고, 참고문헌 http://m.cafe.daum.net/dotax/D8UA/274782?q=D_LhkOVB62tSZesOix-5K71w00&
	*/

	enemyHp = enemyStat->hp; // hp 초기화
	myHp = myStat->hp; // hp 초기화
	myAttack = myStat->attack; // 공격값 초기화
	enemyAttack = enemyStat->attack; // 적 공격력 초기화
	
	system("cls");

	if (enemyStat->hp > 0 && myStat->hp > 0) { // 몬스터, 유저중 hp가 0이 되면 종료

		printUser(myStat);// 오프라인 대전시 유저 디스플레이 2016 11 25 한진오 수정
		baseAt1(myStat); // 공격모션
		onlineAttack(enemyStat); // 온라인에 해당하는 모션

		if (myStat->energy < 5)
			myStat->energy = myStat->energy + 1; // 기력이 5이하일 경우 기력 증가
		
		gotoxy(x, y);
		if (rand() % 100 < enemyStat->health) { // 방어율보다 낮은 난수 발생시 방어 성공
			system("cls");//공격모션 지움
			printEnemy(enemyStat);

			PlaySound(TEXT("Defend.wav"), NULL, SND_FILENAME | SND_ASYNC); //음성 출력 한진오->http://breadlab.net/36
			gotoxy(x, y);
			printf("방어성공 !!!\n\n");
			Sleep(speed);
			gotoxy(x, y);
			printf("                          ");//출력문 지우기
		}
		else {
			if (rand() % 100 < myStat->agility) { // 크리티커율보다 낮은 난수 발생시 크리티컬 발생
				enemyStat->hp = enemyStat->hp - (myStat->attack + myStat->agility - enemyStat->health); // 공격력 = 공격력 + 크리댐 - 상대방어력
				PlaySound(TEXT("critical.wav"), NULL, SND_FILENAME | SND_ASYNC); //음성 출력 한진오->http://breadlab.net/36
				damaged();// 해골 모양 출력
				system("cls");
				printEnemy(enemyStat); // 적 이미지
				
				
				gotoxy(x - 10, y);
				printf("크리티컬 발생!!!\n\n");
				gotoxy(x, y + 2);
				printf("데미지 : %2d", myStat->attack + myStat->agility - enemyStat->health);
				Sleep(speed);
				gotoxy(x - 10, y);
				printf("                     ");//크리티컬 발생!!! 출력문 지우기
				gotoxy(x, y + 2);
				printf("              ");// 데미지 출력문 지우기
			}
			else {
				enemyStat->hp = enemyStat->hp - (myStat->attack - enemyStat->health); // 공격력 = 공격력 - 상대방어력
				PlaySound(TEXT("damaged.wav"), NULL, SND_FILENAME | SND_ASYNC); //음성 출력 한진오->http://breadlab.net/36
				damaged();
				system("cls");
				printEnemy(enemyStat); // 적 이미지
			
				gotoxy(x, y);
				printf("데미지 : %2d", myStat->attack - enemyStat->health);
				Sleep(speed);
				gotoxy(x, y);
				printf("              "); // 데미지 출력 초기화
			}
		}

		Sleep(speed);
		if (enemyStat->hp <= 0 && myStat->hp > 0) {
			PlaySound(TEXT("Win.wav"), NULL, SND_FILENAME | SND_ASYNC); //음성 출력 한진오->http://breadlab.net/36
			printWin();// win 이미지
			return 1; 
		}
		
		enemyAt1(enemyStat); //2016 11 25 한진오 수정
		system("cls");
		printUser(myStat); // 오프라인 대전시 유저 디스플레이 2016 11 25 한진오 수정
		monAt2(myStat);

		gotoxy(x, y);
		if (rand() % 100 < myStat->health) { // 방어율보다 낮은 난수 발생시 방어 성공
			system("cls");//공격모션 지움
			printUser(myStat);
			
			PlaySound(TEXT("Defend.wav"), NULL, SND_FILENAME | SND_ASYNC); //음성 출력 한진오->http://breadlab.net/36
			gotoxy(x, y);
			printf("유저 방어성공 !!!\n");
			Sleep(speed);
			gotoxy(x, y);
			printf("                          ");//출력문 지우기
		}
		else {
			if (rand() % 100 < enemyStat->agility) { // 크리티커율보다 낮은 난수 발생시 크리티컬 발생
				myStat->hp = myStat->hp - (enemyStat->attack + enemyStat->agility - myStat->health); // 공격력 = 공격력 + 크리댐 - 상대방어력
				PlaySound(TEXT("critical.wav"), NULL, SND_FILENAME | SND_ASYNC); //음성 출력 한진오->http://breadlab.net/36
				damaged();
				system("cls");
				printUser(myStat);// 오프라인 대전시 유저 디스플레이 2016 11 25 한진오 수정
				
				
				gotoxy(x, y);
				printf("크리티컬 발생!!!\n");
				gotoxy(x, y + 2);
				printf("데미지 : %2d", enemyStat->attack + enemyStat->agility - myStat->health);
				Sleep(speed);
				gotoxy(x, y);
				printf("                     "); // 크리티컬 발생!!! 출력문 지우기
				gotoxy(x, y + 2);
				printf("              "); // 데미지 출력문 지우기
			}
			else {
				myStat->hp = myStat->hp - (enemyStat->attack - myStat->health); // 공격력 = 공격력 - 상대방어력
				PlaySound(TEXT("damaged.wav"), NULL, SND_FILENAME | SND_ASYNC); //음성 출력 한진오->http://breadlab.net/36
				damaged();
				system("cls");
				printUser(myStat);// 오프라인 대전시 유저 디스플레이 2016 11 25 한진오 수정
				
				gotoxy(x, y);
				printf("데미지 : %2d", enemyStat->attack - myStat->health);
				Sleep(speed);
				gotoxy(x, y);
				printf("              ");//데미지 출력 초기화(한진오)
			}

			if (myStat->hp <= 0 && enemyStat->hp > 0) {  // 유저가 죽으면 break
				PlaySound(TEXT("Lose.wav"), NULL, SND_FILENAME | SND_ASYNC); //음성 출력 한진오->http://breadlab.net/36
				printLose(); // lose 이미지
				enemyStat->hp = enemyHp;
				myStat->hp = myHp;
				myStat->energy = 0;
				return 1; 
			}
		}
		
		if (myStat->energy < 5)
			myStat->energy = myStat->energy + 1;
		Sleep(speed);
		system("cls");

		myStat->attack = myAttack; // 공격력 초기화
		enemyStat->attack = enemyAttack; // 공격력 초기화
	}
	if (enemyStat->hp <= 0 && myStat->hp <= 0) {
		PlaySound(TEXT("Draw.wav"), NULL, SND_FILENAME | SND_ASYNC); //음성 출력 한진오->http://breadlab.net/36
		printDraw();
		enemyStat->hp = enemyHp; // hp 초기화
		myStat->hp = myHp; // hp 초기화
		myStat->energy = 0; // 기력 초기화
		return 1;
	}
	return 0;
}
