
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

// ���� ��ȸ
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

// ������ȸ
void preorder_iter(TreeNode* root)
{
	if (root == NULL) return; // ��Ʈ�� ���� ������ ����

	push(root); // ù ���ð� �Է�

	while (!is_empty()) // empty�� �ƴҶ�����
	{
		root = pop(); // ��Ʈ�� pop �Է�(������ȸ)
		printf("%d ", root->data);

		if (root->right != NULL) push(root->right); // ������ �ڽ� �湮
		if (root->left != NULL) push(root->left); // ���� �ڽ� �湮
	}
}

// ������ȸ �Լ�
void postorder_iter(TreeNode* root)
{
	top = -1; // ���� ũ�� �ʱ�ȭ�� ��
	int i = 0;
	TreeNode* node;
	TreeNode* output[SIZE]; // �ΰ��� ������ �̿��ϴ� ��� ���� �ϳ��� �迭�� �̿�
	push(root); // ù ���ð� push
	while (top >= 0) // �ռ��� ���� ũ�� �ʱ�ȭ������ top���� stack�� ����ִ��� Ȯ��
	{
		node = pop(); // ù ��� ����
		output[i++] = node; // ��带 �迭�� ����
		if (node->left != NULL) push(node->left); // ���� �ڽ� ��尡 ���� �� ������ ����
		if (node->right != NULL) push(node->right); // �����ʵ� ����
	}
	for (i = i - 1; i >= 0; i--) printf("%d ", output[i]->data); // ���� �ݴ�� ����Ǿ� �����ϱ� �ڿ����� ���
}

//TreeNode ����
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

	printf("\n1. ���� ��ȸ");
	preorder_iter(root);

	printf("\n\n2. ���� ��ȸ");
	inorder_iter(root);

	printf("\n\n3. ���� ��ȸ");
	postorder_iter(root);
	printf("\n\n");

	return 0;
}
