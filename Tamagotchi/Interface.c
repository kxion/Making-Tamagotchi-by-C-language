#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include"Character.h"
#include"Interface.h"
#include"Display.h"
#include"SaveLoad.h"
#include"BinaryTree.h"
#include"Monster.h"
#include"Client.h"
#pragma comment(lib, "winmm.lib")//PlaySound함수 구현을 위한 라이브러리 참조
#pragma warning(disable:4996) // warning C4996을 잡기 위한 코드, 참고문헌 http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266

/*

2012244063 한진오
2012244009 이대웅 코드통합 및 추가
참고문헌 https://dojang.io/mod/page/view.php?id=716
게임에 필요한 인터페이스 구현

*/

void interfaceMain() { // 2012244009 이대웅
	int select = 0, save = 0;
	const int x = 40, y = 15;
	ChStat *chStat;

	//system("color F");//출력문을 흰색으로 변경(옥색에서)

	select = selectStart(); // 메인 인터페이스에서 선택

	if (select == 1) {
		chStat = character(1); // 초기화
		gotoxy(x, y);
		printf("닉네임을 입력하세요 : ");
		gotoxy(x + 25, y);
		fgets(chStat->name, 20, stdin); // 이름 길이제한
		
		int i=0; // 이름 문자열 마지막의 개행문자 제거
		while (1)
		{
			if (chStat->name[i] == '\n')
			{
				chStat->name[i] = '\0';
				break;
			}
			i++;
		}
		
		strcpy(chStat->condition, "유년기");
		strcpy(chStat->digimon, "코요몬");

		menu(chStat);
	}

	else if (select == 2) { // 이어하기시 불러오기
		chStat = character(1); // 초기화
		save = selectLoad(chStat); // 몇번 슬롯 불러올것인지 파악
		chStat = LoadGame(chStat, save); // 해당슬롯 불러오기
		if (!chStat->agility) { // 빈슬롯일 시
			wait();
			system("cls");
			interfaceMain();
			wait();
		}
		else {
			character(chStat->lv);
			menu(chStat);
		}
	}
}
void menu(ChStat* chStat) { // 2012244009 이대웅
	int monLv = 0, number = 0, exp = 0, save = 0, hp = 0;
	const int x = 35, y = 15;
	PlaySound(TEXT("game.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//메모리를 음악의 크기만큼 사용하게 됨. 이 경우는 약 38mb  ->http://breadlab.net/36
																		   //NULL, SND_FILENAME 는 파일을 못찾을시 재생을 안함, SND_ASYNC는 음악 재생과 동시에 다른 작업 가능. SND_LOOP는 음악 무한재생.
																		   //음악 출처 ->http://bgmstore.net/view/D1uAK
	system("cls");

	while (1) {
		
		
		digimonDisplay(chStat->lv); // 디지몬 이미지
		showStat(); // 스텟

		number = selectMove(); // 모험, 대전등 인터페이스 설정

		switch (number) {
		case 1:
			monLv = selectAdventure(chStat->lv); // 모험선택
			
			exp = fight(chStat, monLv); // 대전
			if (exp < 0) exp = 0;
			chStat->exp += exp;
			addExp(chStat->exp);
			chStat = levelUp(chStat->lv); // 렙업
			Sleep(1000);
			system("cls");
			PlaySound(TEXT("game.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//메모리를 음악의 크기만큼 사용하게 됨. 이 경우는 약 38mb  ->http://breadlab.net/36
																				   //NULL, SND_FILENAME 는 파일을 못찾을시 재생을 안함, SND_ASYNC는 음악 재생과 동시에 다른 작업 가능. SND_LOOP는 음악 무한재생.
																				   //음악 출처 ->http://bgmstore.net/view/D1uAK
			break;
		case 2:
			save = selectSave(chStat->lv); // 세이브슬롯 선택
			SaveGame(chStat, save); // 세이브
			break;
		case 3:
			digimonDisplay(chStat->lv);
			showStat();
			skillDescription(chStat); // 스킬설명
			system("cls");
			break;
		case 4:
			digimonDisplay(chStat->lv);
			showAllStat(); // 세부적 스텟 
			wait();
			system("cls");
			break;
		case 5:
			hp = chStat->hp;
			digimonDisplay(chStat->lv);
			client(chStat); // 온라인 대전
			chStat->hp = hp;
			system("cls");
			break;
		case 6:
			printf("종료되었습니다\n"); // 종료
			exit(0);
		case 7:
			save = selectLoad(chStat); // 불러오기
			chStat = LoadGame(chStat, save);
			if (!chStat->agility) {
				wait();
				menu(chStat);
			}
			break;
		}
	}
}
int selectStart() { // 게임 초기 인터페이스 동작  2012244009 이대웅
	const int x = 45, y = 15; // 임의의 좌표;
	int selectNum = 1;

	while (1) {
		int key = 1; // 초기화를 안하면 if문에서 에러가 나므로, 아무 값이나 초기화.
		if (_kbhit()) // 키 입력 여부 확인 ->http://showmiso.tistory.com/8
			key = _getch(); // 키를 입력 받음. 이하는 키에따른 처리 출처

		if (key == UP) { // 위 72
			if (selectNum == 2) // selectNum이 1보다 클경우(2 이상)
				selectNum -= 1;
			else continue; // 아니면 계속 진행
		}
		else if (key == DOWN) { // 아래 80
			if (selectNum == 1) // selectNUm이 2보다 작은경우(2 이하)
				selectNum += 1;
			else continue; // 아니면 계속 진행
		}

		else if (key == ENTER) { // 엔터의 아스키값. 엔터가 입력되었을시, 타이틀을 탈출. 및 selectNum에 해당하는 동작 수행.
			system("cls"); // 메뉴 겹침 방지
			break;
		}

		gotoxy(x, y);

		switch (selectNum) {
		case 1:
			printf("▶ 처음하기\n");
			gotoxy(x, y + 1);
			printf("   이어하기\n");
			break;
		case 2:
			printf("   처음하기\n");
			gotoxy(x, y + 1);
			printf("▶ 이어하기\n");
			break;
		}
	}
	return selectNum;
}
int selectMove(){ // 게임상 메인 인터페이스 동작  2012244009 이대웅
	const int x = 60, y = 10;
	int selectNum = 1;
	
	while (1) {
		int key = 1; // 초기화를 안하면 if문에서 에러가 나므로, 아무 값이나 초기화.
		if (_kbhit()) // 키 입력 여부 확인 ->http://showmiso.tistory.com/8
			key = _getch(); // 키를 입력 받음. 이하는 키에따른 처리 출처

		if (key == UP) { // 위 72
			if (selectNum >= 4) // selectNum이 1,2,3보다 클 경우
				selectNum -= 3;
			else continue; // 아니면 계속 진행
		}
		else if (key == DOWN) { // 아래 80
			if (selectNum <= 4)  // selectNUm이 4,5,6보다 작은 경우
				selectNum += 3;
			else continue; // 아니면 계속 진행
		}
		else if (key == LEFT) {
			if (selectNum > 1) // selectNum이 1보다 클 경우
				selectNum -= 1;
			else continue; // 아니면 계속 진행
		}
		else if (key == RIGHT) {
			if (selectNum < 7) // selectNUm이 7보다 작은 경우
				selectNum += 1;
			else continue; // 아니면 계속 진행
		}
		else if (key == ENTER) { // 엔터의 아스키값. 엔터가 입력되었을시, 타이틀을 탈출. 및 selectNum에 해당하는 동작 수행
			system("cls"); // 메뉴 겹침 방지
			break;
		}

		gotoxy(x, y);

		switch (selectNum) {
		case 1:
			printf("▶ 모험     저장     스킬");
			gotoxy(x, y + 1);
			printf("   정보     대전     종료");
			gotoxy(x, y + 2);
			printf("   불러오기 ");
			break;
		case 2:
			printf("   모험  ▶ 저장     스킬");
			gotoxy(x, y + 1);
			printf("   정보     대전     종료");
			gotoxy(x, y + 2);
			printf("   불러오기 ");
			break;
		case 3:
			printf("   모험     저장  ▶ 스킬");
			gotoxy(x, y + 1);
			printf("   정보     대전     종료");
			gotoxy(x, y + 2);
			printf("   불러오기 ");
			break;
		case 4:
			printf("   모험     저장     스킬");
			gotoxy(x, y + 1);
			printf("▶ 정보     대전     종료");
			gotoxy(x, y + 2);
			printf("   불러오기 ");
			break;
		case 5:
			printf("   모험     저장     스킬");
			gotoxy(x, y + 1);
			printf("   정보  ▶ 대전     종료");
			gotoxy(x, y + 2);
			printf("   불러오기 ");
			break;
		case 6:
			printf("   모험     저장     스킬");
			gotoxy(x, y + 1);
			printf("   정보     대전  ▶ 종료");
			gotoxy(x, y + 2);
			printf("   불러오기 ");
			break;
		case 7:
			printf("   모험     저장     스킬");
			gotoxy(x, y + 1);
			printf("   정보     대전     종료");
			gotoxy(x, y + 2);
			printf("▶ 불러오기 ");
			break;
		}
	}
	return selectNum;
}
int selectAdventure(int lv) { // 모험선택 인터페이스, 2012244009 이대웅 
	digimonDisplay(lv);
	showStat();
	int selectNum = 1;

	while (1) {
		int key = 1; // 초기화를 안하면 if문에서 에러가 나므로, 아무 값이나 초기화.
		if (_kbhit()) // 키 입력 여부 확인 ->http://showmiso.tistory.com/8
			key = _getch(); // 키를 입력 받음. 이하는 키에따른 처리 출처

		if (key == UP) { // 위 72
			if (selectNum > 1) // selectNum이 1보다 클경우(2 이상)
				selectNum -= 1;
			else continue; // 아니면 계속 진행
		}
		else if (key == DOWN) { // 아래 80
			if (selectNum < 10) // selectNUm이 2보다 작은경우(2 이하)
				selectNum += 1;
			else continue; // 아니면 계속 진행
		}

		else if (key == ENTER) { // 엔터의 아스키값. 엔터가 입력되었을시, 타이틀을 탈출. 및 selectNum에 해당하는 동작 수행.
			system("cls"); // 메뉴 겹침 방지
			break;
		}

		int x = 75, y = 8;
		gotoxy(x, y);

		switch (selectNum) {
		case 1:
			printf("▶ 모험 1\n");
			gotoxy(x, ++y + 1);
			printf("   모험 2\n");
			gotoxy(x, ++y + 2);
			printf("   모험 3\n");
			gotoxy(x, ++y + 3);
			printf("   모험 4\n");
			gotoxy(x, ++y + 4);
			printf("   모험 5\n");
			gotoxy(x, ++y + 5);
			printf("   모험 6\n");
			gotoxy(x, ++y + 6);
			printf("   모험 7\n");
			gotoxy(x, ++y + 7);
			printf("   모험 8\n");
			gotoxy(x, ++y + 8);
			printf("   모험 9\n");
			gotoxy(x, ++y + 9);
			printf("   모험 10\n");
			break;
		case 2:
			printf("   모험 1\n");
			gotoxy(x, ++y + 1);
			printf("▶ 모험 2\n");
			gotoxy(x, ++y + 2);
			printf("   모험 3\n");
			gotoxy(x, ++y + 3);
			printf("   모험 4\n");
			gotoxy(x, ++y + 4);
			printf("   모험 5\n");
			gotoxy(x, ++y + 5);
			printf("   모험 6\n");
			gotoxy(x, ++y + 6);
			printf("   모험 7\n");
			gotoxy(x, ++y + 7);
			printf("   모험 8\n");
			gotoxy(x, ++y + 8);
			printf("   모험 9\n");
			gotoxy(x, ++y + 9);
			printf("   모험 10\n");
			break;
		case 3:
			printf("   모험 1\n");
			gotoxy(x, ++y + 1);
			printf("   모험 2\n");
			gotoxy(x, ++y + 2);
			printf("▶ 모험 3\n");
			gotoxy(x, ++y + 3);
			printf("   모험 4\n");
			gotoxy(x, ++y + 4);
			printf("   모험 5\n");
			gotoxy(x, ++y + 5);
			printf("   모험 6\n");
			gotoxy(x, ++y + 6);
			printf("   모험 7\n");
			gotoxy(x, ++y + 7);
			printf("   모험 8\n");
			gotoxy(x, ++y + 8);
			printf("   모험 9\n");
			gotoxy(x, ++y + 9);
			printf("   모험 10\n");
			break;
		case 4:
			printf("   모험 1\n");
			gotoxy(x, ++y + 1);
			printf("   모험 2\n");
			gotoxy(x, ++y + 2);
			printf("   모험 3\n");
			gotoxy(x, ++y + 3);
			printf("▶ 모험 4\n");
			gotoxy(x, ++y + 4);
			printf("   모험 5\n");
			gotoxy(x, ++y + 5);
			printf("   모험 6\n");
			gotoxy(x, ++y + 6);
			printf("   모험 7\n");
			gotoxy(x, ++y + 7);
			printf("   모험 8\n");
			gotoxy(x, ++y + 8);
			printf("   모험 9\n");
			gotoxy(x, ++y + 9);
			printf("   모험 10\n");
			break;
		case 5:
			printf("   모험 1\n");
			gotoxy(x, ++y + 1);
			printf("   모험 2\n");
			gotoxy(x, ++y + 2);
			printf("   모험 3\n");
			gotoxy(x, ++y + 3);
			printf("   모험 4\n");
			gotoxy(x, ++y + 4);
			printf("▶ 모험 5\n");
			gotoxy(x, ++y + 5);
			printf("   모험 6\n");
			gotoxy(x, ++y + 6);
			printf("   모험 7\n");
			gotoxy(x, ++y + 7);
			printf("   모험 8\n");
			gotoxy(x, ++y + 8);
			printf("   모험 9\n");
			gotoxy(x, ++y + 9);
			printf("   모험 10\n");
			break;
		case 6:
			printf("   모험 1\n");
			gotoxy(x, ++y + 1);
			printf("   모험 2\n");
			gotoxy(x, ++y + 2);
			printf("   모험 3\n");
			gotoxy(x, ++y + 3);
			printf("   모험 4\n");
			gotoxy(x, ++y + 4);
			printf("   모험 5\n");
			gotoxy(x, ++y + 5);
			printf("▶ 모험 6\n");
			gotoxy(x, ++y + 6);
			printf("   모험 7\n");
			gotoxy(x, ++y + 7);
			printf("   모험 8\n");
			gotoxy(x, ++y + 8);
			printf("   모험 9\n");
			gotoxy(x, ++y + 9);
			printf("   모험 10\n");
			break;
		case 7:
			printf("   모험 1\n");
			gotoxy(x, ++y + 1);
			printf("   모험 2\n");
			gotoxy(x, ++y + 2);
			printf("   모험 3\n");
			gotoxy(x, ++y + 3);
			printf("   모험 4\n");
			gotoxy(x, ++y + 4);
			printf("   모험 5\n");
			gotoxy(x, ++y + 5);
			printf("   모험 6\n");
			gotoxy(x, ++y + 6);
			printf("▶ 모험 7\n");
			gotoxy(x, ++y + 7);
			printf("   모험 8\n");
			gotoxy(x, ++y + 8);
			printf("   모험 9\n");
			gotoxy(x, ++y + 9);
			printf("   모험 10\n");
			break;
		case 8:
			printf("   모험 1\n");
			gotoxy(x, ++y + 1);
			printf("   모험 2\n");
			gotoxy(x, ++y + 2);
			printf("   모험 3\n");
			gotoxy(x, ++y + 3);
			printf("   모험 4\n");
			gotoxy(x, ++y + 4);
			printf("   모험 5\n");
			gotoxy(x, ++y + 5);
			printf("   모험 6\n");
			gotoxy(x, ++y + 6);
			printf("   모험 7\n");
			gotoxy(x, ++y + 7);
			printf("▶ 모험 8\n");
			gotoxy(x, ++y + 8);
			printf("   모험 9\n");
			gotoxy(x, ++y + 9);
			printf("   모험 10\n");
			break;
		case 9:
			printf("   모험 1\n");
			gotoxy(x, ++y + 1);
			printf("   모험 2\n");
			gotoxy(x, ++y + 2);
			printf("   모험 3\n");
			gotoxy(x, ++y + 3);
			printf("   모험 4\n");
			gotoxy(x, ++y + 4);
			printf("   모험 5\n");
			gotoxy(x, ++y + 5);
			printf("   모험 6\n");
			gotoxy(x, ++y + 6);
			printf("   모험 7\n");
			gotoxy(x, ++y + 7);
			printf("   모험 8\n");
			gotoxy(x, ++y + 8);
			printf("▶ 모험 9\n");
			gotoxy(x, ++y + 9);
			printf("   모험 10\n");
			break;
		case 10:
			printf("   모험 1\n");
			gotoxy(x, ++y + 1);
			printf("   모험 2\n");
			gotoxy(x, ++y + 2);
			printf("   모험 3\n");
			gotoxy(x, ++y + 3);
			printf("   모험 4\n");
			gotoxy(x, ++y + 4);
			printf("   모험 5\n");
			gotoxy(x, ++y + 5);
			printf("   모험 6\n");
			gotoxy(x, ++y + 6);
			printf("   모험 7\n");
			gotoxy(x, ++y + 7);
			printf("   모험 8\n");
			gotoxy(x, ++y + 8);
			printf("   모험 9\n");
			gotoxy(x, ++y + 9);
			printf("▶ 모험 10\n");
			break;
		}
	}
	return selectNum;
}
int selectMotion() { // 2012244009 이대웅
	int selectNum = 1; //selectNum 초기화
	const int x = 38, y = 19;
	
	while (1) {
		int key = 1; // 초기화를 안하면 if문에서 에러가 나므로, 아무 값이나 초기화.

		if (_kbhit()) // 키 입력 여부 확인 ->http://showmiso.tistory.com/8
			key = _getch();	// 키를 입력 받음. 이하는 키에따른 처리 출처

		if (key == LEFT) {
			if (selectNum > 1) // selectNum이 1보다 클경우(1 이상)
				selectNum -= 1;
			else continue; // 아니면 계속 진행
		}
		else if (key == RIGHT) {
			if (selectNum < 4) // selectNUm이 4보다 작은경우(3 이하)
				selectNum += 1;
			else continue; // 아니면 계속 진행
		}
		else if (key == ENTER) // 엔터의 아스키값. 엔터가 입력되었을시, 타이틀을 탈출. 및 selectNum에 해당하는 동작 수행
			break;
		
		gotoxy(x, y);

		switch (selectNum) {
		case 1:
			printf("▶ 공격     스킬     도망\n");
			break;
		case 2:
			printf("   공격  ▶ 스킬     도망\n");
			break;
		case 3:
			printf("   공격     스킬  ▶ 도망\n");
			break;
		}
	}
	return selectNum;
}
int selectSkill(ChStat *chStat) { // 스킬 선택 인터페이스,  2012244009 이대웅
	int selectNum = 1;
	const int x = 40, y = 25;

	while (1) {
		int key = 1; // 초기화를 안하면 if문에서 에러가 나므로, 아무 값이나 초기화.

		if (_kbhit()) // 키 입력 여부 확인 ->http://showmiso.tistory.com/8
			key = _getch(); // 키를 입력 받음. 이하는 키에따른 처리 출처

		if (key == LEFT) {
			if (selectNum > 1) // selectNum이 1보다 클경우(1 이상)
				selectNum -= 1;
			else continue; // 아니면 계속 진행
		}
		else if (key == RIGHT) {
			if (selectNum < 2) // selectNUm이 2보다 작은경우(2 이하)
				selectNum += 1;
			else continue; // 아니면 계속 진행
		}
		else if (key == ENTER) { // 엔터의 아스키값. 엔터가 입력되었을시, 타이틀을 탈출. 및 selectNum에 해당하는 동작 수행
			//system("cls"); // 메뉴 겹침 방지
			break;
		}
		gotoxy(x, y);

		if (!strcmp(chStat->digimon, "코요몬")) {
			printf("▶ 몸통박치기");
		}
		if (!strcmp(chStat->digimon, "아구몬")) {
			switch (selectNum) {
			case 1:
				printf("▶ 꼬마불꽃       꼬마화염\n");
				break;
			case 2:
				printf("   꼬마불꽃    ▶ 꼬마화염\n");
				break;
			}
		}
		else if (!strcmp(chStat->digimon, "그레이몬")) {
			switch (selectNum) {
			case 1:
				printf("▶ 화염 불        메가화염\n");
				break;
			case 2:
				printf("   화염 불     ▶ 메가화염\n");
				break; 
			}
		}
		else if (!strcmp(chStat->digimon, "메탈그레이몬")) {
			switch (selectNum) {
			case 1:
				printf("▶ 다연발 불꽃       기가 디스티로이어\n");
				break;
			case 2:
				printf("   다연발 불꽃    ▶ 기가 디스티로이어\n");
				break;
			}
		}
		else if (!strcmp(chStat->digimon, "워그레이몬")) {
			switch (selectNum) {
			case 1:
				printf("▶ 테라광선       가이아포스\n");
				break;
			case 2:
				printf("   테라광선    ▶ 가이아포스\n");
				break;
			}
		}
		else if (!strcmp(chStat->digimon, "오메가몬")) {
			switch (selectNum) {
			case 1:
				printf("▶ 그레이검       가루캐논\n");
				break;
			case 2:
				printf("   그레이검    ▶ 가루캐논\n");
				break;
			}
		}
	}
	return selectNum;
}
int selectSave(int lv) { // 2012244009 이대웅
	digimonDisplay(lv);
	showStat();
	
	int selectNum = 1;
	Name *name = (Name*)malloc(sizeof(Name)); // 구조체포인터 동적으로 할당
	FILE *fp1 = fopen("save1.txt", "rt");
	FILE *fp2 = fopen("save2.txt", "rt");
	FILE *fp3 = fopen("save3.txt", "rt");

	if (fp1 == NULL) strcpy(name->name1, "빈");
	else fscanf(fp1, "%s", name->name1);

	if (fp2 == NULL) strcpy(name->name2, "빈");
	else fscanf(fp2, "%s", name->name2);

	if (fp3 == NULL) strcpy(name->name3, "빈");
	else fscanf(fp3, "%s", name->name3);

	if (!strcmp(name->name1, "유년기") || !strcmp(name->name1, "성장기") || !strcmp(name->name1, "성숙기") || !strcmp(name->name1, "완전체") ||
		!strcmp(name->name1, "궁극체") || !strcmp(name->name1, "초궁극체")) // 이름이 공백일 떄의 예외처리
		strcpy(name->name1, " ");
	else if (!strcmp(name->name2, "유년기") || !strcmp(name->name2, "성장기") || !strcmp(name->name2, "성숙기") || !strcmp(name->name2, "완전체") ||
		!strcmp(name->name2, "궁극체") || !strcmp(name->name2, "초궁극체")) // 이름이 공백일 떄의 예외처리
		strcpy(name->name2, " ");
	else if (!strcmp(name->name3, "유년기") || !strcmp(name->name3, "성장기") || !strcmp(name->name3, "성숙기") || !strcmp(name->name3, "완전체") ||
		!strcmp(name->name3, "궁극체") || !strcmp(name->name3, "초궁극체")) // 이름이 공백일 떄의 예외처리
		strcpy(name->name3, " ");
		
	while (1) {
		int key = 1; // 초기화를 안하면 if문에서 에러가 나므로, 아무 값이나 초기화.
		if (_kbhit()) // 키 입력 여부 확인 ->http://showmiso.tistory.com/8
			key = _getch(); // 키를 입력 받음. 이하는 키에따른 처리 출처

		if (key == UP) { // 위 72
			if (selectNum > 1) // selectNum이 1보다 클경우(2 이상)
				selectNum -= 1;

			else continue; // 아니면 계속 진행
		}
		else if (key == DOWN) { // 아래 80
			if (selectNum < 3) // selectNUm이 3보다 작은경우(3 이하)
				selectNum += 1;

			else continue; // 아니면 계속 진행
		}

		else if (key == ENTER) { // 엔터의 아스키값. 엔터가 입력되었을시, 타이틀을 탈출. 및 selectNum에 해당하는 동작 수행.
			system("cls"); // 메뉴 겹침 방지
			break;
		}
		int x = 75, y = 8;
		gotoxy(x, y);

		switch (selectNum) {
		case 1:
			printf("▶ %s 슬롯", name->name1); // 본인 캐릭터의 이름 출력
			gotoxy(x, ++y + 1);
			printf("   %s 슬롯", name->name2);
			gotoxy(x, ++y + 2);
			printf("   %s 슬롯", name->name3);
			break;
		case 2:
			printf("   %s 슬롯", name->name1);
			gotoxy(x, ++y + 1);
			printf("▶ %s 슬롯", name->name2);
			gotoxy(x, ++y + 2);
			printf("   %s 슬롯", name->name3);
			break;
		case 3:
			printf("   %s 슬롯", name->name1);
			gotoxy(x, ++y + 1);
			printf("   %s 슬롯", name->name2);
			gotoxy(x, ++y + 2);
			printf("▶ %s 슬롯", name->name3);
			break;
		}
	}
	int count1 = 1, count2 = 1, count3 = 1;

	if (!strcmp(name->name1, "빈")) count1--; // 빈슬롯일 시 0으로 감소
	if (!strcmp(name->name2, "빈")) count2--;
	if (!strcmp(name->name3, "빈")) count3--;

	if (count1) fclose(fp1); // 빈슬롯이 아니라면 close
	if (count2) fclose(fp2);
	if (count3) fclose(fp3);

	free(name);

	return selectNum;
}
int selectLoad(ChStat *chStat) { // 2012244009 이대웅
	int selectNum = 1;
	Name *name = (Name*)malloc(sizeof(Name)); // 구조체포인터 동적으로 할당
	FILE *fp1 = fopen("save1.txt", "rt");
	FILE *fp2 = fopen("save2.txt", "rt");
	FILE *fp3 = fopen("save3.txt", "rt");

	if (fp1 == NULL) strcpy(name->name1, "빈");
	else fscanf(fp1, "%s", name->name1);
	
	if (fp2 == NULL) strcpy(name->name2, "빈");
	else fscanf(fp2, "%s", name->name2);

	if (fp3 == NULL) strcpy(name->name3, "빈");
	else fscanf(fp3, "%s", name->name3);

	if (!strcmp(name->name1, "유년기") || !strcmp(name->name1, "성장기") || !strcmp(name->name1, "성숙기") || !strcmp(name->name1, "완전체") ||
		!strcmp(name->name1, "궁극체") || !strcmp(name->name1, "초궁극체")) // 이름이 공백일 떄의 예외처리
		strcpy(name->name1, " ");
	else if (!strcmp(name->name2, "유년기") || !strcmp(name->name2, "성장기") || !strcmp(name->name2, "성숙기") || !strcmp(name->name2, "완전체") ||
		!strcmp(name->name2, "궁극체") || !strcmp(name->name2, "초궁극체")) // 이름이 공백일 떄의 예외처리
		strcpy(name->name2, " ");
	else if (!strcmp(name->name3, "유년기") || !strcmp(name->name3, "성장기") || !strcmp(name->name3, "성숙기") || !strcmp(name->name3, "완전체") ||
		!strcmp(name->name3, "궁극체") || !strcmp(name->name3, "초궁극체")) // 이름이 공백일 떄의 예외처리
		strcpy(name->name3, " ");

	while (1) {
		int key = 1; // 초기화를 안하면 if문에서 에러가 나므로, 아무 값이나 초기화.
		if (_kbhit()) // 키 입력 여부 확인 ->http://showmiso.tistory.com/8
			key = _getch(); // 키를 입력 받음. 이하는 키에따른 처리 출처

		if (key == UP) { // 위 72
			if (selectNum > 1) // selectNum이 1보다 클경우(2 이상)
				selectNum -= 1;

			else continue; // 아니면 계속 진행
		}
		else if (key == DOWN) { // 아래 80
			if (selectNum < 3) // selectNUm이 3보다 작은경우(3 이하)
				selectNum += 1;

			else continue; // 아니면 계속 진행
		}

		else if (key == ENTER) { // 엔터의 아스키값. 엔터가 입력되었을시, 타이틀을 탈출. 및 selectNum에 해당하는 동작 수행.
			system("cls"); // 메뉴 겹침 방지
			break;
		}

		int x = 44, y = 14;
		gotoxy(x, y);

		switch (selectNum) {
		case 1:
			printf("▶ %s 슬롯", name->name1); // 캐릭터의 이름 출력
			gotoxy(x, ++y + 1);
			printf("   %s 슬롯", name->name2);
			gotoxy(x, ++y + 2);
			printf("   %s 슬롯", name->name3);
			break;
		case 2:
			printf("   %s 슬롯", name->name1);
			gotoxy(x, ++y + 1);
			printf("▶ %s 슬롯", name->name2);
			gotoxy(x, ++y + 2);
			printf("   %s 슬롯", name->name3);
			break;
		case 3:
			printf("   %s 슬롯", name->name1);
			gotoxy(x, ++y + 1);
			printf("   %s 슬롯", name->name2);
			gotoxy(x, ++y + 2);
			printf("▶ %s 슬롯", name->name3);
			break;
		}
	}
	int count1 = 1, count2 = 1, count3 = 1;

	if (!strcmp(name->name1, "빈")) count1--; // 빈 슬롯일 시 0으로 감소
	if (!strcmp(name->name2, "빈")) count2--;
	if (!strcmp(name->name3, "빈")) count3--;

	if (count1) fclose(fp1); // 빈슬롯이 아니라면 close
	if (count2) fclose(fp2);
	if (count3) fclose(fp3);
	
	free(name);

	return selectNum;
}
void wait() { // 엔터 입력 전 까지 대기, 2012244009 이대웅
	int key = 1;

	while (1) {
		if (_kbhit()) // 키 입력 여부 확인 ->http://showmiso.tistory.com/8
			key = _getch(); // 키를 입력 받음. 이하는 키에따른 처리 출처

		if (key == ENTER) 
			break; // 엔터의 아스키값, 엔터가 입력되었을시 탈출
	}
}
void printTitle()
{
	int x = 10, y = 3;
	PlaySound(TEXT("title.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//메모리를 음악의 크기만큼 사용하게 됨. 이 경우는 약 38mb  ->http://breadlab.net/36
																		   //NULL, SND_FILENAME 는 파일을 못찾을시 재생을 안함, SND_ASYNC는 음악 재생과 동시에 다른 작업 가능. SND_LOOP는 음악 무한재생.
																		   //음악 출처 ->http://bgmstore.net/view/D1uAK
	system("mode con: cols=140 lines=28");//가로 , 세로 ->http://berabue.tistory.com/59
	gotoxy(x, y++);
	printf(" [(\\\?,                    +|             |!                    ?xCCY|I                      ^(YCCr[.  :$i          `J< \n");
	gotoxy(x, y++);
	printf(" $&xuXqq$$dl                 m$X           O$v                 `b$ku||nZ$0                   {$$Lu[jc#v  j$l          >$x \n");
	gotoxy(x, y++);
	printf(" &0       X$X                OW$;         +$8n                )$u                           a$<          j$l              \n");
	gotoxy(x, y++);
	printf(" &O        +$/      i~l      ZdX@         $18n      :~<      -$+                 >~i       d@            j$I  >~^         \n");
	gotoxy(x, y++);
	printf(" &O         w@   +@$pZ#$t    Z* $U       wW $n    o$aZd$w    @0               ~$$qmb$o^   <$!            j$jZ@Zm$$I    $} \n");
	gotoxy(x, y++);
	printf(" &O         ($^  ?;    i$~   Z* i$I     _$. $n   ,[     $J  l$>              f$?     n$I  C$             j$$+    O$    $] \n");
	gotoxy(x, y++);
	printf(" &O         }$,         @z   Z*  L$     $t  $n          J8  ]$:     {@&&#q  `$}       qW  dW             j$|     j$>   $] \n");
	gotoxy(x, y++);
	printf(" &O         u$    {O&8$#$z   Z*   $U   qW   $n    iJ*&$8@&  l$~         Y@  ($        )$  Q$             j$;     .$~   $] \n");
	gotoxy(x, y++);
	printf(" &O         $J   $a_    $X   Z*   l$l -$`   $n   w$1^   v$   @m         zB  |$        )$  ~$+            j$l     `$<   $] \n");
	gotoxy(x, y++);
	printf(" &O        &8   z$      $z   Z*    U@ $/    $n  !$j     a8   ?$)        cB  j$]       b*   d$.           j$l     `$<   $] \n");
	gotoxy(x, y++);
	printf(" &Q     !Y$0    f$`    *$z   Z*     @B#     $n  j$(    J$&    1$q:      O$   r$?     U$^    w$x       I  j$l     `$<   $] \n");
	gotoxy(x, y++);
	printf(" $$$B$$$Wv.      U$amM$.@C   d8     l$`     $z   [$Bmh$}X$      U$$$qW$$d[    _B$dwo$w       id$$MqB$$(  :$i     `$+   ${ \n");
	gotoxy(x, y++);
	printf("                   i<                              :<,             >>>           ><:            .>>l                      \n");

	gotoxy(60, y + 6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("Plese press AnyKey...");

	int key;//엔터키입력시  중복 방지

	while (1)//---------------------------------------------------------------------------------타이틀의 while문
	{
		gotoxy(60, y + 6);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		printf("Plese press AnyKey...");
		
		if (_kbhit())//키 입력 여부 확인 ->http://showmiso.tistory.com/8
		{
			system("mode con: cols=100 lines=30");//가로 , 세로 ->http://berabue.tistory.com/59
			key = getch();//엔터기를 입력 받았을시의 경우 대비(방파제)
			break;
		} 
		Sleep(500);
		gotoxy(60, y + 6);
		printf("                     ");

		if (_kbhit())//키 입력 여부 확인 ->http://showmiso.tistory.com/8
		{
			system("mode con: cols=100 lines=30");//가로 , 세로 ->http://berabue.tistory.com/59
			key = getch();//엔터기를 입력 받았을시의 경우 대비(방파제)
			break;
		}
		Sleep(500);
	}
	
}

void printUser(ChStat *chStat) { // 오프라인 대전시 유저 디스플레이 2016 11 25 한진오 수정
	const int chX = 5, chY = 2; // hp바 위치 고정
	int i = 0;


	digimonDisplay(chStat->lv);

	gotoxy(chX, chY);
	printf("%s hp : ", chStat->name);

	gotoxy(chX + 12, chY);
	for (i = 1; i <= chStat->hp; i++) {
		printf("l");
		if (i == 50)
			gotoxy(chX, chY + 1);
	}
	gotoxy(73, 26);
	printf("기력 : ");
	gotoxy(81, 26);
	for (i = 1; i <= chStat->energy; i++)
		printf("■");
}
void printUser2(ChStat *chStat) { // 기력 표시 안되는, 유저 디스플레이 2016 11 25 한진오 수정
	const int chX = 5, chY = 2; // hp바 위치 고정
	int i = 0;

	digimonDisplay(chStat->lv);

	gotoxy(chX, chY);
	printf("%s hp : ", chStat->name);

	gotoxy(chX + 12, chY);
	for (i = 1; i <= chStat->hp; i++) {
		printf("l");
		if (i == 50)
			gotoxy(chX, chY + 1);
	}
}
void printMon(MonStat *mon)//오프라인 대전시 몬스터 디스플레이 2016 11 25 한진오 수정
{
	const int monX = 5, monY = 2;
	int i = 0;

	enemyDisplay(mon->lv);//**

	gotoxy(monX, monY);//**
	printf("몬스터 hp : ");
	gotoxy(monX + 12, monY);
	for (i = 1; i <= mon->hp; i++)
		printf("l");//**

}
void printEnemy(ChStat *enemyStat) { // 2012244009 이대웅
	const int enemyX = 5, enemyY = 2;
	int i = 0;

	onlineDisplay(enemyStat->lv); // 적 이미지 출력

	gotoxy(enemyX, enemyY);
	printf("%s hp : ", enemyStat->name);
	gotoxy(enemyX + 12, enemyY);
	for (i = 1; i <= enemyStat->hp; i++)
		printf("l");
}

void disappear() { // goto사용시 깜박이는 콘솔의 커서 제거, 참고문헌 http://tip.daum.net/question/39372106 2012244009 이대웅
	HANDLE hConsole; // 콘솔 핸들
	CONSOLE_CURSOR_INFO ConsoleCursor; // 콘솔커서 정보 구조체

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 핸들을 구하고

	ConsoleCursor.bVisible = 0; // 1 보임 , 0 안보임
	ConsoleCursor.dwSize = 1; // 커서 사이즈

	SetConsoleCursorInfo(hConsole, &ConsoleCursor); // 설정
}
void gotoxy(int x, int y) { // goto 함수선언, 참고문헌 http://m.blog.naver.com/bestheroz/110240153  2012244009 이대웅
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}