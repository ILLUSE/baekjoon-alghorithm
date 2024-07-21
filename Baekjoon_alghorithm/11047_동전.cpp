#include <stdio.h>

int main() {

	int N, K; //N , K 입력받기
	scanf_s("%d %d", &N, &K);

	if (N < 1 || N>10) //(1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)
		return 0;
	if (K < 1 || K>100000000)
		return 0;

	int arr[10];
	
	for (int i = 0; i < N; i++) { //N개만큼 동전의 가치 A를 오름차순으로 입력받음
		scanf_s("%d", &arr[i]);

		if (arr[0] != 1) //A1 = 1
			return 0;

		if (i > 0 && arr[i] % arr[i-1] != 0) { //i ≥ 2인 경우에 Ai는 Ai-1의 배수
			return 0;
		}

		if (i > 0 && arr[i] < arr[i - 1]) //오름차순으로 입력
			return 0;
	}

	int j = N - 1;
	int count = 0;
	for (j = N-1; j >= 0; j--) { 

		if (K % arr[j] == 0) { //나누어 떨어질 경우
			
			count = count + K / arr[j];  
			printf("%d", count);
			return 0;

		}
		else if (K % arr[j] != 0) {//나누어 떨어지지 않을 경우

			count = count + (K / arr[j]);
			K = K - (K / arr[j]) * arr[j];
		}

	}
}