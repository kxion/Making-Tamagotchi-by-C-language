#include<stdio.h>
#include"Display.h"
#include"Interface.h"

void coyomon() {
	gotoxy(2, 15);

	printf("                 ■\n");
	printf("                 ■■\n");
	printf("                 ■■\n");
	printf(" ■■■■         ■  ■\n");
	printf("   ■   ■■       ■  ■\n");
	printf("    ■■    ■     ■  ■\n");
	printf("     ■■    ■     ■  ■\n");
	printf("        ■■  ■■■■  ■\n");
	printf("        ■■  ■        ■\n");
	printf("       ■                 ■\n");
	printf("      ■                  ■\n");
	printf("     ■        ■       ■ ■\n");
	printf("     ■        ■       ■ ■\n");
	printf("     ■                    ■\n");
	printf("     ■          ■■■    ■\n");
	printf("     ■         ■■■■   ■\n");
	printf("      ■                ■\n");
	printf("        ■■■■■■■■■\n"); // 18
}
void agumon() {
	gotoxy(2, 14);

	printf("          ■■■■■        	  \n");
	printf("        ■         ■       	  \n");
	printf("      ■     ■■  ■■     	  \n");
	printf("      ■   ■■       ■■  	  \n");
	printf("    ■     ■■■         ■	  \n");
	printf("    ■      ■■          ■  	  \n");
	printf("    ■              ■■■■	  \n");
	printf("    ■                  ■  	  \n");
	printf("      ■       ■■■■■   	  \n");
	printf("      ■  ■       ■■■     	  \n");
	printf("     ■     ■      ■ ■■ 	  \n");
	printf("   ■■      ■     ■   ■  	  \n");
	printf("   ■■  ■■■      ■■■ 	  \n");
	printf("   ■    ■       ■■■		  \n");
	printf("   ■      ■■■■    ■■■	  \n");
	printf(" ■ ■■   ■■  ■■  ■■  ■■  \n");
	printf(" ■ ■■   ■■  ■■  ■■  ■■  \n"); // 17
}
void greymon() {
	gotoxy(2, 11);

	printf("   ■■■   ■■■■■\n");
	printf("  ■   ■■         ■    ■■\n");
	printf("   ■    ■■         ■   ■■\n");
	printf("    ■       ■■    ■■■  ■\n");
	printf("      ■■■    ■■     ■■■\n");
	printf("        ■           ■      ■\n");
	printf("        ■         ■■■■■\n");
	printf("        ■         ■■■■■\n");
	printf("      ■                 ■\n");
	printf("      ■        ■■■■■\n");
	printf("    ■   ■         ■\n");
	printf("    ■     ■■       ■■\n");
	printf(" ■■■        ■     ■  ■\n");
	printf(" ■■■         ■     ■  ■\n");
	printf(" ■  ■  ■      ■     ■  ■\n");
	printf(" ■  ■   ■■■      ■■\n");
	printf("  ■     ■         ■  ■■\n");
	printf(" ■  ■  ■  ■■■■■   ■  ■\n");
	printf(" ■ ■ ■■ ■■■■■   ■ ■\n");
	printf(" ■■■■■     ■■■■■■\n"); // 20
}
void metalgreymon() {
	gotoxy(2, 11);

	printf("   ■■■   ■■■■■\n");
	printf("   ■    ■■■■■■■  ■■\n");
	printf("    ■   ■■   ■■■■■ ■\n");
	printf("    ■   ■■    ■■■■  ■\n");
	printf("      ■■■■■   ■■■■■\n");
	printf("        ■■■■■■■■■■\n");
	printf("        ■■    ■■■  ■■■■\n");
	printf("      ■■ ■            ■\n");
	printf("      ■■  ■            ■\n");
	printf("    ■          ■■■■■\n");
	printf("    ■   ■    ■    ■\n");
	printf("    ■   ■■■       ■■\n");
	printf(" ■■■  ■      ■      ■  ■\n");
	printf(" ■■■ ■      ■      ■  ■\n");
	printf(" ■ ■■■      ■      ■  ■\n");
	printf(" ■ ■   ■■■       ■■\n");
	printf("   ■     ■         ■ ■■\n");
	printf(" ■ ■  ■  ■■■■■   ■  ■\n");
	printf(" ■ ■■■ ■   ■■■■■■■\n");
	printf(" ■■■■■■    ■■■■■■\n");
}
void wargraymon() {
	gotoxy(2, 11);

	printf("  ■■■   ■■■■■\n");
	printf("  ■    ■■■■■■■     ■■\n");
	printf("    ■  ■■■   ■■■ ■ ■■\n");
	printf("    ■    ■■    ■■■■■  ■\n");
	printf("  ■  ■■■■■    ■■■■■■\n");
	printf("  ■  ■  ■■■■■■■■■■\n");
	printf("  ■  ■  ■ ■■■■■■■■■\n");
	printf(" ■     ■     ■■       ■\n");
	printf(" ■      ■     ■■       ■\n");
	printf(" ■      ■       ■■■■■\n");
	printf(" ■  ■  ■ ■        ■\n");
	printf(" ■  ■■     ■■     ■■\n");
	printf(" ■  ■■    ■    ■    ■  ■\n");
	printf(" ■ ■■   ■    ■   ■  ■\n");
	printf(" ■■  ■■ ■    ■   ■  ■\n");
	printf(" ■  ■    ■■■■     ■■\n");
	printf("  ■      ■         ■  ■■\n");
	printf(" ■  ■  ■  ■■■■    ■  ■\n");
	printf(" ■ ■  ■ ■■■■■   ■ ■■\n");
	printf(" ■■■■■      ■■■■■■■\n");
}
void omegamon() {
	gotoxy(2, 11);

	printf("    ■■              ■■\n");
	printf("    ■  ■■■■■  ■ ■\n");
	printf("    ■     ■■■■■■ ■\n");
	printf("     ■     ■■■■■■ ■\n");
	printf("      ■■■■   ■■■■\n");
	printf(" ■■    ■■■■   ■■■■  ■\n");
	printf(" ■ ■■■ ■■■■■■■■■\n");
	printf("   ■    ■   ■■■■■■  ■\n");
	printf("   ■    ■   ■■ ■ ■■  ■\n");
	printf("   ■      ■■  ■      ■  ■\n");
	printf(" ■ ■■■   ■■■■■ ■  ■\n");
	printf(" ■   ■              ■    ■\n");
	printf("   ■■  ■■■■  ■■■■■\n");
	printf(" ■   ■■ ■   ■  ■■   ■\n");
	printf(" ■   ■■ ■   ■  ■■    ■\n");
	printf(" ■   ■  ■  ■■  ■  ■    ■\n");
	printf(" ■■■■■ ■   ■  ■■■■■\n");
	printf("   ■  ■  ■■■■  ■ ■\n");
	printf("   ■■■■■ ■■■■■■\n");
	printf("   ■■■■■  ■■■■■\n");
}

void digimonDisplay(int lv) {
	if (lv >= 1 && lv < 5)
		coyomon();
	else if (lv >= 5 && lv < 10)
		agumon();
	else if (lv >= 10 && lv < 15)
		greymon();
	else if (lv >= 15 && lv < 20)
		metalgreymon();
	else if (lv >= 20 && lv < 25)
		wargraymon();
	else omegamon();
}
void enemyDisplay(int monLv) {
	switch (monLv) {
	case 1: enemy1(); break;
	case 2: enemy2(); break;
	case 3: enemy3(); break;
	case 4: enemy4(); break;
	case 5: enemy5(); break;
	case 6: enemy6(); break;
	case 7: enemy7(); break;
	case 8: enemy8(); break;
	case 9: enemy9(); break;
	case 10: enemy10(); break;
	}
}

void enemy1()
{
	int x = 70, y = 4;
	gotoxy(x,y);
	printf("        ■■■■■■■\n");
	gotoxy(x, y+1);
	printf("     ■■             ■■\n");
	gotoxy(x, y+2);
	printf("     ■■             ■■\n");
	gotoxy(x, y+3);
	printf("  ■■                   ■■\n");
	gotoxy(x, y+4);
	printf("  ■■                   ■■\n");
	gotoxy(x, y+5);
	printf("  ■■  ■■       ■■  ■■\n");
	gotoxy(x, y+6);
	printf("  ■■  ■■       ■■  ■■\n");
	gotoxy(x, y+7);
	printf("  ■■                   ■■\n");
	gotoxy(x, y+8);
	printf("  ■■                   ■■\n");
	gotoxy(x, y+9);
	printf("  ■■                   ■■\n");
	gotoxy(x, y+10);
	printf("  ■■                   ■■\n");
	gotoxy(x, y+11);
	printf("  ■■                   ■■\n");
	gotoxy(x, y+12);
	printf("  ■■                   ■■\n");
	gotoxy(x, y+13);
	printf("  ■■                   ■■\n");
	gotoxy(x, y+14);
	printf("  ■■   ■■       ■■ ■■\n");
	gotoxy(x, y+15);
	printf("  ■■   ■■       ■■ ■■\n");
	gotoxy(x, y+16);
	printf("     ■■   ■■■■   ■■\n");
}
void enemy2() {
	int x = 70, y = 4;

	gotoxy(x, y);
	printf("               ■■■\n");
	gotoxy(x, y+1);
	printf("            ■■     ■\n");
	gotoxy(x, y+2);
	printf("          ■  ■     ■\n");
	gotoxy(x, y+3);
	printf("          ■       ■■\n");
	gotoxy(x, y+4);
	printf("        ■       ■■ \n");
	gotoxy(x, y+5);
	printf("        ■        ■\n");
	gotoxy(x, y+6);
	printf("       ■            ■\n");
	gotoxy(x, y+7);
	printf("     ■■     ■■    ■\n");
	gotoxy(x, y+8);
	printf("     ■■     ■■    ■\n");
	gotoxy(x, y+9);
	printf("    ■    ■ ■       ■\n");
	gotoxy(x, y+10);
	printf("   ■                   ■\n");
	gotoxy(x, y+11);
	printf("   ■ ■    ■   ■    ■■\n");
	gotoxy(x, y+12);
	printf(" ■   ■■ ■■ ■■   ■\n");
	gotoxy(x, y+13);
	printf(" ■  ■■■■■■■■    ■\n");
	gotoxy(x, y+14);
	printf(" ■                     ■\n");
	gotoxy(x, y+15);
	printf("   ■                  ■\n");
	gotoxy(x, y+16);
	printf("     ■■■■■■■■■\n");
}
void enemy3() {
	int x = 70, y = 3;

	gotoxy(x, y);
	printf("    ■■■      ■■■\n");
	gotoxy(x, y+1);
	printf("    ■■■      ■■■\n");
	gotoxy(x, y+2);
	printf("  ■      ■  ■     ■\n");
	gotoxy(x, y+3);
	printf("  ■■    ■  ■  ■ ■\n");
	gotoxy(x, y+4);
	printf("  ■      ■  ■     ■\n");
	gotoxy(x, y+5);
	printf("   ■      ■  ■     ■\n");
	gotoxy(x, y + 6);
	printf("    ■  ■      ■ ■\n");
	gotoxy(x, y + 7);
	printf("      ■  ■  ■  ■\n");
	gotoxy(x, y + 8);
	printf("      ■  ■  ■  ■\n");
	gotoxy(x, y + 9);
	printf("      ■  ■  ■  ■\n");
	gotoxy(x, y + 10);
	printf("      ■  ■■■  ■\n");
	gotoxy(x, y + 11);
	printf("      ■          ■\n");
	gotoxy(x, y + 12);
	printf("    ■             ■\n");
	gotoxy(x, y + 13);
	printf("    ■               ■■\n");
	gotoxy(x, y + 14);
	printf("    ■               ■■\n");
	gotoxy(x, y + 15);
	printf("  ■      ■■■         ■\n");
	gotoxy(x, y + 16);
	printf("  ■                      ■\n");
	gotoxy(x, y + 17);
	printf("  ■                    ■■\n");
	gotoxy(x, y + 18);
	printf("  ■                   ■■\n");
	gotoxy(x, y + 19);
	printf("    ■■■■■■■■■■\n");
}
void enemy4() {
	int x = 70, y = 4;

	gotoxy(x, y );
	printf("        ■■■■■■\n");
	gotoxy(x, y + 1);
	printf("      ■■         ■■\n");
	gotoxy(x, y + 2);
	printf("      ■  ■        ■■■■\n");
	gotoxy(x, y + 3);
	printf("    ■■  ■           ■■\n");
	gotoxy(x, y + 4);
	printf("    ■  ■   ■■         ■\n");
	gotoxy(x, y + 5);
	printf(" ■■■     ■■      ■■■■\n");
	gotoxy(x, y + 6);
	printf(" ■        ■■■    ■\n");
	gotoxy(x, y + 7);
	printf(" ■          ■■■    ■\n");
	gotoxy(x, y + 8);
	printf("  ■                 ■\n");
	gotoxy(x, y + 9);
	printf("  ■    ■■         ■\n");
	gotoxy(x, y + 10);
	printf("    ■■     ■    ■\n");
	gotoxy(x, y + 11);
	printf("      ■■■■        ■\n");
	gotoxy(x, y + 12);
	printf("      ■■■■        ■\n");
	gotoxy(x, y + 13);
	printf("      ■■     ■■  ■\n");
	gotoxy(x, y + 14);
	printf("    ■  ■   ■      ■■■\n");
	gotoxy(x, y + 15);
	printf("    ■  ■   ■    ■     ■\n");
	gotoxy(x, y + 16);
	printf("      ■  ■    ■■■  ■■■\n");
	gotoxy(x, y + 17);
	printf("      ■  ■   ■■■ ■■■\n");
	gotoxy(x, y + 18);
	printf("    ■    ■■■      ■\n");
	gotoxy(x, y + 19);
	printf("    ■■■■  ■■■■■\n");
}
void enemy5() {
	int x = 70, y = 4;

	gotoxy(x, y++);
	printf("         ■■■■■\n");
	gotoxy(x, y++);
	printf("      ■■        ■■■■\n");
	gotoxy(x, y++);
	printf("    ■     ■■        ■\n");
	gotoxy(x, y++);
	printf("   ■      ■■         ■\n");
	gotoxy(x, y++);
	printf("   ■      ■      ■■■■\n");
	gotoxy(x, y++);
	printf(" ■                   ■\n");
	gotoxy(x, y++);
	printf(" ■■■■■■   ■■■■■\n");
	gotoxy(x, y++);
	printf("   ■           ■      ■\n");
	gotoxy(x, y++);
	printf("    ■■■■■    ■■■\n");
	gotoxy(x, y++);
	printf("           ■■     ■\n");
	gotoxy(x, y++);
	printf("           ■       ■   \n");
	gotoxy(x, y++);
	printf("         ■■   ■    ■■\n");
	gotoxy(x, y++);
	printf("         ■  ■ ■       ■\n");
	gotoxy(x, y++);
	printf("        ■  ■   ■■  ■  ■\n");
	gotoxy(x, y++);
	printf("        ■     ■   ■     ■\n");
	gotoxy(x, y++);
	printf("        ■ ■       ■     ■\n");
	gotoxy(x, y++);
	printf("         ■  ■ ■       ■\n");
	gotoxy(x, y++);
	printf("          ■  ■ ■■  ■■\n");
	gotoxy(x, y++);
	printf("           ■■■■■■■\n");
}
void enemy6() {
	int x = 70, y = 4;

	gotoxy(x, y++);
	printf("      ■            ■\n");
	gotoxy(x, y++);
	printf("    ■  ■   ■■ ■  ■\n");
	gotoxy(x, y++);
	printf("    ■  ■ ■■■ ■  ■\n");
	gotoxy(x, y++);
	printf("    ■  ■■■■■■  ■\n");
	gotoxy(x, y++);
	printf("     ■              ■■\n");
	gotoxy(x, y++);
	printf("     ■■■   ■■■ ■■■\n");
	gotoxy(x, y++);
	printf("    ■  ■     ■       ■■■\n");
	gotoxy(x, y++);
	printf("    ■              ■       ■\n");
	gotoxy(x, y++);
	printf("    ■  ■   ■    ■    ■  ■\n");
	gotoxy(x, y++);
	printf("     ■  ■   ■   ■  ■■  ■\n");
	gotoxy(x, y++);
	printf("       ■   ■   ■■  ■■  ■\n");
	gotoxy(x, y++);
	printf("     ■■■■■■■■       ■\n");
	gotoxy(x, y++);
	printf("    ■    ■      ■    ■■■\n");
	gotoxy(x, y++);
	printf("    ■■■■■       ■\n");
	gotoxy(x, y++);
	printf("     ■■■■    ■■■\n");
	gotoxy(x, y++);
	printf("      ■■■     ■■■\n");
	gotoxy(x, y++);
	printf("    ■   ■     ■     ■\n");
	gotoxy(x, y++);
	printf("  ■ ■    ■■■  ■    ■\n");
	gotoxy(x, y++);
	printf("  ■■■■■    ■■■■■■\n");
}
void enemy7(){
	int x = 70, y = 4;

	gotoxy(x, y++);
	printf("          ■  ■ ■\n");
	gotoxy(x, y++);
	printf(" ■■■■ ■■  ■■  ■■■■\n");
	gotoxy(x, y++);
	printf(" ■      ■■      ■■     ■\n");
	gotoxy(x, y++);
	printf("  ■■   ■■■■■    ■■\n");
	gotoxy(x, y++);
	printf("  ■■   ■■■■■    ■■\n");
	gotoxy(x, y++);
	printf("  ■■  ■         ■  ■■\n");
	gotoxy(x, y++);
	printf(" ■  ■■            ■■■■\n");
	gotoxy(x, y++);
	printf(" ■  ■   ■       ■  ■  ■\n");
	gotoxy(x, y++);
	printf("  ■■  ■■      ■■  ■■\n");
	gotoxy(x, y++);
	printf("  ■■  ■■      ■■  ■■\n");
	gotoxy(x, y++);
	printf(" ■  ■                ■ ■\n");
	gotoxy(x, y++);
	printf(" ■■■   ■  ■ ■    ■■■\n");
	gotoxy(x, y++);
	printf(" ■    ■   ■  ■   ■   ■\n");
	gotoxy(x, y++);
	printf(" ■    ■■         ■■   ■\n");
	gotoxy(x, y++);
	printf(" ■ ■  ■ ■  ■  ■■ ■ ■ ■\n");
	gotoxy(x, y++);
	printf("  ■■■ ■■■■■  ■■■\n");
	gotoxy(x, y++);
	printf(" ■■■  ■  ■■■  ■  ■■■\n");
	gotoxy(x, y++);
	printf(" ■■■     ■■■      ■■■\n");
	gotoxy(x, y++);
	printf("    ■■■■■  ■■■■■\n");
}
void enemy8() {
	int x = 70, y = 4;

	gotoxy(x, y++);
	printf("    ■      ■   ■ \n");
	gotoxy(x, y++);
	printf("    ■      ■■ ■ \n");
	gotoxy(x, y++);
	printf("    ■  ■■■■■  ■  ■\n");
	gotoxy(x, y++);
	printf("    ■            ■■■\n");
	gotoxy(x, y++);
	printf("    ■■■ ■■   ■ ■■■\n");
	gotoxy(x, y++);
	printf("    ■  ■   ■  ■■■■\n");
	gotoxy(x, y++);
	printf("    ■           ■■■■■■\n");
	gotoxy(x, y++);
	printf("  ■ ■■■■  ■      ■■■\n");
	gotoxy(x, y++);
	printf("  ■ ■■■■  ■      ■■■\n");
	gotoxy(x, y++);
	printf("  ■ ■      ■       ■■■\n");
	gotoxy(x, y++);
	printf("    ■   ■■   ■■■■■■\n");
	gotoxy(x, y++);
	printf("    ■■■    ■■    ■■■\n");
	gotoxy(x, y++);
	printf("  ■   ■   ■   ■   ■ ■■\n");
	gotoxy(x, y++);
	printf("  ■   ■■■    ■ ■     ■\n");
	gotoxy(x, y++);
	printf("    ■■■■■■■■■     ■\n");
	gotoxy(x, y++);
	printf("    ■  ■■■■         ■■ \n");
	gotoxy(x, y++);
	printf("    ■    ■■■■      ■\n");
	gotoxy(x, y++);
	printf("  ■ ■   ■  ■  ■ ■ ■\n");
	gotoxy(x, y++);
	printf("  ■■■■■  ■■■■■■\n");
}
void enemy9() {
	int x = 70, y = 4;

	gotoxy(x, y++);
	printf("  ■     ■■■       ■\n");
	gotoxy(x, y++);
	printf("  ■ ■■   ■■■  ■■\n");
	gotoxy(x, y++);
	printf("    ■   ■   ■■■ \n");
	gotoxy(x, y++);
	printf("  ■   ■■■   ■■■\n");
	gotoxy(x, y++);
	printf(" ■■  ■■■   ■■■\n");
	gotoxy(x, y++);
	printf("■■■   ■   ■■■■■\n");
	gotoxy(x, y++);
	printf("  ■            ■■■\n");
	gotoxy(x, y++);
	printf("■■   ■   ■       ■■\n");
	gotoxy(x, y++);
	printf("   ■  ■   ■    ■   ■\n");
	gotoxy(x, y++);
	printf("    ■■      ■  ■■   ■\n");
	gotoxy(x, y++);
	printf("     ■         ■■ ■■\n");
	gotoxy(x, y++);
	printf("    ■■■■■■■■■■■\n");
	gotoxy(x, y++);
	printf("  ■■   ■ ■■■■■■■\n");
	gotoxy(x, y++);
	printf("■■   ■■     ■ ■■■■\n");
	gotoxy(x, y++);
	printf("■■   ■ ■    ■ ■  ■■\n");
	gotoxy(x, y++);
	printf("■■   ■  ■   ■ ■  ■■\n");
	gotoxy(x, y++);
	printf("■■ ■    ■           ■\n");
	gotoxy(x, y++);
	printf("■   ■    ■■    ■  ■ \n");
	gotoxy(x, y++);
	printf("     ■■■■■■■■\n");
}
void enemy10(){
	int x = 70, y = 4;

	gotoxy(x, y++);
	printf("    ■■     ■■  ■■\n");
	gotoxy(x, y++);
	printf("    ■■     ■■ ■■\n");
	gotoxy(x, y++);
	printf("    ■  ■■■■■  ■  ■\n");
	gotoxy(x, y++);
	printf("    ■■            ■■■\n");
	gotoxy(x, y++);
	printf("    ■■   ■■   ■ ■■■■\n");
	gotoxy(x, y++);
	printf("    ■    ■■   ■  ■■■■\n");
	gotoxy(x, y++);
	printf("    ■         ■  ■■■■■■\n");
	gotoxy(x, y++);
	printf("  ■ ■■■■■ ■      ■■■\n");
	gotoxy(x, y++);
	printf("  ■ ■■■■  ■      ■■■\n");
	gotoxy(x, y++);
	printf("  ■ ■      ■       ■■■■\n");
	gotoxy(x, y++);
	printf("    ■■   ■■■  ■■■■■■\n");
	gotoxy(x, y++);
	printf("    ■■■    ■■■   ■■■■\n");
	gotoxy(x, y++);
	printf("  ■   ■   ■   ■   ■ ■■\n");
	gotoxy(x, y++);
	printf("  ■   ■■■■   ■ ■     ■\n");
	gotoxy(x, y++);
	printf("    ■■■■■■■■■     ■\n");
	gotoxy(x, y++);
	printf("    ■  ■■■■■     ■    ■\n");
	gotoxy(x, y++);
	printf("    ■    ■■■■     ■\n");
	gotoxy(x, y++);
	printf("  ■ ■   ■  ■  ■ ■  ■\n");
	gotoxy(x, y++);
	printf("  ■■■■■  ■■■■■■\n");
}
