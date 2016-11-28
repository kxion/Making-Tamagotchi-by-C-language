////��ó: http://remocon33.tistory.com/465
#pragma comment(lib, "ws2_32.lib")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <process.h>


#define BUF_SIZE 100
#define MAX_CLNT 256

unsigned WINAPI HandleClient(void* arg); // ������ �Լ�
void SendMsg(char* msg, int len); // �޽��� ������ �Լ�
void ErrorHandling(char* msg);

int clientCount = 0;
static int i = 0;
SOCKET clientSocks[MAX_CLNT]; // Ŭ���̾�Ʈ ���� ������ �迭
HANDLE hMutex; // ���ؽ�

int main(int argc, char **argv) {
	WSADATA wsaData;
	SOCKET serverSock, clientSock;
	SOCKADDR_IN serverAddr, clientAddr;
	int clientAddrSize;
	HANDLE hThread;

	/*
	if(argc!=2){
	printf("Usage : %s <port>\n",argv[0]);
	exit(1);
	}
	*/
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) // ������ ������ ����ϰڴٴ� ����� �ü���� ����
		ErrorHandling("WSAStartup() error!");

	hMutex = CreateMutex(NULL, FALSE, NULL);// �ϳ��� ���ؽ��� �����Ѵ�.
	serverSock = socket(PF_INET, SOCK_STREAM, 0); // �ϳ��� ������ �����Ѵ�.

	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddr.sin_port = htons(8888); // ������Ʈ

	if (bind(serverSock, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) // ������ ������ ��ġ�Ѵ�.
		ErrorHandling("bind() error");
	if (listen(serverSock, 5) == SOCKET_ERROR) //������ �غ���¿� �д�.
		ErrorHandling("listen() error");

	printf("Fixed port : 8888\n");
	printf("listening...\n");

	while (1) {
		clientAddrSize = sizeof(clientAddr);
		clientSock = accept(serverSock, (SOCKADDR*)&clientAddr, &clientAddrSize); // �������� ���޵� Ŭ���̾�Ʈ ������ clientSock�� ����
		WaitForSingleObject(hMutex, INFINITE); // ���ؽ� ����
		clientSocks[clientCount++] = clientSock; // Ŭ���̾�Ʈ ���Ϲ迭�� ��� ������ ���� �ּҸ� ����
		ReleaseMutex(hMutex); // ���ؽ� ����
		hThread = (HANDLE)_beginthreadex(NULL, 0, HandleClient, (void*)&clientSock, 0, NULL); // HandleClient ������ ����, clientSock�� �Ű������� ����
		printf("Connected Client IP : %s\n", inet_ntoa(clientAddr.sin_addr));
	}
	closesocket(serverSock);// ������ ������ ����.
	WSACleanup(); // ������ ������ �����ϰڴٴ� ����� �ü���� ����

	return 0;
}
unsigned WINAPI HandleClient(void* arg) {
	SOCKET clientSock = *((SOCKET*)arg); // �Ű������ι��� Ŭ���̾�Ʈ ������ ����
	int strLen = 0, i;
	char msg[BUF_SIZE];

	while ((strLen = recv(clientSock, msg, sizeof(msg), 0)) != 0) { // Ŭ���̾�Ʈ�κ��� �޽����� ���������� ��ٸ���.
		if (!strcmp(msg, "q")) {
			send(clientSock, "q", 1, 0);
			break;
		}
		SendMsg(msg, strLen); // SendMsg�� ���� �޽����� �����Ѵ�.
	}

	// �� ���� �����Ѵٴ� ���� �ش� Ŭ���̾�Ʈ�� �����ٴ� ����� ���� �ش� Ŭ���̾�Ʈ�� �迭���� �����������

	printf("client left the chat\n");

	WaitForSingleObject(hMutex, INFINITE); // ���ؽ� ����
	for (i = 0; i < clientCount; i++) { // �迭�� ������ŭ
		if (clientSock == clientSocks[i]) { // ���� ���� clientSock���� �迭�� ���� ���ٸ�
			while (i++ < clientCount - 1) // Ŭ���̾�Ʈ ���� ��ŭ
				clientSocks[i] = clientSocks[i + 1]; // ������ �����.
			break;
		}
	}
	clientCount--; // Ŭ���̾�Ʈ ���� �ϳ� ����
	ReleaseMutex(hMutex); // ���ؽ� ����
	closesocket(clientSock); // ������ �����Ѵ�.
	return 0;
}
void SendMsg(char* msg, int len) { // �޽����� ��� Ŭ���̾�Ʈ���� ������
	WaitForSingleObject(hMutex, INFINITE); // ���ؽ� ����
	if (i == 0) { // 0�� Ŭ���̾�Ʈ�� �޼����� 1�� Ŭ���̾�Ʈ���� ������.
		i = 1;
		send(clientSocks[1], msg, len, 0);
	}
	else if (i == 1) { // 1�� Ŭ���̾�Ʈ�� �޼����� 1�� Ŭ���̾�Ʈ���� ������.
		send(clientSocks[0], msg, len, 0);
		i = 0;
	}
	ReleaseMutex(hMutex); // ���ؽ� ����
}
void ErrorHandling(char* msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}