#define _CRT_SECURE_NO_WARNINGS //접근부터 틀림
#include <stdio.h> 
#include <stdlib.h> //qsort라이브러리를 부를 수 있는 헤더파일

int compare(const void* a, const void* b) {
    if (*(int*)a > *(int*)b) {
        return 1;
    }
    else if (*(int*)a < *(int*)b) {
        return -1;
    }
    else {
        return 0;
    }
}

int main() {

	int N = 0;
	int arr[100000];
    scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, N, sizeof(int), compare);

    int sum = 0;
    int total = 0;
    if (N == 1)sum = 0;
    else if (N == 2)sum = arr[0] + arr[1];
    else {
        total = arr[0] + arr[1];
        sum += total;
        for (int i = 2; i < N; i++) {

            total +=arr[i];
            sum += total;

        }
    }
   
    printf("%d", sum);
	return 0;
}