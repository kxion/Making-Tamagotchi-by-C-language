#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BinaryTree.h"

TreeNode *root;



void createRoot(int number, char name[20]) { // ��Ʈ ����
	root = (TreeNode*)malloc(sizeof(TreeNode));
	root->number = number;
	strcpy(root->name, name);
	root->left = NULL;
	root->right = NULL;
}
void *child(int number, char name[20]) { // ���忡 �ش��ϴ� ������ �ܰ� ����
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
			if (parrent->left == NULL) { // ���� �ڼ����� ����
				parrent->left = newNodeTree;
				return;
			}
			parrent = parrent->left;
		}
		else {
			if (parrent->right == NULL) { // ������ �ڼ����� ����
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
		if (search->number == number) // �̹� ���� ����ִٸ� 1 ��ȯ
			return 1;
		if (search->number < number) { // ���ʳ�忡 ���� ������� �ʴٸ� 0 ��ȯ
			if (search->left == NULL)
				return 0;
			search = search->left;
		}
		else { // ������ ��忡 ���� ������� �ʴٸ� 0 ��ȯ
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
	createRoot(10, "������"); // ���� 5�� ������� ��ȭ
	child(1,  "�����");
	child(5, "�����");
	child(15, "����ü");
	child(20, "�ñ�ü");
	child(25, "�ʱñ�ü");
}