#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include"Interface.h"

/*

2012244063 한진오
2012244009 이대웅 코드통합
참고문헌 https://dojang.io/mod/page/view.php?id=716
게임에 필요한 인터페이스 구현

*/

int selectStart() { // 게임 초기 인터페이스 동작
	int selectNum = 1;

	while (1){
		int key = 1; // 초기화를 안하면 if문에서 에러가 나므로, 아무 값이나 초기화.
		if (_kbhit()) // 키 입력 여부 확인 ->http://showmiso.tistory.com/8
			key = _getch(); // 키를 입력 받음. 이하는 키에따른 처리 출처

		if (key == UP){ // 위 72
			if (selectNum == 2) // selectNum이 1보다 클경우(2 이상)
				selectNum -= 1;
			else continue; // 아니면 계속 진행
		}
		else if (key == DOWN){ // 아래 80
			if (selectNum == 1) // selectNUm이 2보다 작은경우(2 이하)
				selectNum += 1;
			else continue; // 아니면 계속 진행
		}

		else if (key == ENTER){ // 엔터의 아스키값. 엔터가 입력되었을시, 타이틀을 탈출. 및 selectNum에 해당하는 동작 수행.
			system("cls"); // 메뉴 겹침 방지
			break;
		}

		int x = 55, y = 17; // 임의의 좌표
		gotoxy(x, y);

		switch (selectNum){
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
		default:
			printf("starting 오류");
		}	
	}
	return selectNum;
}
int selectMove(){ // 게임상 메인 인터페이스 동작
	int selectNum = 1;//selectNum 초기화

	while (1){
		int key = 1; // 초기화를 안하면 if문에서 에러가 나므로, 아무 값이나 초기화.

		if (_kbhit()) // 키 입력 여부 확인 ->http://showmiso.tistory.com/8
			key = _getch(); // 키를 입력 받음. 이하는 키에따른 처리 출처
						   // 위 72 아래 80
		if (key == LEFT){
			if (selectNum > 1) // selectNum이 1보다 클경우(2 이상)
				selectNum -= 1;
			else continue; // 아니면 계속 진행
		}
		else if (key == RIGHT){
			if (selectNum < 4) // selectNUm이 4보다 작은경우(3 이하)
				selectNum += 1;
			else continue; // 아니면 계속 진행
		}
		else if (key == ENTER) { // 엔터의 아스키값. 엔터가 입력되었을시, 타이틀을 탈출. 및 selectNum에 해당하는 동작 수행
			system("cls"); // 메뉴 겹침 방지
			break; 
		}
		gotoxy(55, 15);

		switch (selectNum){
		case 1:
			printf("▶ 모험      싸우기      저장하기       종료\n");
			break;
		case 2:
			printf("   모험   ▶ 싸우기      저장하기       종료\n");
			break;
		case 3:
			printf("   모험      싸우기   ▶ 저장하기       종료\n");
			break;
		case 4:
			printf("   모험      싸우기      저장하기    ▶ 종료\n");
			break;
		default:
			printf("메뉴 입력오류");
		}
	}
	return selectNum;
}
int selectAdventure() {
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
			if (selectNum < 10) // selectNUm이 10보다 작은경우(10 이하)
				selectNum += 1;

			else continue; // 아니면 계속 진행
		}

		else if (key == ENTER) { // 엔터의 아스키값. 엔터가 입력되었을시, 타이틀을 탈출. 및 selectNum에 해당하는 동작 수행.
			system("cls"); // 메뉴 겹침 방지
			break;
		}

		int x =75, y = 8;
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
		default:
			printf("선택 오류");
		}
	}
	return selectNum;
}
void disappear() { // goto사용시 깜박이는 콘솔의 커서 제거, 참고문헌 http://tip.daum.net/question/39372106
	HANDLE hConsole; // 콘솔 핸들
	CONSOLE_CURSOR_INFO ConsoleCursor; // 콘솔커서 정보 구조체

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 핸들을 구하고

	ConsoleCursor.bVisible = 0; // 1 보임 , 0 안보임
	ConsoleCursor.dwSize = 1; // 커서 사이즈

	SetConsoleCursorInfo(hConsole, &ConsoleCursor); // 설정
}
void gotoxy(int x, int y) { // goto 함수선언, 참고문헌 http://m.blog.naver.com/bestheroz/110240153
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}