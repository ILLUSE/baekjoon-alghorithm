#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int is_prime(int a) {


	if (a == 1)return 0;
	if (a == 2)return 1;
	for (int i = 2; i <= sqrt(a); i++) { //소수면 1출력
		if (a % i == 0) 
			return 0;
	}
	return 1;
}

int main() {

	int n = 0;
	scanf("%d", &n);
	int count = 0;

	for (int i = 0; i < n; i++) {
		int a = 0;
		scanf("%d", &a);
		if(is_prime(a) == 1)
			count++;
	}

	printf("%d", count);
	return 0;
}