#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

// �迭�� Ư�� ���� ���ԵǾ� �ִ��� Ȯ���ϴ� �Լ�
bool contains(int arr[], int size, int value) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) {
			return true;
		}
	}
	return false;
}


int main() {

	int N = 0;
	scanf("%d", &N);

	int A[50];
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	int B[50];
	for (int i = 0; i < N; i++) {
		scanf("%d", &B[i]);
	}

	/* //Ȯ�ο�
	for (int i = 0; i < N; i++) {
		printf("A[%d] = %d / B[%d] = %d\n",i, A[i], i ,B[i]);
	}
	*/

	int fixed[50]; //������ �ε����� �� �迭
	for (int i = 0; i < 50; i++) { //-1�� �ʱ�ȭ
		fixed[i] = -1;
	}

	for (int j = 0; j < N; j++) {

		int min_index = -1;
		for (int i = 0; i < N; i++) { //A�� �ּҰ� ã��
			if (contains(fixed, N, i)) {
				//printf("\nskip index %d\n", i); Ȯ�ο�
				continue;
			}
			if (min_index== -1 || A[min_index] > A[i])
				min_index = i;
		}

		int max_index = -1;
		for (int i = 0; i < N; i++) { //B�� �ּҰ� ã��
			if (contains(fixed, N, i)) {
				//printf("\nskip index %d\n", i); Ȯ�ο�
				continue;
			}
			if (max_index == -1 || B[max_index] < B[i])
				max_index = i;
		}

		//A���� ���� ���� ���� B�� ���� ū ���� ���ֺ��� �ϱ�
		int temp = A[min_index];
		A[min_index] = A[max_index];
		A[max_index] = temp;

		fixed[j] = max_index;

		/*
		printf("\nfixed[%d] = %d\n", j, fixed[j]); //Ȯ�ο�
		printf("A - ");
		for (int i = 0; i < N; i++) {
			printf("%d ", A[i]);
		}
		printf("\nB - ");
		for (int i = 0; i < N; i++) {
			printf("%d ", B[i]);
		}
		*/
	}



	int S = 0; //S ���
	for (int i = 0; i < N; i++) {
		S += A[i] * B[i];
	}

	printf("%d", S);

	return 0;
}