#include"Interface.h"
#include"BinaryTree.h"

/*
2012244009 이대웅
*/

int main(int argc, char **argv) {
	setDigimonCondition(); // 트리에 디지몬명, 성장 저장
	disappear(); // 콘솔에 커서 제거
	printTitle();
	
	interfaceMain();

	return 0;
}