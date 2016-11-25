#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <process.h>
#include"Client.h"
#include"Interface.h"
#include"Character.h"

// ��ó: http://remocon33.tistory.com/465
// IP�ּ� ������ ������ http://tapito.tistory.com/441

#pragma warning(disable:4996) // warning C4996�� ��� ���� �ڵ�, ������ http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266

unsigned WINAPI SendMsg(void* arg); // ������ �����Լ�
unsigned WINAPI RecvMsg(void* arg); // ������ �����Լ�
void ErrorHandling(char* msg);

ChStat *clientStat;
char msg[BUF_SIZE];

void client(ChStat *chStat) {
	WSADATA wsaData;
	SOCKET sock;
	SOCKADDR_IN serverAddr;
	HANDLE sendThread, recvThread;

	char localHostName[512]; // ��Ʈ��ũ���� �ĺ��Ǵ� �̸� ������ ����
	struct hostent *localHostINFO; // ���� ȣ��Ʈ�� ������ ��� ����ü ������
	const int x = 70, y = 1;

	clientStat = chStat;
	/*
	if(argc!=4){
	printf("Usage : %s <IP> <port> <name>\n",argv[0]);
	exit(1);
	}
	*/
	gotoxy(x, y);
	printf("connect to Server\n");
	
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)// ������ ������ ����Ѵٰ� �ü���� �˸�
		ErrorHandling("WSAStartup() error!");

	// IP�ּ� ������ ������ http://tapito.tistory.com/441
	gethostname(localHostName, sizeof(localHostName)); // ���� ȣ��Ʈ�� �̸����
	localHostINFO = gethostbyname(localHostName); // ���� ȣ��Ʈ�� �Ӽ����

	printf("������ : %s\n", clientStat->name);

	sock = socket(PF_INET, SOCK_STREAM, 0);//������ �ϳ� �����Ѵ�.

	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*)localHostINFO->h_addr_list[0]));
	serverAddr.sin_port = htons(8888); // ���� ��Ʈ ����

	if (connect(sock, (SOCKADDR*)& serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)//������ �����Ѵ�.
		ErrorHandling("connect() error");

	// ���ӿ� �����ϸ� �� �� �Ʒ��� ����ȴ�.
	sendThread = (HANDLE)_beginthreadex(NULL, 0, SendMsg, (void*)&sock, 0, NULL); // �޽��� ���ۿ� �����尡 ����ȴ�.
	recvThread = (HANDLE)_beginthreadex(NULL, 0, RecvMsg, (void*)&sock, 0, NULL); // �޽��� ���ſ� �����尡 ����ȴ�.

	WaitForSingleObject(sendThread, INFINITE); // ���ۿ� �����尡 �����ɶ����� ��ٸ���.
	WaitForSingleObject(recvThread, INFINITE); // ���ſ� �����尡 �����ɶ����� ��ٸ���.
	
    // Ŭ���̾�Ʈ�� ���Ḧ �õ��Ѵٸ� ���� �Ʒ��� ����ȴ�.
	closesocket(sock); // ������ �����Ѵ�.
	WSACleanup(); // ������ ���� ��������� �ü���� �˸���.
}
unsigned WINAPI SendMsg(void* arg) { // ���ۿ� �������Լ�
	SOCKET sock = *((SOCKET*)arg); // ������ ������ �����Ѵ�.
	char clientMsg[STAT_SIZE + BUF_SIZE];
	while (1) {//�ݺ�
		fgets(msg, BUF_SIZE, stdin); // �Է��� �޴´�.
		if (!strcmp(msg, "q\n")) { // q�� �Է��ϸ� �����Ѵ�.
			send(sock, "q", 1, 0); // nameMsg�� �������� �����Ѵ�.
		}
		sprintf(clientMsg, "%s %s %s %s %d %d %d %d %d %d %d %d",  msg, clientStat->name, clientStat->condition, clientStat->digimon,
			clientStat->lv, clientStat->hp, clientStat->energy, clientStat->exp, clientStat->money, clientStat->attack, clientStat->agility,
			clientStat->health); // clientMsg�� �޽����� �����Ѵ�.
		
		send(sock, clientMsg, strlen(clientMsg), 0); // clientMsg�� �������� �����Ѵ�.
	}
	return 0;
}
unsigned WINAPI RecvMsg(void* arg) {
	SOCKET sock = *((SOCKET*)arg); // ������ ������ �����Ѵ�.
	char recvMsg[BUF_SIZE];
	char *tokMsg; // tok�� ���ڿ� �ڸ���
	int strLen;
	while (1) {//�ݺ�
		strLen = recv(sock, recvMsg, BUF_SIZE - 1, 0); // �����κ��� �޽����� �����Ѵ�.
		if (strLen == -1)
			return -1;
		recvMsg[strLen] = 0; // ���ڿ��� ���� �˸��� ���� ����
		if (!strcmp(recvMsg, "q")) {
			printf("left the chat\n");
			closesocket(sock);
			exit(0);
		}

		tokMsg = strtok(recvMsg, " "); // tok ������ http://huneyboy.blogspot.kr/2013/08/cstrtok.html
		while (tokMsg != NULL) {
			printf("%s ", tokMsg);
			tokMsg = strtok(NULL, " ");
		}
	}
	return 0;
}
void ErrorHandling(char* msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}