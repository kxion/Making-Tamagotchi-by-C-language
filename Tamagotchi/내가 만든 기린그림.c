#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void gotoxy(int x, int y);
void printWin();//윈 이미지
void printLose();//로즈 이미지
void printLveUp();//레벨업 이미지

int main()
{
	system("mode con: cols=100 lines=30");//가로 , 세로 ->http://berabue.tistory.com/59

	while (1)//실행 시켜보면 암..
	{
		printWin();
		Sleep(1000);
		system("cls");
		printLose();
		Sleep(1000);
		system("cls");
		printLveUp();
		Sleep(1000);
		system("cls");
	}

	system("pause");
	return 0;
}

void gotoxy(int x, int y) { // ***2012244063 한진오*** , goto() 함수 선언
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


void printWin()
{
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
}

void printLose()
{
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

}

void printLveUp()
{
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
}
