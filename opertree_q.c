#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define SIZE 100

typedef struct treeNode
{
	double data;
	struct treeNode* left, * right;
} TreeNode;


int top = -1;
TreeNode* stack[SIZE];

int is_empty()
{
	if (top == -1) return 1;
	else return 0;
}

void push(TreeNode* p)
{
	if (top < SIZE - 1) stack[++top] = p;
}

TreeNode* pop()
{
	TreeNode* p = NULL;
	if (top >= 0) p = stack[top--];
	return p;
}


int inorder_iter(TreeNode* root)
{
	int cnt = 0;
	while (root || !is_empty())
	{
		if (root)
		{
			push(root);
			root = root->left;
		}
		else
		{
			root = pop();
			cnt++;
			root = root->right;
		}
	}
	return cnt;
}

TreeNode n1 = { 2, NULL, NULL };
TreeNode n2 = { 3, NULL, NULL };
TreeNode n3 = { 4, NULL, NULL };
TreeNode n4 = { 5, NULL, NULL };
TreeNode n5 = { 6, NULL, NULL };
TreeNode n6 = { 7, NULL ,NULL };
TreeNode n7 = { 9, NULL ,NULL };

TreeNode op1 = { '*', &n3 ,&n4 };
TreeNode op2 = { '/', &n5 ,&n6 };
TreeNode op3 = { '+', &n1,&n2 };
TreeNode op4 = { '+', &op3,&op1 };
TreeNode op5 = { '-', &op4,&op2 };
TreeNode root = { '+', &op5,&n7 };

double evaluate(TreeNode* root)
{
	double result = 0;
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return root->data;
	else
	{
		double op1 = evaluate(root->left);
		double op2 = evaluate(root->right);
		printf("%.2f %c %.2f = ", op1, (char)root->data, op2);
		switch ((char)root->data)
		{
		case '+': printf("%.2f\n", op1 + op2); return op1 + op2;
		case '-': printf("%.2f\n", op1 - op2); return op1 - op2;
		case '*': printf("%.2f\n", op1 * op2); return op1 * op2;
		case '/': printf("%.2f\n", op1 / op2); return op1 / op2;
		}

	}
}

int main(void)
{
	printf("수식의 값은 %.2f입니다.\n", evaluate(&root));
	int count = inorder_iter(&root);
	printf("\n총 노드의 수는 %d개 입니다.\n", count);
	return 0;
}