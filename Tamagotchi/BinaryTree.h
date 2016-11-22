#ifndef BINARYTREE_H // BINARYTREE_H�� ���ǵǾ� ���� �ʴٸ�
#define BINARYTREE_H // BINARYTREE_H ��ũ�� ����

/*

2012244009 �̴��
������ https://dojang.io/mod/page/view.php?id=716
Ʈ�������� �̿��� Ž��

*/



typedef struct treeNode {
	int number;
	char name[20]; 
	struct treeNode *left;
	struct treeNode *right;
}TreeNode;

void createRoot(int number, char name[20]); // ���忡 ���õ� �� �Է�
void *child(int number, char name[20]); // ���忡 �ش��ϴ� ������ �ܰ� ����
int search(int number); // Ʈ��Ž��
TreeNode* searchName(int number);
void setTree(); // ���� �� 5�ǹ����� ��ȭ

#endif // #ifndef BINARYTREE_H ����