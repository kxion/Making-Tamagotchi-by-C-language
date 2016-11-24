#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <process.h>
#include"Client.h"
#include"Interface.h"

// ��ó: http://remocon33.tistory.com/465
// IP�ּ� ������ ������ http://tapito.tistory.com/441

unsigned WINAPI SendMsg(void* arg); // ������ �����Լ�
unsigned WINAPI RecvMsg(void* arg); // ������ �����Լ�
void ErrorHandling(char* msg);

char name[NAME_SIZE] = "[DEFAULT]";
char msg[BUF_SIZE];

void client(char *name[100]) {
	WSADATA wsaData;
	SOCKET sock;
	SOCKADDR_IN serverAddr;
	HANDLE sendThread, recvThread;

	char localHostName[512]; // ��Ʈ��ũ���� �ĺ��Ǵ� �̸� ������ ����
	struct hostent *localHostINFO; // ���� ȣ��Ʈ�� ������ ��� ����ü ������
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
	
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)// ������ ������ ����Ѵٰ� �ü���� �˸�
		ErrorHandling("WSAStartup() error!");

	// IP�ּ� ������ ������ http://tapito.tistory.com/441
	gethostname(localHostName, sizeof(localHostName)); // ���� ȣ��Ʈ�� �̸����
	localHostINFO = gethostbyname(localHostName); // ���� ȣ��Ʈ�� �Ӽ����

	sprintf(name, "[%s]", name);

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
	return 0;
}
unsigned WINAPI SendMsg(void* arg) { // ���ۿ� �������Լ�
	SOCKET sock = *((SOCKET*)arg); // ������ ������ �����Ѵ�.
	char nameMsg[NAME_SIZE + BUF_SIZE];
	while (1) {//�ݺ�
		fgets(msg, BUF_SIZE, stdin); // �Է��� �޴´�.
		if (!strcmp(msg, "q\n")) { // q�� �Է��ϸ� �����Ѵ�.
			send(sock, "q", 1, 0); // nameMsg�� �������� �����Ѵ�.
		}
		sprintf(nameMsg, "%s %s", name, msg); // nameMsg�� �޽����� �����Ѵ�.
		send(sock, nameMsg, strlen(nameMsg), 0); // nameMsg�� �������� �����Ѵ�.
	}
	return 0;
}
unsigned WINAPI RecvMsg(void* arg) {
	SOCKET sock = *((SOCKET*)arg); // ������ ������ �����Ѵ�.
	char nameMsg[NAME_SIZE + BUF_SIZE];
	int strLen;
	while (1) {//�ݺ�
		strLen = recv(sock, nameMsg, NAME_SIZE + BUF_SIZE - 1, 0); // �����κ��� �޽����� �����Ѵ�.
		if (strLen == -1)
			return -1;
		nameMsg[strLen] = 0; // ���ڿ��� ���� �˸��� ���� ����
		if (!strcmp(nameMsg, "q")) {
			printf("left the chat\n");
			closesocket(sock);
			exit(0);
		}
		fputs(nameMsg, stdout); // �ڽ��� �ֿܼ� ���� �޽����� ����Ѵ�.
	}
	return 0;
}
void ErrorHandling(char* msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}