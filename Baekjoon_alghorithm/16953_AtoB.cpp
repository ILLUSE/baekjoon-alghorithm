#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int a, b;

int main() {
	scanf("%d %d", &a, &b);
	int cnt = 0;
	while (1) {
		if (a > b) { //만약 a가 b보다 커지면 -1 출력
			printf("-1");
			break;
		}
		if (a == b) { //답이다!
			printf("%d", cnt + 1);
			break;
		}

		if (b % 10 == 1) { //1 덧붙인 값이면 1 빼주기 
			b /= 10;
		}
		else if (b % 2 == 0) { //2곱한 값이면 / 2 해주기
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
1.BFS 공부 필요(일단 접근 자체가 현 코드가 아님)
2.이 코드대로 푼다고 해도 얼마나 노드를 만들어야할지 모름

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// 노드 구조체 정의
struct Node {
	int data;
	int depth;
	struct Node* left;
	struct Node* right;
};

// 새로운 노드를 생성하는 함수
struct Node* createNode(int data,int depth) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->depth = depth;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// 이진 트리에 노드를 삽입하는 함수
struct Node* insertNode(struct Node* root, int data,int depth) {

	if (data > pow(10, 9)) { //만약 데이터가 10의 9승보다 크다면 삽입x
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

// 트리를 중위 순회하는 함수
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

	struct Node* root = NULL; //루트 노드 선언

	int A, B = 0;
	scanf("%d %d", &A, &B);

	int i = 0;
	while (i< 5) {                        //노드를 얼마나 만들어야 최적일까
		root = insertNode(root, A,0); 
		i++;
	}

	inorderTraversal(root,B);
	
	printf("-1");
	return 0;
}

*/