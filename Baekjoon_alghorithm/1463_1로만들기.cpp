#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//1���� N���� ���°� �����ߴµ� ������ ū�;� �Ѵٰ� ������ �ƴϴ�... ���� �ؾ�����!?
int main() {

	int n = 0;
	scanf("%d", &n);

	int a = 1;
	int cnt = 0;
	while (a != n) {

		if (a * 3 <= n) {
			a = a * 3;
			cnt++;
		}
		else if (a * 2 <= n) {
			a = a * 2;
			cnt++;
		}
		else if (a <= n) {
			a++;
			cnt++;
		}
	}

	printf("%d", cnt);
	return 0;
}