#include"Interface.h"
#include"BinaryTree.h"

int main(int argc, char **argv) {
	setDigimonCondition();
	disappear(); // 콘솔에 커서 제거
	printTitle();
	
	interfaceMain();

	return 0;
}