#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n = 0;
	scanf("%d", &n);

	double a[1000];
	double max = 0;

	for (int i = 0; i < n; i++) {
		scanf("%lf", &a[i]);
		if (a[i] > max)
			max = a[i];
	}


	double total = 0;
	for (int i = 0; i < n; i++) {
		
		a[i] = a[i] / max * 100;
		
		
		total = total + a[i];
	}
	

	total = total / n;

	printf("%lf", total);
	
	return 0;
}