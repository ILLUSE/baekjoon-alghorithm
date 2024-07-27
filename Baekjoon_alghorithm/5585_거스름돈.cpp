#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {

	int N;
	scanf("%d", &N);
	
	N = 1000 - N;

	int count = 0;

	if (N == 500) { //500원일때
		printf("1");
		return 0;
	}

	if (N > 500) { //N이 500보다 크면
		count += N / 500;
		N = N % 500;
	}

	if (N >= 100) { //N이 100보다 크면
		count += N / 100;
		N = N % 100;
	}

	if (N >= 50) { //N이 50보다 크면
		count += N / 50;
		N = N % 50;
	}

	if (N >= 10) { //N이 10보다 크면
		count += N / 10;
		N = N % 10;
	}

	if (N >= 5) { //N이 5보다 크면
		count += N / 5;
		N = N % 5;
	}

	count += N; //나머지 1원 동전 개수 추가

	printf("%d", count);

	return 0;
}