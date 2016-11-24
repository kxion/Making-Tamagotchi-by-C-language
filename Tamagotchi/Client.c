#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <process.h>
#include"Client.h"
#include"Interface.h"

// 출처: http://remocon33.tistory.com/465
// IP주소 얻어오기 참고문헌 http://tapito.tistory.com/441

unsigned WINAPI SendMsg(void* arg); // 쓰레드 전송함수
unsigned WINAPI RecvMsg(void* arg); // 쓰레드 수신함수
void ErrorHandling(char* msg);

char name[NAME_SIZE] = "[DEFAULT]";
char msg[BUF_SIZE];

void client(char *name[100]) {
	WSADATA wsaData;
	SOCKET sock;
	SOCKADDR_IN serverAddr;
	HANDLE sendThread, recvThread;

	char localHostName[512]; // 네트워크에서 식별되는 이름 저장할 변수
	struct hostent *localHostINFO; // 로컬 호스트의 정보가 담길 구조체 포인터
	char port[100];

	const int x = 70, y = 1;
	/*
	if(argc!=4){
	printf("Usage : %s <IP> <port> <name>\n",argv[0]);
	exit(1);
	}
	*/
	gotoxy(x, y);
	printf("connect to Server");
	
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)// 윈도우 소켓을 사용한다고 운영체제에 알림
		ErrorHandling("WSAStartup() error!");

	// IP주소 얻어오기 참고문헌 http://tapito.tistory.com/441
	gethostname(localHostName, sizeof(localHostName)); // 로컬 호스트의 이름얻기
	localHostINFO = gethostbyname(localHostName); // 로컬 호스트의 속성얻기

	sprintf(name, "[%s]", name);

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
	return 0;
}
unsigned WINAPI SendMsg(void* arg) { // 전송용 쓰레드함수
	SOCKET sock = *((SOCKET*)arg); // 서버용 소켓을 전달한다.
	char nameMsg[NAME_SIZE + BUF_SIZE];
	while (1) {//반복
		fgets(msg, BUF_SIZE, stdin); // 입력을 받는다.
		if (!strcmp(msg, "q\n")) { // q를 입력하면 종료한다.
			send(sock, "q", 1, 0); // nameMsg를 서버에게 전송한다.
		}
		sprintf(nameMsg, "%s %s", name, msg); // nameMsg에 메시지를 전달한다.
		send(sock, nameMsg, strlen(nameMsg), 0); // nameMsg를 서버에게 전송한다.
	}
	return 0;
}
unsigned WINAPI RecvMsg(void* arg) {
	SOCKET sock = *((SOCKET*)arg); // 서버용 소켓을 전달한다.
	char nameMsg[NAME_SIZE + BUF_SIZE];
	int strLen;
	while (1) {//반복
		strLen = recv(sock, nameMsg, NAME_SIZE + BUF_SIZE - 1, 0); // 서버로부터 메시지를 수신한다.
		if (strLen == -1)
			return -1;
		nameMsg[strLen] = 0; // 문자열의 끝을 알리기 위해 설정
		if (!strcmp(nameMsg, "q")) {
			printf("left the chat\n");
			closesocket(sock);
			exit(0);
		}
		fputs(nameMsg, stdout); // 자신의 콘솔에 받은 메시지를 출력한다.
	}
	return 0;
}
void ErrorHandling(char* msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}