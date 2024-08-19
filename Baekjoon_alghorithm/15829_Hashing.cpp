#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//https://sedangdang.tistory.com/4 참고
int main() {
	int n = 0;
	scanf("%d", &n);

	char a[50];
	long long hash = 0;
	long long p = 1;
	for (int i = 0; i < n; i++) {
		scanf(" %c", &a[i]);
	
		
		hash += (((int)(a[i]) - 96) * p) % 1234567891; //오버플로우 발생하지 않도록 계산마다 %해주기!
		p = p * 31 % 1234567891;
	}
	hash = hash % 1234567891;
	printf("%lld", hash);
	return 0;
}