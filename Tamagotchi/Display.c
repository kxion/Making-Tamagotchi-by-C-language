#include<stdio.h>
#include"Display.h"
#include"Interface.h"

void LeftAgumon() {
		printf("           бсбсбсбсбсбс        \n");
		printf("          бс          бс       \n");
		printf("        бсбс  бсбсбс   бс     \n");
		printf("    бсбс       бсбс    бс      \n");
		printf("   бс         бсбсбс     бс   \n");
		printf("   бс        бсбсбс      бс    \n");
		printf("   бсбсбсбс              бс    \n");
		printf("    бс                   бс    \n");
		printf("      бсбсбсбсбс       бс     \n");
		printf("        бсбсбс     бс  бс     \n");
		printf("      бсбс бс     бсбс   бс   \n");
		printf("      бс  бс     бсбс    бсбс   \n");
		printf("      бсбсбс      бсбс   бсбс   \n");
		printf("         бсбсбс       бсбс бс  \n");
		printf("      бсбсбс  бсбсбсбсбс  бс  \n");
		printf("   бсбс бсбс бсбс бсбс  бсбс бс\n");
		printf("   бсбс бсбс бсбс бсбс  бсбс бс\n");
}
void RightAgumon() {
	gotoxy(2, 18);

	printf("          бсбсбсбсбс        	  \n");
	printf("        бс         бс       	  \n");
	printf("      бс     бсбс  бсбс     	  \n");
	printf("      бс   бсбс       бсбс  	  \n");
	printf("    бс     бсбсбс         бс	  \n");
	printf("    бс      бсбс          бс  	  \n");
	printf("    бс              бсбсбсбс	  \n");
	printf("    бс                  бс  	  \n");
	printf("      бс       бсбсбсбсбс   	  \n");
	printf("      бс  бс       бсбсбс     	  \n");
	printf("     бс     бс      бс бсбс 	  \n");
	printf("   бсбс      бс     бс   бс  	  \n");
	printf("   бсбс  бсбсбс      бсбсбс 	  \n");
	printf("   бс    бс       бсбсбс		  \n");
	printf("   бс      бсбсбсбс    бсбсбс	  \n");
	printf(" бс бсбс   бсбс  бсбс  бсбс  бсбс  \n");
	printf(" бс бсбс   бсбс  бсбс  бсбс  бсбс  \n");
}
void enemy_4(){
	int x = 90, y = 1;

	gotoxy(x, y + 1);
	printf("   бсбсбс      бсбсбс      ");
	gotoxy(x, y + 2);
	printf("   бс    бс    бс    бс    ");
	gotoxy(x, y + 3);
	printf("   бс    бс    бсбс   бс    ");
	gotoxy(x, y + 4);
	printf("   бс  бсбсбсбсбсбс   бс    ");
	gotoxy(x, y + 5);
	printf("     бс         бсбсбсбс   ");
	gotoxy(x, y + 6);
	printf("     бс         бсбсбсбс    ");
	gotoxy(x, y + 7);
	printf("     бсбсбсбсбсбсбсбсбсбс  ");
	gotoxy(x, y + 8);
	printf("     бс      бсбс    бсбс  бсбс");
	gotoxy(x, y + 9);
	printf("  бс бс      бсбс    бсбс  бсбс");
	gotoxy(x, y + 10);
	printf("  бс бс    бс      бсбсбс   ");
	gotoxy(x, y + 11);
	printf("   бсбс  бс         бсбс    ");
	gotoxy(x, y + 12);
	printf("  бс бс  бс         бсбс     ");
	gotoxy(x, y + 13);
	printf("     бс            бс       ");
	gotoxy(x, y + 14);
	printf("       бсбсбсбсбсбс  бсбс    ");
	gotoxy(x, y + 15);
	printf("   бсбс  бс      бс    бс   ");
	gotoxy(x, y + 16);
	printf("   бсбс  бс      бс     бс  ");
	gotoxy(x, y + 17);
	printf(" бс    бс          бсбс    бс");
	gotoxy(x, y + 18);
	printf(" бс    бс          бс      бс");
	gotoxy(x, y + 19);
	printf(" бс    бс          бс      бс");
	gotoxy(x, y + 20);
	printf(" бсбсбс  бс    бс  бсбсбсбс  ");
	gotoxy(x, y + 21);
	printf("   бс      бсбсбс      бсбс");
	gotoxy(x, y + 22);
	printf("   бс      бсбсбс        бс ");
	gotoxy(x, y + 23);
	printf("   бсбсбсбсбсбсбсбсбсбсбсбс  ");
}
