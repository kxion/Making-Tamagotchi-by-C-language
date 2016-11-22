#ifndef BINARYTREE_H // BINARYTREE_H가 정의되어 있지 않다면
#define BINARYTREE_H // BINARYTREE_H 매크로 정의

/*

2012244009 이대웅
참고문헌 https://dojang.io/mod/page/view.php?id=716
트리구조를 이용한 탐색

*/



typedef struct treeNode {
	int number;
	char name[20]; 
	struct treeNode *left;
	struct treeNode *right;
}TreeNode;

void createRoot(int number, char name[20]); // 성장에 관련된 값 입력
void *child(int number, char name[20]); // 성장에 해당하는 레벨과 단계 저장
int search(int number); // 트리탐색
TreeNode* searchName(int number);
void setTree(); // 렙업 시 5의배수라면 진화

#endif // #ifndef BINARYTREE_H 종료