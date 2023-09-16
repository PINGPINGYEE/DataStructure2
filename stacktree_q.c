
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define SIZE 100

typedef struct TreeNode
{
	int data;
	struct TreeNode* left, * right;
} TreeNode;

int top = -1;
TreeNode* stack[SIZE];

int is_empty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

void push(TreeNode* p)
{
	if (top < SIZE - 1)
		stack[++top] = p;
}

TreeNode* pop()
{
	TreeNode* p = NULL;
	if (top >= 0)
		p = stack[top--];
	return p;
}

// 중위 순회
void inorder_iter(TreeNode* root)
{
	while (!is_empty() || root != NULL)
	{
		if (root != NULL)
		{
			push(root);
			root = root->left;
		}
		else
		{
			root = pop();
			printf("%d ", root->data);
			root = root->right;
		}
	}
}

// 선위순회
void preorder_iter(TreeNode* root)
{
	if (root == NULL) return; // 루트에 값이 없으면 리턴

	push(root); // 첫 스택값 입력

	while (!is_empty()) // empty가 아닐때까지
	{
		root = pop(); // 루트에 pop 입력(선위순회)
		printf("%d ", root->data);

		if (root->right != NULL) push(root->right); // 오른쪽 자식 방문
		if (root->left != NULL) push(root->left); // 왼쪽 자식 방문
	}
}

// 후위순회 함수
void postorder_iter(TreeNode* root)
{
	top = -1; // 스택 크기 초기화를 함
	int i = 0;
	TreeNode* node;
	TreeNode* output[SIZE]; // 두개의 스택을 이용하는 대신 스택 하나와 배열을 이용
	push(root); // 첫 스택값 push
	while (top >= 0) // 앞서서 스택 크기 초기화했으니 top으로 stack이 비어있는지 확인
	{
		node = pop(); // 첫 노드 꺼냄
		output[i++] = node; // 노드를 배열에 저장
		if (node->left != NULL) push(node->left); // 왼쪽 자식 노드가 있을 시 왼쪽을 넣음
		if (node->right != NULL) push(node->right); // 오른쪽도 동일
	}
	for (i = i - 1; i >= 0; i--) printf("%d ", output[i]->data); // 값에 반대로 저장되어 있으니까 뒤에부터 출력
}

//TreeNode 선언
TreeNode n1 = { 4, NULL, NULL };
TreeNode n3 = { 5, NULL, NULL };
TreeNode n2 = { 3, &n1, &n3 };
TreeNode n4 = { 6, NULL, NULL };
TreeNode n5 = { 2, &n2, &n4 };
TreeNode n6 = { 10, NULL, NULL };
TreeNode n7 = { 11, NULL, NULL };
TreeNode n8 = { 9, &n6, &n7 };
TreeNode n9 = { 8, NULL, NULL };
TreeNode n10 = { 7, &n9, &n8 };
TreeNode n11 = { 1, &n5, &n10 };

TreeNode* root = &n11;

int main(void)
{
	printf("<Traversal with Stack>");

	printf("\n1. 전위 순회");
	preorder_iter(root);

	printf("\n\n2. 중위 순회");
	inorder_iter(root);

	printf("\n\n3. 후위 순회");
	postorder_iter(root);
	printf("\n\n");

	return 0;
}
