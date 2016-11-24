#include<stdio.h>
#include<string.h>
#include<windows.h>
#include"Display.h"
#include"Interface.h"
#include"Skill.h"

void coyomon() {
	gotoxy(2, 15);

	printf("                 ■\n");
	printf("                 ■ ■\n");
	printf("                 ■  ■\n");
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
	printf("      ■                 ■\n");
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

	printf("  ■■    ■■■■■\n");
	printf(" ■   ■■■■■■■■     ■■\n");
	printf(" ■     ■■■   ■■■ ■ ■■\n");
	printf(" ■       ■■    ■■■■■  ■\n");
	printf(" ■   ■■■■■    ■■■■■■\n");
	printf(" ■   ■  ■■■■■■■■■■\n");
	printf(" ■   ■  ■ ■■■■■■■■■\n");
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
ChStat* skillDisplay(ChStat *chStat, int selectNum) {
	const int x = 40, y = 23;
	gotoxy(x, y);

	if (!strcmp(chStat->digimon, "코요몬")) {
		if (chStat->energy >= 2) {
			printf("몸통박치기 !!!");
			chStat->attack = coyomonSkill(chStat->attack);
			chStat->energy = chStat->energy - 2;
		}
		else {
			printf("기력이 2 필요합니다 !!!");
			gotoxy(x, y + 2);
			printf("기력부족으로 인한 기본공격 !!!");
		}
	}

	if(!strcmp(chStat->digimon, "아구몬")) {
		if (selectNum == 1 && chStat->energy >= 2) {
			printf("꼬마불꽃 !!!\n");
			chStat->attack = agumonSkill_1(chStat->attack);
			chStat->energy = chStat->energy - 2;
		}
		else if (selectNum == 1 && chStat->energy < 2) {
			printf("기력이 2 필요합니다 !!!");
			gotoxy(x, y + 2);
			printf("기력부족으로 인한 기본공격 !!!");
		}
		else if (selectNum == 2 && chStat->energy >= 4) {
			printf("꼬마화염 !!!\n");
			chStat->attack = agumonSkill_2(chStat->attack);
			chStat->energy = chStat->energy - 4;
		}
		else if (selectNum == 2 && chStat->energy < 4) {
			printf("기력이 4 필요합니다 !!!");
			gotoxy(x, y + 2);
			printf("기력부족으로 인한 기본공격 !!!");
		}
	}
	else if (!strcmp(chStat->digimon, "그레이몬")) {
		if (selectNum == 1 && chStat->energy >= 2) {
			printf("화염 불 !!!\n");
			chStat->attack = greymonSkill_1(chStat->attack);
			chStat->energy = chStat->energy - 2;
		}
		else if(selectNum == 1 && chStat->energy < 2){
			printf("기력이 2 필요합니다 !!!");
			gotoxy(x, y + 2);
			printf("기력부족으로 인한 기본공격 !!!");
		}
		else if (selectNum == 2 && chStat->energy >= 4) {
			printf("메가화염 !!!\n");
			chStat->attack = greymonSkill_2(chStat->attack);
			chStat->energy = chStat->energy - 4;
		}
		else if (selectNum == 2 && chStat->energy < 4){
			printf("기력이 4 필요합니다 !!!");
			gotoxy(x, y + 2);
			printf("기력부족으로 인한 기본공격 !!!");
		}
	}
	else if (!strcmp(chStat->digimon, "메탈그레이몬")) {
		if (selectNum == 1 && chStat->energy >= 2) {
			printf("다연발 불꽃 !!! \n");
			chStat->attack = metalGreymonSkill_1(chStat->attack);
			chStat->energy = chStat->energy - 2;
		}
		else if (selectNum == 1 && chStat->energy < 2) {
			printf("기력이 2 필요합니다 !!!");
			gotoxy(x, y + 2);
			printf("기력부족으로 인한 기본공격 !!!");
		}
		else if (selectNum == 2 && chStat->energy >= 4) {
			printf("기가 디스티로이어 !!!\n");
			chStat->attack = metalGreymonSkill_2(chStat->attack);
			chStat->energy = chStat->energy - 4;
		}
		else if (selectNum == 2 && chStat->energy < 4) {
			printf("기력이 4 필요합니다 !!!");
			gotoxy(x, y + 2);
			printf("기력부족으로 인한 기본공격 !!!");
		}
	}
	else if (!strcmp(chStat->digimon, "워그레이몬")) {
		if (selectNum == 1 && chStat->energy >= 2) {
			printf("테라광선 !!!\n");
			chStat->attack = wargraymonSkill_1(chStat->attack);
			chStat->energy = chStat->energy - 2;
		}
		else if (selectNum == 1 && chStat->energy < 2) {
			printf("기력이 2 필요합니다 !!!");
			gotoxy(x, y + 2);
			printf("기력부족으로 인한 기본공격 !!!");
		}
		else if (selectNum == 2 && chStat->energy >= 4) {
			printf("가이아포스 !!!\n");
			chStat->attack = wargraymonSkill_2(chStat->attack);
			chStat->energy = chStat->energy - 4;
		}
		else if (selectNum == 2 && chStat->energy < 4) {
			printf("기력이 4 필요합니다 !!!");
			gotoxy(x, y + 2);
			printf("기력부족으로 인한 기본공격 !!!");
		}
	}
	else if (!strcmp(chStat->digimon, "오메가몬")) {
		if (selectNum == 1 && chStat->energy >= 2) {
			printf("그레이검 !!!\n");
			chStat->attack = omegaMonSKill_1(chStat->attack);
			chStat->energy = chStat->energy - 2;
		}
		else if (selectNum == 1 && chStat->energy < 2) {
			printf("기력이 2 필요합니다 !!!");
			gotoxy(x, y + 2);
			printf("기력부족으로 인한 기본공격 !!!");
		}
		else if(selectNum == 2 && chStat->energy >= 4){
			printf("가루캐논 !!!\n");
			chStat->attack = omegaMonSKill_2(chStat->attack);
			chStat->energy = chStat->energy - 4;
		}
		else if (selectNum == 2 && chStat->energy < 4) {
			printf("기력이 4 필요합니다 !!!");
			gotoxy(x, y + 2);
			printf("기력부족으로 인한 기본공격 !!!");
		}
	}
	return chStat;
}
void skillDescription(ChStat *chStat) {
	const int x = 60, y = 10;
	int selectNum = 1;

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
			if (selectNum < 3) // selectNUm이 4보다 작은경우(3 이하)
				selectNum += 1;
			else continue; // 아니면 계속 진행
		}
		else if (key == ENTER) { // 엔터의 아스키값. 엔터가 입력되었을시, 타이틀을 탈출. 및 selectNum에 해당하는 동작 수행
			break;
		}

		gotoxy(x, y);
		if (!strcmp(chStat->digimon, "코요몬")) {
			printf("▶ 몸통박치기");
			gotoxy(x, y + 2);
			printf("   공격력 : %2d", coyomonSkill(chStat->attack));
		}
		else if (!strcmp(chStat->digimon, "아구몬")) {
			switch (selectNum) {
			case 1:
				printf("▶ 꼬마불꽃       꼬마화염\n");
				gotoxy(x, y + 2);
				printf("   공격력 : %2d", agumonSkill_1(chStat->attack));
				break;
			case 2:
				printf("   꼬마불꽃    ▶ 꼬마화염\n");
				gotoxy(x, y + 2);
				printf("   공격력 : %2d", agumonSkill_2(chStat->attack));
				break;
			}
		}
		else if (!strcmp(chStat->digimon, "그레이몬")) {
			switch (selectNum) {
			case 1:
				printf("▶ 화염불        메가화염\n");
				gotoxy(x, y + 2);
				printf("   공격력 : %2d", greymonSkill_1(chStat->attack));
				break;
			case 2:
				printf("   화염불     ▶ 메가화염\n");
				gotoxy(x , y + 2);
				printf("   공격력 : %2d", greymonSkill_2(chStat->attack));
				break;
			}
		}
		else if (!strcmp(chStat->digimon, "메탈그레이몬")) {
			switch (selectNum) {
			case 1:
				printf("▶ 다연발 불꽃       기가 디스티로이어\n");
				gotoxy(x, y + 2);
				printf("   공격력 : %2d", metalGreymonSkill_1(chStat->attack));
				break;
			case 2:
				printf("   다연발 불꽃    ▶ 기가 디스티로이어\n");
				gotoxy(x , y + 2);
				printf("   공격력 : %2d", metalGreymonSkill_2(chStat->attack));
				break;
			}
		}
		else if (!strcmp(chStat->digimon, "워그레이몬")) {
			switch (selectNum) {
			case 1:
				printf("▶ 테라광선       가이아포스\n");
				gotoxy(x, y + 2);
				printf("   공격력 : %2d", wargraymonSkill_1(chStat->attack));
				break;
			case 2:
				printf("   테라광선    ▶ 가이아포스\n");
				gotoxy(x, y + 2);
				printf("   공격력 : %2d", wargraymonSkill_2(chStat->attack));
				break;
			}
		}
		else {
			switch (selectNum) {
			case 1:
				printf("▶ 그레이검       가루캐논\n");
				gotoxy(x, y + 2);
				printf("   공격력 : %2d", omegaMonSKill_1(chStat->attack));
				break;
			case 2:
				printf("   그레이검    ▶ 가루캐논\n");
				gotoxy(x, y + 2);
				printf("   공격력 : %2d", omegaMonSKill_2(chStat->attack));
				break;
			}
		}
	}
}
void printWin(){
	int x = 20, y = 4;
	gotoxy(x, y++);
	printf("$bcccccccccccccccccccccccccccccccccccccccccccccccccccccccccccbB\n");
	gotoxy(x, y++);
	printf("&                                                             q\n");
	gotoxy(x, y++);
	printf("8                                                             d\n");
	gotoxy(x, y++);
	printf("8                                                             d\n");
	gotoxy(x, y++);
	printf("8                                                             d\n");
	gotoxy(x, y++);
	printf("8                                                             d\n");
	gotoxy(x, y++);
	printf("8  /z,      !X`      tY. U$\                rv    ^z1    -z!   d\n");
	gotoxy(x, y++);
	printf("8 j$C      a$z     ^$$  fq?                @$    I$p    z${   d\n");
	gotoxy(x, y++);
	printf("8  $$     ,$$$     c$(                     W$    Lee    Han   d\n");
	gotoxy(x, y++);
	printf("8  Y$|    L$Z$[    $$   ~v:  `v~ vpqUl     W$    Dea    Jin   d\n");
	gotoxy(x, y++);
	printf("8  ^$W    $k $a   ]$X   n$+  ;$8$0[($$f    *@    Unn    Ooo   d\n");
	gotoxy(x, y++);
	printf("8   b$l  x$+ d$$  b$^   j$~  :$$,    @$    #@    `$J    t$~   d\n");
	gotoxy(x, y++);
	printf("8   <$0  @B  ~$X `$b    j$~  :$Q     J$,   a@    .$U    ($>   d\n");
	gotoxy(x, y++);
	printf("8     $$ [$\   $$ u$_    j$~  :$X     U$,   #$    .$J    \$i    d\n");
	gotoxy(x, y++);
	printf("8    |${o$    t$-$B     j$~  :$X     U$,   (j     u?    ic$   d\n");
	gotoxy(x, y++);
	printf("8     $$$z     $@$j     j$~  :$X     U$,                      d\n");
	gotoxy(x, y++);
	printf("8     Y$$`     L$$      x$+  ;$J     L$,   $$!   ]$8    Q$c   d\n");
	gotoxy(x, y++);
	printf("8     ^z|      ,z)      +X:  ^z]     [X`   0w^   !pY    /d}   d\n");
	gotoxy(x, y++);
	printf("8                                                             d\n");
	gotoxy(x, y++);
	printf("8                                                             d\n");
	gotoxy(x, y++);
	printf("8                                                             d\n");
	gotoxy(x, y++);
	printf("&                                                             p\n");
	gotoxy(x, y++);
	printf("@xcccccccccccccccccccccccccccccccccccccccccccccccccccccccccccxW\n");

	Sleep(1000);
}
void printLose() {
	int x = 20, y = 4;
	gotoxy(x, y++);
	printf("@############################################################@\n");
	gotoxy(x, y++);
	printf("@                                                            @\n");
	gotoxy(x, y++);
	printf("@                                                            @\n");
	gotoxy(x, y++);
	printf("@                                                            @\n");
	gotoxy(x, y++);
	printf("@      :                                                     @\n");
	gotoxy(x, y++);
	printf("@     :@:                                                    @\n");
	gotoxy(x, y++);
	printf("@     :@.                                                    @\n");
	gotoxy(x, y++);
	printf("@     :@.                                                    @\n");
	gotoxy(x, y++);
	printf("@     :@.            =#$$#+       .*$$#+      :#$$*:         @\n");
	gotoxy(x, y++);
	printf("@     :@.          +@$=..=$@=    #@+..=$.    @@=..+@$        @\n");
	gotoxy(x, y++);
	printf("@     :@.         +@:      :@=  :@:         @*      @*       @\n");
	gotoxy(x, y++);
	printf("@     :@.         @+        #@   @*        #@       +@       @\n");
	gotoxy(x, y++);
	printf("@     :@.        :@.        =@   :@@*.     @@@@@@@@@@@       @\n");
	gotoxy(x, y++);
	printf("@     :@.        :@.        =@     :#@@=   @#                @\n");
	gotoxy(x, y++);
	printf("@     :@.         @+        #@        =@=  $@                @\n");
	gotoxy(x, y++);
	printf("@     :@.         #@       :@=         @*  :@+               @\n");
	gotoxy(x, y++);
	printf("@     :@+:=====.   *@*:  :#@+   =$=  .$@    =@$:  :+@:       @\n");
	gotoxy(x, y++);
	printf("@     .########=     *$@@$+      +$@@$+       +$@@$*.        @\n");
	gotoxy(x, y++);
	printf("@                                                            @\n");
	gotoxy(x, y++);
	printf("@                                                            @\n");
	gotoxy(x, y++);
	printf("@                                                            @\n");
	gotoxy(x, y++);
	printf("@                                                            @\n");
	gotoxy(x, y++);
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

	Sleep(1000);
}
void printLvUp() {
	int x = 20, y = 1;
	gotoxy(x, y++);
	printf("@************************************************************@\n");
	gotoxy(x, y++);
	printf("$    @+                                              @=      $\n");
	gotoxy(x, y++);
	printf("$    @+            .==.    .         .      ==.      @=      $\n");
	gotoxy(x, y++);
	printf("$    @+          =@@**@@:  #@       @@   :@@**@@=    @=      $\n");
	gotoxy(x, y++);
	printf("$    @+         *@     :@.  @+     :@   +@.    .@:   @=      $\n");
	gotoxy(x, y++);
	printf("$    @+        .@.      #$  +@     @*   @:      *@   @=      $\n");
	gotoxy(x, y++);
	printf("$    @+        +@#######@@   @*   =@   =@#######@@   @=      $\n");
	gotoxy(x, y++);
	printf("$    @+        *@.::::::..   :@   @=   +@.::::::..   @=      $\n");
	gotoxy(x, y++);
	printf("$    @+        =@             @# +@    :@.           @=      $\n");
	gotoxy(x, y++);
	printf("$    @+         @$            .@ @:     @@           @=      $\n");
	gotoxy(x, y++);
	printf("$    @$++++++:   @@+::=#@      $@$       @@+::=*@.   @=      $\n");
	gotoxy(x, y++);
	printf("$    +++++++*:    :*##*=        +         .*##*=     +.      $\n");
	gotoxy(x, y++);
	printf("$                                                            $\n");
	gotoxy(x, y++);
	printf("$    +:         +.                  =:     =:     ==         $\n");
	gotoxy(x, y++);
	printf("$    @*         @=                  @#     @$     @$         $\n");
	gotoxy(x, y++);
	printf("$    @+         @=                  @*     @#     @#         $\n");
	gotoxy(x, y++);
	printf("$    @+         @=                  @*     @#     @#         $\n");
	gotoxy(x, y++);
	printf("$    @+         @=   #$ #@@@@@:     @*     @#     @#         $\n");
	gotoxy(x, y++);
	printf("$    @+         @=   #$@=    +@=    @*     @*     $#         $\n");
	gotoxy(x, y++);
	printf("$    @+         @=   #@.      +@    @*     $*     $#         $\n");
	gotoxy(x, y++);
	printf("$    @+         @=   #@        @:   @*     $*     $*         $\n");
	gotoxy(x, y++);
	printf("$    @*         @:   #$        @:   @*     @*     $#         $\n");
	gotoxy(x, y++);
	printf("$    @$        :@    #@       :@    :.     :.     :.         $\n");
	gotoxy(x, y++);
	printf("$    =@:       @$    Lee      Oh                             $\n");
	gotoxy(x, y++);
	printf("$     *@#:. .=@@     Dea*   Jin     #*     #*     #*         $\n");
	gotoxy(x, y++);
	printf("$      .*@@@@#:      Unn+@@Han      @$     @$     @@         $\n");
	gotoxy(x, y++);
	printf("$                    #$                                      $\n");
	gotoxy(x, y++);
	printf("$                    #$                                      $\n");
	gotoxy(x, y++);
	printf("@************************************************************@\n");

	Sleep(1000);
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
