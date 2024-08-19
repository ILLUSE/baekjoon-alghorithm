#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int n = 0;
	scanf("%d", &n);
	int movie = 665;
	char str[100000];
	for (int i = 0; i < n; i++) {

		do {

			movie++;
			sprintf(str,"%d", movie);

		} while (strstr(str,"666") == NULL);

	}
	printf("%d", movie);
	return 0;
}