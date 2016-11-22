#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include"Character.h"
#include"Interface.h"
#include"Display.h"

/*

2012244063 한진오
2012244009 이대웅 코드통합 및 추가
참고문헌 https://dojang.io/mod/page/view.php?id=716
게임에 필요한 인터페이스 구현

*/

int selectStart() { // 게임 초기 인터페이스 동작
	int selectNum = 1, x = 45, y = 15; // 임의의 좌표;

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
	int selectNum = 1;
	const int x = 60, y = 10;

	while (1){
		int key = 1; // 초기화를 안하면 if문에서 에러가 나므로, 아무 값이나 초기화.

		if (_kbhit()) // 키 입력 여부 확인 ->http://showmiso.tistory.com/8
			key = _getch(); // 키를 입력 받음. 이하는 키에따른 처리 출처
		
		if (key == UP) { // 위 72
			if (selectNum >= 4) // selectNum이 1,2,3보다 클 경우
				selectNum -= 3;
			else continue; // 아니면 계속 진행
		}
		else if (key == DOWN) { // 아래 80
			if (selectNum <= 4) // selectNUm이 4,5,6보다 작은 경우
				selectNum += 3;
			else continue; // 아니면 계속 진행
		}
		else if (key == LEFT){
			if (selectNum > 1) // selectNum이 1보다 클 경우
				selectNum -= 1;
			else continue; // 아니면 계속 진행
		}
		else if (key == RIGHT){
			if (selectNum < 7) // selectNUm이 7보다 작은 경우
				selectNum += 1;
			else continue; // 아니면 계속 진행
		}
		else if (key == ENTER) { // 엔터의 아스키값. 엔터가 입력되었을시, 타이틀을 탈출. 및 selectNum에 해당하는 동작 수행
			system("cls"); // 메뉴 겹침 방지
			break; 
		}
		gotoxy(x, y);

		switch (selectNum){
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
int selectAdventure(int lv) { // 모험선택 인터페이스, 이대웅 추가
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
		}
	}
	return selectNum;
}
int selectMotion() {
	int selectNum = 1;//selectNum 초기화
	const int x = 40, y = 23;

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
			if (selectNum < 5) // selectNUm이 4보다 작은경우(3 이하)
				selectNum += 1;
			else continue; // 아니면 계속 진행
		}
		else if (key == ENTER) { // 엔터의 아스키값. 엔터가 입력되었을시, 타이틀을 탈출. 및 selectNum에 해당하는 동작 수행
			//system("cls"); // 메뉴 겹침 방지
			break;
		}
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
int selectSkill() { // 스킬 선택 인터페이스, 이대웅 추가
	int selectNum = 1;
	const int x = 40, y = 29;

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

		switch (selectNum) {
		case 1:
			printf("▶ 꼬마불꽃       꼬마화염\n");
			break;
		case 2:
			printf("   꼬마불꽃    ▶ 꼬마화염\n");
			break;
		}
	}
	return selectNum;
}
int selectSave(int lv) {
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
			printf("▶ 1번 슬롯");
			gotoxy(x, ++y + 1);
			printf("   2번 슬롯");
			gotoxy(x, ++y + 2);
			printf("   3번 슬롯");
			break;
		case 2:
			printf("   1번 슬롯");
			gotoxy(x, ++y + 1);
			printf("▶ 2번 슬롯");
			gotoxy(x, ++y + 2);
			printf("   3번 슬롯");
			break;
		case 3:
			printf("   1번 슬롯");
			gotoxy(x, ++y + 1);
			printf("   2번 슬롯");
			gotoxy(x, ++y + 2);
			printf("▶ 3번 슬롯");
			break;
		}
	}
	return selectNum;
}
int selectLoad(ChStat *chStat) {
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
			printf("▶ %s 슬롯", chStat->name);
			gotoxy(x, ++y + 1);
			printf("   %s 슬롯", chStat->name);
			gotoxy(x, ++y + 2);
			printf("   %s 슬롯", chStat->name);
			break;
		case 2:
			printf("   %s 슬롯", chStat->name);
			gotoxy(x, ++y + 1);
			printf("▶ %s 슬롯", chStat->name);
			gotoxy(x, ++y + 2);
			printf("   %s 슬롯", chStat->name);
			break;
		case 3:
			printf("   %s 슬롯", chStat->name);
			gotoxy(x, ++y + 1);
			printf("   %s 슬롯", chStat->name);
			gotoxy(x, ++y + 2);
			printf("▶ %s 슬롯", chStat->name);
			break;
		}
	}
	return selectNum;
}
int wait() { // 엔터 입력 전 까지 대기, 이대웅 추가
	int key = 1;

	while (1) {
		if (_kbhit()) // 키 입력 여부 확인 ->http://showmiso.tistory.com/8
			key = _getch(); // 키를 입력 받음. 이하는 키에따른 처리 출처

		if (key == ENTER) 
			break; // 엔터의 아스키값, 엔터가 입력되었을시 탈출
	}
		return 1;
}
void printTitle()
{
	int x = 10, y = 3;

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
	printf("Plese press anyKey...");

	while (1)//---------------------------------------------------------------------------------타이틀의 while문
	{
		if (_kbhit())//키 입력 여부 확인 ->http://showmiso.tistory.com/8
		{
			system("mode con: cols=100 lines=30");//가로 , 세로 ->http://berabue.tistory.com/59
												  //아무키 입력 받았을때, 호출되는 함수 입력
			wait();
			break;
		}
	}
}
void fightInterface(int chHp, int monHp, int lv, int monLv) { // 싸움시 디스플레이
	const int chX = 50, chY = 30, monX = 5, monY = 2; // hp바 위치 고정
	int i = 0;

	enemyDisplay(monLv);
	digimonDisplay(lv);

	gotoxy(chX - 10, chY);
	printf("아구몬 hp : ");
	gotoxy(chX, chY);
	for (i = 1; i <= chHp; i++)
		printf("l");
	gotoxy(monX, monY);
	printf("몬스터 hp : ");
	gotoxy(monX + 12, monY);
	for (i = 1; i <= monHp; i++)
		printf("l");
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