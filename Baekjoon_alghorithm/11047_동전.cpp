#include <stdio.h>

int main() {

	int N, K; //N , K �Է¹ޱ�
	scanf_s("%d %d", &N, &K);

	if (N < 1 || N>10) //(1 �� N �� 10, 1 �� K �� 100,000,000)
		return 0;
	if (K < 1 || K>100000000)
		return 0;

	int arr[10];
	
	for (int i = 0; i < N; i++) { //N����ŭ ������ ��ġ A�� ������������ �Է¹���
		scanf_s("%d", &arr[i]);

		if (arr[0] != 1) //A1 = 1
			return 0;

		if (i > 0 && arr[i] % arr[i-1] != 0) { //i �� 2�� ��쿡 Ai�� Ai-1�� ���
			return 0;
		}

		if (i > 0 && arr[i] < arr[i - 1]) //������������ �Է�
			return 0;
	}

	int j = N - 1;
	int count = 0;
	for (j = N-1; j >= 0; j--) { 

		if (K % arr[j] == 0) { //������ ������ ���
			
			count = count + K / arr[j];  
			printf("%d", count);
			return 0;

		}
		else if (K % arr[j] != 0) {//������ �������� ���� ���

			count = count + (K / arr[j]);
			K = K - (K / arr[j]) * arr[j];
		}

	}
}