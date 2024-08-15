#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int a, b;

int main() {
	scanf("%d %d", &a, &b);
	int cnt = 0;
	while (1) {
		if (a > b) { //���� a�� b���� Ŀ���� -1 ���
			printf("-1");
			break;
		}
		if (a == b) { //���̴�!
			printf("%d", cnt + 1);
			break;
		}

		if (b % 10 == 1) { //1 ������ ���̸� 1 ���ֱ� 
			b /= 10;
		}
		else if (b % 2 == 0) { //2���� ���̸� / 2 ���ֱ�
			b /= 2;
		}
		else {
			printf("-1");
			break;
		}
		cnt++;
	}
	return 0;
}

/*
24.08.15
#Feedback
1.BFS ���� �ʿ�(�ϴ� ���� ��ü�� �� �ڵ尡 �ƴ�)
2.�� �ڵ��� Ǭ�ٰ� �ص� �󸶳� ��带 ���������� ��

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// ��� ����ü ����
struct Node {
	int data;
	int depth;
	struct Node* left;
	struct Node* right;
};

// ���ο� ��带 �����ϴ� �Լ�
struct Node* createNode(int data,int depth) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->depth = depth;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// ���� Ʈ���� ��带 �����ϴ� �Լ�
struct Node* insertNode(struct Node* root, int data,int depth) {

	if (data > pow(10, 9)) { //���� �����Ͱ� 10�� 9�º��� ũ�ٸ� ����x
		return root;
	}

	if (root == NULL) {
		return createNode(data,depth);
	}

	int doubleA = data * 2;
	int plus1A = data * 10 + 1;
	depth = depth + 1;
	root->left = insertNode(root->left, doubleA,depth);
	
	root->right = insertNode(root->right, plus1A,depth);
	
	return root;
}

// Ʈ���� ���� ��ȸ�ϴ� �Լ�
void inorderTraversal(struct Node* root,int B) {
	if (root != NULL) {
		inorderTraversal(root->left,B);
		//printf("%d ", root->data);
		inorderTraversal(root->right,B);
		if (root->data == B) {
			printf("%d", root->depth+1);
			exit(1);
		}
	}
}


int main() {

	struct Node* root = NULL; //��Ʈ ��� ����

	int A, B = 0;
	scanf("%d %d", &A, &B);

	int i = 0;
	while (i< 5) {                        //��带 �󸶳� ������ �����ϱ�
		root = insertNode(root, A,0); 
		i++;
	}

	inorderTraversal(root,B);
	
	printf("-1");
	return 0;
}

*/