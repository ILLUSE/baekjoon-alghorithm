#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0;
	int b = 0;
	scanf("%d %d", &a,&b);

	if (a < b) { //a�� �� ū ���� ����
		int temp = 0;
		temp = a;
		a = b;
		b = temp;
	}

	for (int i = b; i >= 1; i--) { //�ִ�����
		if (a % i == 0 && b % i == 0) {
			printf("%d\n", i);
			break;
		}
	}

	int a_multi = 1;
	int b_multi = 1;
	while (1) {
		
		while (a * a_multi >= b * b_multi) {
			if (a * a_multi == b * b_multi) { //�ּҰ����
				printf("%d", a * a_multi);
				return 0;
			}
			b_multi++;
		}
		a_multi++;
	}


	return 0;
}