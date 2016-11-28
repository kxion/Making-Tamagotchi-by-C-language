#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BinaryTree.h"

#pragma warning(disable:4996) // warning C4996을 잡기 위한 코드, 참고문헌 http://blog.naver.com/PostView.nhn?blogId=sorkelf&logNo=40137167266
/*
2012244009 이대웅

이진트리 -> hashmap 처럼 사용, 레벨을 키 값으로하여, 디지몬에 관련된 이름과 성장 이름 저장.
C로 배우는 쉬운 자료구조 (개정판) 참고.
참고 http://robodream.tistory.com/192
*/
TreeNode *root;

void createRoot(int number, char name[20], char digimon[20]) { // 루트 생성
	root = (TreeNode*)malloc(sizeof(TreeNode)); // 동적할당
	root->number = number; // 값 초기화
	strcpy(root->name, name); // 값 초기화
	strcpy(root->digimon, digimon); // 값 초기화
	root->left = NULL; // 자식노드의 링크 NULL 초기화
	root->right = NULL; // 자식노드의 링크 NULL 초기화
}
void child(int number, char name[20], char digimon[20]) { // 성장에 해당하는 레벨과 단계 저장
	TreeNode *parrent; // 부모노드를 명시
	TreeNode *newNodeTree = (TreeNode*)malloc(sizeof(TreeNode)); // 동적할당

	if (search(number)) { // 1을 반환하면 FULL
		printf("full\n");
		return;
	}
	newNodeTree->left = NULL; // 생성한 노드의 자식노드  NULL 초기화
	newNodeTree->right = NULL; // 생성한 노드의 자식노드 NULL 초기화
	newNodeTree->number = number; // 값 초기화
	strcpy(newNodeTree->name, name); // 값 초기화
	strcpy(newNodeTree->digimon, digimon); // 값 초기화

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
		if (search->number == number) // 캐릭터 레벨을 토대로 디지몬명과 성장 찾기
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
			child(i, "성장기", "아구몬"); // i를 레벨로 명시하여 성장과 디지몬명 저장
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
		else child(i, "유년기","코요몬");
	}
}