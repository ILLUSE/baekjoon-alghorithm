#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	
	char a[1000000];
	scanf("%s", a);

	int change = 0;
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] != a[i + 1])
			change++;
	}

	printf("%d", change / 2);
	return 0;
}