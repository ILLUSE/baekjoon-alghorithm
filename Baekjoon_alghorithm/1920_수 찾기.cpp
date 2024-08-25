/*
문제
N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다.
다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다.
다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다.
다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다.
모든 정수의 범위는 -231 보다 크거나 같고 231보다 작다.

출력
M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.

-key point
1.qsort
왜
int compare(const int* a, const int* b)
	return(*a - *b);
는 안되고
int compare(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}
는 되지

2.이분탐색

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
		if (key == data[mid]) {            //탐색 성공
			return 1;
		}
		else if (key < data[mid]) {        //탐색 범위를 아래쪽으로
			high = mid - 1;
		}
		else if (key > data[mid]) {        //탐색 범위를 위쪽으로
			low = mid + 1;
		}
	}
	return 0;                            //탐색 실패
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