#ifndef CLIENT_H // CLIENT_H�� ���ǵǾ� ���� �ʴٸ�
#define CLIENT_H // CLIENT_H ��ũ�� ����

#pragma comment(lib, "ws2_32.lib");

/*
�¶��� ������ ���� Ŭ���̾�Ʈ �ҽ�

IP�ּ� ������ ������ http://tapito.tistory.com/441
Ŭ���̾�Ʈ ��ó http://remocon33.tistory.com/465
*/
#include <Windows.h>

#define BUF_SIZE 100
#define NAME_SIZE 20

void client(char *name[100]);
unsigned WINAPI SendMsg(void* arg); // ������ �����Լ�
unsigned WINAPI RecvMsg(void* arg); //������ �����Լ�
void ErrorHandling(char* msg);

#endif // #ifndef CLIENT_H ����