#include<stdio.h>
#include"Display.h"
#include"Interface.h"

void LeftAgumon() {
		printf("           �������        \n");
		printf("          ��          ��       \n");
		printf("        ���  ����   ��     \n");
		printf("    ���       ���    ��      \n");
		printf("   ��         ����     ��   \n");
		printf("   ��        ����      ��    \n");
		printf("   �����              ��    \n");
		printf("    ��                   ��    \n");
		printf("      ������       ��     \n");
		printf("        ����     ��  ��     \n");
		printf("      ��� ��     ���   ��   \n");
		printf("      ��  ��     ���    ���   \n");
		printf("      ����      ���   ���   \n");
		printf("         ����       ��� ��  \n");
		printf("      ����  ������  ��  \n");
		printf("   ��� ��� ��� ���  ��� ��\n");
		printf("   ��� ��� ��� ���  ��� ��\n");
}
void RightAgumon() {
	gotoxy(2, 18);

	printf("          ������        	  \n");
	printf("        ��         ��       	  \n");
	printf("      ��     ���  ���     	  \n");
	printf("      ��   ���       ���  	  \n");
	printf("    ��     ����         ��	  \n");
	printf("    ��      ���          ��  	  \n");
	printf("    ��              �����	  \n");
	printf("    ��                  ��  	  \n");
	printf("      ��       ������   	  \n");
	printf("      ��  ��       ����     	  \n");
	printf("     ��     ��      �� ��� 	  \n");
	printf("   ���      ��     ��   ��  	  \n");
	printf("   ���  ����      ���� 	  \n");
	printf("   ��    ��       ����		  \n");
	printf("   ��      �����    ����	  \n");
	printf(" �� ���   ���  ���  ���  ���  \n");
	printf(" �� ���   ���  ���  ���  ���  \n");
}
void enemy_4(){
	int x = 90, y = 1;

	gotoxy(x, y + 1);
	printf("   ����      ����      ");
	gotoxy(x, y + 2);
	printf("   ��    ��    ��    ��    ");
	gotoxy(x, y + 3);
	printf("   ��    ��    ���   ��    ");
	gotoxy(x, y + 4);
	printf("   ��  �������   ��    ");
	gotoxy(x, y + 5);
	printf("     ��         �����   ");
	gotoxy(x, y + 6);
	printf("     ��         �����    ");
	gotoxy(x, y + 7);
	printf("     �����������  ");
	gotoxy(x, y + 8);
	printf("     ��      ���    ���  ���");
	gotoxy(x, y + 9);
	printf("  �� ��      ���    ���  ���");
	gotoxy(x, y + 10);
	printf("  �� ��    ��      ����   ");
	gotoxy(x, y + 11);
	printf("   ���  ��         ���    ");
	gotoxy(x, y + 12);
	printf("  �� ��  ��         ���     ");
	gotoxy(x, y + 13);
	printf("     ��            ��       ");
	gotoxy(x, y + 14);
	printf("       �������  ���    ");
	gotoxy(x, y + 15);
	printf("   ���  ��      ��    ��   ");
	gotoxy(x, y + 16);
	printf("   ���  ��      ��     ��  ");
	gotoxy(x, y + 17);
	printf(" ��    ��          ���    ��");
	gotoxy(x, y + 18);
	printf(" ��    ��          ��      ��");
	gotoxy(x, y + 19);
	printf(" ��    ��          ��      ��");
	gotoxy(x, y + 20);
	printf(" ����  ��    ��  �����  ");
	gotoxy(x, y + 21);
	printf("   ��      ����      ���");
	gotoxy(x, y + 22);
	printf("   ��      ����        �� ");
	gotoxy(x, y + 23);
	printf("   �������������  ");
}
