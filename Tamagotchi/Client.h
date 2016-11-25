#ifndef CLIENT_H // CLIENT_H가 정의되어 있지 않다면
#define CLIENT_H // CLIENT_H 매크로 정의

#pragma comment(lib, "ws2_32.lib");

/*
온라인 대전을 위한 클라이언트 소스

IP주소 얻어오기 참고문헌 http://tapito.tistory.com/441
클라이언트 출처 http://remocon33.tistory.com/465
*/
#include <Windows.h>

#define BUF_SIZE 100
#define NAME_SIZE 20

void client(char *name[100]);
unsigned WINAPI SendMsg(void* arg); // 쓰레드 전송함수
unsigned WINAPI RecvMsg(void* arg); //쓰레드 수신함수
void ErrorHandling(char* msg);

#endif // #ifndef CLIENT_H 종료