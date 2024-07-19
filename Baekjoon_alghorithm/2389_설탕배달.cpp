#include <stdio.h>
int main() {

	int N;
	scanf_s("%d", &N);
	int count = 0;

	if (N < 3 || N > 5000) {
		printf("N shoould be 3 <= N <= 5000");
		return 0;
	}

	if (N % 5 == 0) {
		printf("%d", N / 5);
		return 0;
	}

	while (N >= 0) {

		if (N % 5 == 0) {
			printf("%d", (N / 5) + count);
			return 0;
		}

		N = N - 3;
		count++;

	}

	printf("-1");

	return 0;
}