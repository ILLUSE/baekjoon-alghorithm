/*
����
N���� ���� A[1], A[2], ��, A[N]�� �־��� ���� ��, �� �ȿ� X��� ������ �����ϴ��� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� N(1 �� N �� 100,000)�� �־�����.
���� �ٿ��� N���� ���� A[1], A[2], ��, A[N]�� �־�����.
���� �ٿ��� M(1 �� M �� 100,000)�� �־�����.
���� �ٿ��� M���� ������ �־����µ�, �� ������ A�ȿ� �����ϴ��� �˾Ƴ��� �ȴ�.
��� ������ ������ -231 ���� ũ�ų� ���� 231���� �۴�.

���
M���� �ٿ� ���� ����Ѵ�. �����ϸ� 1��, �������� ������ 0�� ����Ѵ�.

-key point
1.qsort
��
int compare(const int* a, const int* b)
	return(*a - *b);
�� �ȵǰ�
int compare(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}
�� ����

2.�̺�Ž��

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}

int binsearch(int data[], int n, int key) {
	int low, high;
	int mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (key == data[mid]) {            //Ž�� ����
			return 1;
		}
		else if (key < data[mid]) {        //Ž�� ������ �Ʒ�������
			high = mid - 1;
		}
		else if (key > data[mid]) {        //Ž�� ������ ��������
			low = mid + 1;
		}
	}
	return 0;                            //Ž�� ����
}


int main() {
	int n = 0;
	scanf("%d", &n);
	 
	int* arrN = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arrN[i]);
	}

	int m = 0;
	scanf("%d", &m);

	int* arrM = (int*)malloc(sizeof(int) * m);
	
	for (int i = 0; i < m; i++) {
		scanf("%d", &arrM[i]);
	}

	qsort(arrN, n, sizeof(int), compare);
	

	for (int i = 0; i < m; i++) {
		
		int num = binsearch(arrN, n, arrM[i]);
		printf("%d\n", num);
		
	}
	return 0;
}