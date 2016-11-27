#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <process.h>
#include"Client.h"
#include"Interface.h"
#include"Character.h"
#include"Fight.h"

// 출처: http://remocon33.tistory.com/465
// IP주소 얻어오기 참고문헌 http://tapito.tistory.com/441

#pragma warning(disable:4996) // warning C4996을 잡기 위한 코드, 참고문헌 http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266

unsigned WINAPI SendMsg(void* arg); // 쓰레드 전송함수
unsigned WINAPI RecvMsg(void* arg); // 쓰레드 수신함수
void ErrorHandling(char* msg);

ChStat *myStat;
char msg[BUF_SIZE];

void client(ChStat *chStat) {
	WSADATA wsaData;
	SOCKET sock;
	SOCKADDR_IN serverAddr;
	HANDLE sendThread, recvThread;

	char localHostName[512]; // 네트워크에서 식별되는 이름 저장할 변수
	struct hostent *localHostINFO; // 로컬 호스트의 정보가 담길 구조체 포인터
	const int x = 70, y = 1;

	myStat = chStat;
	/*
	if(argc!=4){
	printf("Usage : %s <IP> <port> <name>\n",argv[0]);
	exit(1);
	}
	*/
	gotoxy(x, y);
	printf("connect to Server\n");
	
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)// 윈도우 소켓을 사용한다고 운영체제에 알림
		ErrorHandling("WSAStartup() error!");

	// IP주소 얻어오기 참고문헌 http://tapito.tistory.com/441
	gethostname(localHostName, sizeof(localHostName)); // 로컬 호스트의 이름얻기
	localHostINFO = gethostbyname(localHostName); // 로컬 호스트의 속성얻기

	printf("접속자 : %s\n", myStat->name);

	sock = socket(PF_INET, SOCK_STREAM, 0);//소켓을 하나 생성한다.

	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*)localHostINFO->h_addr_list[0]));
	serverAddr.sin_port = htons(8888); // 고정 포트 접근

	if (connect(sock, (SOCKADDR*)& serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)//서버에 접속한다.
		ErrorHandling("connect() error");

	// 접속에 성공하면 이 줄 아래가 실행된다.
	sendThread = (HANDLE)_beginthreadex(NULL, 0, SendMsg, (void*)&sock, 0, NULL); // 메시지 전송용 쓰레드가 실행된다.
	recvThread = (HANDLE)_beginthreadex(NULL, 0, RecvMsg, (void*)&sock, 0, NULL); // 메시지 수신용 쓰레드가 실행된다.

	WaitForSingleObject(sendThread, INFINITE); // 전송용 쓰레드가 중지될때까지 기다린다.
	WaitForSingleObject(recvThread, INFINITE); // 수신용 쓰레드가 중지될때까지 기다린다.
	
    // 클라이언트가 종료를 시도한다면 이줄 아래가 실행된다.
	closesocket(sock); // 소켓을 종료한다.
	WSACleanup(); // 윈도우 소켓 사용중지를 운영체제에 알린다.
}
unsigned WINAPI SendMsg(void* arg) { // 전송용 쓰레드함수
	SOCKET sock = *((SOCKET*)arg); // 서버용 소켓을 전달한다.
	char clientMsg[STAT_SIZE + BUF_SIZE] = "";
	
	while (1) {//반복
		fgets(msg, BUF_SIZE, stdin); // 입력을 받는다.
		if (!strcmp(msg, "q\n")) { // q를 입력하면 종료한다.
			send(sock, "q", 1, 0); // nameMsg를 서버에게 전송한다.
		}

		sprintf(clientMsg, "%s %s %s %s %d %d %d %d %d %d %d %d",msg, myStat->name, myStat->condition, myStat->digimon, myStat->lv, myStat->hp, 
			myStat->energy, myStat->exp, myStat->money, myStat->attack, myStat->agility, myStat->health); // clientMsg에 메시지를 전달한다.
		
		send(sock, clientMsg, strlen(clientMsg), 0); // clientMsg를 서버에게 전송한다.
	}
	return 0;
}
unsigned WINAPI RecvMsg(void* arg) {
	const int x = 70, y = 1;
	
	ChStat *enemyStat = NULL;
	SOCKET sock = *((SOCKET*)arg); // 서버용 소켓을 전달한다.
	
	char recvMsg[STAT_SIZE];
	char *tokMsg; // tok로 문자열 자르기
	int strLen = 0, i = 0;
	
	char stat[12][20] = { "" }, buffer[20] = "";

	enemyStat = &stat;

	while (1) { // 반복
		strLen = recv(sock, recvMsg, STAT_SIZE - 1, 0); // 서버로부터 메시지를 수신한다.
		if (strLen == -1)
			return -1;
		recvMsg[strLen] = 0; // 문자열의 끝을 알리기 위해 설정
		if (!strcmp(recvMsg, "q")) {
			printf("left the chat\n");
			closesocket(sock);
			exit(0);
		}
		i = 0;
		tokMsg = strtok(recvMsg, " "); // tok 참고문헌 http://huneyboy.blogspot.kr/2013/08/cstrtok.html
		while (tokMsg != NULL) {
			strcpy(stat[i++], tokMsg);
			//printf("%s ", tokMsg);
			tokMsg = strtok(NULL, " ");
		}
		strcpy(buffer, stat[0]);
		strcpy(enemyStat->name, stat[1]); // 이름 저장
		strcpy(enemyStat->condition, stat[2]); // 성장
		strcpy(enemyStat->digimon, stat[3]); // 디지몬
		enemyStat->lv = atoi(&stat[4]); // 레벨
		enemyStat->hp = atoi(&stat[5]); // 체력
		enemyStat->energy = atoi(stat[6]); // 기력
		enemyStat->exp = atoi(stat[7]); // 경험치
		enemyStat->money = atoi(&stat[8]); // 돈
		enemyStat->attack = atoi(&stat[9]); // 공격
		enemyStat->agility = atoi(&stat[10]); // 민첩
		enemyStat->health = atoi(&stat[11]); // 건강

		if (onlineFight(myStat, enemyStat)) {
			Sleep(1000);
			menu(myStat);
		}
		digimonDisplay(myStat->lv);
		gotoxy(x, y);
		printf("connect to Server\n");
	}
	return 0;
}
void ErrorHandling(char* msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}