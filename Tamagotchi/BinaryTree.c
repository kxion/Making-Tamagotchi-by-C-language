#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BinaryTree.h"

#pragma warning(disable:4996) // warning C4996�� ��� ���� �ڵ�, ������ http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266
/*
2012244009 �̴��

����Ʈ�� -> hashmap ó�� ���, ������ Ű �������Ͽ�, ������ ���õ� �̸��� ���� �̸� ����.
C�� ���� ���� �ڷᱸ�� (������) ����.
���� http://robodream.tistory.com/192
*/
TreeNode *root;

void createRoot(int number, char name[20], char digimon[20]) { // ��Ʈ ����
	root = (TreeNode*)malloc(sizeof(TreeNode)); // �����Ҵ�
	root->number = number; // �� �ʱ�ȭ
	strcpy(root->name, name); // �� �ʱ�ȭ
	strcpy(root->digimon, digimon); // �� �ʱ�ȭ
	root->left = NULL; // �ڽĳ���� ��ũ NULL �ʱ�ȭ
	root->right = NULL; // �ڽĳ���� ��ũ NULL �ʱ�ȭ
}
void child(int number, char name[20], char digimon[20]) { // ���忡 �ش��ϴ� ������ �ܰ� ����
	TreeNode *parrent; // �θ��带 ���
	TreeNode *newNodeTree = (TreeNode*)malloc(sizeof(TreeNode)); // �����Ҵ�

	if (search(number)) { // 1�� ��ȯ�ϸ� FULL
		printf("full\n");
		return;
	}
	newNodeTree->left = NULL; // ������ ����� �ڽĳ��  NULL �ʱ�ȭ
	newNodeTree->right = NULL; // ������ ����� �ڽĳ�� NULL �ʱ�ȭ
	newNodeTree->number = number; // �� �ʱ�ȭ
	strcpy(newNodeTree->name, name); // �� �ʱ�ȭ
	strcpy(newNodeTree->digimon, digimon); // �� �ʱ�ȭ

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
		if (search->number == number) // ĳ���� ������ ���� �������� ���� ã��
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

	createRoot(10, "������", "�׷��̸�"); // ���� 5�� ������� ��ȭ
	for (i = 1; i <= 30; i++) {
		if (i >= 5 && i < 10)
			child(i, "�����", "�Ʊ���"); // i�� ������ ����Ͽ� ����� ������� ����
		else if (i >= 10 && i < 15) {
			if (i == 10) continue;
			child(i, "������", "�׷��̸�");
		}
		else if (i >= 15 && i < 20)
			child(i, "����ü", "��Ż�׷��̸�");
		else if (i >= 20 && i < 25)
			child(i, "�ñ�ü","���׷��̸�");
		else if (i >= 25 && i <= 30)
			child(i, "�ʱñ�ü","���ް���");
		else child(i, "�����","�ڿ��");
	}
}