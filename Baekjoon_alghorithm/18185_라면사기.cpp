#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Min(int a, int b, int c) {
	if (a < b && a < c)return a;
	else if (b < a && b < c)return b;
	else return c;
}

int main() {

	int N = 0;
	scanf("%d", &N);


	int arr[10002] = { 0, };
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	int sum = 0;

	for (int i = 0; i < N-2; i++) {

		if (arr[i + 1] > arr[i + 2]) { //i+1�� i+2���� ũ�ٸ� i,i+1�� �����Ѹ�ŭ �Ⱦ� i+1�� i+2�� ���� �ִ��� �����ֱ�
			int min = arr[i];
			if (arr[i + 1] - arr[i + 2] < min) min = arr[i + 1] - arr[i + 2];
			arr[i] -= min;
			arr[i + 1] -= min;
			sum += min * 5;
		}

		
		int min = Min(arr[i], arr[i + 1], arr[i + 2]);
		arr[i] -= min;
		arr[i + 1] -= min;
		arr[i+2] -= min;

		sum += min * 7;
		
		
		sum += arr[i] * 3;
		

	}
	if (arr[N - 2] > 0 && arr[N - 1] > 0) {
		int min = arr[N-2];
		if (arr[N-1] < min) min = arr[N - 1];
		arr[N-2] -= min;
		arr[N-1] -= min;
		sum += min * 5;
	}
	
	sum += arr[N - 1]*3;

	printf("%d", sum);
	return 0;
}