#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

void printTitle();
void gotoxy(int x, int y);

int main()
{
	system("mode con: cols=140 lines=30");//가로 , 세로 ->http://berabue.tistory.com/59
	printTitle();


	system("pause");
	return 0;
}


void printTitle()
{
	int x = 10, y = 3;

	gotoxy(x, y++);
	printf(" [(\\\|?,                    +|             |!                    ?xCCY|I                      ^(YCCr[.  :$i          `J< \n");
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
	printf("Plese press anyKey...");

	while (1)//---------------------------------------------------------------------------------타이틀의 while문
	{
		int key = 1;//초기화를 안하면 if문에서 에러가 나므로, 아무 값이나 초기화.
		if (_kbhit())//키 입력 여부 확인 ->http://showmiso.tistory.com/8
		{
			//아무키 입력 받았을때, 호출되는 함수 입력
			exit(1);
		}
	
	}

}

void gotoxy(int x, int y) { // ***2012244063 한진오*** , goto() 함수 선언
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}



