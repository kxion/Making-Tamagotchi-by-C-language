#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BinaryTree.h"

TreeNode *root;



void createRoot(int number, char name[20]) { // 루트 생성
	root = (TreeNode*)malloc(sizeof(TreeNode));
	root->number = number;
	strcpy(root->name, name);
	root->left = NULL;
	root->right = NULL;
}
void *child(int number, char name[20]) { // 성장에 해당하는 레벨과 단계 저장
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
void setTree() {
	createRoot(10, "성숙기"); // 렙이 5의 배수마다 진화
	child(1,  "유년기");
	child(5, "성장기");
	child(15, "완전체");
	child(20, "궁극체");
	child(25, "초궁극체");
}