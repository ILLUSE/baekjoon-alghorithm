/*
N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.
입력
첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)

출력
첫째 줄에 구한 0의 개수를 출력한다.

-key point
1.0의 개수는 x * (2*5)를 구하라는 뜻이다.
ex)3600 = 36 * (2*5) * (2*5) 이므로 (2*5)가 두번 있음
2는 짝수마다 있으므로 5가 몇개인지 세는 것

5의 배수의 수 + 25의 배수의 수(5 * 5이므로 2번 카운트) + 125의 배수의 수(5 * 5 * 5이므로 3번 카운트) = 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n = 0;
	scanf("%d", &n);

	if (n == 0 || n == 1) {
		printf("0");
		return 0;
	}

	int count = 0;

	for (int i = 1; i <= n; i++) {

		if (i % 5 == 0)//5의 배수면 count+1;
			count++;
		if (i % 25 == 0)//25의 배수면 count+2;
			count++;
		if (i % 125 == 0)//125의 배수면 count+3;
			count++;
			
	}

	printf("%d", count);
	return 0;
}