#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

int descending_comp(const void* a, const void* b)
{
	return(*(int*)b - *(int*)a); //�������� 
}

int main() {

	int N = 0; //N �Է¹ޱ�
	scanf("%d", &N);

	int rope[100000]; //������ �ִ��߷��� �� �迭
	for (int i = 0; i < N; i++) {
		scanf("%d", &rope[i]);
	}

	qsort(rope, N, sizeof(int), descending_comp); //�������� �ִ��߷��� ������������ �迭 ����

	/*
	printf("rope after sort\n"); //Ȯ�ο�
	for (int i = 0; i < N; i++) {
		printf("%d\n", rope[i]);
	}
	*/
	int arr[100000]; //������ i�� ������ �ִ��߷��� �� �迭
	
	for (int i = 0; i < N; i++) {
		
		if(i==0)
			arr[i] = rope[i];
		else
			arr[i] = rope[i]*(i+1);

	}

	int max = 0;
	for (int i = 0; i < N; i++) { //arr �� �ִ밪 ã��
		if (max < arr[i])
			max = arr[i];
	}

	printf("%d", max);
	return 0;
}