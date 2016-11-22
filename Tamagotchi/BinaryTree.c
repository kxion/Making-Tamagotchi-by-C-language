#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BinaryTree.h"

#pragma warning(disable:4996) // warning C4996을 잡기 위한 코드, 참고문헌 http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266

TreeNode *root;

void createRoot(int number, char name[20], char digimon[20]) { // 루트 생성
	root = (TreeNode*)malloc(sizeof(TreeNode));
	root->number = number;
	strcpy(root->name, name);
	strcpy(root->digimon, digimon);
	root->left = NULL;
	root->right = NULL;
}
void child(int number, char name[20], char digimon[20]) { // 성장에 해당하는 레벨과 단계 저장
	TreeNode *parrent;
	TreeNode *newNodeTree = (TreeNode*)malloc(sizeof(TreeNode));

	if (search(number)) {
		printf("full\n");
		return;
	}
	newNodeTree->left = NULL;
	newNodeTree->right = NULL;
	newNodeTree->number = number;
	strcpy(newNodeTree->name, name);
	strcpy(newNodeTree->digimon, digimon);

	parrent = root;

	while (1) {
		if (parrent->number < number) {
			if (parrent->left == NULL) { // 왼쪽 자손으로 저장
				parrent->left = newNodeTree;
				return;
			}
			parrent = parrent->left;
		}
		else {
			if (parrent->right == NULL) { // 오른쪽 자손으로 저장
				parrent->right = newNodeTree;
				return;
			}
			parrent = parrent->right;
		}
	}
}
int search(int number) {
	TreeNode *search = root;
	while (1) {
		if (search->number == number) // 이미 값이 들어있다면 1 반환
			return 1;
		if (search->number < number) { // 왼쪽노드에 값이 들어있지 않다면 0 반환
			if (search->left == NULL)
				return 0;
			search = search->left;
		}
		else { // 오른쪽 노드에 값이 들어있지 않다면 0 반환
			if (search->right == NULL) 
				return 0;
			search = search->right;
		}
	}
}
TreeNode* searchName(int number) {
	TreeNode *search = root;
	while (1) {
		if (search->number == number)
			return search;
		if (search->number < number) {
			if (search->left == NULL)
				return 0;
			search = search->left;
		}
		else {
			if (search->right == NULL)
				return 0;
			search = search->right;
		}
	}
}
void setDigimonCondition() {
	int i = 1;

	createRoot(10, "성숙기", "그레이몬"); // 렙이 5의 배수마다 진화
	for (i = 1; i <= 30; i++) {
		if (i >= 5 && i < 10)
			child(i, "성장기", "아구몬");
		else if (i >= 10 && i < 15) {
			if (i == 10) continue;
			child(i, "성숙기", "그레이몬");
		}
		else if (i >= 15 && i < 20)
			child(i, "완전체", "메탈그레이몬");
		else if (i >= 20 && i < 25)
			child(i, "궁극체","워그레이몬");
		else if (i >= 25 && i <= 30)
			child(i, "초궁극체","오메가몬");
		else child(i, "유아기","코요몬");
	}
}