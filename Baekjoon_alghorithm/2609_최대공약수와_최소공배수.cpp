#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0;
	int b = 0;
	scanf("%d %d", &a,&b);

	if (a < b) { //a를 더 큰 수로 설정
		int temp = 0;
		temp = a;
		a = b;
		b = temp;
	}

	for (int i = b; i >= 1; i--) { //최대공약수
		if (a % i == 0 && b % i == 0) {
			printf("%d\n", i);
			break;
		}
	}

	int a_multi = 1;
	int b_multi = 1;
	while (1) {
		
		while (a * a_multi >= b * b_multi) {
			if (a * a_multi == b * b_multi) { //최소공배수
				printf("%d", a * a_multi);
				return 0;
			}
			b_multi++;
		}
		a_multi++;
	}


	return 0;
}