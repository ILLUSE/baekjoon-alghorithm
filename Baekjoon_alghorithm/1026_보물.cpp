#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

// 배열에 특정 값이 포함되어 있는지 확인하는 함수
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

	/* //확인용
	for (int i = 0; i < N; i++) {
		printf("A[%d] = %d / B[%d] = %d\n",i, A[i], i ,B[i]);
	}
	*/

	int fixed[50]; //고정된 인덱스가 들어갈 배열
	for (int i = 0; i < 50; i++) { //-1로 초기화
		fixed[i] = -1;
	}

	for (int j = 0; j < N; j++) {

		int min_index = -1;
		for (int i = 0; i < N; i++) { //A의 최소값 찾기
			if (contains(fixed, N, i)) {
				//printf("\nskip index %d\n", i); 확인용
				continue;
			}
			if (min_index== -1 || A[min_index] > A[i])
				min_index = i;
		}

		int max_index = -1;
		for (int i = 0; i < N; i++) { //B의 최소값 찾기
			if (contains(fixed, N, i)) {
				//printf("\nskip index %d\n", i); 확인용
				continue;
			}
			if (max_index == -1 || B[max_index] < B[i])
				max_index = i;
		}

		//A에서 가장 작은 값을 B의 가장 큰 값과 마주보게 하기
		int temp = A[min_index];
		A[min_index] = A[max_index];
		A[max_index] = temp;

		fixed[j] = max_index;

		/*
		printf("\nfixed[%d] = %d\n", j, fixed[j]); //확인용
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



	int S = 0; //S 출력
	for (int i = 0; i < N; i++) {
		S += A[i] * B[i];
	}

	printf("%d", S);

	return 0;
}