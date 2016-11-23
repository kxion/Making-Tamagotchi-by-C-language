#include"Interface.h"
#include"BinaryTree.h"

int main() {
	setDigimonCondition();
	disappear(); // 콘솔에 커서 제거
	printTitle();
	/*
	select = selectStart(); // 메인 인터페이스에서 선택
	
	if (select == 1) {
		chStat = character(1); // 초기화
		gotoxy(x, y);
		printf("닉네임을 입력하세요 : ");
		gotoxy(x + 25, y);
		fgets(chStat->name, 10, stdin); /* gets(string); XXX: gets 함수는 string의 크기가 어느 정도인지 알지 못한다. 따라서 STRING_SIZE 이상의 길이를 가진 문자열 입력시 정상 작동을 보장할 수 없다. https://kldp.org/node/75467 */
		strcpy(chStat->condition, "유아기");
		strcpy(chStat->digimon, "코요몬");
	/*}

	else if (select == 2) { // 이어하기시 불러오기
		chStat = character(1); // 초기화
		save = selectLoad(chStat);
		chStat = LoadGame(chStat, save);
		lv = chStat->lv;
		character(lv);
	}
	
	system("cls");

	while (1) {
		digimonDisplay(chStat->lv);
		showStat();
		
		number = selectMove();
		*/
	interfaceMain();

	return 0;
}