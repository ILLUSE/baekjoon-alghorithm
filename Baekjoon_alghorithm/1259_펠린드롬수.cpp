#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	
	while (1) {
		char a[100000];
		scanf("%s", a);

		if (a[0] == '0') { //0�� ���Դٸ�
			return 0;
		}
		else if (strlen(a) == 1) { //�ѱ��ڸ� ���Դٸ�
			printf("yes\n");
			continue;
		}
		else {
			int stop = 0;
			for (int i = 0; i < strlen(a) / 2; i++) {
				if (a[i] != a[strlen(a) - i-1]) { //���� ��Ī�� �ȸ´ٸ�
					printf("no\n");
					stop++;
					break;
				}
			}
			if(stop == 0)
				printf("yes\n");
		}
	}


	return 0;
}