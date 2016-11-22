#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include"Character.h"
#include"Interface.h"
#include"Display.h"

/*

2012244063 ������
2012244009 �̴�� �ڵ����� �� �߰�
������ https://dojang.io/mod/page/view.php?id=716
���ӿ� �ʿ��� �������̽� ����

*/

int selectStart() { // ���� �ʱ� �������̽� ����
	int selectNum = 1, x = 45, y = 15; // ������ ��ǥ;

	while (1){
		int key = 1; // �ʱ�ȭ�� ���ϸ� if������ ������ ���Ƿ�, �ƹ� ���̳� �ʱ�ȭ.
		if (_kbhit()) // Ű �Է� ���� Ȯ�� ->http://showmiso.tistory.com/8
			key = _getch(); // Ű�� �Է� ����. ���ϴ� Ű������ ó�� ��ó

		if (key == UP){ // �� 72
			if (selectNum == 2) // selectNum�� 1���� Ŭ���(2 �̻�)
				selectNum -= 1;
			else continue; // �ƴϸ� ��� ����
		}
		else if (key == DOWN){ // �Ʒ� 80
			if (selectNum == 1) // selectNUm�� 2���� �������(2 ����)
				selectNum += 1;
			else continue; // �ƴϸ� ��� ����
		}

		else if (key == ENTER){ // ������ �ƽ�Ű��. ���Ͱ� �ԷµǾ�����, Ÿ��Ʋ�� Ż��. �� selectNum�� �ش��ϴ� ���� ����.
			system("cls"); // �޴� ��ħ ����
			break;
		}

		gotoxy(x, y);

		switch (selectNum){
		case 1:
			printf("�� ó���ϱ�\n");
			gotoxy(x, y + 1);
			printf("   �̾��ϱ�\n");
			break;
		case 2:
			printf("   ó���ϱ�\n");
			gotoxy(x, y + 1);
			printf("�� �̾��ϱ�\n");
			break;
		default:
			printf("starting ����");
		}	
	}
	return selectNum;
}
int selectMove(){ // ���ӻ� ���� �������̽� ����
	int selectNum = 1;
	const int x = 60, y = 10;

	while (1){
		int key = 1; // �ʱ�ȭ�� ���ϸ� if������ ������ ���Ƿ�, �ƹ� ���̳� �ʱ�ȭ.

		if (_kbhit()) // Ű �Է� ���� Ȯ�� ->http://showmiso.tistory.com/8
			key = _getch(); // Ű�� �Է� ����. ���ϴ� Ű������ ó�� ��ó
		
		if (key == UP) { // �� 72
			if (selectNum >= 4) // selectNum�� 1,2,3���� Ŭ ���
				selectNum -= 3;
			else continue; // �ƴϸ� ��� ����
		}
		else if (key == DOWN) { // �Ʒ� 80
			if (selectNum <= 4) // selectNUm�� 4,5,6���� ���� ���
				selectNum += 3;
			else continue; // �ƴϸ� ��� ����
		}
		else if (key == LEFT){
			if (selectNum > 1) // selectNum�� 1���� Ŭ ���
				selectNum -= 1;
			else continue; // �ƴϸ� ��� ����
		}
		else if (key == RIGHT){
			if (selectNum < 7) // selectNUm�� 7���� ���� ���
				selectNum += 1;
			else continue; // �ƴϸ� ��� ����
		}
		else if (key == ENTER) { // ������ �ƽ�Ű��. ���Ͱ� �ԷµǾ�����, Ÿ��Ʋ�� Ż��. �� selectNum�� �ش��ϴ� ���� ����
			system("cls"); // �޴� ��ħ ����
			break; 
		}
		gotoxy(x, y);

		switch (selectNum){
		case 1:
			printf("�� ����     ����     ��ų");
				gotoxy(x, y + 1);
			printf("   ����     ����     ����");
			gotoxy(x, y + 2);
			printf("   �ҷ����� ");
			break;
		case 2:
			printf("   ����  �� ����     ��ų");
			gotoxy(x, y + 1);
			printf("   ����     ����     ����");
			gotoxy(x, y + 2);
			printf("   �ҷ����� ");
			break;
		case 3:
			printf("   ����     ����  �� ��ų");
			gotoxy(x, y + 1);
			printf("   ����     ����     ����");
			gotoxy(x, y + 2);
			printf("   �ҷ����� ");
			break;
		case 4:
			printf("   ����     ����     ��ų");
			gotoxy(x, y + 1);
			printf("�� ����     ����     ����");
			gotoxy(x, y + 2);
			printf("   �ҷ����� ");
			break;
		case 5:
			printf("   ����     ����     ��ų");
			gotoxy(x, y + 1);
			printf("   ����  �� ����     ����");
			gotoxy(x, y + 2);
			printf("   �ҷ����� ");
			break;
		case 6:
			printf("   ����     ����     ��ų");
			gotoxy(x, y + 1);
			printf("   ����     ����  �� ����");
			gotoxy(x, y + 2);
			printf("   �ҷ����� ");
			break;
		case 7:
			printf("   ����     ����     ��ų");
			gotoxy(x, y + 1);
			printf("   ����     ����     ����");
			gotoxy(x, y + 2);
			printf("�� �ҷ����� ");
			break;
		}
	}
	return selectNum;
}
int selectAdventure(int lv) { // ���輱�� �������̽�, �̴�� �߰�
	digimonDisplay(lv);
	showStat();

	int selectNum = 1;

	while (1) {
		int key = 1; // �ʱ�ȭ�� ���ϸ� if������ ������ ���Ƿ�, �ƹ� ���̳� �ʱ�ȭ.
		if (_kbhit()) // Ű �Է� ���� Ȯ�� ->http://showmiso.tistory.com/8
			key = _getch(); // Ű�� �Է� ����. ���ϴ� Ű������ ó�� ��ó

		if (key == UP) { // �� 72
			if (selectNum > 1) // selectNum�� 1���� Ŭ���(2 �̻�)
				selectNum -= 1;

			else continue; // �ƴϸ� ��� ����
		}
		else if (key == DOWN) { // �Ʒ� 80
			if (selectNum < 10) // selectNUm�� 10���� �������(10 ����)
				selectNum += 1;

			else continue; // �ƴϸ� ��� ����
		}

		else if (key == ENTER) { // ������ �ƽ�Ű��. ���Ͱ� �ԷµǾ�����, Ÿ��Ʋ�� Ż��. �� selectNum�� �ش��ϴ� ���� ����.
			system("cls"); // �޴� ��ħ ����
			break;
		}

		int x =75, y = 8;
		gotoxy(x, y);

		switch (selectNum) {
		case 1:
			printf("�� ���� 1\n");
			gotoxy(x, ++y + 1);
			printf("   ���� 2\n");
			gotoxy(x, ++y + 2);
			printf("   ���� 3\n");
			gotoxy(x, ++y + 3);
			printf("   ���� 4\n");
			gotoxy(x, ++y + 4);
			printf("   ���� 5\n");
			gotoxy(x, ++y + 5);
			printf("   ���� 6\n");
			gotoxy(x, ++y + 6);
			printf("   ���� 7\n");
			gotoxy(x, ++y + 7);
			printf("   ���� 8\n");
			gotoxy(x, ++y + 8);
			printf("   ���� 9\n");
			gotoxy(x, ++y + 9);
			printf("   ���� 10\n");
			break;
		case 2:
			printf("   ���� 1\n");
			gotoxy(x, ++y + 1);
			printf("�� ���� 2\n");
			gotoxy(x, ++y + 2);
			printf("   ���� 3\n");
			gotoxy(x, ++y + 3);
			printf("   ���� 4\n");
			gotoxy(x, ++y + 4);
			printf("   ���� 5\n");
			gotoxy(x, ++y + 5);
			printf("   ���� 6\n");
			gotoxy(x, ++y + 6);
			printf("   ���� 7\n");
			gotoxy(x, ++y + 7);
			printf("   ���� 8\n");
			gotoxy(x, ++y + 8);
			printf("   ���� 9\n");
			gotoxy(x, ++y + 9);
			printf("   ���� 10\n");
			break;
		case 3:
			printf("   ���� 1\n");
			gotoxy(x, ++y + 1);
			printf("   ���� 2\n");
			gotoxy(x, ++y + 2);
			printf("�� ���� 3\n");
			gotoxy(x, ++y + 3);
			printf("   ���� 4\n");
			gotoxy(x, ++y + 4);
			printf("   ���� 5\n");
			gotoxy(x, ++y + 5);
			printf("   ���� 6\n");
			gotoxy(x, ++y + 6);
			printf("   ���� 7\n");
			gotoxy(x, ++y + 7);
			printf("   ���� 8\n");
			gotoxy(x, ++y + 8);
			printf("   ���� 9\n");
			gotoxy(x, ++y + 9);
			printf("   ���� 10\n");
			break;
		case 4:
			printf("   ���� 1\n");
			gotoxy(x, ++y + 1);
			printf("   ���� 2\n");
			gotoxy(x, ++y + 2);
			printf("   ���� 3\n");
			gotoxy(x, ++y + 3);
			printf("�� ���� 4\n");
			gotoxy(x, ++y + 4);
			printf("   ���� 5\n");
			gotoxy(x, ++y + 5);
			printf("   ���� 6\n");
			gotoxy(x, ++y + 6);
			printf("   ���� 7\n");
			gotoxy(x, ++y + 7);
			printf("   ���� 8\n");
			gotoxy(x, ++y + 8);
			printf("   ���� 9\n");
			gotoxy(x, ++y + 9);
			printf("   ���� 10\n");
			break;
		case 5:
			printf("   ���� 1\n");
			gotoxy(x, ++y + 1);
			printf("   ���� 2\n");
			gotoxy(x, ++y + 2);
			printf("   ���� 3\n");
			gotoxy(x, ++y + 3);
			printf("   ���� 4\n");
			gotoxy(x, ++y + 4);
			printf("�� ���� 5\n");
			gotoxy(x, ++y + 5);
			printf("   ���� 6\n");
			gotoxy(x, ++y + 6);
			printf("   ���� 7\n");
			gotoxy(x, ++y + 7);
			printf("   ���� 8\n");
			gotoxy(x, ++y + 8);
			printf("   ���� 9\n");
			gotoxy(x, ++y + 9);
			printf("   ���� 10\n");
			break;
		case 6:
			printf("   ���� 1\n");
			gotoxy(x, ++y + 1);
			printf("   ���� 2\n");
			gotoxy(x, ++y + 2);
			printf("   ���� 3\n");
			gotoxy(x, ++y + 3);
			printf("   ���� 4\n");
			gotoxy(x, ++y + 4);
			printf("   ���� 5\n");
			gotoxy(x, ++y + 5);
			printf("�� ���� 6\n");
			gotoxy(x, ++y + 6);
			printf("   ���� 7\n");
			gotoxy(x, ++y + 7);
			printf("   ���� 8\n");
			gotoxy(x, ++y + 8);
			printf("   ���� 9\n");
			gotoxy(x, ++y + 9);
			printf("   ���� 10\n");
			break;
		case 7:
			printf("   ���� 1\n");
			gotoxy(x, ++y + 1);
			printf("   ���� 2\n");
			gotoxy(x, ++y + 2);
			printf("   ���� 3\n");
			gotoxy(x, ++y + 3);
			printf("   ���� 4\n");
			gotoxy(x, ++y + 4);
			printf("   ���� 5\n");
			gotoxy(x, ++y + 5);
			printf("   ���� 6\n");
			gotoxy(x, ++y + 6);
			printf("�� ���� 7\n");
			gotoxy(x, ++y + 7);
			printf("   ���� 8\n");
			gotoxy(x, ++y + 8);
			printf("   ���� 9\n");
			gotoxy(x, ++y + 9);
			printf("   ���� 10\n");
			break;
		case 8:
			printf("   ���� 1\n");
			gotoxy(x, ++y + 1);
			printf("   ���� 2\n");
			gotoxy(x, ++y + 2);
			printf("   ���� 3\n");
			gotoxy(x, ++y + 3);
			printf("   ���� 4\n");
			gotoxy(x, ++y + 4);
			printf("   ���� 5\n");
			gotoxy(x, ++y + 5);
			printf("   ���� 6\n");
			gotoxy(x, ++y + 6);
			printf("   ���� 7\n");
			gotoxy(x, ++y + 7);
			printf("�� ���� 8\n");
			gotoxy(x, ++y + 8);
			printf("   ���� 9\n");
			gotoxy(x, ++y + 9);
			printf("   ���� 10\n");
			break;
		case 9:
			printf("   ���� 1\n");
			gotoxy(x, ++y + 1);
			printf("   ���� 2\n");
			gotoxy(x, ++y + 2);
			printf("   ���� 3\n");
			gotoxy(x, ++y + 3);
			printf("   ���� 4\n");
			gotoxy(x, ++y + 4);
			printf("   ���� 5\n");
			gotoxy(x, ++y + 5);
			printf("   ���� 6\n");
			gotoxy(x, ++y + 6);
			printf("   ���� 7\n");
			gotoxy(x, ++y + 7);
			printf("   ���� 8\n");
			gotoxy(x, ++y + 8);
			printf("�� ���� 9\n");
			gotoxy(x, ++y + 9);
			printf("   ���� 10\n");
			break;
		case 10:
			printf("   ���� 1\n");
			gotoxy(x, ++y + 1);
			printf("   ���� 2\n");
			gotoxy(x, ++y + 2);
			printf("   ���� 3\n");
			gotoxy(x, ++y + 3);
			printf("   ���� 4\n");
			gotoxy(x, ++y + 4);
			printf("   ���� 5\n");
			gotoxy(x, ++y + 5);
			printf("   ���� 6\n");
			gotoxy(x, ++y + 6);
			printf("   ���� 7\n");
			gotoxy(x, ++y + 7);
			printf("   ���� 8\n");
			gotoxy(x, ++y + 8);
			printf("   ���� 9\n");
			gotoxy(x, ++y + 9);
			printf("�� ���� 10\n");
			break;
		}
	}
	return selectNum;
}
int selectMotion() {
	int selectNum = 1;//selectNum �ʱ�ȭ
	const int x = 40, y = 23;

	while (1) {
		int key = 1; // �ʱ�ȭ�� ���ϸ� if������ ������ ���Ƿ�, �ƹ� ���̳� �ʱ�ȭ.

		if (_kbhit()) // Ű �Է� ���� Ȯ�� ->http://showmiso.tistory.com/8
			key = _getch(); // Ű�� �Է� ����. ���ϴ� Ű������ ó�� ��ó

		if (key == LEFT) {
			if (selectNum > 1) // selectNum�� 1���� Ŭ���(1 �̻�)
				selectNum -= 1;
			else continue; // �ƴϸ� ��� ����
		}
		else if (key == RIGHT) {
			if (selectNum < 5) // selectNUm�� 4���� �������(3 ����)
				selectNum += 1;
			else continue; // �ƴϸ� ��� ����
		}
		else if (key == ENTER) { // ������ �ƽ�Ű��. ���Ͱ� �ԷµǾ�����, Ÿ��Ʋ�� Ż��. �� selectNum�� �ش��ϴ� ���� ����
			//system("cls"); // �޴� ��ħ ����
			break;
		}
		gotoxy(x, y);

		switch (selectNum) {
		case 1:
			printf("�� ����     ��ų     ����\n");
			break;
		case 2:
			printf("   ����  �� ��ų     ����\n");
			break;
		case 3:
			printf("   ����     ��ų  �� ����\n");
			break;
		}
	}
	return selectNum;
}
int selectSkill() { // ��ų ���� �������̽�, �̴�� �߰�
	int selectNum = 1;
	const int x = 40, y = 29;

	while (1) {
		int key = 1; // �ʱ�ȭ�� ���ϸ� if������ ������ ���Ƿ�, �ƹ� ���̳� �ʱ�ȭ.

		if (_kbhit()) // Ű �Է� ���� Ȯ�� ->http://showmiso.tistory.com/8
			key = _getch(); // Ű�� �Է� ����. ���ϴ� Ű������ ó�� ��ó

		if (key == LEFT) {
			if (selectNum > 1) // selectNum�� 1���� Ŭ���(1 �̻�)
				selectNum -= 1;
			else continue; // �ƴϸ� ��� ����
		}
		else if (key == RIGHT) {
			if (selectNum < 2) // selectNUm�� 2���� �������(2 ����)
				selectNum += 1;
			else continue; // �ƴϸ� ��� ����
		}
		else if (key == ENTER) { // ������ �ƽ�Ű��. ���Ͱ� �ԷµǾ�����, Ÿ��Ʋ�� Ż��. �� selectNum�� �ش��ϴ� ���� ����
			//system("cls"); // �޴� ��ħ ����
			break;
		}
		gotoxy(x, y);

		switch (selectNum) {
		case 1:
			printf("�� �����Ҳ�       ����ȭ��\n");
			break;
		case 2:
			printf("   �����Ҳ�    �� ����ȭ��\n");
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
		int key = 1; // �ʱ�ȭ�� ���ϸ� if������ ������ ���Ƿ�, �ƹ� ���̳� �ʱ�ȭ.
		if (_kbhit()) // Ű �Է� ���� Ȯ�� ->http://showmiso.tistory.com/8
			key = _getch(); // Ű�� �Է� ����. ���ϴ� Ű������ ó�� ��ó

		if (key == UP) { // �� 72
			if (selectNum > 1) // selectNum�� 1���� Ŭ���(2 �̻�)
				selectNum -= 1;

			else continue; // �ƴϸ� ��� ����
		}
		else if (key == DOWN) { // �Ʒ� 80
			if (selectNum < 3) // selectNUm�� 3���� �������(3 ����)
				selectNum += 1;

			else continue; // �ƴϸ� ��� ����
		}

		else if (key == ENTER) { // ������ �ƽ�Ű��. ���Ͱ� �ԷµǾ�����, Ÿ��Ʋ�� Ż��. �� selectNum�� �ش��ϴ� ���� ����.
			system("cls"); // �޴� ��ħ ����
			break;
		}

		int x = 75, y = 8;
		gotoxy(x, y);

		switch (selectNum) {
		case 1:
			printf("�� 1�� ����");
			gotoxy(x, ++y + 1);
			printf("   2�� ����");
			gotoxy(x, ++y + 2);
			printf("   3�� ����");
			break;
		case 2:
			printf("   1�� ����");
			gotoxy(x, ++y + 1);
			printf("�� 2�� ����");
			gotoxy(x, ++y + 2);
			printf("   3�� ����");
			break;
		case 3:
			printf("   1�� ����");
			gotoxy(x, ++y + 1);
			printf("   2�� ����");
			gotoxy(x, ++y + 2);
			printf("�� 3�� ����");
			break;
		}
	}
	return selectNum;
}
int selectLoad(ChStat *chStat) {
	int selectNum = 1;
	
	while (1) {
		int key = 1; // �ʱ�ȭ�� ���ϸ� if������ ������ ���Ƿ�, �ƹ� ���̳� �ʱ�ȭ.
		if (_kbhit()) // Ű �Է� ���� Ȯ�� ->http://showmiso.tistory.com/8
			key = _getch(); // Ű�� �Է� ����. ���ϴ� Ű������ ó�� ��ó

		if (key == UP) { // �� 72
			if (selectNum > 1) // selectNum�� 1���� Ŭ���(2 �̻�)
				selectNum -= 1;

			else continue; // �ƴϸ� ��� ����
		}
		else if (key == DOWN) { // �Ʒ� 80
			if (selectNum < 3) // selectNUm�� 3���� �������(3 ����)
				selectNum += 1;

			else continue; // �ƴϸ� ��� ����
		}

		else if (key == ENTER) { // ������ �ƽ�Ű��. ���Ͱ� �ԷµǾ�����, Ÿ��Ʋ�� Ż��. �� selectNum�� �ش��ϴ� ���� ����.
			system("cls"); // �޴� ��ħ ����
			break;
		}

		int x = 44, y = 14;
		gotoxy(x, y);

		switch (selectNum) {
		case 1:
			printf("�� %s ����", chStat->name);
			gotoxy(x, ++y + 1);
			printf("   %s ����", chStat->name);
			gotoxy(x, ++y + 2);
			printf("   %s ����", chStat->name);
			break;
		case 2:
			printf("   %s ����", chStat->name);
			gotoxy(x, ++y + 1);
			printf("�� %s ����", chStat->name);
			gotoxy(x, ++y + 2);
			printf("   %s ����", chStat->name);
			break;
		case 3:
			printf("   %s ����", chStat->name);
			gotoxy(x, ++y + 1);
			printf("   %s ����", chStat->name);
			gotoxy(x, ++y + 2);
			printf("�� %s ����", chStat->name);
			break;
		}
	}
	return selectNum;
}
int wait() { // ���� �Է� �� ���� ���, �̴�� �߰�
	int key = 1;

	while (1) {
		if (_kbhit()) // Ű �Է� ���� Ȯ�� ->http://showmiso.tistory.com/8
			key = _getch(); // Ű�� �Է� ����. ���ϴ� Ű������ ó�� ��ó

		if (key == ENTER) 
			break; // ������ �ƽ�Ű��, ���Ͱ� �ԷµǾ����� Ż��
	}
		return 1;
}
void printTitle()
{
	int x = 10, y = 3;

	system("mode con: cols=140 lines=28");//���� , ���� ->http://berabue.tistory.com/59
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

	while (1)//---------------------------------------------------------------------------------Ÿ��Ʋ�� while��
	{
		if (_kbhit())//Ű �Է� ���� Ȯ�� ->http://showmiso.tistory.com/8
		{
			system("mode con: cols=100 lines=30");//���� , ���� ->http://berabue.tistory.com/59
												  //�ƹ�Ű �Է� �޾�����, ȣ��Ǵ� �Լ� �Է�
			wait();
			break;
		}
	}
}
void fightInterface(int chHp, int monHp, int lv, int monLv) { // �ο�� ���÷���
	const int chX = 50, chY = 30, monX = 5, monY = 2; // hp�� ��ġ ����
	int i = 0;

	enemyDisplay(monLv);
	digimonDisplay(lv);

	gotoxy(chX - 10, chY);
	printf("�Ʊ��� hp : ");
	gotoxy(chX, chY);
	for (i = 1; i <= chHp; i++)
		printf("l");
	gotoxy(monX, monY);
	printf("���� hp : ");
	gotoxy(monX + 12, monY);
	for (i = 1; i <= monHp; i++)
		printf("l");
}
void disappear() { // goto���� �����̴� �ܼ��� Ŀ�� ����, ������ http://tip.daum.net/question/39372106
	HANDLE hConsole; // �ܼ� �ڵ�
	CONSOLE_CURSOR_INFO ConsoleCursor; // �ܼ�Ŀ�� ���� ����ü

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �ڵ��� ���ϰ�

	ConsoleCursor.bVisible = 0; // 1 ���� , 0 �Ⱥ���
	ConsoleCursor.dwSize = 1; // Ŀ�� ������

	SetConsoleCursorInfo(hConsole, &ConsoleCursor); // ����
}
void gotoxy(int x, int y) { // goto �Լ�����, ������ http://m.blog.naver.com/bestheroz/110240153
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}