#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n = 0;
	scanf("%d", &n);

	int count = 1;
	if (n == 1) {
		printf("1");
		return 0;
	}
	int range1 = 1;
	int range2 = 7;
	while (1) {
		count++;
		if (range1 < n && n <= range2) {
			printf("%d", count);
			return 0;
		}
		range1 = range2;
		range2 = range2 + 6 * count;
	}

	return 0;
}