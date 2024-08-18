#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int n = 0;
	scanf("%d", &n);

	for (int i = 1; i < n; i++) {
		//각 자리 수 구하기
		int num = i;
		int million = num / 1000000;
		num = num - million * 1000000;
		int hundred_thousands = num / 100000;
		num = num - hundred_thousands * 100000;
		int ten_thousands = num / 10000;
		num = num - ten_thousands * 10000;
		int thousands = num / 1000;
		num = num - thousands * 1000;
		int hundreds = num / 100;
		num = num - hundreds * 100;
		int tens = num / 10;
		num = num - tens * 10;
		int units = num / 1;

		int sum = i + million + hundred_thousands + ten_thousands + thousands + hundreds + tens + units;
		
		if (sum == n) {
			printf("%d",i);
			return 0;
		}

 	}
	
	printf("0");
	return 0;
}