#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {

	int N;
	scanf("%d", &N);
	
	N = 1000 - N;

	int count = 0;

	if (N == 500) { //500���϶�
		printf("1");
		return 0;
	}

	if (N > 500) { //N�� 500���� ũ��
		count += N / 500;
		N = N % 500;
	}

	if (N >= 100) { //N�� 100���� ũ��
		count += N / 100;
		N = N % 100;
	}

	if (N >= 50) { //N�� 50���� ũ��
		count += N / 50;
		N = N % 50;
	}

	if (N >= 10) { //N�� 10���� ũ��
		count += N / 10;
		N = N % 10;
	}

	if (N >= 5) { //N�� 5���� ũ��
		count += N / 5;
		N = N % 5;
	}

	count += N; //������ 1�� ���� ���� �߰�

	printf("%d", count);

	return 0;
}