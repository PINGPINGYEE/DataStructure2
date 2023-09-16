#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX 100

// Linked Tree 구조체
typedef struct TreeNode
{
	int data;
	struct TreeNode* left, * right;
} TreeNode;


// Array Tree 구조체
struct TreeNodeArray {
	int data;
};

// Array Tree 선언
struct TreeNodeArray tree[MAX];

// 배열 초기화 함수
void resetArrayTree() {
	for (int i = 0; i < MAX; i++) {
		tree[i].data = -1;
	}
}

// 배열 추가 함수
void addNode(int index, int data) {
	if (index >= 0 && index < MAX) {
		tree[index].data = data;
	}
	else {
		printf("Index가 없습니다\n");
	}
}


// 배열 순회시 2*index+1은 왼쪽 노드, 2*index+2는 오른쪽 노드 
// 배열 전위 순회 함수
void preorder1(int index) {
	if (index >= 0 && index < MAX && tree[index].data != -1) {
		printf("%d ", tree[index].data);
		preorder1(2 * index + 1);
		preorder1(2 * index + 2);
	}
}

// 배열 중위 순회 함수
void inorder1(int index) {
	if (index >= 0 && index < MAX && tree[index].data != -1) {
		inorder1(2 * index + 1);
		printf("%d ", tree[index].data);
		inorder1(2 * index + 2);
	}
}

// 배열 후위 순회 함수
void postorder1(int index) {
	if (index >= 0 && index < MAX && tree[index].data != -1) {
		postorder1(2 * index + 1);
		postorder1(2 * index + 2);
		printf("%d ", tree[index].data);
	}
}

// Linked 전위 순회
preorder(TreeNode* root)
{
	if (root)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

// Linked 중위 순회
inorder(TreeNode* root)
{
	if (root)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

// Linked 후위 순회
postorder(TreeNode* root)
{
	if (root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

// Linked Tree 선언
TreeNode* LinkedTree()
{
	TreeNode* n1, * n2, * n3, * n4, * n5, * n6, * n7, * n8, * n9, * n10, * n11;

	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));
	n4 = (TreeNode*)malloc(sizeof(TreeNode));
	n5 = (TreeNode*)malloc(sizeof(TreeNode));
	n6 = (TreeNode*)malloc(sizeof(TreeNode));
	n7 = (TreeNode*)malloc(sizeof(TreeNode));
	n8 = (TreeNode*)malloc(sizeof(TreeNode));
	n9 = (TreeNode*)malloc(sizeof(TreeNode));
	n10 = (TreeNode*)malloc(sizeof(TreeNode));
	n11 = (TreeNode*)malloc(sizeof(TreeNode));
	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;
	n5->data = 5;
	n6->data = 6;
	n7->data = 7;
	n8->data = 8;
	n9->data = 9;
	n10->data = 10;
	n11->data = 11;
	n1->left = n2; n1->right = n7;
	n2->left = n3; n2->right = n6;
	n3->left = n4; n3->right = n5;
	n4->left = NULL; n4->right = NULL;
	n5->left = NULL; n5->right = NULL;
	n6->left = NULL; n6->right = NULL;
	n7->left = n8; n7->right = n9;
	n8->left = NULL; n8->right = NULL;
	n9->left = n10; n9->right = n11;
	n10->left = NULL; n10->right = NULL;
	n11->left = NULL; n11->right = NULL;
	return n1;
}

// 배열 선언
int ArrayTree() {
	resetArrayTree();

	addNode(0, 1);
	addNode(1, 2);
	addNode(2, 7);
	addNode(3, 3);
	addNode(4, 6);
	addNode(5, 8);
	addNode(6, 9);
	addNode(7, 4);
	addNode(8, 5);
	addNode(13, 10);
	addNode(14, 11);

	return 0;
}


void main()
{
	TreeNode* n1 = LinkedTree();
	ArrayTree();

	printf("<Linked Tree>\n");
	printf("\n1. 전위 순회\n");
	preorder(n1);
	printf("\n\n2. 중위 순회\n");
	inorder(n1);
	printf("\n\n3. 후위 순회\n");
	postorder(n1);
	printf("\n\n\n");

	printf("<Array Tree>\n");
	printf("\n1. 전위 순회\n");
	preorder1(0);
	printf("\n\n2. 중위 순회\n");
	inorder1(0);
	printf("\n\n3. 후위 순회\n");
	postorder1(0);
	printf("\n");
}








