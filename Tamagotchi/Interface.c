#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include"Interface.h"

/*

2012244063 ������
2012244009 �̴�� �ڵ�����
������ https://dojang.io/mod/page/view.php?id=716
���ӿ� �ʿ��� �������̽� ����

*/

int selectStart() { // ���� �ʱ� �������̽� ����
	int selectNum = 1;

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

		int x = 55, y = 17; // ������ ��ǥ
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
	int selectNum = 1;//selectNum �ʱ�ȭ

	while (1){
		int key = 1; // �ʱ�ȭ�� ���ϸ� if������ ������ ���Ƿ�, �ƹ� ���̳� �ʱ�ȭ.

		if (_kbhit()) // Ű �Է� ���� Ȯ�� ->http://showmiso.tistory.com/8
			key = _getch(); // Ű�� �Է� ����. ���ϴ� Ű������ ó�� ��ó
						   // �� 72 �Ʒ� 80
		if (key == LEFT){
			if (selectNum > 1) // selectNum�� 1���� Ŭ���(2 �̻�)
				selectNum -= 1;
			else continue; // �ƴϸ� ��� ����
		}
		else if (key == RIGHT){
			if (selectNum < 4) // selectNUm�� 4���� �������(3 ����)
				selectNum += 1;
			else continue; // �ƴϸ� ��� ����
		}
		else if (key == ENTER) { // ������ �ƽ�Ű��. ���Ͱ� �ԷµǾ�����, Ÿ��Ʋ�� Ż��. �� selectNum�� �ش��ϴ� ���� ����
			system("cls"); // �޴� ��ħ ����
			break; 
		}
		gotoxy(55, 15);

		switch (selectNum){
		case 1:
			printf("�� ����      �ο��      �����ϱ�       ����\n");
			break;
		case 2:
			printf("   ����   �� �ο��      �����ϱ�       ����\n");
			break;
		case 3:
			printf("   ����      �ο��   �� �����ϱ�       ����\n");
			break;
		case 4:
			printf("   ����      �ο��      �����ϱ�    �� ����\n");
			break;
		default:
			printf("�޴� �Է¿���");
		}
	}
	return selectNum;
}
int selectAdventure() {
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
		default:
			printf("���� ����");
		}
	}
	return selectNum;
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