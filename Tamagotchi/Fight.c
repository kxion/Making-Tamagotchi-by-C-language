/*

2012244009 �̴��
������ https://dojang.io/mod/page/view.php?id=716
���Ϳ� �ο�

*/
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include"Fight.h"
#include"Interface.h"
#include"Skill.h"
#include"Display.h"

#pragma warning(disable:4996) // warning C4996�� ��� ���� �ڵ�, ������ http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266

int fight(ChStat *chStat, int monLv) {
	const int x = 38, y = 23;
	int chSelect = 0, money = 0, skSelect = 0, monHp = 0, chHp = 0, chAttack = 0, monAttack = 0, speed = 500;

	srand((unsigned)time(NULL));
	/*  
		seed�� ���, ������ http://www.jynote.net/64
		time_h���� unsigned int ������ �ս� ���, ������ http://m.cafe.daum.net/dotax/D8UA/274782?q=D_LhkOVB62tSZesOix-5K71w00&
	 */

	MonStat *mon = monster(monLv);

	monHp = mon->hp; // hp �ʱ�ȭ
	chHp = chStat->hp; // hp �ʱ�ȭ
	chAttack = chStat->attack; // ���ݰ� �ʱ�ȭ
	monAttack = mon->attack;

	while (mon->hp > 0 && chStat->hp > 0) { // ����, ������ hp�� 0�� �Ǹ� ����
		
		printUser(chStat);// �������� ������ ���� ���÷��� 2016 11 25 ������ ����
		chSelect = selectMotion();
		
		switch (chSelect) {
		case 1:
			baseAt1(chStat);
			baseAt2(mon);
			if (chStat->energy < 5)
				chStat->energy = chStat->energy + 1;
			break;
		case 2:
			skSelect = selectSkill(chStat);
			chStat = skillDisplay(chStat, mon, skSelect);
			break;
		case 3:
			menu(chStat);
			break;
		}
		
		gotoxy(x, y);
		if (rand() % 100 < mon->sheild) { // ��������� ���� ���� �߻��� ��� ����
			system("cls");//���ݸ�� ����
			printMon(mon);
			gotoxy(x, y);
			printf("���� ���� !!!\n\n");
			Sleep(speed);
			gotoxy(x, y);
			printf("                          ");//��¹� �����
		}
		else {
			if (rand() % 100 < chStat->agility) { // ũ��ƼĿ������ ���� ���� �߻��� ũ��Ƽ�� �߻�
				mon->hp = mon->hp - (chStat->attack + chStat->agility - mon->sheild); // ���ݷ� = ���ݷ� + ũ���� - ������

				damaged();// �ذ� ��� ���
				system("cls");

				printMon(mon);//�������� ������ ���� �� hp ���÷��� 2016 11 25 ������ ����

				gotoxy(x - 10, y);
				printf("ũ��Ƽ�� �߻�!!!\n\n");
				gotoxy(x, y + 2);
				printf("������ : %2d", chStat->attack + chStat->agility - mon->sheild);
				Sleep(speed);
				gotoxy(x - 10, y);
				printf("                     ");//ũ��Ƽ�� �߻�!!! ��¹� �����
				gotoxy(x, y + 2);
				printf("              ");// ������ ��¹� �����
			}
			else {
				mon->hp = mon->hp - (chStat->attack - mon->sheild); // ���ݷ� = ���ݷ� - ������

				damaged();
				system("cls");

				printMon(mon);//�������� ������ ���� �� hp ���÷��� 2016 11 25 ������ ����

				gotoxy(x, y);
				printf("������ : %2d", chStat->attack - mon->sheild);
				Sleep(speed);
				gotoxy(x, y);
				printf("              ");//������ ��� �ʱ�ȭ(������)
			}
		}

		Sleep(speed);

		if (mon->hp <= 0) break; // ���Ͱ� ������ break;

		monAt1(mon);//2016 11 25 ������ ����
		system("cls");
		printUser(chStat);// �������� ������ ���� ���÷��� 2016 11 25 ������ ����
		monAt2(chStat);
		
		gotoxy(x, y);
		if (rand() % 100 < chStat->health) { // ��������� ���� ���� �߻��� ��� ����
			system("cls");//���ݸ�� ����
			printUser(chStat);
			gotoxy(x, y);
			printf("���� ���� !!!\n");
			Sleep(speed);
			gotoxy(x, y);
			printf("                          ");//��¹� �����
		}
		else {
			if (rand() % 100 < mon->critical) { // ũ��ƼĿ������ ���� ���� �߻��� ũ��Ƽ�� �߻�
				chStat->hp = chStat->hp - (mon->attack + mon->critical - chStat->health); // ���ݷ� = ���ݷ� + ũ���� - ������

				damaged();
				system("cls");
				printUser(chStat);// �������� ������ ���� ���÷��� 2016 11 25 ������ ����
				gotoxy(x, y);
				printf("ũ��Ƽ�� �߻�!!!\n");
				gotoxy(x, y + 2);
				printf("������ : %2d", mon->attack + mon->critical - chStat->health);
				Sleep(speed);
				gotoxy(x, y);
				printf("                     ");//ũ��Ƽ�� �߻�!!! ��¹� �����
				gotoxy(x, y + 2);
				printf("              ");// ������ ��¹� �����
			}
			else {
				chStat->hp = chStat->hp - (mon->attack - chStat->health); // ���ݷ� = ���ݷ� - ������
				damaged();
				system("cls");
				printUser(chStat);// �������� ������ ���� ���÷��� 2016 11 25 ������ ����
				gotoxy(x, y);
				printf("������ : %2d", mon->attack - chStat->health);
				Sleep(speed);
				gotoxy(x, y);
				printf("              ");//������ ��� �ʱ�ȭ(������)
			}
		}

		if (chStat->hp <= 0) break; // ������ ������ break
		chStat->energy;
		if (chStat->energy < 5)
			chStat->energy = chStat->energy + 1;
		Sleep(speed);
		system("cls");

		chStat->attack = chAttack;
		mon->attack = monAttack;
	}

	//chStat->attack = chAttack;
	//mon->attack = monAttack;

	if (mon->hp <= 0) {
		printWin();//win �̹���
		chStat->money += 500 * monLv;
		mon->hp = monHp;
		chStat->hp = chHp;
		chStat->energy = 0;
		return 20 * monLv; // ���� ������ �˸��� ����ġ ��ȯ
	}
	else if (mon->hp < 0 && chStat->hp < 0) {
		printf("���º�....\n");
		mon->hp = monHp;
		chStat->hp = chHp;
		chStat->energy = 0;
		return 0;
	}
	else {
		printLose();//lose �̹���
		mon->hp = monHp;
		chStat->hp = chHp;
		chStat->energy = 0;
		return -30 * monLv; // ���� ������ �˸��� -����ġ ��ȯ
	}
}
int onlineFight(ChStat *myStat, ChStat *enemyStat) {
	const int x = 38, y = 23;
	int mySelect = 0, money = 0, skSelect = 0, enemyHp = 0, myHp = 0, myAttack = 0, enemyAttack = 0, speed = 300;

	srand((unsigned)time(NULL));
	/*
	seed�� ���, ������ http://www.jynote.net/64
	time_h���� unsigned int ������ �ս� ���, ������ http://m.cafe.daum.net/dotax/D8UA/274782?q=D_LhkOVB62tSZesOix-5K71w00&
	*/

	enemyHp = enemyStat->hp; // hp �ʱ�ȭ
	myHp = myStat->hp; // hp �ʱ�ȭ
	myAttack = myStat->attack; // ���ݰ� �ʱ�ȭ
	enemyAttack = enemyStat->attack;
	
	system("cls");

	if (enemyStat->hp > 0 && myStat->hp > 0) { // ����, ������ hp�� 0�� �Ǹ� ����

		printUser(myStat);// �������� ������ ���� ���÷��� 2016 11 25 ������ ����
	/*	mySelect = selectMotion();

		switch (mySelect) {
		case 1:
			baseAt1(myStat);
			baseAt2(enemyStat);
			if (myStat->energy < 5)
				myStat->energy = myStat->energy + 1;
			break;
		case 2:
			skSelect = selectSkill(myStat);
			myStat = skillDisplay(myStat, enemyStat, skSelect);
			break;
		case 3: // �������� Ŭ���̾�Ʈ �ƿ�
			//menu(chStat);
			break;
		}
*/
		baseAt1(myStat);
		onlineAttack(enemyStat);

		if (myStat->energy < 5)
			myStat->energy = myStat->energy + 1;
		
		gotoxy(x, y);
		if (rand() % 100 < enemyStat->health) { // ��������� ���� ���� �߻��� ��� ����
			system("cls");//���ݸ�� ����
		//	digimonDisplay(enemyStat->lv);
			printEnemy(enemyStat);

			gotoxy(x, y);
			printf("���� !!!\n\n");
			Sleep(speed);
			gotoxy(x, y);
			printf("                          ");//��¹� �����
		}
		else {
			if (rand() % 100 < myStat->agility) { // ũ��ƼĿ������ ���� ���� �߻��� ũ��Ƽ�� �߻�
				enemyStat->hp = enemyStat->hp - (myStat->attack + myStat->agility - enemyStat->health); // ���ݷ� = ���ݷ� + ũ���� - ������

				damaged();// �ذ� ��� ���
				system("cls");
				//enemyDisplay(10);
				printEnemy(enemyStat);
				
				gotoxy(x - 10, y);
				printf("ũ��Ƽ�� �߻�!!!\n\n");
				gotoxy(x, y + 2);
				printf("������ : %2d", myStat->attack + myStat->agility - enemyStat->health);
				Sleep(speed);
				gotoxy(x - 10, y);
				printf("                     ");//ũ��Ƽ�� �߻�!!! ��¹� �����
				gotoxy(x, y + 2);
				printf("              ");// ������ ��¹� �����
			}
			else {
				enemyStat->hp = enemyStat->hp - (myStat->attack - enemyStat->health); // ���ݷ� = ���ݷ� - ������

				damaged();
				system("cls");
				printEnemy(enemyStat);
				
				gotoxy(x, y);
				printf("������ : %2d", myStat->attack - enemyStat->health);
				Sleep(speed);
				gotoxy(x, y);
				printf("              "); // ������ ��� �ʱ�ȭ
			}
		}

		Sleep(speed);

		if (enemyStat->hp <= 0 && myStat->hp > 0) {
			printWin();// win �̹���
			enemyStat->hp = enemyHp;
			myStat->hp = myHp;
			myStat->energy = 0;
			return 1; 
		}
		
		monAt1(enemyStat); //2016 11 25 ������ ����
		system("cls");
		printUser(myStat); // �������� ������ ���� ���÷��� 2016 11 25 ������ ����
		monAt2(myStat);

		gotoxy(x, y);
		if (rand() % 100 < myStat->health) { // ��������� ���� ���� �߻��� ��� ����
			system("cls");//���ݸ�� ����
			printUser(myStat);
			gotoxy(x, y);
			printf("���� ���� !!!\n");
			Sleep(speed);
			gotoxy(x, y);
			printf("                          ");//��¹� �����
		}
		else {
			if (rand() % 100 < enemyStat->agility) { // ũ��ƼĿ������ ���� ���� �߻��� ũ��Ƽ�� �߻�
				myStat->hp = myStat->hp - (enemyStat->attack + enemyStat->agility - myStat->health); // ���ݷ� = ���ݷ� + ũ���� - ������

				damaged();
				system("cls");
				printUser(myStat);// �������� ������ ���� ���÷��� 2016 11 25 ������ ����
				gotoxy(x, y);
				printf("ũ��Ƽ�� �߻�!!!\n");
				gotoxy(x, y + 2);
				printf("������ : %2d", enemyStat->attack + enemyStat->agility - myStat->health);
				Sleep(speed);
				gotoxy(x, y);
				printf("                     "); // ũ��Ƽ�� �߻�!!! ��¹� �����
				gotoxy(x, y + 2);
				printf("              "); // ������ ��¹� �����
			}
			else {
				myStat->hp = myStat->hp - (enemyStat->attack - myStat->health); // ���ݷ� = ���ݷ� - ������

				damaged();
				system("cls");
				printUser(myStat);// �������� ������ ���� ���÷��� 2016 11 25 ������ ����
				gotoxy(x, y);
				printf("������ : %2d", enemyStat->attack - myStat->health);
				Sleep(speed);
				gotoxy(x, y);
				printf("              ");//������ ��� �ʱ�ȭ(������)
			}

			if (myStat->hp <= 0 && enemyStat->hp > 0) {  // ������ ������ break
				printLose(); // lose �̹���
				enemyStat->hp = enemyHp;
				myStat->hp = myHp;
				myStat->energy = 0;
				return 1; 
			}
		}
		
		myStat->energy;
		if (myStat->energy < 5)
			myStat->energy = myStat->energy + 1;
		Sleep(speed);
		system("cls");

		myStat->attack = myAttack;
		enemyStat->attack = enemyAttack;

		return 0;
	}
		
	if (enemyStat->hp <= 0 && myStat->hp <= 0) {
		printf("���º�....\n");
		enemyStat->hp = enemyHp;
		myStat->hp = myHp;
		myStat->energy = 0;
		return 1;
	}
}
