#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int T = 0;
	scanf("%d", &T);

	int A = 300;
	int B = 60;
	int C = 10;

	int A_count = 0;
	int B_count = 0;
	int C_count = 0;

	A_count = T / A;
	T = T % A;

	B_count = T / B;
	T = T % B;

	C_count = T / C;
	T = T % C;
	
	if (T == 0) {
		printf("%d %d %d", A_count, B_count, C_count);
	}
	else printf("-1");

	return 0;
}